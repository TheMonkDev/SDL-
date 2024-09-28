#include "element.h"

#include <SDL.h>

#include <cmath>
#include <iostream>

Element* createRootElement(Window* window) { return new Element(window); }

void Element::elementInit() {
  this->position = new Position{0, 0};
  this->dimension = new Dimension();
  this->borders = new BorderConfig();
  this->color = new Color();
}

Element::Element(Window* window) {
  this->elementInit();
  this->renderer = window->getWindowRenderer();
  this->dimension = window->getWindowDimension();
  this->color->a = 0;
}

Element::Element(Element* parent, Position* position, Dimension* dimension,
                 BorderConfig* borderConfig, Color* color) {
  this->parent = parent;
  parent->addChild(this);
  this->renderer = parent->renderer;
  this->elementInit();
  if (this->dimension != dimension && dimension) this->dimension = dimension;
  if (this->borders != borderConfig && borderConfig) this->borders = borderConfig;
  if (this->color != color && color) this->color = color;
}

Element::~Element() {
  if (this->dimension) delete this->dimension;
  if (this->borders) delete this->borders;
  if (this->color) delete this->color;
}

void Element::setPosition(Position* position) {
  if (this->position != position) {
    delete this->position;
  }
  this->position = position;
}

void Element::setDimensions(Dimension* dimension) {
  if (this->dimension != dimension) {
    delete this->dimension;
  }
  this->dimension = dimension;
}

void Element::setBorders(BorderConfig* borderConfig) {
  if (this->borders != borderConfig) {
    delete this->borders;
  }
  this->borders = borders;
}

void Element::setColor(Color* color) {
  if (this->color != color) {
    delete this->color;
  }
  this->color = color;
}

void Element::addChild(Element* childElement) { this->children.push_back(childElement); }

Position* Element::getPosition() { return this->position; }

Dimension* Element::getDimension() { return this->dimension; }

Color* Element::getColor() { return this->color; }

BorderConfig* Element::getBorders() { return this->borders; }

// The below functions look like C code,
// and that's because I haven't yet created
// a wrapper for SDL_Renderer

void Element::drawBorder(BorderSideConfig borderSide) {
  int thickness = borderSide.thickness;
  int startX, startY, width, height;

  switch (borderSide.borderDirection) {
    case BorderDirection::top:
    case BorderDirection::bottom:
      width = this->dimension->width;
      height = thickness;
      break;

    case BorderDirection::right:
    case BorderDirection::left:
      width = thickness;
      height = this->dimension->height;
      break;
  }

  int distance = (int)sqrt(2) * thickness, signX = 1, signY = 1;

  switch (borderSide.borderDirection) {
    case BorderDirection::top:
      signX = -1;
      signY = -1;
      break;

    case BorderDirection::right:
      signX = 1;
      signY = -1;
      break;

    case BorderDirection::bottom:
      signX = 1;
      signY = 1;
      break;

    case BorderDirection::left:
      signX = -1;
      signY = 1;
      break;

    default:
      break;
  }

  startX = this->position->x + signX * distance;
  startY = this->position->x + signY * distance;

  SDL_Rect borderRect;
  borderRect.x = startX;
  borderRect.y = startY;
  borderRect.w = width;
  borderRect.h = height;
  SDL_SetRenderDrawColor(this->renderer, borderSide.color.r, borderSide.color.g, borderSide.color.b,
                         borderSide.color.a);
  SDL_RenderDrawRect(this->renderer, &borderRect);
}

void Element::drawBorders() {
  this->drawBorder(this->borders->top);
  this->drawBorder(this->borders->right);
  this->drawBorder(this->borders->bottom);
  this->drawBorder(this->borders->left);
}

void Element::draw() {
  SDL_SetRenderDrawBlendMode(this->renderer, SDL_BLENDMODE_BLEND);
  SDL_SetRenderDrawColor(renderer, this->color->r, this->color->g, this->color->b, this->color->a);
  // std::cout << this->color->r << " " << this->color->g << " " << this->color->b << " "
  //           << this->color->a << std::endl;
  SDL_Rect elementRect;
  elementRect.x = this->position->x;
  elementRect.y = this->position->y;
  elementRect.w = this->dimension->width;
  elementRect.h = this->dimension->height;
  SDL_RenderFillRect(this->renderer, &elementRect);
  this->drawBorders();
  // std::cout << this->renderer << std::endl;
  // std::cout << elementRect.x << " " << elementRect.y << " " << elementRect.w << " " << elementRect.h
  //           << std::endl;
  for (size_t i = 0; i < this->children.size(); i++) {
    this->children[i]->draw();
  }
}
