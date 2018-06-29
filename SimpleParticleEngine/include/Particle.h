#pragma once
#include "cinder/Channel.h"
#include "cinder/Vector.h"
#include <vector>

// Declare simple layout of class so other classes can know and use methods
// Abit like that one in the main app file
class Particle {
	public:
		Particle();
		Particle(ci::vec2);
		void update();
		void draw();

		ci::vec2	mLoc;
		ci::vec2	mDir;
		float		mVel;
		float		mRadius;
};