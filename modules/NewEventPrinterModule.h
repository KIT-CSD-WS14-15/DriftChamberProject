#pragma once
#include <core/Module.h>
#include <iostream>

/** Prints a separation line. */
class NewEventPrinterModule :public Module {
public:
  void event() override {
    std::cout << "====================================================" << std::endl;
  }
};
