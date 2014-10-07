#pragma once
#include <math.h>

class Particle {
public:

	Particle (float pX, float pY) : m_x(0.), m_y(-0.5) {
		m_pX = pX/ sqrtf(pX * pX + pY * pY);
    	m_pY = pY/ sqrtf(pX * pX + pY * pY);
	}

	float getXPosition(){
		return m_x;
	}

	float getYPosition(){
		return m_y;
	}

	float getPX(){
		return m_pX;
	}

	float getPY(){
		return m_pY;
	}

	void makeStep(){
		m_x = m_x + m_pX/5.;
		m_y = m_y + m_pY/5.;
	}

private:
  float m_x;
  float m_y;

  float m_pX;
  float m_pY;
};

