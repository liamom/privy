//
// Created by Owner on 7/29/2017.
//

#include "exception_impl.h"
#include <SDL.h>

namespace privy {
namespace internal {

_Exception::_Exception(const char *file, const char *func, int line) {
  const char *sdl_error = SDL_GetError();
  stream_ << file << "|"
          << func << ":"
          << line << "|"
          << " SDL error:" << sdl_error << "| ";
}

const char *_Exception::what() const noexcept {
  message_ = stream_.str();
  return message_.c_str();
}

}
}