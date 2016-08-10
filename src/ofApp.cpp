#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);

	grabber.setup(1240, 720, true);

	haarFinderLinks.setup("links.xml");
	haarFinderRechts.setup("rechts.xml");

	image.load("trippy.jpg");
	beeld = grabber.getPixels();
    
    camWidth = 1240;  // try to grab at this size.
    camHeight = 720;
    transperantie = 170;
    
    //we can now get back a list of devices.
    vector<ofVideoDevice> devices = vidGrabber.listDevices();
    
    for(int i = 0; i < devices.size(); i++){
        if(devices[i].bAvailable){
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
        }else{
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
        }
    }
    
    vidGrabber.setDeviceID(0);
    //vidGrabber.setDesiredFrameRate(60);
    vidGrabber.initGrabber(camWidth, camHeight);
}

//--------------------------------------------------------------
void ofApp::update() {
	grabber.update();
	
	if (grabber.isFrameNew()) {
		//haarFinderLinks.findHaarObjects(grabber.getPixels(),60,60);
		//haarFinderLinks.findHaarObjects(beeld.getPixels(), 60, 60);
		//haarFinderRechts.findHaarObjects(grabber.getPixels(), 60, 60);
	}
    
    vidGrabber.update();
    
    if(vidGrabber.isFrameNew()){
        ofPixels & pixels = vidGrabber.getPixels();
        beeld = vidGrabber.getPixels();
        //beeld = vidGrabber.getPixels();
        haarFinderLinks.findHaarObjects(beeld.getPixels(),60,60);
        //haarFinderLinks.findHaarObjects(beeld.getPixels(), 60, 60);
        haarFinderRechts.findHaarObjects(beeld.getPixels(), 60, 60);
    }

}

