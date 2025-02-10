#include "mainMenu_scene.h" 
 

        //SetupScene function
    //*****************************************************
    void MainMenu_scene::setupScene(){

        this->signTitleWidht = 5*(ofGetWidth()/10);
        this->signTitleHeight = 1*(ofGetHeight()/10);
        this->signTitlePosX = 2.5*(ofGetWidth()/10);
        this->signTitlePosY = 1*(ofGetHeight()/10);
        this->title="PARATROOPER GAME";
        this->titleFont.load("verdana.ttf", 30, true, true);
        this->titleFont.setLineHeight(34.0f);
        this->titleFont.setLetterSpacing(1.035);

        this->signMenuWidht = 4*(ofGetWidth()/10);
        this->signMenuHeight = 5*(ofGetHeight()/10);
        this->signMenuPosX = 3*(ofGetWidth()/10);
        this->signMenuPosY = 3*(ofGetHeight()/10);

            this->buttonFont.load("verdana.ttf", 18, true, true);
            this->buttonFont.setLineHeight(34.0f);
            this->buttonFont.setLetterSpacing(1.035);

            this->playButton = "Play";
			this->signPlayButtonWidht = 3*(ofGetWidth()/10);
			this->signPlayButtonHeight = 0.5*(ofGetHeight()/10);
			this->signPlayButtonPosX = 3.5*(ofGetWidth()/10);
			this->signPlayButtonPosY = 3.5*(ofGetHeight()/10);

            this->exitButton = "Exit";
			this->signExitButtonWidht = 3*(ofGetWidth()/10);
			this->signExitButtonHeight = 0.5*(ofGetHeight()/10);
			this->signExitButtonPosX = 3.5*(ofGetWidth()/10);
			this->signExitButtonPosY = 4.5*(ofGetHeight()/10);
            
        return;
    }


        //DrawScene function
    //*****************************************************
    void MainMenu_scene::drawScene(){
        ofBackground(114, 156, 212);
        ofFill();
        ofSetColor(160, 171, 43);
        ofDrawRectangle(this->signTitlePosX, this->signTitlePosY, this->signTitleWidht, this->signTitleHeight);
        ofDrawRectangle(this->signMenuPosX, this->signMenuPosY, this->signMenuWidht, this->signMenuHeight);
        ofSetColor(145, 65, 12);
        ofDrawRectangle(this->signPlayButtonPosX, this->signPlayButtonPosY, this->signPlayButtonWidht, this->signPlayButtonHeight);
        ofDrawRectangle(this->signExitButtonPosX, this->signExitButtonPosY, this->signExitButtonWidht, this->signExitButtonHeight);
       
        ofSetColor(0,0,0);
        this->titleFont.drawString(this->title, this->signTitlePosX + this->signTitlePosX/10, this->signTitlePosY + this->signTitleHeight/1.5 );
        this->titleFont.drawString(this->playButton, this->signPlayButtonPosX, this->signPlayButtonPosY + this->signPlayButtonHeight);
        this->titleFont.drawString(this->exitButton, this->signExitButtonPosX, this->signExitButtonPosY + this->signExitButtonHeight);

        return;
    }


        //UpdateScene function
    //*****************************************************
    void MainMenu_scene::updateScene(){
        
    }