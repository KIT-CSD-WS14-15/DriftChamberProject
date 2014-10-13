#pragma once
#include <core/Module.h>

/** This module finds tracks in the Chamber by making use of a Hough-Algorithm.
 *
 *  http://de.wikipedia.org/wiki/Hough-Transformation
 */
class TrackFinderModule  :public Module {
public:
	void event() override{}
};