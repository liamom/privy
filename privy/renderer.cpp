//
// Created by lioth on 7/29/2017.
//

#include "renderer.h"
#include "exception_impl.h"

privy::Renderer::Renderer(SDL_Window *window, int index, SDL_RendererFlags flags) {
  sdl_ptr_ = SDL_CreateRenderer(window, index, flags);
  if(sdl_ptr_ == nullptr) {
    throw MAKE_EXCEPTION;
  }
}

privy::Renderer::~Renderer() {
  SDL_DestroyRenderer(sdl_ptr_);
  sdl_ptr_ = nullptr;
}

privy::Texture privy::Renderer::createTexture(const std::string &bitmap) {
  return privy::Texture(*this, bitmap.c_str());
}

void privy::Renderer::RenderClear() {
  SDL_RenderClear(sdl_ptr_);
}

void privy::Renderer::RenderCopy(SDL_Texture *tex, const SDL_Rect *srcrect, const SDL_Rect *dstrect) {
  SDL_RenderCopy(sdl_ptr_, tex, srcrect, dstrect);
}
void privy::Renderer::RenderPresent() {
  SDL_RenderPresent(sdl_ptr_);
}
