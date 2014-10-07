#include <GeometryCreatorModule.h>
#include <DataStore.h>
#include <iostream>
#include <Chamber.h>
#include <Cell.h>
#include <memory>


using namespace std;

void GeometryCreatorModule::begin(){
  cout << "Build some geometry" << endl;

  Chamber chamber;
  unsigned chamberSize = 16;

  for (int ii = 0; ii < chamberSize; ii++){
	  chamber.addCell(std::shared_ptr<Cell>(new Cell()));
  }


  //print Setup of Cells
  chamber.visualize();
}

