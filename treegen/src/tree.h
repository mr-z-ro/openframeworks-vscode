#pragma once

#include "ofMain.h"
#include "trunk.h"
#include "branch.h"
#include "leaf.h"

class Tree
{
public:
    ofVec2f startPos = ofVec2f(0,0);
    Trunk trunk = Trunk(startPos, 2.0f/5.0f*ofRandomHeight(), ofRandomWidth()/10.0f, ofRandomf()*PI/12.0f, ofRandomf());
    vector<Branch> branches;
    vector<Leaf> leaves;
    
    Tree(ofVec2f startPos);
    
    void update();
    void draw();
    
protected:
private:
};
