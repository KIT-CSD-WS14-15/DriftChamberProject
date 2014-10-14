#pragma once
class Chamber;

#include <core/Module.h>
#include <utility>
#include <vector>
#include <tuple>

/** This module finds tracks in the Chamber by making use of a Hough-Algorithm.
 *
 *  http://de.wikipedia.org/wiki/Hough-Transformation
 */
class TrackFinderModule  : public Module {
public:
  /** We try to find exactly one Track per event.*/
  void event() override;

private:
  void voteHough(const Chamber& chamber,
                 std::vector<std::vector<unsigned> >& houghSpace);

  std::tuple<unsigned, float, float>
  findMaximum(const std::vector<std::vector<unsigned> >& houghSpace,
              const Chamber& chamber);
};
