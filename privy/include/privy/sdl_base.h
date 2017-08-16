//
// Created by lioth on 7/29/2017.
//

#ifndef PROJECT_SDL_BASE_H
#define PROJECT_SDL_BASE_H

template <class TYPE>
class sdl_base {
public:
  operator TYPE*(){
    return sdl_ptr_;
  }

  sdl_base() = default;
  sdl_base(const sdl_base&) = delete;

  sdl_base(sdl_base &&other) {
    this->sdl_ptr_ = other.sdl_ptr_;
    other.sdl_ptr_ = nullptr;
  }

  TYPE *sdl_ptr_ = nullptr;
};

#endif //PROJECT_SDL_BASE_H
