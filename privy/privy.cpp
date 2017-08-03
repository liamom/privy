//
// Created by Owner on 7/29/2017.
//

#include "privy.h"
#include <SDL.h>
#include <SDL_render.h>
#include <iostream>
#include "exception_impl.h"

privy::Game::Game() {
  int numdrivers = SDL_GetNumRenderDrivers();

  printf("Drivers count: %i\n", numdrivers);

  for (int i=0;i<numdrivers;i++)
  {
    SDL_RendererInfo drinfo;
    SDL_GetRenderDriverInfo(i, &drinfo);


    printf("Driver name: %s\n", drinfo.name);
  }

  auto ret = SDL_Init(SDL_INIT_VIDEO);
  if (ret != 0){
    throw MAKE_EXCEPTION << "init error";
  }
}
privy::Game::~Game() {
  SDL_Quit();
}
