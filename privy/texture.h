//
// Created by lioth on 7/29/2017.
//

#ifndef PROJECT_TEXTURE_H
#define PROJECT_TEXTURE_H

#include <SDL.h>
#include "sdl_base.h"

namespace privy {

class Texture : public sdl_base<SDL_Texture> {
public:
  Texture(SDL_Renderer *renderer, const char* bitmap);
  Texture(Texture&&) = default;
  ~Texture();
};

}

#endif //PROJECT_TEXTURE_H
