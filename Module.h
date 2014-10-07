#pragma once

#include <iostream>

/** This is a base class for modules, that will then do the actual work.
 *
 *  The default for each function is, that nothing is done.
 */
class Module{
public:
	virtual ~Module(){}

	/** Function called at the beginning of the modules loop. */
	virtual void begin(){
	}

	/** Function called potentially several times, where the event then is processed. */
	virtual void event(){
	}

	/** Function called at the end of the event loop. */
	virtual void end()  {
	}
};
