// https://libcinder.org/docs/guides/tour/hello_cinder_chapter1.html
// https://github.com/cinder/Cinder/tree/3bb2a1d5c52a2d2548e01df6244a3afe55ee7cf0/tour/Chapter%201
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "ParticleController.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class SimpleParticleEngineApp : public App {
  public:
	void prepareSettings(Settings *settings);
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;

	ParticleController mParticleController;
};

// Setup window properties
void SimpleParticleEngineApp::prepareSettings(Settings *settings)
{
	settings->setWindowSize(800, 600);
	settings->setFrameRate(60.0f);
}

// Setup app
void SimpleParticleEngineApp::setup()
{
	mParticleController.addParticles(100);
}

void SimpleParticleEngineApp::mouseDown( MouseEvent event )
{
}

// Called once a frame before draw
void SimpleParticleEngineApp::update()
{
	mParticleController.update();
}

// Called once a frame to draw stuff
void SimpleParticleEngineApp::draw()
{
	gl::clear( Color( 0, 0, 0 ), true ); // Draw black background

	mParticleController.draw();

}

CINDER_APP( SimpleParticleEngineApp, RendererGl )
