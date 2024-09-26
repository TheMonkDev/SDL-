#include <SDL.h>
#include "window.h"

int main() {
  Window* window = Window::getWindow();
  bool loop = true;
  SDL_Event event;
  while(loop) {
    while(SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        loop = false;
      }
    }
    SDL_Delay(1);
  }
  delete window;
  return 0;
}
