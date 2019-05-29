#include "field.h"

Field::Field(int fieldLineCount, float maxFieldLineLength) {
    this->fieldLineCount = fieldLineCount;
    this->maxFieldLineLength = maxFieldLineLength;
    for (int i=0; i<fieldLineCount; i++) {
        samplePoints.push_back(ofVec2f(ofRandomWidth(), ofRandomHeight()));
    }
}

void Field::update() {
    noiseVel = ofGetElapsedTimef();
}

//--------------------------------------------------------------
void Field::draw(ofColor fgColor, ofColor bgColor) {
    float val;
    int x,y;
    fieldLineLength = ofMap(ofGetMouseX(), 0, ofGetWidth(), 1, maxFieldLineLength);

    ofBackground(bgColor);
    ofSetColor(fgColor);
    
    for (int i=0; i<fieldLineCount; i++) {  
        x = samplePoints[i].x;
        y = samplePoints[i].y;
        val = getValue(x, y);
        
        ofPushMatrix();

        ofTranslate(x, y);
        render(val);

        ofPopMatrix();
    }
}

float Field::getValue(int x, int y) {
    float noise = ofNoise(x, y, noiseVel);
    float mappedNoise = ofMap(noise, 0, 1, 0.00996, 0.01004);
    float mappedStrength = ofMap(fieldLineLength, 1, maxFieldLineLength, 0.1, 20);
    return mappedStrength * (sin(x * mappedNoise) + sin(y * mappedNoise)) * 2 * PI;
}

void Field::render(float val) {
    ofRotateRad(val);
    ofDrawLine(0,0,fieldLineLength,1);
}
