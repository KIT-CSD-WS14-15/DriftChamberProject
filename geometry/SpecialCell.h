#pragma once

#include <geometry/Cell.h>

#include <geometry/ColourStrategy.h>

# include <memory>

class SpecialCell : public Cell {
public:
  SpecialCell (unsigned xPosition, unsigned yPosition,
               const std::shared_ptr<ColourStrategy> colourStrategy) : 
    Cell(xPosition, yPosition),
    m_colourStrategy (colourStrategy)
    {}
    
  std::string visualize() override {
    if (m_eDepositionCount == 0) {
      return m_colourStrategy->displayEmptyElement();
    } else {
      return m_colourStrategy->displayHitElement();
    }
  }
protected:
  std::shared_ptr<ColourStrategy> m_colourStrategy;
};