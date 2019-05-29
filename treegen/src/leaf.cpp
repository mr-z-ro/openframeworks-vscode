#include "leaf.h"

Leaf::Leaf(Branch& branch) : branch(branch) {
    this->length = ofRandom(branch.length/4.0f);
    this->width = ofRandom(branch.width/6.0f);
    this->direction = 8 * ofRandom(-branch.direction, branch.direction);
    this->startPos = branch.endPos;
    this->endPos = startPos + ofVec2f(length*sin(direction), -length*cos(direction));
}

void Leaf::update() {

}

void Leaf::draw() {
    ofSetColor(255,223,0, 60);
    ofSetLineWidth(1);
    ofPushMatrix();
    ofTranslate(startPos);
    ofRotateRad(direction);
    ofDrawLine(0, 0, length, 0);
    for (float x=0; x<length; x+=length/10.0) {
        ofDrawLine(x, -0.25*length*sin(length*x/PI), x, 0.25*length*sin(length*x/PI));
    }
    ofPopMatrix();
    isComplete = true;
}