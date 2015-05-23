

#include <map>
#include <iostream>
#include <string>
#include "../../string-utils.h"

class MyConf {

private:
  std::map<std::string, std::string> pairs;
public:
  MyConf(std::string file_name) {
    std::string content = ReadFile(file_name);
    std::vector<std::string> vec = Split(content, "\n");
    for (int i=0; i<vec.size(); ++i) {
      std::vector<std::string> kv = Split(vec[i], "=");
      pairs[Trim(kv[0])] = Trim(kv[1]);
    } 
  }

  std::string get(std::string key) {
    return pairs[key];
  }

};


int main (int argc, char *argv[]) {

  MyConf conf("my.conf");

  std::cout << "user_name: " << conf.get("user_name") << std::endl;
  std::cout << "program_name: " << conf.get("program_name") << std::endl;
  std::cout << "working_directory: " << conf.get("working_directory") << std::endl;


  return 0;
}