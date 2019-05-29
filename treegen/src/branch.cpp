#include "branch.h"

Branch::Branch(Trunk& trunk) : trunk(trunk) {
    this->length = ofRandom(trunk.length/2);
    this->width = ofRandom(trunk.width/2);
    this->direction = 4 * ofRandom(-trunk.direction, trunk.direction);
    this->startPos = trunk.endPos;
    this->endPos = startPos + ofVec2f(length*sin(direction), -length*cos(direction));

    this->numLeaves = ofRandom(2*MAX_LEAVES/3, MAX_LEAVES);
    this->isComplete = false;
}

void Branch::update() {

}

void Branch::draw() {
    ofSetColor(34,139,34,60);
    ofSetLineWidth(width);
    ofDrawLine(startPos, endPos);
    isComplete=true;
}