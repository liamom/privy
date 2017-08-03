//
// Created by lioth on 7/29/2017.
//

#ifndef PROJECT_RENDERER_H
#define PROJECT_RENDERER_H

#include <SDL_render.h>
#include "sdl_base.h"
#include "texture.h"
#include <string>

namespace privy {

class Renderer : public sdl_base<SDL_Renderer> {
public:
  Renderer(SDL_Window *window, int index = -1, SDL_RendererFlags flags = static_cast<SDL_RendererFlags>(SDL_RendererFlags::SDL_RENDERER_ACCELERATED | SDL_RendererFlags::SDL_RENDERER_PRESENTVSYNC));
  ~Renderer();

  Texture createTexture(const std::string &bitmap);

  void RenderClear();
  void RenderCopy(SDL_Texture *tex, const SDL_Rect * srcrect = nullptr, const SDL_Rect * dstrect = nullptr);
  void RenderPresent();
};

}

#endif //PROJECT_RENDERER_H
