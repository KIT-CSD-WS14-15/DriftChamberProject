#pragma once

#include <iostream>

struct ColourStrategy{
  virtual std::string displayHitElement ()   const = 0;
  virtual std::string displayEmptyElement () const = 0;
};

struct ColourStrategyRed  : public ColourStrategy{
  std::string displayHitElement ()   const override {
    return "\x1B[97;41;1mX\x1B[0m";
  }
  std::string displayEmptyElement () const override {
    return "\x1B[97;41;1mO\x1B[0m";
  }
};

struct ColourStrategyBlue : public ColourStrategy {
  std::string displayHitElement ()   const override {
    return "\x1B[97;44;1mX\x1B[0m";
  }
  std::string displayEmptyElement () const override {
    return "\x1B[97;44;1mO\x1B[0m";
  }
};