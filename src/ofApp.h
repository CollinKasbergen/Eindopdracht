#pragma once

#include "ofMain.h"

#include "ofxOpenCv.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void mousePressed(int x, int y, int button);


		ofVideoGrabber grabber;
		ofxCvHaarFinder haarFinderLinks;
		ofxCvHaarFinder haarFinderRechts;

		ofImage image;
		ofImage beeld;
    
    ofVideoGrabber vidGrabber;
    ofPixels videoInverted;
    ofTexture videoTexture;
    int camWidth;
    int camHeight;
    int transperantie;
};
