//
// Created by Owner on 7/29/2017.
//

#ifndef PROJECT_SDL_MAIN_H
#define PROJECT_SDL_MAIN_H

#include <SDL2/SDL.h>
#include "exception"
#include "exception_impl.h"

namespace privy {

class Game {
  Game() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
      throw MAKE_EXCEPTION << "init error";
    }
  }


};

}

#endif //PROJECT_SDL_MAIN_H
