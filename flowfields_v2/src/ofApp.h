#pragma once

#include "ofMain.h"
#include "field.h"
#include "particle.h"
#include <string>     // to use std::string, std::to_string() and "+" operator acting on strings 

class ofApp : public ofBaseApp{

	Field field;
	vector<Particle> particles;
	bool bShowField;

	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mousePressed(int x, int y, int button);
};
