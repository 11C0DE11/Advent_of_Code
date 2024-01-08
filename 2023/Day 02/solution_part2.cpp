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
   
    int sum{0};

    while (std::getline(file, line)) {
	
	auto it = line.begin();

	std::unordered_map<std::string, int> map  {
	   {"red", 0}, {"blue", 0}, {"green", 0}
	};
	
	while (*it != ':' && it != line.end()) { 	 
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

            if ((*it) == ',' || (*it) == ';' || it == line.end()-1) {
		map[colour] = std::max(map[colour], string_to_int(number));	
	        number.clear();
		colour.clear();	
	    }

	    it++;
	}

        sum += map["red"] * map["blue"] * map["green"];	
    }

    std::cout << "Final value: " << sum << '\n'; 

    return 0;
}
