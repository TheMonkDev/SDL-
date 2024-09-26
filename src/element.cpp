#include "element.h"

#include <SDL.h>

Div::Div() {
  this->dimensions = new Dimensions();
  this->borders = new BorderConfig();
  this->color = new Color();
}

Div::Div(Dimensions* dimensions = nullptr, BorderConfig* borderConfig = nullptr,
         Color* color = nullptr) {
  this->dimensions = dimensions;
  this->borders = borderConfig;
  this->color = color;
}

Div::~Div() {
  if (this->dimensions) delete this->dimensions;
  if (this->borders) delete this->borders;
  if (this->color) delete this->color;
}

void Div::setDimensions(Dimensions* dimensions) {
  if (this->dimensions != dimensions) {
    delete this->dimensions;
  }
  this->dimensions = dimensions;
}

void Div::setBorders(BorderConfig* borderConfig) {
  if (this->borders != borderConfig) {
    delete this->borders;
  }
  this->borders = borders;
}

void Div::setColor(Color* color) {
  if (this->color != color) {
    delete this->color;
  }
  this->color = color;
}

Dimensions* Div::getDimensions() { return this->dimensions; }

Color* Div::getColor() { return this->color; }

BorderConfig* Div::getBorders() { return this->borders; }

void Div::draw() {
  
}
