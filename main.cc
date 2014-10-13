#include <GeometryCreatorModule.h>
#include <ParticleGunModule.h>
#include <TrackFinderModule.h>

#include <Module.h>

#include <list>
#include <iostream>
#include <memory>

/** The program starts here.
 *
 *  You may use Doxygen
 *  http://www.stack.nl/~dimitri/doxygen/
 *  to get some browsable documentation of the project.
 */
int main() {
	std::cout << "This program makes a toy simulation of a drift chamber and "
		      << "then tries some simple reconstruction algorithms."
		      << std::endl;

	/** List, that holds modules to be executed during the program. */
	std::list<std::shared_ptr<Module> > moduleList;

	//-----------------------------------------------------------------------------------
	// Configuration Code
	//-----------------------------------------------------------------------------------
	//The following code decides, which modules actually will be executed.
	moduleList.emplace_back(new GeometryCreatorModule());
	moduleList.emplace_back(new ParticleGunModule());
	moduleList.emplace_back(new TrackFinderModule());

	/** Number of times, the event function is called for each module.
	 *
	 *  @todo This might be better handled as a paramter to the main function.
	 */
	unsigned nEvents = 10;

	//-----------------------------------------------------------------------------------
    //Loop over the modules, that are foreseen for this run.
	for (auto& module : moduleList){
		module->begin();
	}

    for (int ii = 0; ii < nEvents; ii++){
	  for (auto& module : moduleList){
  		module->event();
	  }
    }

	for (auto& module : moduleList){
		module->end();
	}

	return 0;
}
