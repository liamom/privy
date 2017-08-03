//
// Created by lioth on 7/29/2017.
//

#ifndef PROJECT_WINDOW_H
#define PROJECT_WINDOW_H

#include <SDL_video.h>
#include "exception_impl.h"
#include "sdl_base.h"

namespace privy {

class Window : public sdl_base<SDL_Window>{
public:
  Window(const char *title,
         int x, int y, int w,
         int h, SDL_WindowFlags flags = SDL_WindowFlags::SDL_WINDOW_SHOWN);

  ~Window();
};

}

#endif //PROJECT_WINDOW_H
