//
// Created by Owner on 7/29/2017.
//

#ifndef PROJECT_LOGGER_H
#define PROJECT_LOGGER_H

#include <ostream>

class _logger {
 public:
  static _logger make_logger() {
    return _logger();
  }

  operator std::ostream &() { return _ss; }
 private:
  ~_logger() {
    ss << _endl;
  }

  std::stringstream ss_;
};

#define LOG _logger::make_logger() << __FILE__ << "|" << __func__ <<  ":" << __LINE__ << "|"

#endif //PROJECT_LOGGER_H
