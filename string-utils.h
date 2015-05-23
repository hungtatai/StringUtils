

#include <string>
#include <sstream>
#include <fstream>
#include <vector>

#ifndef STRING_UTILS_H
#define STRING_UTILS_H


static inline std::vector<std::string> Compact(const std::vector<std::string> &tokens){
  std::vector<std::string> compacted;

  for(int i=0; i<tokens.size(); ++i) {
    if (!tokens[i].empty()) {
      compacted.push_back(tokens[i]);
    }
  }

  return compacted;
}

static inline std::vector<std::string> Split(const std::string &str, const std::string &delim, const bool trim_empty = false){
  size_t pos, last_pos = 0, len;
  std::vector<std::string> tokens;

  while(true) {
    pos = str.find(delim, last_pos);
    if (pos == std::string::npos) {
      pos = str.size();
    }

    len = pos-last_pos;
    if ( !trim_empty || len != 0) {
      tokens.push_back(str.substr(last_pos, len));
    }

    if (pos == str.size()) {
      break; 
    } else {
      last_pos = pos + delim.size();
    }
  }

  return tokens;
}

static inline std::string Join(const std::vector<std::string> &tokens, const std::string &delim, const bool trim_empty = false){
  if(trim_empty) {
    return Join(Compact(tokens), delim, false);
  } else {
    std::stringstream ss;
    for(int i=0; i<tokens.size()-1; ++i) {
      ss << tokens[i] << delim;
    }
    ss << tokens[tokens.size()-1];

    return ss.str();
  }
}

static inline std::string Trim(const std::string &str){
  
  std::string blank = "\r\n\t ";
  size_t begin = str.size(), end = 0;
  for (int i=0; i<str.size(); ++i) {
    if ( blank.find(str[i]) == std::string::npos) {
      begin = i;
      break;
    }
  }

  for (int i=str.size()-1; i>=0; --i) {
    if ( blank.find(str[i]) == std::string::npos) {
      end = i;
      break;
    }
  }
  
  if (begin >= end) {
    return "";
  } else {
    return str.substr(begin, end-begin+1);
  }
}

static inline std::string ReadFile(const std::string &filename) {
  std::ifstream ifs(filename);
  std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );
  return content;
}



#endif