#pragma once
#include <math.h>

/** A Particle is stepped through the geometry to determine, where energy will be deposited. */
class Particle {
public:

  /** Useful constructor.
   *
   *  The particle always starts its life at y == 0,
   *  directly below the Chamber.
   *  The momentum is normalized, to get a defined step length afterwards.
   */
  Particle(float pX, float pY, float x) : m_x(x), m_y(0.),
    m_pX(pX / sqrtf(pX * pX + pY* pY)),
    m_pY(pY / sqrtf(pX * pX + pY* pY))
  {}

  /** Getter for current x position of the particle. */
  float getXPosition() {
    return m_x;
  }

  /** Getter for current y position of the particle. */
  float getYPosition() {
    return m_y;
  }

  /** Getter for current x momentum of the particle. */
  float getPX() {
    return m_pX;
  }

  /** Getter for current y momentum of the particle. */
  float getPY() {
    return m_pY;
  }

  /** Move the particle 0.2 units along the direction of its momentum. */
  void makeStep() {
    m_x = m_x + m_pX / 5.;
    m_y = m_y + m_pY / 5.;
  }

private:
  float m_x;
  float m_y;

  float m_pX;
  float m_pY;
};

