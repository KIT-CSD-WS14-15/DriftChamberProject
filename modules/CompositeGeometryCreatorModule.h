#pragma once
#include <core/Module.h>
#include <iostream>
#include <geometry/CompositeChamber.h>
#include <core/DataStore.h>
#include <vector>
#include <memory>

class CompositeGeometryCreatorModule : public Module {
  void begin () override {
    std::cout << "Creating a composite geometry!" << std::endl;
    // Config info:
    unsigned xSize = 100;

    std::vector<unsigned> nLayers = {8,6,6,6};

    CompositeChamber compositeChamber(xSize);
    for (int ii=0; ii < nLayers.size(); ii++){
      std::shared_ptr<SuperLayer> superLayer = compositeChamber.addSuperLayer();
      for (int jj = 0; jj < nLayers[ii]; ++jj ){
        superLayer->addLayer();
      }
    }
    compositeChamber.fillCells();

    std::cout << compositeChamber.getMaxX() << std::endl;
    std::cout << compositeChamber.getMaxY() << std::endl;

    compositeChamber.visualize();

    DataStore<Chamber>::Instance().store("Chamber", std::shared_ptr<Chamber>(&compositeChamber));
  }
};
