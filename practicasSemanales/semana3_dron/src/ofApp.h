#pragma once

#include "ofxGui.h"
#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		void changeExcene_eventFunction();

		
		int dronWidth;
		int dronHeight;
		int wingWidth;
		int wingHeight;
		int rotation;

		
};
