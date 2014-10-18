#pragma once
#include <geometry/ChamberComponent.h>
#include <geometry/SpecialCell.h>
#include <memory>
#include <iostream>

class Layer : public ChamberComponent {
public:
  Layer(ChamberComponent* parent) : ChamberComponent(parent),
    m_widthStrategy(new WidthStrategyOne()),
    m_colourStrategy(new ColourStrategyBlue()) {
  }

  void fillCells() override {
    for (int ii = m_children.size() * m_widthStrategy->getWidth(); ii < getMaxX(); ++ii) {

      m_children.emplace_back(new SpecialCell(ii * m_widthStrategy->getWidth(), getMyY(), this,
                                              m_colourStrategy, m_widthStrategy));

    }
  }

  /** Cells are actually building up the Chamber.
   *
   *  But only the
   */
  unsigned getMaxY() const override {
    if (m_children.empty()) {
      return 0;
    }
    return 1;
  }

  std::string visualize() override {
    //This provides a "Y-axis".
    std::cout <<  getMyY() << "\t | ";
    for (auto & childPtr : m_children) {
      std::cout << childPtr->visualize();
    }
    std::cout << std::endl;
    return "";
  }

private:
  const WidthStrategy*   m_widthStrategy;
  const ColourStrategy*  m_colourStrategy;
};
