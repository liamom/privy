//
// Created by lioth on 7/29/2017.
//

#include "Window.h"
#include "exception_impl.h"

privy::Window::Window(const char *title, int x, int y, int w, int h, SDL_WindowFlags flags) {
  sdl_ptr_ = SDL_CreateWindow(title, x, y, w, h, flags);
  if(sdl_ptr_ == nullptr) {
    throw MAKE_EXCEPTION << "failed to create a Window";
  }
}

privy::Window::~Window() {
  if(sdl_ptr_) {
    SDL_DestroyWindow(sdl_ptr_);
    sdl_ptr_ = nullptr;
  }
}
