#include <iostream>
#include <string>
using namespace std;
int main() {

  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  while (true){
    std::cout << "$ ";
    
    std::string input;
    getline(std::cin, input);
    if (input == "exit 0") return 0;
    else if (input.find("echo ")==0){
      std::cout << input.substr(5) << std::endl;
    }
    else{
      cout << input << ": command not found" << endl;
    }
  }
}
