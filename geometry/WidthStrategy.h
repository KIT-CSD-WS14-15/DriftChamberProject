#pragma once
#include <iostream>

struct WidthStrategy {
  virtual unsigned    getWidth () const              = 0;
  virtual std::string getEmptyDisplayElement() const = 0;
  virtual std::string getHitDisplayElement() const   = 0;
};

struct WidthStrategyOne : public WidthStrategy{
  unsigned getWidth () const override {
    return 1;
  }
  std::string getEmptyDisplayElement () const override {
    return "O";
  }
  std::string getHitDisplayElement () const override {
    return "X";
  }
};

struct WidthStrategyTwo : public WidthStrategy{
  unsigned getWidth () const override {
    return 2;
  }
  std::string getEmptyDisplayElement () const override {
    return "oo";
  }
  std::string getHitDisplayElement () const override {
    return "><";
  }
};

struct WidthStrategyThree : public WidthStrategy{
  unsigned getWidth () const override {
    return 3;
  }
  std::string getEmptyDisplayElement () const override {
    return "|O|";
  }
  std::string getHitDisplayElement () const override {
    return ">-<";
  }
};