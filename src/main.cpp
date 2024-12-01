#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>    // for std::getenv
#include <string>     // for std::string
#include <sstream>    // for std::stringstream
#include <unistd.h>   
using namespace std;


std::string get_path(const std::string& command) {
    // Get the PATH environment variable
    std::string path_env = std::getenv("PATH");
    std::stringstream ss(path_env);
    std::string path;

    // Iterate over each path in the PATH environment variable
    while (getline(ss, path, ':')) {
        std::string abs_path = path + "/" + command;

        // Check if the file exists and is executable
        if (access(abs_path.c_str(), X_OK) == 0) {
            return abs_path;  // Return the absolute path if found
        }
    }

    // Return empty string if command not found
    return "";
}

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
    else if (input.find("type ")==0){
      string sub = input.substr(5);
      if (input.substr(5) == "exit" || input.substr(5) == "echo" || input.substr(5) == "type") std::cout << input.substr(5)<<" "<<"is a shell built-in" << std::endl;
      else {
        std::string path = get_path(sub);
        if (path.empty()) {
            std::cout << sub << ": not found\n";
        } else {
            std::cout << input.substr(5) << " is " << path << std::endl;
        }
      }
    }
    else if(input.find("pwd")==0){
      char cwd[1024];
      if (getcwd(cwd, sizeof(cwd)) != NULL) {
          std::cout << cwd << std::endl;
      } else {
          std::cerr << "getcwd() error" << std::endl;
      }
    }
    else if(input.find("cd")==0){
      string sub = input.substr(3);
      if (sub == "") {
        chdir(getenv("HOME"));
      } 
      else if (sub == "~"){
        chdir(getenv("HOME"));
      }
      else {
        int check_path=chdir(sub.c_str());
        if (check_path == -1) {
          std::cerr << "cd: " << sub << ": No such file or directory" << std::endl;
        }
      }
    }
    else{
      int check_file=system(input.c_str());
      if (check_file == 0) continue;
      else
      cout << input << ": command not found" << endl;
    }
  }
}
