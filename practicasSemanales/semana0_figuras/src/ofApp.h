#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);


		void drawFigure(int posX_1, int posY_1, int posX_2, int posY_2);
		void drawData();
		void acierto1();
		void fallo1();
		void acierto2();
		void fallo2();

		int score1, score2;
		int success1, success2;
		int mistakes1, mistakes2;
		int startTime, finalTime;
		int numRounds, actualRound;
		int timeForRound;
		int figure1, figure2;
		int colour1, colour2;
		int timeData, actualTimeData, lastData;
		bool decision;
		bool next;
		bool scoreScene;
};
