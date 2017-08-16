//
// Created by lioth on 8/5/2017.
//

#ifndef GAMEENGINE_VIEW_H
#define GAMEENGINE_VIEW_H

#include "privy_math.h"
#include "renderer.h"

namespace privy {

class View {
public:
  View(Renderer &renderer): renderer_(renderer) {};
  View(Renderer &renderer, iVector2 src, iVector2 dest): renderer_(renderer), src_position_(src), dest_position_(dest) {};

  void RenderCopy(SDL_Texture *tex, const SDL_Rect &source_rect, const SDL_Rect &dest_rectconst, double angle = 0);
  void RenderCopy(SDL_Texture *tex, const SDL_Rect &source_rect, SDL_Rect dest_rect, double angle, const SDL_Point &center, SDL_RendererFlip flip);

//private:
  Renderer &renderer_;
  iVector2 src_position_;
  iVector2 dest_position_;
  dVector2 mult_;// {{1,1}};
  double rotation_;
};

}

#endif //GAMEENGINE_VIEW_H
