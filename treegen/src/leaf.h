#pragma once

#include "branch.h"

class Leaf
{
public:
    Branch &branch;

    ofVec2f startPos;
    ofVec2f endPos;
    int length;
    int width;
    float direction;
    float waviness;
    bool isComplete;
    
    Leaf(Branch& branch);
    
    void update();
    void draw();
    
protected:
private:
    
};