//--------------------------------------------------------------
void ofApp::draw() {
	image.draw(0, 0);
    
    //vidGrabber.draw(20, 20);
	ofNoFill();
	for (int i = 0; i < haarFinderLinks.blobs.size(); i++) {
		ofRectangle blobBoundingRect = haarFinderLinks.blobs[i].boundingRect;
		if(blobBoundingRect.width < 150 && blobBoundingRect.width > 100){
			ofImage oog = beeld;
			oog.crop(blobBoundingRect.x, blobBoundingRect.y, blobBoundingRect.width, blobBoundingRect.height);
			for (int i = 0; i < 40; i++) {
				switch (i)
				{
				case 0:
					ofEnableAlphaBlending();
					ofPushMatrix();
					ofTranslate(250, 500, 0);
					ofRotate(80);
					ofSetColor(255, 255, 255, transperantie);
					oog.draw(0, 0);
					ofPopMatrix();
					ofDisableAlphaBlending();
					break;
				case 1:
					//oog.draw(100, 100);
					break;
				case 2:
                        ofEnableAlphaBlending();
                        ofPushMatrix();
                        ofTranslate(260, 600, 0);
                        ofRotate(50);
                        ofSetColor(255, 255, 255, transperantie);
                        oog.draw(0, 0);
                        ofPopMatrix();
                        ofDisableAlphaBlending();
                        break;
                    case 3:
                        ofEnableAlphaBlending();
                        ofPushMatrix();
                        ofTranslate(320, 690, 0);
                        ofRotate(25);
                        ofSetColor(255, 255, 255, transperantie);
                        oog.draw(0, 0);
                        ofPopMatrix();
                        ofDisableAlphaBlending();
                        break;
                    case 4:
                        ofEnableAlphaBlending();
                        ofPushMatrix();
                        ofTranslate(400, 740, 0);
                        ofRotate(5);
                        ofSetColor(255, 255, 255, transperantie);
                        oog.draw(0, 0);
                        ofPopMatrix();
                        ofDisableAlphaBlending();
                        break;
                    case 5:
                        ofEnableAlphaBlending();
                        ofPushMatrix();
                        ofTranslate(510, 750, 0);
                        ofRotate(-5);
                        ofSetColor(255, 255, 255, transperantie);
                        oog.draw(0, 0);
                        ofPopMatrix();
                        ofDisableAlphaBlending();
                        break;
                    case 6:
                        ofEnableAlphaBlending();
                        ofPushMatrix();
                        ofTranslate(600, 750, 0);
                        ofRotate(-35);
                        ofSetColor(255, 255, 255, transperantie);
                        oog.draw(0, 0);
                        ofPopMatrix();
                        ofDisableAlphaBlending();
                        break;
                    case 7:
                        ofEnableAlphaBlending();
                        ofPushMatrix();
                        ofTranslate(700, 700, 0);
                        ofRotate(-65);
                        ofSetColor(255, 255, 255, transperantie);
                        oog.draw(0, 0);
                        ofPopMatrix();
                        ofDisableAlphaBlending();
                        break;
                    case 8:
                        ofEnableAlphaBlending();
                        ofPushMatrix();
                        ofTranslate(760, 620, 0);
                        ofRotate(-90);
                        ofSetColor(255, 255, 255, transperantie);
                        oog.draw(0, 0);
                        ofPopMatrix();
                        ofDisableAlphaBlending();
                        break;
                    case 9:
                        ofEnableAlphaBlending();
                        ofPushMatrix();
                        ofTranslate(770, 510, 0);
                        ofRotate(-100);
                        ofSetColor(255, 255, 255, transperantie);
                        oog.draw(0, 0);
                        ofPopMatrix();
                        ofDisableAlphaBlending();
                        break;
                    case 10:
                        ofEnableAlphaBlending();
                        ofPushMatrix();
                        ofTranslate(750, 400, 0);
                        ofRotate(-125);
                        ofSetColor(255, 255, 255, transperantie);
                        oog.draw(0, 0);
                        ofPopMatrix();
                        ofDisableAlphaBlending();
                        break;
                    case 11:
                        ofEnableAlphaBlending();
                        ofPushMatrix();
                        ofTranslate(700, 320, 0);
                        ofRotate(-145);
                        ofSetColor(255, 255, 255, transperantie);
                        oog.draw(0, 0);
                        ofPopMatrix();
                        ofDisableAlphaBlending();
                        break;
                    case 12:
                        ofEnableAlphaBlending();
                        ofPushMatrix();
                        ofTranslate(620, 260, 0);
                        ofRotate(-170);
                        ofSetColor(255, 255, 255, transperantie);
                        oog.draw(0, 0);
                        ofPopMatrix();
                        ofDisableAlphaBlending();
                        break;
                    case 13:
                        ofEnableAlphaBlending();
                        ofPushMatrix();
                        ofTranslate(510, 240, 0);
                        ofRotate(-190);
                        ofSetColor(255, 255, 255, transperantie);
                        oog.draw(0, 0);
                        ofPopMatrix();
                        ofDisableAlphaBlending();
                        break;
                    case 14:
                        ofEnableAlphaBlending();
                        ofPushMatrix();
                        ofTranslate(410, 255, 0);
                        ofRotate(-210);
                        ofSetColor(255, 255, 255, transperantie);
                        oog.draw(0, 0);
                        ofPopMatrix();
                        ofDisableAlphaBlending();
                        break;
                    case 15:
                        ofEnableAlphaBlending();
                        ofPushMatrix();
                        ofTranslate(320, 310, 0);
                        ofRotate(-230);
                        ofSetColor(255, 255, 255, transperantie);
                        oog.draw(0, 0);
                        ofPopMatrix();
                        ofDisableAlphaBlending();
                        break;
                    case 16:
                        ofEnableAlphaBlending();
                        ofPushMatrix();
                        ofTranslate(260, 390, 0);
                        ofRotate(-265);
                        ofSetColor(255, 255, 255, transperantie);
                        oog.draw(0, 0);
                        ofPopMatrix();
                        ofDisableAlphaBlending();
                        break;
                        
                        break;
				}
			
				}
			}
	}
}

void ofApp::mousePressed(int x, int y, int button) {
	ofLog(OF_LOG_NOTICE, "X:%d", x);
	ofLog(OF_LOG_NOTICE, "Y:%d", y);
    image.draw(0, 0);
	beeld = vidGrabber.getPixels();
}