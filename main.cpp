//
// Created by Owner on 7/29/2017.
//

#include <iostream>
#include <privy/privy.h>

#include "util/ini_parser.h"
#include <thread>
#include "util/util.h"

#include "FroggerTexturePack.h"

void pause_console() {
  std::cout << "Press any key to continue..." << std::endl;
  char a;
  std::cin >> a;
};

class FoggerGame : public privy::Game {
public:
};

//int SDL_main(int argc, char **argv) {
int main(int argc, char *argv[]) {
  try {
    using namespace privy;

    FoggerGame game;

    Window win("game", 50, 50, 500, 500);
    Renderer ren(win);
    ren.RenderClear();
    Texture tex = ren.createTexture(get_file("hello.bmp"));
    ren.RenderCopy(tex);
    ren.RenderPresent();
//    std::this_thread::sleep_for(std::chrono::seconds(5));

    ren.RenderClear();

    FroggerTexturePack pack(ren);

    //for(privy::Sprite &tex : pack.running_) {

    int i = 0;

    privy::View views[2] = {
        privy::View(ren, { 0, 0 }, { 0, 0 }),
        privy::View(ren, { 0, 0 }, { 100, 100 })
    };

    auto iter = make_cycle(pack.running_);
    while(true) {
      privy::Sprite &tex = *iter;
      ren.RenderClear();

      for(privy::View &v : views) {
        tex.render(v, 0, 0);
        tex.render(v, 100, 100);
      }

      views[1].rotation_ -= 1;

      ren.RenderPresent();
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
      ++iter;

      if (i++ > 5000)
        return 1;
    }

    return 1;
  } catch(privy::Exception &e) {
    std::cout << e.what() << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 1;
}