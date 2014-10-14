#include <geometry/Chamber.h>
#include <geometry/Cell.h>

#include <modules/GeometryCreatorModule.h>

#include <core/DataStore.h>

#include <iostream>
#include <memory>

using namespace std;

void GeometryCreatorModule::begin()
{
  cout << "Build some geometry" << endl;
  unsigned nLayers = 10;
  unsigned cellsPerLayer = 2 * nLayers;

  std::shared_ptr<Chamber>  chamber(new Chamber(nLayers));

  for (int ii = 0; ii < cellsPerLayer; ii++) {
    chamber->addCell();
  }

  //print Setup of Cells
  chamber->visualize();

  //Store the geometry
  DataStore<Chamber>::Instance().store("Chamber", chamber);

}

void GeometryCreatorModule::event()
{
  DataStore<Chamber>::Instance().getStorable("Chamber")->cleanUp();
}
