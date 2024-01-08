#include <unordered_map>
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

int string_to_int(std::string str) {

    int multiplier{1}, result{0};

    for (int i = str.size()-1; i >= 0; i--, multiplier *= 10) {
	 result += (str[i] - '0') * multiplier;
    }

    return result;
}

int main() {

    std::ifstream file{"input"};
    std::string line;
    
    if (!file.is_open()) {
	std::cerr << "failed to open input file" << '\n';
	return -1;
    }

    std::unordered_map<std::string, int> map {
       {"red", 12}, {"green", 13}, {"blue", 14}
    };
   
    int sum{0};

    while (std::getline(file, line)) {
	
	auto it = line.begin();

	std::string id; 
	std::unordered_map<std::string, int> temp_map;
	
	while (*it != ':' && it != line.end()) { // Parse ID
	
	    if (std::isdigit(*it)) 
	        id += *it;	

	    it++;
	}
			
	std::string number;
	std::string colour; 	

        while (it != line.end()) { // Go through rest of line
	
 	    if (std::isalpha(*it)) {
		colour += *it;
	    } 
            else if (std::isdigit(*it)) {
		number += *it;
	    } 

            if ((*it) == ',') {

		temp_map[colour] += string_to_int(number);
	
         	if (map[colour] - temp_map[colour] < 0) {
		    break;
 		}

                number.clear();
		colour.clear();	
	    }

	    if ((*it) == ';' || it == line.end()-1) {
 
	       	temp_map[colour] += string_to_int(number);
	
         	if (map[colour] - temp_map[colour] < 0) {
		    break;
 		}

                number.clear();
		colour.clear();	
		temp_map.clear();
	    }

	    it++;
	}

	if (it == line.end()) {
	    sum += string_to_int(id);
	}
    } 

    std::cout << "Final value: " << sum << '\n';

    return 0;
}
