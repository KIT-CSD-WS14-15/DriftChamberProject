#include <GeometryCreatorModule.h>
#include <Module.h>

#include <list>
#include <iostream>

int main() {
	std::cout << "This program makes a toy simulation of a drift chamber and "
		 <<	"then tries some simple reconstruction algorithms." << std::endl;

	//Define list of modules to be taken.
	std::list<Module*> moduleList;

	//-----------------------------------------------------------------------------------
	//The following code decides, which modules actually will be executed.
	GeometryCreatorModule geometryCreatorModule;
	moduleList.push_back(&geometryCreatorModule);

	//How many events do we want?
	unsigned nEvents = 10;

	//-----------------------------------------------------------------------------------
    //Loop over the modules, that are foreseen for this run.
	for (auto module : moduleList){
		module->begin();
	}

    for (int ii = 0; ii < nEvents; ii++){
	  for (auto module : moduleList){
  		module->event();
	  }
    }

	for (auto module : moduleList){
		module->end();
	}

	return 0;
}
