// Declare our particle class using similar methodolgy to how we do it in processing
// with an update function to alter the position of the particle over time and a draw function
// to actually draw the particle when called

#include "cinder/app/App.h" // Maybe this is wrong? going on very old code that is probably out of date https://github.com/cinder/Cinder/blob/3bb2a1d5c52a2d2548e01df6244a3afe55ee7cf0/tour/Chapter%201/src/Particle.cpp#L4
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Particle.h"

using namespace ci;

// Default constructor
Particle::Particle()
{
}

Particle::Particle(vec2 loc)
{
	// When we create a new particle give it a random direction and velocity
	mLoc = loc;
	mDir = Rand::randVec2();
	mVel = Rand::randFloat(5.0f);
	mRadius = 3.0f; // Size of particle
}

void Particle::update()
{
	mLoc += mDir * mVel;
}

void Particle::draw()
{
	// use cinder call to draw circle at current location of particle
	gl::drawSolidCircle(mLoc, mRadius);
}