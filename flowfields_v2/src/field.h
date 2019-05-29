#pragma once

#include "ofMain.h"

class Field {

	int fieldLineCount;
	float fieldLineLength;
	float maxFieldLineLength;
	float noiseVel;
	vector<ofVec2f> samplePoints;

	public:
		Field(int fieldLineCount=1000, float fieldLineLength=30);
		float getValue(int x, int y);
		void update();
		void draw(ofColor fgColor=ofColor(100), ofColor bgColor=ofColor(255));
		void render(float val);
};
