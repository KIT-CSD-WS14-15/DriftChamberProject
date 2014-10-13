#pragma once

/** This is a base class for modules, that will then do the actual work.
 *
 *  The idea is, that first begin is called for each module, then event is called for
 *  each module several times, and then end is called for each module.
 *  Always in the same order.
 */
class Module{
public:
	/** Make destructor virtual as this is a base class for other classes. */
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
