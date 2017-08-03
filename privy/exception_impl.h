//
// Created by Owner on 7/29/2017.
//

#ifndef PROJECT_EXCEPTION_IMPL_H
#define PROJECT_EXCEPTION_IMPL_H

#include "include/privy/exception.h"
#include <sstream>
#include <string>

namespace privy {
namespace internal {

class _Exception : public privy::Exception {
public:
  _Exception(const char *file, const char *func, int line);
  _Exception(const _Exception &) = delete;
  _Exception(_Exception &&) = default;

  const char *what() const noexcept override;

private:
  mutable std::string message_;
  std::stringstream stream_;

  template<class ANYTHING> friend _Exception &&operator<<(_Exception &&t, ANYTHING thing);

};

template<class ANYTHING>
_Exception &&operator<<(_Exception &&t, ANYTHING thing) {
  t.stream_ << thing;
  return std::move(t);
}

}
}

#define MAKE_EXCEPTION privy::internal::_Exception(__FILE__, __func__, __LINE__)

#endif //PROJECT_EXCEPTION_IMPL_H
