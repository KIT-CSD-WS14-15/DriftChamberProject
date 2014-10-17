#pragma once

#include <vector>
#include <memory>
#include <iostream>

class ChamberComponent {
public:
  /** Virtual Constructor because ...*/
  virtual ~ChamberComponent() {}

  ChamberComponent(ChamberComponent* parent):
    m_children(), m_parent(parent)
  {}

  ChamberComponent* getChild(unsigned iChild);

  ChamberComponent* getParent() {
    return m_parent;
  }

  virtual unsigned getMaxY() const {
    unsigned sizeCounter = 0;
    for (auto & childPtr : m_children) {
      sizeCounter += childPtr->getMaxY();
    }
    return sizeCounter;
  }

  virtual std::string visualise() {
    for (auto& childPtr : m_children){
      childPtr->visualise();
    }
    return "";
  }

  virtual unsigned getMyY() const;

  virtual unsigned getMaxX() const {
    m_parent->getMaxX();
  }

  virtual void fillCells(ChamberComponent* chamberComponent) {
    if (chamberComponent->isTopLevel()) {
      for (auto & childPtr : m_children) {
        childPtr->fillCells(chamberComponent);
      }
    } else {
      std::cout << "ERROR: addCell() shall only be called from Top Level." << std::endl;
    }
  }

  virtual bool isTopLevel() const {
    return false;
  }

protected:
  std::vector<std::shared_ptr<ChamberComponent> > m_children;
  ChamberComponent* m_parent;

};
