#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    minDistance = 10;
    capturingDrawing = false;
    isSavingPDF = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    if (capturingDrawing) {
        ofPoint mousePos(ofGetMouseX(), ofGetMouseY());
        if (lastPoint.distance(mousePos) >= minDistance) {
            // a.distance(b) calculates the Euclidean distance between point a and b.  It's
            // the length of the straight line distance between the points.
            currentPolyline.curveTo(mousePos);  // Here we are using an ofVec2f with curveTo(...)
            lastPoint = mousePos;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofSetColor(255);  // White color for saved polylines

    // If isSavingPDF is true (i.e. the s key has been pressed), then
    // anything in between ofBeginSaveScreenAsPDF(...) and ofEndSaveScreenAsPDF()
    // is saved to the file.
    if (isSavingPDF) {
        ofBeginSaveScreenAsPDF("savedScreenshot_"+ofGetTimestampString()+".pdf");
        ofBackground(255);
        ofSetColor(0, 0);  // Black color for pdf saved polylines
    }
    
    for (int i=0; i<polylines.size(); i++) {
        ofPolyline polyline = polylines[i];
        polyline.draw();
        
        // Circles at all vertices (every time we call curveTo())
//        vector<glm::tvec3<float, glm::packed_highp>> vertices = polyline.getVertices();
//        for (int vertexIndex=0; vertexIndex<vertices.size(); vertexIndex++) {
//            ofVec3f vertex = vertices[vertexIndex];  // ofVec3f is like ofVec2f, but with a third dimension, z
//            ofDrawCircle(vertex, 5);
//        }
        
        // Circles at evenly spaced vertices
//        for (int p=0; p<100; p+=10) {
//            ofVec3f point = polyline.getPointAtPercent(p/100.0);  // Returns a point at a percentage along the polyline
//            ofDrawCircle(point, 5);
//        }
        
        // Normal lines at all vertices
//        vector<glm::tvec3<float, glm::packed_highp>> vertices = polyline.getVertices();
//        float normalLength = 50;
//        for (int vertexIndex=0; vertexIndex<vertices.size(); vertexIndex++) {
//            ofVec3f vertex = vertices[vertexIndex];  // Get the vertex
//            ofVec3f normal = polyline.getNormalAtIndex(vertexIndex) * normalLength;  // Scale the normal
//            ofDrawLine(vertex-normal/2, vertex+normal/2);  // Center the scaled normal around the vertex
//        }
        
        // Normal lines at evenly spaced vertices
//        float normalLength = 50;
//        for (int p=0; p<500; p+=1) {
//            ofVec3f point = polyline.getPointAtPercent(p/500.0);
//            float floatIndex = polyline.getIndexAtPercent(p/500.0);
//            ofVec3f normal = polyline.getNormalAtIndexInterpolated(floatIndex) * normalLength;
//            ofSetColor(255, 100);
//            ofDrawLine(point-normal/2, point+normal/2);
//        }
        
        // Tangent lines at all vertices
//        vector<glm::tvec3<float, glm::packed_highp>> vertices = polyline.getVertices();
//        float tangentLength = 80;
//        for (int vertexIndex=0; vertexIndex<vertices.size(); vertexIndex++) {
//            ofVec3f vertex = vertices[vertexIndex];
//            ofVec3f tangent = polyline.getTangentAtIndex(vertexIndex) * tangentLength;
//            ofDrawLine(vertex-tangent/2, vertex+tangent/2);
//        }
        
        // Tangent lines at evenly spaced vertices
        ofSetColor(255, 50);
        if (isSavingPDF) {
            ofSetColor(0, 100);
        }
        float tangentLength = 300;
        for (int p=0; p<500; p+=1) {
            ofVec3f point = polyline.getPointAtPercent(p/500.0);
            float floatIndex = polyline.getIndexAtPercent(p/500.0);
            ofVec3f tangent = polyline.getTangentAtIndexInterpolated(floatIndex) * tangentLength;
            ofDrawLine(point-tangent/2, point+tangent/2);
        }
    }
    ofSetColor(255,100,0);  // Orange color for active polyline
    currentPolyline.draw();
    
    // Finish saving the PDF and reset the isSavingPDF flag to false
    // Ending the PDF tells openFrameworks to resume drawing to the screen.
    if (isSavingPDF) {
        ofEndSaveScreenAsPDF();
        isSavingPDF = false;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 's') {
        // isSavingPDF is a flag that lets us know whether or not save a PDF
        isSavingPDF = true;
    } else if (key == 'c') {
        capturingDrawing = true;
        int x = ofGetMouseX();
        int y = ofGetMouseY();
        currentPolyline.curveTo(x, y);  // Remember that x and y are the location of the mouse
        currentPolyline.curveTo(x, y);  // Necessary duplicate for first control point
        lastPoint.set(x, y);  // Set the x and y of a ofVec2f in a single line
    } else if (key == 'd') {
        polylines.clear();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == 'c') {
        capturingDrawing = false;
        int x = ofGetMouseX();
        int y = ofGetMouseY();
        currentPolyline.curveTo(x, y); // Necessary duplicate for last control point
        currentPolyline.simplify(0.75);
        polylines.push_back(currentPolyline);
        currentPolyline.clear();  // Erase the vertices, allows us to start a new brush stroke
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
