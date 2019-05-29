#include "particle.h"
//------------------------------------------------------------
Particle::Particle(int radius, ofColor color){
    this->radius = radius;
    this->color = color;
    setInitialCondition(0,0,0,0);
    damping = 0.12f;
}

//------------------------------------------------------------
void Particle::resetForce(){
    // we reset the forces every frame
    frc.set(0,0);
}

//------------------------------------------------------------
void Particle::addForce(float x, float y){
    // add in a force in X and Y for this frame.
    frc.x = frc.x + x;
    frc.y = frc.y + y;
}

//------------------------------------------------------------
void Particle::addRepulsionForce(float x, float y, float radius, float scale){
    // ----------- (1) make a vector of where this position is:
    ofVec2f posOfForce;
    posOfForce.set(x,y);
    
    // ----------- (2) calculate the difference & length
    ofVec2f diff    = pos - posOfForce;
    float length    = diff.length();
    
    // ----------- (3) check close enough
    bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
    
    // ----------- (4) if so, update force
    if (bAmCloseEnough == true){
        float pct = 1 - (length / radius);  // stronger on the inside
        diff.normalize();
        frc.x = frc.x + diff.x * scale * pct;
        frc.y = frc.y + diff.y * scale * pct;
    }
}

//------------------------------------------------------------
void Particle::addAttractionForce(float x, float y, float radius, float scale){
    // ----------- (1) make a vector of where this position is:
    ofVec2f posOfForce;
    posOfForce.set(x,y);
    
    // ----------- (2) calculate the difference & length
    ofVec2f diff    = pos - posOfForce;
    float length    = diff.length();
    
    // ----------- (3) check close enough
    bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
    
    // ----------- (4) if so, update force
    if (bAmCloseEnough == true){
        float pct = 1 - (length / radius);  // stronger on the inside
        diff.normalize();
        frc.x = frc.x - diff.x * scale * pct;
        frc.y = frc.y - diff.y * scale * pct;
    }
}

//------------------------------------------------------------
void Particle::addRepulsionForce(Particle &p, float radius, float scale){
    // ----------- (1) make a vector of where this Particle p is:
    ofVec2f posOfForce;
    posOfForce.set(p.pos.x,p.pos.y);
    
    // ----------- (2) calculate the difference & length
    ofVec2f diff    = pos - posOfForce;
    float length    = diff.length();
    
    // ----------- (3) check close enough
    bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
    
    // ----------- (4) if so, update force
    if (bAmCloseEnough == true){
        float pct = 1 - (length / radius);  // stronger on the inside
        diff.normalize();
        frc.x = frc.x + diff.x * scale * pct;
        frc.y = frc.y + diff.y * scale * pct;
        p.frc.x = p.frc.x - diff.x * scale * pct;
        p.frc.y = p.frc.y - diff.y * scale * pct;
    }
}

//------------------------------------------------------------
void Particle::addAttractionForce(Particle & p, float radius, float scale){
    // ----------- (1) make a vector of where this Particle p is:
    ofVec2f posOfForce;
    posOfForce.set(p.pos.x,p.pos.y);
    
    // ----------- (2) calculate the difference & length
    ofVec2f diff    = pos - posOfForce;
    float length    = diff.length();
    
    // ----------- (3) check close enough
    bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
    
    // ----------- (4) if so, update force
    if (bAmCloseEnough == true){
        float pct = 1 - (length / radius);  // stronger on the inside
        diff.normalize();
        frc.x = frc.x - diff.x * scale * pct;
        frc.y = frc.y - diff.y * scale * pct;
        p.frc.x = p.frc.x + diff.x * scale * pct;
        p.frc.y = p.frc.y + diff.y * scale * pct;
    }
}

//------------------------------------------------------------
void Particle::addDampingForce(){
    
    // the usual way to write this is  vel *= 0.99
    // basically, subtract some part of the velocity
    // damping is a force operating in the oposite direction of the
    // velocity vector
    
    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.y * damping;
}

//------------------------------------------------------------
void Particle::setInitialCondition(float px, float py, float vx, float vy){
    pos.set(px,py);
    vel.set(vx,vy);
}

//------------------------------------------------------------
void Particle::update(){
    lastPos = pos;
    vel = vel + frc;
    pos = pos + vel;
}

//------------------------------------------------------------
void Particle::draw(){
    drawPoint();
}

//------------------------------------------------------------
void Particle::drawPoint(){
    ofEnableAlphaBlending();
    ofSetColor(color);
    ofDrawCircle(pos.x, pos.y, radius);
}

void Particle::drawPath() {
    ofEnableAlphaBlending();
    ofSetColor(color);
    ofSetLineWidth(radius);
    ofDrawLine(lastPos.x, lastPos.y, pos.x, pos.y);
}

//------------------------------------------------------------
void Particle::bounceOffWalls(){
    // sometimes it makes sense to damped, when we hit
    bool bDampedOnCollision = true;
    bool bDidICollide = false;
    
    // what are the walls
    float minx = 0;
    float miny = 0;
    float maxx = ofGetWidth()-radius;
    float maxy = ofGetHeight()-radius;
    
    if (pos.x > maxx){
        pos.x = maxx; // move to the edge, (important!)
        vel.x *= -1;
        bDidICollide = true;
    } else if (pos.x < minx){
        pos.x = minx; // move to the edge, (important!)
        vel.x *= -1;
        bDidICollide = true;
    }
    
    if (pos.y > maxy){
        pos.y = maxy; // move to the edge, (important!)
        vel.y *= -1;
        bDidICollide = true;
    } else if (pos.y < miny){
        pos.y = miny; // move to the edge, (important!)
        vel.y *= -1;
        bDidICollide = true;
    }
    
    if (bDidICollide == true && bDampedOnCollision == true){
        vel *= 0.3;
    }
}

//------------------------------------------------------------
void Particle::wrapAroundWalls(){    
    // what are the walls
    float minx = 0;
    float miny = 0;
    float maxx = ofGetWidth()-radius;
    float maxy = ofGetHeight()-radius;
    
    if (pos.x > maxx){
        pos.x = minx; // off right of screen, return to left
    } else if (pos.x < minx){
        pos.x = maxx; // off left of screen, return to right
    }
    
    if (pos.y > maxy){
        pos.y = 0; // off bottom of screen, return to top
    } else if (pos.y < miny){
        pos.y = maxy; // off top of screen, return to bottom
    }
}
