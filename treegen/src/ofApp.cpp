#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofColor colorOne(144,238,144);
    ofColor colorTwo(200, 255, 200);
    ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_LINEAR);
    initializeTrees();
}

void ofApp::initializeTrees() {
    trees.clear();

    int width = ofGetWidth();
    for(int i=0; i<width; i=ofRandom(i, i+width/numTrees)) {
        trees.push_back(Tree(ofVec2f(i, 1.0f/2.0f*(ofRandomHeight()+ofGetHeight()))));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i=0; i<trees.size(); i++) {
        trees[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i=0; i<trees.size(); i++) {
        trees[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    ofColor colorOne(144,238,144);
    ofColor colorTwo(200, 255, 200);
    ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_LINEAR);
    initializeTrees();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
