//
// Created by lioth on 7/29/2017.
//

#include "surface.h"
#include "exception_impl.h"

privy::Surface::Surface(const char *bmp) {
  sdl_ptr_ = SDL_LoadBMP(bmp);
  if (sdl_ptr_ == nullptr)
    throw  MAKE_EXCEPTION;
}

privy::Surface::~Surface() {
  SDL_FreeSurface(sdl_ptr_);
  sdl_ptr_ = nullptr;
}
