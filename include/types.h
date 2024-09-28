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

enum class BorderDirection {
  top, right, bottom, left
};

typedef struct BorderSideConfig {
  int thickness = 0;
  Color color;
  BorderDirection borderDirection;
  BorderSideConfig(BorderDirection direction): borderDirection(direction) {};
} BorderSideConfig;

typedef struct RadiusConfig {
  int angle = 0;
} RadiusConfig;

typedef struct BorderConfig {
  BorderSideConfig top = BorderSideConfig(BorderDirection::top);
  BorderSideConfig left = BorderSideConfig(BorderDirection::left);
  BorderSideConfig bottom = BorderSideConfig(BorderDirection::bottom);
  BorderSideConfig right = BorderSideConfig(BorderDirection::right);
  RadiusConfig topLeft, topRight, bottomRight, bottomLeft;
} BorderConfig;

#endif
