
#ifndef PROJECT_EXCEPTION_H
#define PROJECT_EXCEPTION_H

#include <exception>
#include <string>

namespace privy {

class Exception : std::exception {
public:
  using std::exception::what;
};

}

#endif