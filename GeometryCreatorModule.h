#pragma once
#include <Module.h>
#

class GeometryCreatorModule : public Module {
public:
	GeometryCreatorModule(){}

	void begin();

	/** Clean up any created chamber from stored information. */
	void event();
};
