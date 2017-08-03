//
// Created by lioth on 7/29/2017.
//

#ifndef PROJECT_SURFACE_H
#define PROJECT_SURFACE_H

#include "sdl_base.h"
#include "SDL_surface.h"

namespace privy {

class Surface : public sdl_base<SDL_Surface> {
public:
  Surface(const char *bmp);
  ~Surface();

};

}

#endif //PROJECT_SURFACE_H
