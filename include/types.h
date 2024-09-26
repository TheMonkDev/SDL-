#ifndef TYPES_H
#define TYPES_H

#include <SDL.h>

#include "defaults.h"

typedef struct Position {
  int x = SDL_WINDOWPOS_CENTERED, y = SDL_WINDOWPOS_CENTERED;
} Position;

typedef struct Dimension {
  int width = 0, height = 0;
} Dimension;

typedef struct Color {
  int r, g, b, a;
  Color() : r(0), g(0), b(0), a(255) {};
  Color(int r, int g, int b, int a = 255) : r(r), g(g), b(b), a(a) {};
} Color;

typedef struct BorderSideConfig {
  int thickness = 0;
  Color color;
} BorderSideConfig;

typedef struct RadiusConfig {
  int angle = 0;
} RadiusConfig;

typedef struct BorderConfig {
  BorderSideConfig top, left, bottom, right;
  RadiusConfig topLeft, topRight, bottomRight, bottomLeft;
} BorderConfig;

#endif
