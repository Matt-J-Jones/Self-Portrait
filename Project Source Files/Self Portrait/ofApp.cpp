#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofBackground(255);
    ofSetLineWidth(0.05);
    ofSetColor(0);
    ofNoFill();

    exportVectorGraphics = false;
    
    //Set the size and violence of initial circles
    numOfVertices = 25;
    waveAmplitude = 0;
    radius = 15;

    previousMousePos = vec2(0, 0);
    gestureMagnitude = 0;

    prevMouseAmt = 0.95;
    currentMouseAmount = 1 - prevMouseAmt;

    angleStep = 360.0 / numOfVertices;

    for (int i = 0; i < numOfVertices; i++) {
        noiseSeeds.push_back(ofRandom(200));
    }

    
    //LIVE MIRROR CODE
    ofSetFrameRate(30);
    vidGrabber.listDevices();
    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(30);
    vidGrabber.initGrabber(640, 480);
    spacing = 8;
    startPos = spacing/2;
    //END
    
}

//--------------------------------------------------------------
void ofApp::update() {
    //PIXMIRRORCODE
    vidGrabber.update();
    pixels = vidGrabber.getPixels();
    //END


}

//--------------------------------------------------------------
void ofApp::draw() {
     if (exportVectorGraphics) {
        ofBeginSaveScreenAsSVG("SelfPortrait" + ofGetTimestampString() + ".svg");// so our svg names are unique & don't over-write eachother
        ofNoFill();
    }
     int factor = 30;
     

     ofScale(0.66);
     ofTranslate(150, 150);
     
     //LIVE MIRROR CODE - From Week 9 Code Examples
     for (int i = 0; i < ofGetWidth(); i += spacing) {
         for (int j = 0; j < ofGetHeight(); j += spacing) {
             int locX = i + startPos;
             int locY = j + startPos;

             ofColor c = pixels.getColor(locX, locY);
             int brightness = c.getBrightness();

             ofPushMatrix();

             ofTranslate(locX, locY);

             int maxSize = 10;

             float radius = ofMap(brightness, 0, 255, maxSize, 0);
             float mir_amp = ofMap(brightness, 0, 255, 100,-150);

             //Draw the circles over the background image
             ofPushMatrix();
             ofScale(2);
             ofBeginShape();

             //Noise Pixles code - From Week 4 Noisy Circles Code Examples
             for (int i = 0; i < numOfVertices; i++) {
                 
                 waveAmplitude = mir_amp;
                 previousMousePos.x = ofRandom(350);
                 previousMousePos.y = ofRandom(350);
                 vec2 gesture = previousMousePos;

                 gestureMagnitude = prevMouseAmt * gestureMagnitude + length(gesture) * currentMouseAmount;

                 vec2 pointLocation;
                 pointLocation.x = cos(ofDegToRad(angleStep * i)) * radius;
                 pointLocation.y = sin(ofDegToRad(angleStep * i)) * radius;
                 vec2 pointDir = normalize(pointLocation);
                 pointLocation.x += ofSignedNoise(noiseSeeds[i]) * (waveAmplitude * pointDir.x);
                 pointLocation.y += ofSignedNoise(noiseSeeds[i]) * (waveAmplitude * pointDir.y);
                 ofVertex(pointLocation.x, pointLocation.y);
                 noiseSeeds[i] += 0.01;
                 
             }
             ofEndShape(true);
             ofPopMatrix();

             ofPopMatrix();
         }
     }

     //END
     
     
     for (int x = 0; x < numOfTilesX; x++) {
         int i = 1;
         //ofTranslate((ofGetWidth() / 6) * i, 0);
         ofTranslate(factor, 0);
         i++;
         for (int y = 0; y < numOfTilesY; y++) {
             int q = 1;
             //ofTranslate(0, (ofGetHeight() / 6)*q);
             ofTranslate(0, factor);
             q++;
             ofPushMatrix();
             ofScale(0.13);
             ofTranslate(ofGetWidth() / 6, ofGetHeight() / 6);
             //ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
             //ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
             //ofDrawCircle(0, 0, ofGetWidth() / ofRandom(20));
            //ofBeginShape();
            ////only these points are drawn
            //for (int i = 0; i < numOfVertices; i++) {

            //    waveAmplitude = 1;
            //    previousMousePos.x = ofRandom(350);
            //    previousMousePos.y = ofRandom(350);
            //    vec2 gesture = previousMousePos;
            //    gestureMagnitude = prevMouseAmt * gestureMagnitude + length(gesture) * currentMouseAmount;

            //    vec2 pointLocation;
            //    pointLocation.x = cos(ofDegToRad(angleStep * i)) * radius;
            //    pointLocation.y = sin(ofDegToRad(angleStep * i)) * radius;
            //    vec2 pointDir = normalize(pointLocation);
            //    pointLocation.x += ofSignedNoise(noiseSeeds[i]) * (waveAmplitude * pointDir.x);
            //    pointLocation.y += ofSignedNoise(noiseSeeds[i]) * (waveAmplitude * pointDir.y);
            //    ofVertex(pointLocation.x, pointLocation.y);
            //    noiseSeeds[i] += 0.01;
            //}
            //ofEndShape(true);
            ofPopMatrix();
         }
         //ofTranslate(0, ((ofGetHeight() / 6) * 6) * -1);
         ofTranslate(0, (factor * numOfTilesY) * -1);
     }


    if (exportVectorGraphics) {
        ofEndSaveScreenAsSVG();
        exportVectorGraphics = false;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
    if (key == 's') {
        exportVectorGraphics = true;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
