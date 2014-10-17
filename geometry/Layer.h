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

  void fillCells(ChamberComponent* chamberComponent) override {
    if (chamberComponent->isTopLevel()) {
      for (int ii = m_children.size() * m_widthStrategy->getWidth(); ii < getMaxX(); ++ii) {

        m_children.emplace_back(new SpecialCell(ii * m_widthStrategy->getWidth(), getMyY(),
                                                m_colourStrategy, m_widthStrategy));
      }
    }
    ChamberComponent::fillCells(chamberComponent);
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

  std::string visualize() override{
    //This provides a "Y-axis".
    std::cout <<  getMyY() << "\t | ";
    for (auto & childPtr : m_children) {
      std::cout << childPtr->visualize();
    }
    std::cout << std::endl;
    return "";
  }

private:
  std::shared_ptr<const WidthStrategy>   m_widthStrategy;
  std::shared_ptr<const ColourStrategy>  m_colourStrategy;
};
