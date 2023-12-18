struct Node {
    std::unordered_map<char, Node*> map;
    bool is_word;
    Node() : is_word(false) {} 
};

class Trie {

private:
    Node *root;

public:
    Trie() : root(new Node()) {
       insert("one"); insert("1");
       insert("two"); insert("2"); 
       insert("three"); insert("3");
       insert("four"); insert("4");
       insert("five"); insert("5");
       insert("six"); insert("6");
       insert("seven"); insert("7");
       insert("eight"); insert("8");
       insert("nine"); insert("9"); 
    }
    
    void insert(std::string word) {
        
         Node *curr = root;

         for (int i = 0; i < word.size(); i++) {

              if (curr->map.find(word[i]) == curr->map.end()) {
                  curr->map[word[i]] = new Node();
              }

              curr = curr->map[word[i]];
         }

         curr->is_word = true;
    }
    
    std::vector<std::string> search(std::string& word) {

         Node *curr = root;
	 std::string result;
	 std::vector<std::string> vec;

    	 for (int i = 0; i < word.size(); i++) {

              curr = root;
              result = "";

              for (int j = i; j < word.size(); j++) {

             	   if (curr->map.find(word[j]) == curr->map.end()) {
                       break;
            	   }

            	   result += word[j];
            	   curr = curr->map[word[j]];

            	   if (curr->is_word) {
                       vec.push_back(result);
              	       break;
                   }
              }
         }         
              
         return vec;
    }
};

int main() {

    Trie t;           
    std::ifstream file("input");
    std::string line;

    std::unordered_map<std::string, int> map {
       {"one",1}, {"two",2}, {"three",3}, {"four",4},
       {"five",5}, {"six",6}, {"seven",7}, {"eight",8},
       {"nine",9}, {"1",1}, {"2",2}, {"3",3}, {"4",4},
       {"5",5}, {"6",6}, {"7",7}, {"8",8}, {"9",9}
    };

    if (!file.is_open()) {
	std::cout << "error opening file\n";
        return -1;
    }
    
    int sum = 0;

    while (std::getline(file, line)) {
           
           std::vector<std::string> vec = t.search(line);
	   
           if (vec.size() > 1) {
               sum += (map[vec[0]] * 10) + map[*(vec.rbegin())];
           }
	   else if (vec.size() == 1) { 
	       sum +=  (map[vec[0]] * 10) + (map[vec[0]]);
	   }
    }

    std::cout << "Sum is: " << sum << '\n';
 
    return 0;
}
