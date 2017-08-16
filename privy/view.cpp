//
// Created by lioth on 8/5/2017.
//

#include "view.h"
#include <sdl.h>
#include <cmath>

void privy::View::RenderCopy(SDL_Texture *tex,
                             const SDL_Rect &source_rect,
                             const SDL_Rect &dest_rectconst,
                             double angle) {
  SDL_Point *null = nullptr;
  RenderCopy(tex, source_rect, dest_rectconst, angle, *null, SDL_FLIP_NONE);
}

void privy::View::RenderCopy(SDL_Texture *tex,
                             const SDL_Rect &source_rect,
                             SDL_Rect dest_rect,
                             double angle,
                             const SDL_Point &center,
                             SDL_RendererFlip flip) {
  std::array<double, 2> d{1,1};
  dVector2 test (d);
//  dVector2 test {1,1};

  //rotation
  double rad = (PI/180) * rotation_;
  dest_rect.x = dest_position_.x()*std::cos(rad) - dest_position_.y()*std::sin(rad);
  dest_rect.y = dest_position_.x()*std::sin(rad) + dest_position_.y()*std::cos(rad);


  dest_rect *= mult_;
  dest_rect += dest_position_;
  dest_rect += src_position_;
  angle     += rotation_;



  renderer_.RenderCopy(tex, source_rect, dest_rect, angle, center, flip);
}
