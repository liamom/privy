//
// Created by lioth on 7/29/2017.
//

#include "texture.h"
#include "exception_impl.h"
#include "surface.h"
#include <SDL_image.h>

privy::Texture::Texture(SDL_Renderer *renderer, const char *bitmap) {
//  Surface bmp(bitmap);
//  sdl_ptr_ = SDL_CreateTextureFromSurface(renderer, bmp);
  sdl_ptr_ = IMG_LoadTexture(renderer, bitmap);
  if (sdl_ptr_ == nullptr) {
    throw MAKE_EXCEPTION << "failed to create surface";
  }

}

privy::Texture::~Texture() {
  SDL_DestroyTexture(sdl_ptr_);
  sdl_ptr_ = nullptr;
}
