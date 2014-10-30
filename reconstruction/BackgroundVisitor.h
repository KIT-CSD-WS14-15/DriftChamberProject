#pragma once
#include <geometry/Cell.h>

#include <random>


class BackgroundVisitor {
public:
	void visitCell(Cell* cell){
      float randomNumber =  rand() / static_cast<float>(RAND_MAX);
      if(randomNumber > 0.97){
        cell->addEDeposition(1);
      }
	}
};
