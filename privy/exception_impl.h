//
// Created by Owner on 7/29/2017.
//

#ifndef PROJECT_EXCEPTION_H
#define PROJECT_EXCEPTION_H

#include <exception>
#include <string>

namespace privy {

class _Exception : privy::Exception {
public:
  _Exception(const char* file, const char* func, int line);

  const char* what() override {
    message_ = stream_.str();
    message_.c_str();
  }

  std::ostream& stream() {
    return stream_;
  }

private:
  std::string message_;
  std::stringstream stream_;
};

#define MAKE_EXCEPTION privy::_Exception(__FILE__, __func__, __LINE__).stream()

}

#endif //PROJECT_EXCEPTION_H
