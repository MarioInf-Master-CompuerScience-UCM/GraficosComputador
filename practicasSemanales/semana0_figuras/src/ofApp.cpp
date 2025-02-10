#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0, 0, 0);
	ofSetWindowTitle("Semana 0 - Figuras");
	ofSetFrameRate(60);
	this->score1 = 0;
	this->success1 = 0;
	this->mistakes1 = 0;
	this->score2 = 0;
	this->success2 = 0;
	this->mistakes2 = 0;
	this->startTime=ofGetElapsedTimef();
	this->finalTime = 0;
	this->numRounds = 10;
	this->actualRound = 0;
	this->timeForRound = 2000;
	this->decision=false;
	this->next = false;
	this->timeData = 1000;
	this->actualTimeData = 0;
	this->lastData= 0;
	this->scoreScene=false;

	if (ofRandom(1)==1){
		this->decision=true;
		this->figure1 = ofRandom(3);
		this->figure2 = this->figure1;
		this->colour1 = ofRandom(3);
		this->colour2 = this->colour1;		
	}else{
		this->decision=false;
		this->figure1 = ofRandom(3);
		this->figure2 = ofRandom(3);
		this->colour1 = ofRandom(3);
		this->colour2 = ofRandom(3);
	}
	this->startTime=ofGetElapsedTimeMillis();

}

//--------------------------------------------------------------
void ofApp::update(){

	if(this->scoreScene==false){
		
		this->finalTime= ofGetElapsedTimeMillis() - this->startTime;
		if(finalTime>this->timeForRound || this->next==true){
			if (ofRandom(1)==1){
				this->decision=true;
				this->figure1 = ofRandom(3);
				this->figure2 = this->figure1;
				this->colour1 = ofRandom(3);
				this->colour2 = this->colour1;		
			}else{
				this->decision=false;
				this->figure1 = ofRandom(3);
				this->figure2 = ofRandom(3);
				this->colour1 = ofRandom(3);
				this->colour2 = ofRandom(3);
			}
			this->actualRound++;
			this->startTime=ofGetElapsedTimeMillis();
			this->next=false;
		}

		this->actualTimeData= this->actualTimeData - (ofGetElapsedTimeMillis() - this->startTime);
		if(this->actualTimeData<=0 && this->lastData>=0 && this->lastData<=3){
			this->lastData=-1;
		}

	}
	
	if(this->actualRound>=this->numRounds){
		this->scoreScene=true;
	}

	return;
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofDrawBitmapString( ofToString(ofGetFrameRate()), 5, 0);
    
	ofSetColor(255, 255, 255);
	ofDrawBitmapString( "JUGADOR 1", 40, 50);
	ofDrawBitmapString( "Puntuacion: " + ofToString(this->score1), 40, 80);
	ofDrawBitmapString( "Aciertos: " + ofToString(this->success1), 40, 100);
	ofDrawBitmapString( "Fallos: " + ofToString(this->mistakes1), 40, 120);

    ofDrawBitmapString( "JUGADOR 2", ofGetWidth ()-100, 50);
	ofDrawBitmapString( "Puntuacion: " + ofToString( this->score2), ofGetWidth()-120, 80);
	ofDrawBitmapString( "Aciertos: " + ofToString(this->success2), ofGetWidth()-120, 100);
	ofDrawBitmapString( "Fallos: " + ofToString(this->mistakes2), ofGetWidth()-120, 120);

	ofDrawBitmapString(ofToString(this->actualRound) + " / " + ofToString(this->numRounds), ofGetWidth()/2, 50);

	if(this->scoreScene==false){
		drawFigure(ofGetWidth()/4, ofGetHeight()/2, ofGetWidth()-ofGetWidth()/4, ofGetHeight()/2);	
		drawData();
	}else{
		if(this->score1>this->score2){
			ofDrawBitmapString( "JUGADOR 1 GANA", ofGetWidth()/2, ofGetHeight()/2);
		}else if(this->score1<this->score2){
			ofDrawBitmapString( "JUGADOR 2 GANA", ofGetWidth()/2, ofGetHeight()/2);
		}else{
			ofDrawBitmapString( "EMPATE", ofGetWidth()/2, ofGetHeight()/2);
		}
	}

	return;
}

