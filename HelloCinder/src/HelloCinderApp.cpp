//https://libcinder.org/docs/guides/tour/hello_cinder_chapter1.html
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

// Functions derived from cinder
class HelloCinderApp : public App {
  public:
	void prepareSettings(Settings *settings);
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
};

void HelloCinderApp::prepareSettings(Settings *settings) 
{
	// Setup window
	settings->setWindowSize(800, 600);
	settings->setFrameRate(60.0f);
}

void HelloCinderApp::setup()
{
}

void HelloCinderApp::mouseDown( MouseEvent event )
{
}

void HelloCinderApp::update()
{
}

void HelloCinderApp::draw()
{
	float x = cos(getElapsedSeconds() + getWindowWidth() / 2) * 100;
	float y = sin(getElapsedSeconds() + getWindowHeight() / 2) * 100;
	float gray = sin(getElapsedSeconds()) * 0.5f + 0.5f;

	// GL::clear is a function from cinder that clears the screen, it is a few 
	// opengl commands wrapped up in a single function for convience
	//gl::clear( Color( 0, 0, 0 ) ); 
	gl::clear(Color(gray, gray, gray), true);
	
	// You can also use other inbuilt functions to draw simple shapes
	//gl::drawSolidCircle(vec2(x, y), 50.0f);
}

CINDER_APP( HelloCinderApp, RendererGl )
