#pragma once
#include <geometry/Chamber.h>
#include <geometry/SuperLayer.h>

class CompositeChamber : public Chamber {
public:
  CompositeChamber() : Chamber(-1),
    m_xSizeCoutnter(0)
  {}

  void addSuperLayer(SuperLayer* superLayer) {
    m_children.emplace_back(superLayer);
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