//--------------------------------------------------------------
void ofApp::drawFigure(int posX_1, int posY_1, int posX_2, int posY_2){

	ofFill();

    if(this->colour1==0){
		ofSetColor(0, 128, 255);
	}else if(this->colour1==1){
		ofSetColor(64, 255, 0);
	}else if(this->colour1==2){
		ofSetColor(255, 64, 0);
	}else if(this->colour1==3){
		ofSetColor(255, 0, 255);
	}
    if(this->figure1==0){
		ofDrawCircle(posX_1, posY_1, 100);
	}else if(this->figure1==1){
		ofDrawEllipse(posX_1, posY_1, 100, 100);
	}else if(this->figure1==2){
		ofDrawCylinder(posX_1, posY_1, 50, 100);
	}else if(this->figure1==3){
		ofDrawRectangle(posX_1, posY_1, 50, 100);
	}


    if(this->colour2==0){
		ofSetColor(0, 128, 255);
	}else if(this->colour2==1){
		ofSetColor(64, 255, 0);
	}else if(this->colour2==2){
		ofSetColor(255, 64, 0);
	}else if(this->colour2==3){
		ofSetColor(255, 0, 255);
	}
    if(this->figure2==0){
		ofDrawCircle(posX_2, posY_2, 100);
	}else if(this->figure2==1){
		ofDrawEllipse(posX_2, posY_2, 100, 100);
	}else if(this->figure2==2){
		ofDrawCylinder(posX_2, posY_2, 50, 100);
	}else if(this->figure2==3){
		ofDrawRectangle(posX_2, posY_2, 50, 100);
	}

	return;
}




//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if(key=='a'){					//Jugador 1 presiona igualdad
		if(this->decision==true){
			this->score1++;
			this->lastData=0;
		}else{
			this->score2++;
			this->lastData=1;
		}
		this->actualTimeData=this->timeData;
		this->next=true;

	}else if(key=='d'){				//Jugador 1 presiona desigualdad
		if(this->decision==false){
			this->score1++;
			this->lastData=0;
		}
		else{
			this->score2++;
			this->lastData=1;
		}
		this->actualTimeData=this->timeData;
		this->next=true;

	}else if(key=='j'){				//Jugador 2 presiona igualdad
		if(this->decision==true){
			this->score2++;
			this->lastData=2;
		}
		else{
			this->score1++;
			this->lastData=3;
		}
		this->actualTimeData=this->timeData;
		this->next=true;

	}else if(key=='l'){				//Jugador 2 presiona desigualdad
		if(this->decision==false){
			this->score2++;
			this->lastData=2;
		}
		else{
			this->lastData=3;
			this->score1++;
		}
		this->actualTimeData=this->timeData;
		this->next=true;
	}

	return;
}

void ofApp::drawData(){
	if(this->lastData==0){
		acierto1();
	}else if(this->lastData==1){
		fallo1();
	}else if(this->lastData==2){
		acierto2();
	}else if(this->lastData==3){
		fallo2();
	}

	return;
}

void ofApp::acierto1(){
	ofSetColor(38, 255, 0);
	ofDrawBitmapString( "ACIERTO", 40, 180);
}

void ofApp::fallo1(){
	ofSetColor(255, 0, 0);
	ofDrawBitmapString( "FALLO", 40, 180);
}

void ofApp::acierto2(){
	ofSetColor(38, 255, 0);
	ofDrawBitmapString( "ACIERTO", ofGetWidth ()-100, 180);
}

void ofApp::fallo2(){
	ofSetColor(255, 0, 0);
	ofDrawBitmapString( "FALLO", ofGetWidth ()-100, 180);
}



//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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