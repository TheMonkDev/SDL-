#include "window.h"

#include <SDL.h>

#include "defaults.h"
#include "types.h"

Window::Window() {
  this->title = DEF_TITLE;
  this->position = Position();
  this->dimension = {DEF_WIDTH, DEF_HEIGHT};
  this->windowMode = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
  this->window = nullptr;
  this->renderer = nullptr;
  this->surface = nullptr;
}

Window::~Window() {
  if (this->renderer) SDL_DestroyRenderer(this->renderer);
  if (this->surface) SDL_DestroyWindowSurface(this->window);
  if (this->window) SDL_DestroyWindow(this->window);
}

Window* Window::getWindow() {
  Window* window = new Window();
  window->window =
      SDL_CreateWindow(window->title, window->position.x, window->position.y,
                       window->dimension.width, window->dimension.height, window->windowMode);
  if (!window->window) {
    delete window;
    return nullptr;
  }

  window->renderer = SDL_CreateRenderer(window->window, -1, SDL_RENDERER_ACCELERATED);
  if (!window->renderer) {
    delete window;
    return nullptr;
  }

  return window;
}

SDL_Renderer* Window::getWindowRenderer() { return this->renderer; }

SDL_Surface* Window::getWindowSurface() { return this->surface; }

const char* Window::getWindowTitle() { return this->title; }

Position* Window::getWindowPosition() { return &this->position; }

Dimension* Window::getWindowDimension() { return &this->dimension; }

void Window::setWindowTitle(const char* newTitle) {
  this->title = newTitle;
  SDL_SetWindowTitle(this->window, this->title);
}

void Window::setWindowDimension(int width, int height) {
  Dimension newDim = {width, height};
  this->dimension = newDim;
  SDL_SetWindowSize(this->window, this->dimension.width, this->dimension.height);
}

void Window::setWindowPosition(int x, int y) {
  Position newPos = {x, y};
  this->position = newPos;
  SDL_SetWindowPosition(this->window, this->position.x, this->position.y);
}

Uint32 Window::getWindowMode() { return this->windowMode; }

void Window::setWindowMode(Uint32 modeFlag) { this->windowMode = modeFlag; }
