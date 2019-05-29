#pragma once
#include "ofMain.h"

class Particle
{
public:
    ofVec2f lastPos;
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;   // frc is also know as acceleration (newton says "f=ma")
    float damping;
    int radius;
    ofColor color;
    
    Particle(int radius=3, ofColor color=ofColor(255, 44, 249));
    virtual ~Particle(){};
    
    void resetForce();
    void addForce(float x, float y);
    void addRepulsionForce(float x, float y, float radius, float scale);
    void addAttractionForce(float x, float y, float radius, float scale);
    void addRepulsionForce(Particle &p, float radius, float scale);
    void addAttractionForce(Particle &p, float radius, float scale);
    void addDampingForce();
    void setInitialCondition(float px, float py, float vx, float vy);
    void update();
    void draw();
    void drawPoint();
    void drawPath();
    void bounceOffWalls();
    void wrapAroundWalls();
    
protected:
private:
};
