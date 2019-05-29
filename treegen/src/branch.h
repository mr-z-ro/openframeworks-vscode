#pragma once

#include "trunk.h"

#define MAX_LEAVES 200

class Branch
{
public:
    Trunk &trunk;

    ofVec2f startPos;
    ofVec2f endPos;
    int length;
    int width;
    float direction;
    float waviness;
    bool isComplete;
    int numLeaves;
    
    Branch(Trunk& trunk);
    
    void update();
    void draw();
    
protected:
private:
    
};
