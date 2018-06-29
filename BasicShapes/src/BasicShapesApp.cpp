//https://libcinder.org/docs/guides/tour/hello_cinder_chapter1.html
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class BasicShapesApp : public App {
  public:
	void prepareSettings(Settings *settings);
	void setup() override;
	void draw() override;
};

void BasicShapesApp::prepareSettings(Settings *settings)
{
	settings->setWindowSize(800, 600);
	settings->setFrameRate(60.0f);
}

void BasicShapesApp::setup()
{
}

void BasicShapesApp::draw()
{
	float x = (getWindowWidth() / 2) + cos(getElapsedSeconds()) * 100;
	float y = (getWindowHeight() / 2) + sin(getElapsedSeconds()) * 100;

	gl::clear( Color( 0, 0, 0 ) ); 
	gl::drawSolidCircle(vec2(x, y), 50.0f);
}

CINDER_APP( BasicShapesApp, RendererGl )
