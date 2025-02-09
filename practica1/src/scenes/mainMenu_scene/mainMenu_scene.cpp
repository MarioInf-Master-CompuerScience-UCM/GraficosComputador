#include "mainMenu_scene.h"
 

        //SetupScene function
    //*****************************************************
    void MainMenu_scene::setupScene(){

		ofBackground(bgMain);

		int wh;
		wh = 60 * ofGetWindowHeight() / 768;

        this->title="Defend\nDeath Star";
        this->titleFont.load("V5PRC.TTF", wh, true, true);
        this->titleFont.setLineHeight(wh * 1.05);
        this->titleFont.setLetterSpacing(1.035);

		this->startTextFont.load("pixelmix.TTF", wh * 0.4, true, true);
		this->startTextFont.setLineHeight(wh * 1.05);
		this->startTextFont.setLetterSpacing(1.035);

		loadSounds();

        return;
    }


        //DrawScene function
    //*****************************************************
    void MainMenu_scene::drawScene(){
		this->drawBackground();

		this->drawTitle();

        return;
    }


        //UpdateScene function
    //*****************************************************
    void MainMenu_scene::updateScene(){
		if (ofGetKeyPressed(' ')) {
			soundPlayer[0]->stop();

			int targetScene = 1;
			ofNotifyEvent(onStartGame, targetScene);
		}
    }


	void MainMenu_scene::loadSounds() {
		ofSoundPlayer * soundtrack = new ofSoundPlayer();

		soundPlayer = vector<ofSoundPlayer*>();
		soundPlayer.push_back(soundtrack);

		soundPlayer[0]->load("audio/soundtracks/vvvvvv_passion_for_exploring.mp3");
		soundPlayer[0]->setLoop(true);
		soundPlayer[0]->setVolume(0.8f);
		soundPlayer[0]->play();
	}


	void MainMenu_scene::drawBackground() {
		int halfWidth = (int) (ofGetWidth() / 2.0);
		float counter = ((int)(ofGetElapsedTimeMillis() / 3.0) % halfWidth) / (float)halfWidth;
		float nStrips = 2;

		ofSetColor(bgSecondary);

		ofPushMatrix();

		ofTranslate(ofGetWidth() / 2.0, 0);
		for (int i = 0; i < nStrips; i++) {

			float shift = i / nStrips;
			float widthShift = shift + 1 /(2*nStrips);

			float pos = (counter + shift) - floor(counter + shift);
			float nextPos = counter + widthShift - floor(counter + widthShift);

			int initPos = (int)(halfWidth * (pow(pos, 2)));
			int widthStrip = (int)(halfWidth * (pow(nextPos, 2)) - initPos);

			if (nextPos < pos) {
				widthStrip = halfWidth;
			}

			ofDrawRectangle(initPos, 0, widthStrip, ofGetHeight());

			ofScale(-1, 1);
			ofDrawRectangle(initPos, 0, widthStrip, ofGetHeight());
			ofScale(-1, 1);

		}

		ofPopMatrix();

	}


	void MainMenu_scene::drawTitle() {

		float counter = ofGetElapsedTimeMillis() / 20.0;

		ofSetColor(ofColor::white);
		titleFont.drawString(title, 100, ofGetHeight() * 0.15 + 5 * sin(counter / (2 * 3.14)));


		startTextFont.drawString("Press space to play", 100, ofGetHeight()*0.5);

	}