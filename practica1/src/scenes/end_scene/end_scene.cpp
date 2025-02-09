#include "end_scene.h" 
 

        //SetupScene function
    //*****************************************************
    void End_scene::setupScene(){
		ofResetElapsedTimeCounter();

		ofBackground(bgMain);

		int wh;
		wh = 200 * ofGetWindowHeight() / 1800;

		this->gameOverFont.load("V5PRC.TTF", wh, true, true);
		this->gameOverFont.setLineHeight(wh*1.05);
		this->gameOverFont.setLetterSpacing(1.035);

		this->gameOverBgFont.load("V5PRC.TTF", wh * 0.75, true, true);
		this->gameOverBgFont.setLineHeight(wh * 0.75 * 1.05);
		this->gameOverBgFont.setLetterSpacing(1.035);

		this->subtitleFont.load("pixelmix.TTF", wh * 0.4, true, true);
		this->subtitleFont.setLineHeight(wh * 0.6 * 1.05);
		this->subtitleFont.setLetterSpacing(1.035);

		loadSounds();

    }


        //DrawScene function
    //*****************************************************
    void End_scene::drawScene(){
        
		drawBackground();
    }


        //UpdateScene function
    //*****************************************************
    void End_scene::updateScene(){
		if (ofGetKeyPressed('r') || ofGetElapsedTimeMillis() > 30000){
			soundPlayer[0]->stop();

			int targetScene = 0;
			ofNotifyEvent(onRestart, targetScene);
		}
    }


	void End_scene::loadSounds() {
		ofSoundPlayer * soundtrack = new ofSoundPlayer();

		soundPlayer = vector<ofSoundPlayer*>();
		soundPlayer.push_back(soundtrack);

		soundPlayer[0]->load("audio/soundtracks/game_over.mp3");
		soundPlayer[0]->play();
	}


	void End_scene::setScore(int value) {
		this->score = value;
		
		return;
	}


	void End_scene::drawBackground() {
		int stringWidth = gameOverBgFont.stringWidth("GAME OVER ");
		int stringHeight = gameOverBgFont.stringHeight("GAME OVER ");

		int windowWidth = ofGetWidth();
		int windowHeight = ofGetHeight();

		int nHorizStrings = windowWidth / stringWidth + 1;
		int nVertStrings = windowHeight / stringHeight + 1;

		int stringOffset = (windowWidth + stringWidth)/nHorizStrings - stringWidth;

		int counter = (int)(ofGetElapsedTimeMillis() / 5.0);

		ofSetColor(bgSecondary);

		for (int j = 0; j < nVertStrings; j++) {
			for (int i = 0; i < nHorizStrings; i++) {
				gameOverBgFont.drawString("GAME OVER ", ((int)(counter * (1 + j/5.0)) + j * 50 + i * (stringWidth + stringOffset)) % (windowWidth + stringWidth) - stringWidth,
														 j * (stringHeight + 20));
			}
		}

		ofSetColor(ofColor::white);
		int stringWidthMain = gameOverFont.stringWidth("GAME OVER");
		int stringHeightMain = gameOverFont.stringHeight("GAME OVER");
		gameOverFont.drawString("GAME OVER", windowWidth / 2 - stringWidthMain / 2, windowHeight / 2 - stringHeightMain / 2);

		int stringWidthScore = subtitleFont.stringWidth("Score: " + ofToString(score));
		subtitleFont.drawString("Score: " + ofToString(score), windowWidth / 2 - stringWidthMain / 2, windowHeight / 2 - stringHeightMain / 2 + stringHeightMain);

		return;
	}