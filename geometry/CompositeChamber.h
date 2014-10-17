#pragma once
#include <geometry/Chamber.h>
#include <geometry/SuperLayer.h>
#include <memory>

class CompositeChamber : public Chamber {
public:
  std::string visualize() override {
    ChamberComponent::visualize();
  }

  CompositeChamber(unsigned xSizeCounter = 0) : Chamber(-1),
    m_xSizeCoutnter(xSizeCounter)
  {}

  std::shared_ptr<SuperLayer> addSuperLayer() {
    m_children.emplace_back(new SuperLayer(this));
    return std::static_pointer_cast<SuperLayer> (m_children.back());
  }

  void fillCells() {
    ChamberComponent::fillCells(this);
  }

  void addXSize(unsigned xSize) {
    m_xSizeCoutnter++;
    fillCells();
  }

  unsigned getMaxX() const override {
      return m_xSizeCoutnter;
    }

  bool isTopLevel() const override {
    return true;
  }

private:
  unsigned m_xSizeCoutnter;
};
