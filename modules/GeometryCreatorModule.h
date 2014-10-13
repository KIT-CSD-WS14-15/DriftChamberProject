#pragma once

#include <core/Module.h>

class GeometryCreatorModule : public Module {
public:
	GeometryCreatorModule(){}

	/** Create the actual geometry. */
	void begin();

	/** Clean up any created chamber from stored information. */
	void event();
};
