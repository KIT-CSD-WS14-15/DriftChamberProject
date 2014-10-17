#pragma once
#include <geometry/Chamber.h>
#include <geometry/SuperLayer.h>
#include <memory>

class CompositeChamber : public Chamber {
public:
  CompositeChamber(unsigned xSizeCounter = 0) : Chamber(-1),
    m_xSizeCounter(xSizeCounter)
  {}


  std::string visualize () override {
    std::cout << std::endl;
    for (unsigned ii = 0; ii < m_xSizeCounter; ii++){
      std::cout << "-";
    }
    std::cout << std::endl;
    ChamberComponent::visualize();
    std::cout << std::endl;
    for (unsigned ii = 0; ii < m_xSizeCounter; ii++){
      std::cout << "-";
    }
    std::cout << std::endl;
    return "";
  }

  std::shared_ptr<SuperLayer> addSuperLayer() {
    m_children.emplace_back(new SuperLayer(this));
    return std::static_pointer_cast<SuperLayer> (m_children.back());
  }

  void fillCells() {
    ChamberComponent::fillCells(this);
  }

  void addXSize(unsigned xSize) {
    m_xSizeCounter++;
    fillCells();
  }

  unsigned getMaxX() const override {
    return m_xSizeCounter;
  }

  bool isTopLevel() const override {
    return true;
  }

private:
  unsigned m_xSizeCounter;
};
