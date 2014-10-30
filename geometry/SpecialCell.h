#pragma once

#include <geometry/Cell.h>
#include <geometry/ColourStrategy.h>
#include <geometry/WidthStrategy.h>

# include <memory>

class SpecialCell : public Cell {
public:
  /** Constructor with position and strategies.
   *
   *  Note that in the current version
   */
  SpecialCell(unsigned xPosition, unsigned yPosition,
              ChamberComponent* parent,
              const ColourStrategy* colourStrategy,
              const WidthStrategy*  widthStrategy =
                new WidthStrategyOne()
             ) :
    Cell(xPosition, yPosition, parent),
    m_colourStrategy(colourStrategy),
    m_widthStrategy(widthStrategy)
  {}

  bool xIsInside(unsigned x) override {
    if (x >=  m_xPosition && x <= m_xPosition + m_widthStrategy->getWidth()) {
      return true;
    }
    return false;
  }

  unsigned getMaxY() const override {
    return 0;
  }

  std::string visualize() override {
    std::string returnString = m_colourStrategy->getColourString();
    if (m_eDepositionCount == 0) {
      returnString += m_widthStrategy->getEmptyDisplayElement();
    } else {
      returnString += m_widthStrategy->getHitDisplayElement();
    }
    return (returnString += "\x1B[0m");
  }
protected:
  const ColourStrategy* m_colourStrategy;
  const WidthStrategy*  m_widthStrategy;
};
