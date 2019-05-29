#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	int count;
	float len;
	vector<ofVec2f> samplePoints;

	public:
		float getValue(int x, int y, float noiseVel);
		void render(float val);

		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
};
