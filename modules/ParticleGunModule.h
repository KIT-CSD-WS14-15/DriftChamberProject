#pragma once
#include <core/Module.h>

/** Shoot a particle through the Chamber.
 *
 *  The particle follows some curvature and Cells, that are hit
 *  get potentially an energy deposition and a drift time assigned.
 *
 *  Example:
 *  Cell:
 *  OOOOOOOOOO
 *  OOOOOOOOOO
 *      P      Particle Position
 *
 *  OOOOOOOOOO
 *  OOOOOXPOOO
 *      X
 *
 *  OOOOOOOXPO
 *  OOOOOXXOOO
 *      X
 *
 *  Final Cell Setup in that event.
 *  OOOOOOOXXO
 *  OOOOOXXOOO
 *      X
 *
 *  Currently only straight lines are implemented as paths of particles.
 *
 *  Note on testing:
 *  This module isn't automatically tested, despite being non-trivial. However,
 *  looking into the graphical output of the module gives a quite good understanding
 *  if the thing works in quality we would like it to do.
 */
class ParticleGunModule : public Module {
public:
  void event() override;

};
