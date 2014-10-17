#pragma once
#include <geometry/ChamberComponent.h>
#include <geometry/Layer.h>

class SuperLayer : public ChamberComponent {
public:
  SuperLayer(ChamberComponent* parent) : ChamberComponent(parent) {
  }

  void addLayer(Layer* Layer) {
    m_children.emplace_back(Layer);
  }

protected:
  bool isTopLevel() const override {
    return false;
  }
};
