#pragma once

#include "ofMain.h"

#define MAX_BRANCHES 20

class Trunk
{
public:
    ofVec2f startPos;
    ofVec2f endPos;
    int length;
    int width;
    float direction;
    float waviness;
    bool isComplete;
    int numBranches;
    
    Trunk(ofVec2f startPos, int length, int width, float direction, float waviness);
    
    void setEndpoints(ofVec2f startPos);
    void update();
    void draw();
    
protected:
private:
};
