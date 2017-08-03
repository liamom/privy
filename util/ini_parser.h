//
// Created by lioth on 7/29/2017.
//

#ifndef PROJECT_INI_PARSER_H
#define PROJECT_INI_PARSER_H

#include <string>
#include <map>

class IniParser {
public:
  IniParser(const char* file_path);

  const std::string& get(const std::string &section, const std::string &key);

private:
  using Section = std::map<std::string, std::string>;
  std::map<std::string, Section> file_;
};

#endif //PROJECT_INI_PARSER_H
