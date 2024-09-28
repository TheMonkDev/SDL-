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

enum class BorderDirection { top = 0, right = 1, bottom = 2, left = 3 };

typedef struct BorderSideConfig {
  int thickness = 0;
  Color color;
  BorderDirection borderDirection;
  BorderSideConfig() {};
  BorderSideConfig(BorderDirection direction) : borderDirection(direction) {};
  BorderSideConfig(int thickness, Color color, BorderDirection direction)
      : thickness(thickness), color(color), borderDirection(direction) {};
} BorderSideConfig;

typedef struct RadiusConfig {
  int angle = 0;
} RadiusConfig;

typedef struct BorderConfig {
  BorderSideConfig top;
  BorderSideConfig left;
  BorderSideConfig bottom;
  BorderSideConfig right;
  RadiusConfig topLeft, topRight, bottomRight, bottomLeft;
  BorderConfig() {
    top = BorderSideConfig(BorderDirection::top);
    left = BorderSideConfig(BorderDirection::left);
    bottom = BorderSideConfig(BorderDirection::bottom);
    right = BorderSideConfig(BorderDirection::right);
  }
  BorderConfig(int thickness, Color color) {
    top = BorderSideConfig(thickness, color, BorderDirection::top);
    right = BorderSideConfig(thickness, color, BorderDirection::right);
    left = BorderSideConfig(thickness, color, BorderDirection::left);
    bottom = BorderSideConfig(thickness, color, BorderDirection::bottom);
  }
} BorderConfig;

#endif
