// Again similar in concept to ParticleSystems in processing, this class holds all the particles in a list
// and contains functions relating to updating or drawing all the particles that it contains or adding
// and removing particles from the list

#include "cinder/app/App.h"
#include "cinder/Vector.h"
#include "cinder/Rand.h"
#include "ParticleController.h"

using namespace ci;
using std::list;

ParticleController::ParticleController()
{
}

void ParticleController::update()
{
	// Loop through each particle in our list and update them
	// in c++ this is done using an iterator of our list that can be used to move within
	// and retrieve data from the list
	for (list<Particle>::iterator p = mParticles.begin(); p != mParticles.end(); ++p) { // Reverse increment??: https://cboard.cprogramming.com/c-programming/115136-pplusplus-plusplusp.html
		p->update(); // -> is kinda the equivilent of object.method()
	}
}

void ParticleController::draw()
{
	// Again like the above, we use an iterator to loop through our list of particles
	// and call the draw method of each one in our list
	for (list<Particle>::iterator p = mParticles.begin(); p != mParticles.end(); ++p) { // ++p maybe faster when it comes to objects
		p->draw();
	}
}

void ParticleController::addParticles(int amt)
{
	// For amount of particles we want to add
	for (int i = 0; i < amt; i++) {
		// Get random position based on current window size
		float x = Rand::randFloat(app::getWindowWidth());
		float y = Rand::randFloat(app::getWindowHeight());

		// Add particle to back to the list
		mParticles.push_back(Particle(vec2(x, y)));
	}
}

void ParticleController::removeParticles(int amt) 
{
	// Simarly for the amount of particles we want to remove 
	// we remove the last item from the list
	for (int i = 0; i < amt; i++) {
		mParticles.pop_back();
	}
}