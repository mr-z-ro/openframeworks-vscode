#include "trunk.h"

Trunk::Trunk(ofVec2f startPos, int length, int width, float direction, float waviness) {
    setEndpoints(startPos);
    this->length = length;
    this->direction = direction;
    
    this->width = width;
    this->waviness = waviness;
    this->numBranches = ofRandom(2*MAX_BRANCHES/3, MAX_BRANCHES);
    this->isComplete = false;
}

void Trunk::setEndpoints(ofVec2f startPos) {
    this->startPos = startPos;
    this->endPos = startPos + ofVec2f(length*sin(direction), -length*cos(direction));
}

void Trunk::update() {

}

void Trunk::draw() {
    ofSetColor(34,139,34, 90);
    ofSetLineWidth(width);
    ofDrawLine(startPos, endPos);
    isComplete = true;
}