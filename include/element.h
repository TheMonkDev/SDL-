#ifndef ELEMENT_H
#define ELEMENT_H

#include <SDL.h>

#include <vector>

#include "types.h"
#include "window.h"

class Element {
 private:
  Position* position;
  Dimension* dimension;
  BorderConfig* borders;
  Color* color;
  Element* parent;
  std::vector<Element*> children;

  SDL_Renderer* renderer;

  void elementInit();
  void drawBorder(BorderSideConfig);
  void drawBorders();

 public:
  Element(Window*);
  Element(Element*, Position* pos = nullptr, Dimension* dim = nullptr, BorderConfig* borderConf= nullptr,
          Color* col = nullptr);
  ~Element();

  void setPosition(Position*);
  void setDimensions(Dimension*);
  void setBorders(BorderConfig*);
  void setColor(Color*);

  void addChild(Element*);

  Position* getPosition();
  Dimension* getDimension();
  BorderConfig* getBorders();
  Color* getColor();

  void draw();
};

Element* createRootElement(Window* window);

#endif
