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
 */
class ParticleGunModule : public Module {
public:
  void event() override;

};
