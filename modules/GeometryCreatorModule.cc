#include <Chamber.h>
#include <Cell.h>

#include <modules/GeometryCreatorModule.h>

#include <core/DataStore.h>

#include <iostream>
#include <memory>

using namespace std;

void GeometryCreatorModule::begin(){
  cout << "Build some geometry" << endl;

  std::shared_ptr<Chamber>  chamber (new Chamber());
  unsigned chamberSize = 8;

  for (int ii = 0; ii < chamberSize; ii++){
	  chamber->addCell();
  }

  //print Setup of Cells
  chamber->visualize();

  //Store the geometry
  DataStore<Chamber>::Instance().store("Chamber", chamber);

}

void GeometryCreatorModule::event(){
  DataStore<Chamber>::Instance().getStorable("Chamber")->cleanUp();
}
