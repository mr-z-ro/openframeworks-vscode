#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    count = 40000;
    for (int i=0; i<count; i++) {
        samplePoints.push_back(ofVec2f(ofRandomWidth(), ofRandomHeight()));
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    float noiseVel = ofGetElapsedTimef();
    float val;
    int x,y;
    len = ofMap(ofGetMouseX(), 0, ofGetWidth(), 1, 30);

    ofBackground(255);
    ofSetColor(100);
    
    for (int i=0; i<count; i++) {  
        x = samplePoints[i].x;
        y = samplePoints[i].y;
        val = getValue(x, y, noiseVel);
        
        ofPushMatrix();

        ofTranslate(x, y);
        render(val);

        ofPopMatrix();
    }
}

float ofApp::getValue(int x, int y, float noiseVel) {
    float noise = ofNoise(x, y, noiseVel);
    float mappedNoise = ofMap(noise, 0, 1, 0.00996, 0.01004); 
    return (sin(x * mappedNoise) + sin(y * mappedNoise)) * 2 * PI;
}

void ofApp::render(float val) {
    ofRotateRad(val);
    ofDrawLine(0,0,len,1);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}`
