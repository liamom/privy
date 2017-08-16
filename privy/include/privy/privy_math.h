//
// Created by lioth on 8/5/2017.
//

#ifndef PRIVY_UTIL_H
#define PRIVY_UTIL_H

#include <utility>
#include <sdl.h>
#include <array>
#include "matix.h"

namespace privy{

constexpr const double PI = 3.14159265358979323846;

//template<class TYPE, int size = 2>
//struct Vector {
//  union {
//    struct {
//      TYPE x;
//      TYPE y;
//    };
//    TYPE a[size];
//  };
//};

template<class TYPE>
void operator*=(SDL_Rect &rect, const privy::Vector<TYPE> &vector) {
  rect.x *= vector.x();
  rect.y *= vector.y();
  rect.w *= vector.x();
  rect.h *= vector.y();
}

template<class TYPE>
void operator+=(SDL_Rect &rect, const privy::Vector<TYPE> &vector) {
  rect.x += vector.x();
  rect.y += vector.y();
}

template<class TYPE, class NUMBER_TYPE>
void operator*=(privy::Vector<TYPE> &vector, NUMBER_TYPE mult) {
  vector.x() *= mult;
  vector.y() *= mult;
}


//class Rect {
//public:
//  Rect(const SDL_Rect &rect) {
//    rect_.sdl_rect = rect;
//  }
//
//  operator SDL_Rect*(){
//    return &rect_.sdl_rect;
//  }
//
//  iVector2& position() {
//    return rect_.postition;
//  }
//
//  iVector2& size() {
//    return rect_.size;
//  }
//
//private:
//  union {
//    SDL_Rect sdl_rect;
//    struct {
//      iVector2 postition;
//      iVector2 size;
//    };
//  } rect_;
//};

}

#endif //PRIVY_UTIL_H
