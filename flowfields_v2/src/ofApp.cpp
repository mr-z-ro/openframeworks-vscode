#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // Don't clear background by default
    ofSetBackgroundAuto(false);
    ofBackground(ofColor(47, 39, 85));

    // Initialize a field, specifying the number of sample points to optionally visualize
    field = Field(40000);

    // Don't show the field unless explicitly told to
    bShowField = false;

    // Initialize some particles, randomly positioned, each starting at rest
    // int numParticles = 200;
    // for (int i=0; i<numParticles; i++) {
    //     Particle p;
    //     int x = ofRandom(ofGetWidth());
    //     int y = ofRandom(ofGetHeight());
    //     p.setInitialCondition(x, y, 0, 0);
    //     particles.push_back(p);
    // }

    // Initialize some more particles, positioned along an axis, each starting at rest
    // for (int x=0; x<ofGetWidth(); x+=5) {
    //     Particle p = Particle(1, ofColor(202, 178, 171, 20));
    //     p.setInitialCondition(x, 0, 0, 0);
    //     particles.push_back(p);
    // }
}

//--------------------------------------------------------------
void ofApp::update(){
    // Update the Field
    field.update();

    // Reset all particle forces
    // Wrap around positions if needed (alternatively can bounce off walls)
    for (int i = 0; i < particles.size(); i++){
        particles[i].resetForce();
        particles[i].wrapAroundWalls();
    }

    // Each Particle feels the Field and repels the other Particles
    for (int i = 0; i < particles.size(); i++){
        float val = field.getValue(particles[i].pos.x, particles[i].pos.y);
        particles[i].addForce(cos(val), sin(val));
        for (int j = 0; j < i; j++){
            particles[i].addRepulsionForce(particles[j], 30, 0.4);
            particles[i].addAttractionForce(particles[j], 500, 0.001);
        }
    }
    
    // Dampen the particles (i.e. add friction)
    for (int i = 0; i < particles.size(); i++){
        particles[i].addDampingForce();
        particles[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    // Visualize the flow field
    if (bShowField) {
       field.draw(ofColor(70, 60, 120), ofColor(47, 39, 85));
    }

    // Visualize the particles
    for (int i=0; i<particles.size(); i++) {
        //particles[i].drawPoint();
        particles[i].drawPath();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'q') {
        particles.clear();
    } else if (key == 'p') {
        ofSaveScreen("screenshot-" + ofGetTimestampString() + ".png");
    } else {
        bShowField=true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == 'p') {
        return;
    }
    bShowField=false;
    ofBackground(ofColor(47, 39, 85));
}

void ofApp::mousePressed(int x, int y, int button) {
    // Initialize some more particles, positioned along an axis, each starting at rest
    for (int _x=-50; _x<50; _x+=5) {
        Particle p = Particle(1, ofColor(202, 178, 171, 20));
        p.setInitialCondition(x + _x, y+ofRandom(-1, 1), 0, 0);
        particles.push_back(p);
    }
    for (int _y=-50; _y<50; _y+=5) {
        Particle p = Particle(1, ofColor(202, 178, 171, 20));
        p.setInitialCondition(x+ofRandom(-1, 1), y + _y, 0, 0);
        particles.push_back(p);
    }
}
