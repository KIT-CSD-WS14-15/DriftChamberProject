#pragma once

#include <geometry/Cell.h>
#include <geometry/ColourStrategy.h>
#include <geometry/WidthStrategy.h>

# include <memory>

class SpecialCell : public Cell {
public:
  SpecialCell (unsigned xPosition, unsigned yPosition,
               const std::shared_ptr<ColourStrategy> colourStrategy,
               const std::shared_ptr<WidthStrategy>  widthStrategy =
               std::shared_ptr <WidthStrategy> (new WidthStrategyOne())) : 
    Cell(xPosition, yPosition),
    m_colourStrategy (colourStrategy),
    m_widthStrategy (widthStrategy)
    {}
    
  std::string visualize() override {
    std::string returnString = m_colourStrategy->getColourString();
    if (m_eDepositionCount == 0) {
      returnString += m_widthStrategy->getEmptyDisplayElement();
    } else {
      returnString += m_widthStrategy->getHitDisplayElement();
    }
    return (returnString+="\x1B[0m");
  }
protected:
  std::shared_ptr<ColourStrategy> m_colourStrategy;
  std::shared_ptr<WidthStrategy>  m_widthStrategy;
};