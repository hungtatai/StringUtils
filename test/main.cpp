

#include <iostream>
#include "../string-utils.h"



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
      std::cout << "Passing: " << "Trim(\" hi \")" << std::endl;
      pass_cases++;
    }
  }

  {
    if (eq(Repeat("-", 5), "-----")) {
      std::cout << "Passing: " << "Repeat(\"-\", 5)" << std::endl;
      pass_cases++;
    }
  }

  {
    if (eq(ReplaceAll("monday morning", "mo", "kk"), "kknday kkrning")) {
      std::cout << "Passing: " << "ReplaceAll(\"monday morning\", \"mo\", \"kk\")" << std::endl;
      pass_cases++;
    }
  }

  {
    if (eq(ToUpper("abcd"), "ABCD")) {
      std::cout << "Passing: " << "ToUpper(\"abcd\")" << std::endl;
      pass_cases++;
    }
  }

  {
    if (eq(ToLower("ABCD"), "abcd")) {
      std::cout << "Passing: " << "ToLower(\"ABCD\")" << std::endl;
      pass_cases++;
    }
  }

  {
    if (eq(ReadFile("test_readfile.txt"), "12345")) {
      std::cout << "Passing: " << "ReadFile(\"test_readfile.txt\")" << std::endl;
      pass_cases++;
    }
  }

  {
    WriteFile("test_writefile.txt", "abcde");
    if (eq(ReadFile("test_writefile.txt"), "abcde")) {
      std::cout << "Passing: " << "WriteFile(\"test_writefile.txt\", \"abcde\")" << std::endl;
      pass_cases++;
    }
  }

  std::cout << "Result: " << pass_cases << "/12" << " Completed." << std::endl;

  return 0;
}