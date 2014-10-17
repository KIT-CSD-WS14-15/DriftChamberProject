#pragma once
#include <geometry/ChamberComponent.h>
#include <geometry/Layer.h>
#include <memory>

class SuperLayer : public ChamberComponent {
public:
  SuperLayer(ChamberComponent* parent) : ChamberComponent(parent) {
  }

  std::shared_ptr<Layer>  addLayer() {
    m_children.emplace_back(new Layer(this));
    return std::dynamic_pointer_cast<Layer> (m_children.back());
  }

  std::string visualise() override {
//    std::cout << "In der SuperLayer" << std::endl;
//    std::cout << m_children.size() << std::endl;
    for (auto& childPtr : m_children){
//      std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAa" << std::endl;
      childPtr->visualise();
    }
//    std::cout << "In der SuperLayerEnde" << std::endl;
    return "";
  }
};
