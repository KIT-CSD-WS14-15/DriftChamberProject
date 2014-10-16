#include <reconstruction/Particle.h>
#include "gtest/gtest.h"
#include <cmath>

TEST(ParticleTest, movement)
{
  Particle particle(1., 1., 0.);
  EXPECT_FLOAT_EQ(0., particle.getXPosition());
  EXPECT_FLOAT_EQ(0., particle.getYPosition());

  //move by a fifth
  particle.makeStep();
  EXPECT_FLOAT_EQ(0.2 / sqrt(2), particle.getXPosition());
  EXPECT_FLOAT_EQ(0.2 / sqrt(2), particle.getYPosition());

  //check order of momentum input.
  Particle particle1(2., 1., 5.);
  EXPECT_FLOAT_EQ(2. / sqrt(5), particle1.getPX());
  EXPECT_FLOAT_EQ(1. / sqrt(5), particle1.getPY());

  //check constructed position:
  EXPECT_FLOAT_EQ(5., particle1.getXPosition());
  EXPECT_FLOAT_EQ(0., particle1.getYPosition());
}
