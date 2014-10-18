#pragma once
#include <geometry/SpecialCell.h>
#include <geometry/ChamberIterator.h>
#include <geometry/ChamberComponent.h>

#include <geometry/SuperLayer.h>
#include <memory>

class CompositeChamber : public ChamberComponent {
public:
  CompositeChamber(unsigned xSizeCounter = 0) :
    ChamberComponent(nullptr),
    m_xSizeCounter(xSizeCounter)
  {}

  ChamberIterator first() {
    //get first Cell, which is going to be given to the ChamberIterator
    return ChamberIterator(dynamic_cast<Cell*>(deepFirst()));
  }

  void cleanUp() {
    for (ChamberIterator iter = first(); iter.current() != nullptr; ++iter) {
      iter.current()->resetEDeposition();
    }
  }

  std::string visualize() override {
    std::cout << std::endl;
    for (unsigned ii = 0; ii < m_xSizeCounter; ii++) {
      std::cout << "-";
    }
    std::cout << std::endl;
    ChamberComponent::visualize();
    std::cout << std::endl;
    for (unsigned ii = 0; ii < m_xSizeCounter; ii++) {
      std::cout << "-";
    }
    std::cout << std::endl;
    return "";
  }

  SuperLayer* addSuperLayer() {
    m_children.emplace_back(new SuperLayer(this));
    return (static_cast<SuperLayer*>(m_children.back()));
  }

  void addXSize(unsigned xSize) {
    m_xSizeCounter++;
    fillCells();
  }

  unsigned getMaxX() const override {
    return m_xSizeCounter;
  }

private:
  unsigned m_xSizeCounter;
};
