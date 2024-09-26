#ifndef ELEMENT_H
#define ELEMENT_H

#include <SDL.h>

typedef struct Color {
  int r, g, b, a;
  Color() : r(0), g(0), b(0), a(255) {};
  Color(int r, int g, int b, int a = 255) : r(r), g(g), b(b), a(a) {};
} Color;

typedef struct Dimensions {
  int x, y, w, h;
  Dimensions() : x(0), y(0), w(0), h(0) {};
  Dimensions(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {};
} Dimensions;

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

class UI {
 protected:
  SDL_Renderer* renderer;
 public:
  virtual void draw() = 0;
};

class Div : public UI {
 private:
  Dimensions* dimensions;
  BorderConfig* borders;
  Color* color;

 public:
  Div();
  Div(Dimensions*, BorderConfig*, Color*);
  ~Div();

  void setDimensions(Dimensions*);
  void setBorders(BorderConfig*);
  void setColor(Color*);

  Dimensions* getDimensions();
  BorderConfig* getBorders();
  Color* getColor();

  void draw() override;
};

class Element {
 private:
  Div* boundingRect;
  Element* parent;
  Element* children;
  int childSize;

 public:
  Element() {}
};

#endif
