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
    cout<<input<<": command not found"<<endl;
  }
}
