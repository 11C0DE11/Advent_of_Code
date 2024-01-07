#include <iostream>
#include <fstream>
#include <cctype>

int main() {
    std::ifstream file("input");
    std::string line;

    if (!file.is_open()) {
        std::cerr << "error opening input file" << '\n';
        return -1;
    }

    int left, right, sum = 0;

    while (std::getline(file, line)) {
           left  = 0;
           right = line.size()-1;

	   while (!std::isdigit(line[left])) left++;
           while (!std::isdigit(line[right])) right--;
        
   	   if (left == right) {
	       if (std::isdigit(line[left]))
 		   sum += ((line[left] - '0') * 10 + (line[left] - '0'));
               else
 		   sum += ((line[right] - '0') * 10 + (line[right] - '0'));
	   }
	   else {
               sum += ((line[left] - '0') * 10) + (line[right] - '0');	   
	   }    
    } 

    std::cout << "Final sum: " << sum << '\n';

    return 0;
}
