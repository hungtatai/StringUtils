

#include <iostream>
#include "string-utils.h"



bool eq(std::vector<std::string> v1, std::vector<std::string> v2) {
  if (v1.size() != v2.size()) {
    return false;
  }
  for (int i=0; i<v1.size(); ++i) {
    if (v1[i] != v2[i]) {
      return false;
    }
  }
  return true;
}

bool eq(std::string s1, std::string s2) {
  return s1 == s2;
}

int main (int argc, char *argv[]) {

  std::string s = "--1---2----3--4--";
  std::string delim = "--";
  std::string compacted_s = "1---2--3--4";

  std::vector<std::string> res;
  res.push_back("");
  res.push_back("1");
  res.push_back("-2");
  res.push_back("");
  res.push_back("3");
  res.push_back("4");
  res.push_back("");
  std::vector<std::string> compacted_res;
  compacted_res.push_back("1");
  compacted_res.push_back("-2");
  compacted_res.push_back("3");
  compacted_res.push_back("4");

  int pass_cases = 0;

  {
    if (eq(Split(s, delim, false), res)) {
      std::cout << "Passing: " << "Split(s, delim, false)" << std::endl;
      pass_cases++;
    }
  }

  {
    if (eq(Split(s, delim, true), compacted_res)) {
      std::cout << "Passing: " << "Split(s, delim, true)" << std::endl;
      pass_cases++;
    }
  }

  {
    if (eq(Join(res, delim, false), s)) {
      std::cout << "Passing: " << "Join(res, delim, false)" << std::endl;
      pass_cases++;
    }
  }

  {
    if (eq(Join(res, delim, true), compacted_s)) {
      std::cout << "Passing: " << "Join(res, delim, true)" << std::endl;
      pass_cases++;
    }
  }

  {
    if (eq(Compact(res), compacted_res)) {
      std::cout << "Passing: " << "Compact(res)" << std::endl;
      pass_cases++;
    }
  }


  {
    if (eq(Trim("  hi"), "hi") && eq(Trim("hi  "), "hi") && eq(Trim("  hi  "), "hi") ) {
      std::cout << "Passing: " << "Trim()" << std::endl;
      pass_cases++;
    }
  }

  std::cout << "Result: " << pass_cases << "/6" << " Completed." << std::endl;

  return 0;
}