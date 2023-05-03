#pragma once

#include "ofMain.h"

using namespace glm;

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	int numOfVertices;
	float radius;
	float angleStep;
	float waveAmplitude;

	//		vector <vec2> points;
	vector <float> noiseSeeds;

	vec2 previousMousePos;
	float gestureMagnitude;

	float prevMouseAmt;
	float currentMouseAmount;

	bool exportVectorGraphics;

	int numOfTilesX = 19;
	int numOfTilesY = 13;

	//PIXMIRRORCODE
	ofVideoGrabber vidGrabber;
	ofPixels pixels;
	int spacing;
	int startPos;

};
