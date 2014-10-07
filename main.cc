#include <iostream>
#include <Module.h>
#include <list>

using namespace std;

int main() {
	cout << "This program makes a toy simulation of a drift chamber and "
		 <<	"then tries some simple reconstruction algorithms." << endl;

	//Define list of modules to be taken.
	list<Module*> moduleList;

	Module myDummyModule;
	moduleList.push_back(&myDummyModule);

	//How many events do we want?
	unsigned nEvents = 10;

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
