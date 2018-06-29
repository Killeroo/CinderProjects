//https://libcinder.org/docs/guides/tour/hello_cinder_chapter1.html
//https://github.com/cinder/Cinder/blob/master/samples/ImageFileBasic/src/ImageFileBasicApp.cpp
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Log.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class ImageBasicsApp : public App {
  public:
	void setup() override;
	void keyDown(KeyEvent event) override;
	void fileDrop(FileDropEvent event) override;
	void draw() override;

	gl::TextureRef mTexture;
};

// Run before app starts
void ImageBasicsApp::setup()
{
	// Opening fileopendialog and try loading file as a GL::Texture
	try {
		fs::path path = getOpenFilePath("", ImageIo::getLoadExtensions());
		if (!path.empty()) {
			mTexture = gl::Texture::create(loadImage(path));
		}
	}
	catch (Exception &ex) {
		CI_LOG_EXCEPTION("Failed to load image.", ex);
	}
}

// Handle key pressed
void ImageBasicsApp::keyDown(KeyEvent event) 
{


	if (event.getChar() == 'o') {
		// show openfiledialog again
		fs::path path = getOpenFilePath("", ImageIo::getLoadExtensions());
		if (!path.empty()) {
			mTexture = gl::Texture::create(loadImage(path));
		}
	}
	else if (event.getChar() == 's') {
		// Save current texture to pc
		fs::path path = getSaveFilePath();
		if (!path.empty()) {
			Surface s(mTexture->createSource());
			writeImage(writeFile(path), s);
		}
	}
}

void ImageBasicsApp::fileDrop(FileDropEvent event) 
{
	try {
		// Attempt to load the dropped file into the texture
		mTexture = gl::Texture::create(loadImage(loadFile(event.getFile(0))));
	}
	catch (Exception &ex) {
		CI_LOG_EXCEPTION("Failed to load image: " << event.getFile(0), ex);
	}
}

void ImageBasicsApp::draw()
{
	// Clear the screen at the start of every frame
	gl::clear(Color(0.5f, 0.5f, 0.5f));
	gl::enableAlphaBlending();

	// If the texture is not null draw the image in an rectangle
	if (mTexture) {
		Rectf destRect = Rectf(mTexture->getBounds()).getCenteredFit(getWindowBounds(), true);// .scaleCentered(0.85f);
		gl::draw(mTexture, destRect);
	}
}

CINDER_APP( ImageBasicsApp, RendererGl )
