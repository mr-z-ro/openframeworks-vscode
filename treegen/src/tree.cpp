#include "tree.h"

Tree::Tree(ofVec2f startPos) {
    this->startPos = startPos;
    
    trunk.setEndpoints(startPos);
    vector<Branch> branches;
    vector<Leaf> leaves;
}

void Tree::update() {
    trunk.update();

    if (trunk.isComplete) {
        // Add a branch
        if (branches.size() < trunk.numBranches) {
            for (int i=0; i<trunk.numBranches; i++) {
                branches.push_back(Branch(trunk));
            }
        }
        
        // Update all branches
        for (int i=0; i<branches.size(); i++) {
            branches[i].update();
            if (branches[i].isComplete) {
                if (leaves.size() < branches[i].numLeaves) {
                    leaves.push_back(Leaf(branches[i]));
                }
                for (int j=0; j<leaves.size(); j++) {
                    leaves[j].update();
                }
            }
        }
    }
}

void Tree::draw() {
    trunk.draw();
    for (int i=0; i<branches.size(); i++) {
        branches[i].draw();
    }
    for (int i=0; i<leaves.size(); i++) {
        leaves[i].draw();
    }
}