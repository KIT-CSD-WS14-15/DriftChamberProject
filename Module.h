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
		std::cout << "Do nothing default: begin()" << std::endl;
	}

	/** Function called potentially several times, where the event then is processed. */
	virtual void event(){
		std::cout << "Do nothing default: event()" << std::endl;
	}

	/** Function called at the end of the event loop. */
	virtual void end()  {
		std::cout << "Do nothing default: end()" << std::endl;
	}
};
