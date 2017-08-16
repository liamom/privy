//
// Created by lioth on 8/5/2017.
//

#ifndef GAMEENGINE_SPRITE_H
#define GAMEENGINE_SPRITE_H

#include "texture.h"
#include "view.h"

namespace privy {

class Sprite {
public:
  Sprite(Texture &texture, SDL_Rect render_rect);

  virtual void render(View &view, int x, int y);

private:
  Texture &texture_;
  SDL_Rect render_rect_;
};

}

#endif //GAMEENGINE_SPRITE_H
