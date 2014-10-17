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
              std::shared_ptr<const ColourStrategy> colourStrategy,
              std::shared_ptr<const WidthStrategy>  widthStrategy =
                std::shared_ptr<WidthStrategy> (new WidthStrategyOne())) :
    Cell(xPosition, yPosition),
    m_colourStrategy(colourStrategy),
    m_widthStrategy(widthStrategy)
  {}

  virtual unsigned getMyY() const override {
    return 0;
  }

  std::string visualise() override {
    return visualize();
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
  const std::shared_ptr<const ColourStrategy> m_colourStrategy;
  const std::shared_ptr<const WidthStrategy>  m_widthStrategy;
};
