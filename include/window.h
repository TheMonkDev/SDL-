#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include "types.h"

class Window {
  private:
    const char* title;
    Position position;
    Dimension dimension;
    Uint32 windowMode;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Surface* surface;

  public:
    Window();
    ~Window();

    static Window* getWindow();
    SDL_Renderer* getWindowRenderer();
    SDL_Surface* getWindowSurface();
    void setWindowFocused();

    // Getters
    const char* getWindowTitle();
    Position* getWindowPosition();
    Dimension* getWindowDimension();
    Uint32 getWindowMode();

    // Setters
    void setWindowTitle(const char*);
    void setWindowPosition(int, int);
    void setWindowDimension(int, int);
    void setWindowMode(Uint32);
};

#endif
