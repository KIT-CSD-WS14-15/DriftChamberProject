#pragma once
#include <reconstruction/BackgroundVisitor.h>
#include <core/Module.h>
#include <iostream>

class BackgroundModule : public Module {
public:
  void event() override {
    std::cout << "Adding background to the chamber" << std::endl;
    CompositeChamber& chamber = *(DataStore<CompositeChamber>::Instance().getStorable("Chamber").get());
    BackgroundVisitor backgroundVisitor;
    for (auto chamberIterator = chamber.first();
              chamberIterator.current() != nullptr; ++chamberIterator) {
      chamberIterator.current()->accept(backgroundVisitor);
    }


  }
};
