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

  ChamberIterator first() const {
  /*
  return ChamberIterator(this);std::shared_ptr<Cell> Chamber::getCellAt(unsigned xPosition, unsigned yPosition) const
      {
        if (yPosition < m_cells.size() && xPosition < m_cells[0].size()) {
          return m_cells[yPosition][xPosition];
        }
        return nullptr;
      }
      */
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
  std::shared_ptr<Cell> getCellAt(unsigned xPosition, unsigned yPosition) const;

private:
  unsigned m_xSizeCounter;
};
