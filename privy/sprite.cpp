//
// Created by lioth on 8/5/2017.
//

#include <algorithm>
#include "privy/include/privy/sprite.h"

privy::Sprite::Sprite(Texture &texture, SDL_Rect render_rect)
  :texture_(texture)
  ,render_rect_(std::move(render_rect)){

}

void privy::Sprite::render(privy::View &view, int x, int y) {
  SDL_Rect dest {x, y, render_rect_.w, render_rect_.h};
//  renderer.RenderCopy(texture_, render_rect_, dest);
  view.RenderCopy(texture_, render_rect_, dest);
}
