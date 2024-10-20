#include <iostream>
#include <string>
using namespace std;
int main() {

  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;


  std::cout << "$ ";
  
  std::string input;
  // std::getline(std::cin, input);
  getline(std::cin, input);
}
