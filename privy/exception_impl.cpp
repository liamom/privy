//
// Created by Owner on 7/29/2017.
//

#include "exception_impl.h"
#include <SDL2/SDL.h>

namespace privy {

Exception::Exception(const char* file, const char* func, int line) {
  char* sdl_error = SDL_GetError();
  stream_ << file << "|"
          << func << ":"
          << line << "|"
          << " SDL error:" << sdl_error << " ";
}

}