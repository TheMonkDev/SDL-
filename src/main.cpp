#include <SDL.h>

#include <iostream>

#include "element.h"
#include "window.h"

int main() {
  Window* window = Window::getWindow();
  Element* rootElement = createRootElement(window);
  Element button = Element(rootElement);
  button.setPosition(new Position{50, 50});
  button.setDimensions(new Dimension{100, 100});
  button.setColor(new Color(255, 0, 0, 255));
  button.setBorders(new BorderConfig(10, Color(0, 0, 0, 100)));
  bool loop = true;
  SDL_Event event;
  while (loop) {
    SDL_SetRenderDrawColor(window->getWindowRenderer(), 255, 255, 255, 255);
    SDL_RenderClear(window->getWindowRenderer());
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        loop = false;
      }
    }
    rootElement->draw();
    SDL_RenderPresent(window->getWindowRenderer());
    SDL_Delay(1);
  }
  delete window;
  return 0;
}
