#pragma once

#include <iostream>

struct ColourStrategy {
  virtual std::string getColourString()   const = 0;
};

struct ColourStrategyRed  : public ColourStrategy {
  std::string getColourString() const override {
    return "\x1B[97;41;1m";
  }
};

struct ColourStrategyBlue : public ColourStrategy {
  std::string getColourString() const override {
    return "\x1B[97;44;1m";
  }
};