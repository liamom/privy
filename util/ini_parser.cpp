//
// Created by lioth on 7/29/2017.
//

#include <fstream>
#include "ini_parser.h"

namespace {
  const std::string NULL_STRING;
}

IniParser::IniParser(const char *file_path) {
  std::ifstream file(file_path);

  std::string current_section;

  std::string line;
  while(std::getline(file, line)){
    if(!line.empty()) {
      if (line[0] == ';') continue;

      if(line[0] == '[' && line[line.size()] == ']'){
        current_section.assign(line.begin()+1, line.begin() + line.size() - 1);
        continue;
      }

      std::string::size_type n = line.find('=');
      if(n != std::string::npos) {
        std::string key(line, 0, n);
        std::string value(line, n + 1);
        file_[current_section].emplace(std::move(key), std::move(value));
      }
    }
  }
}
const std::string &IniParser::get(const std::string &section_name, const std::string &key_name) {
  auto section_it = file_.find(section_name);
  if(section_it != file_.end()) {
    Section &section = section_it->second;
    auto key_it = section.find(key_name);
    if (key_it != section.end()) {
      return key_it->second;
    }
  }

  return NULL_STRING;
}
