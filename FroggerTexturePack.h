//
// Created by lioth on 8/5/2017.
//

#ifndef GAMEENGINE_FROGGERTEXTUREPACK_H
#define GAMEENGINE_FROGGERTEXTUREPACK_H

#include "privy/include/privy/privy.h"
#include <array>
#include "util/util.h"

struct FroggerTexturePack {
  FroggerTexturePack(privy::Renderer &ren)
    :frogger(ren.createTexture(get_file("frogger.png")))
  {  }

  privy::Texture frogger;
  std::array<privy::Sprite, 3> running_{{
      privy::Sprite(frogger, SDL_Rect{ 0, 0, 16, 16}),
      privy::Sprite(frogger, SDL_Rect{16, 0, 16, 16}),
      privy::Sprite(frogger, SDL_Rect{32, 0, 16, 16})
  }};

};

#endif //GAMEENGINE_FROGGERTEXTUREPACK_H
