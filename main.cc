#include <GeometryCreatorModule.h>
#include <ParticleGunModule.h>
#include <TrackFinderModule.h>
#include <Module.h>

#include <list>
#include <iostream>
#include <memory>

int main() {
	std::cout << "This program makes a toy simulation of a drift chamber and "
		 <<	"then tries some simple reconstruction algorithms." << std::endl;

	//Define list of modules to be taken.
	std::list<std::shared_ptr<Module> > moduleList;

	//-----------------------------------------------------------------------------------
	//The following code decides, which modules actually will be executed.
	std::shared_ptr<Module> geometryCreatorModule (new GeometryCreatorModule());
	moduleList.push_back(geometryCreatorModule);

	std::shared_ptr<Module> particleGunModule (new ParticleGunModule());
	moduleList.push_back(particleGunModule);

	std::shared_ptr<Module> trackFinderModule(new TrackFinderModule());
	moduleList.push_back(trackFinderModule);

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
