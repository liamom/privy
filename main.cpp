//
// Created by Owner on 7/29/2017.
//

#include <iostream>
#include <privy/privy.h>
#include <privy/renderer.h>
#include <privy/Window.h>

#include "util/ini_parser.h"
#include <thread>

void pause_console() {
  std::cout << "Press any key to continue..." << std::endl;
  char a;
  std::cin >> a;
};

class Game : public privy::Game {
public:
};

//int SDL_main(int argc, char **argv) {
int main(int argc, char *argv[]) {
  IniParser config("config.ini");

  const std::string &path = config.get("", "assets_dir");

  try {
    Game game;

    using namespace privy;
    Window win("game", 50, 50, 500, 500);
    Renderer ren(win);
    ren.RenderClear();
    Texture tex = ren.createTexture(path + "/hello.bmp");
    ren.RenderCopy(tex);
    ren.RenderPresent();
    pause_console();
  } catch(privy::Exception &e) {
    std::cout << e.what() << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  pause_console();
  return 0;
}