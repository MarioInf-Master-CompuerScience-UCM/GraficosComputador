#include "PacMan.h"


// pmInit Function
//*************************************************************
void PacMan::pmInit(int nInitialPosX, int nInitialPosY){

	this->initialPosX = nInitialPosX;
	this->initialPosY = nInitialPosY;
	this->posX = nInitialPosX;
	this->posY = nInitialPosY;
	this->posEyeX = nInitialPosX + this->radius/3;
	this->posEyeX = nInitialPosY;
	this->stepResolutionPer = 3;
	this->angleDirection=90;
	this->angleMouse = this->maxAngleMouse;
	this->stateMouse = true;

    return;
}


// pmUpdate Function
//*************************************************************
void PacMan::pmUpdate(){
	
	if(this->stateMouse){
		this-> angleMouse = this-> angleMouse + this->speedMouse;
	}else{
		this-> angleMouse = this-> angleMouse - this->speedMouse;
	}

	if(this->angleMouse >= this->maxAngleMouse){
		this->stateMouse = false;
		this->angleMouse = this->maxAngleMouse;
	}else if(this->angleMouse <= 0){
		this->stateMouse = true;
		this->angleMouse = 0;
	}

	return;
}


// pmDraw Function
//*************************************************************
void PacMan::pmDraw(){
	
	if (this->angleDirection==90){
		pmDrawRight();
	}
	else if (this->angleDirection==270){
		pmDrawLeft();
	}
	else if (this->angleDirection==0){
		pmDrawUp();
	}
	else if (this->angleDirection==180){
		pmDrawDown();
	}
	
	return;
}


// pmDrawLeft Function
//*************************************************************
void PacMan::pmDrawLeft(){

	int circleStar = 270 + this->angleMouse/2 ;
	int circleEnd = 360 + 270 - this->angleMouse/2 ;


	//Draw PacmanFill
	ofSetColor(color1_R, color1_G, color1_B);
	ofDrawBitmapString("RIGHT ", 40, 40);
    ofFill();
	ofBeginShape();

		ofVertex(this->posX, this->posY);
		for (int i=circleStar ; i<circleEnd ; i=i+stepResolutionPer){
    		ofVertex( this->posX + this->radius * sin( ofDegToRad(i)), 
						this->posY + this->radius * cos( ofDegToRad(i)) );			
			
		}
    	ofVertex( this->posX + this->radius * sin( ofDegToRad(circleEnd)), 
					this->posY + this->radius * cos( ofDegToRad(circleEnd)) );
		ofVertex(this->posX, this->posY);
	ofEndShape();
 

	//Draw PacMan eye
	this->posEyeX = posX - this->radiusEye;
	this->posEyeY = posY - this->radius/3;
	ofSetColor(color2_R, color2_G, color2_B);
	ofBeginShape();
		for (int i=0 ; i<360 ; i=i+stepResolutionPer){
			ofVertex(	this->posEyeX + this->radiusEye * sin( ofDegToRad(i)), 
						this->posEyeY + this->radiusEye * cos( ofDegToRad(i)) );
		}
		ofVertex(	this->posEyeX + this->radiusEye * sin( ofDegToRad(0)), 
					this->posEyeY + this->radiusEye * cos( ofDegToRad(0)) );
	ofEndShape();


}


// pmDrawRight Function
//*************************************************************
void PacMan::pmDrawRight(){
	

	int circleStar = 90 + this->angleMouse/2 ;
	int circleEnd = 360 + 90 - this->angleMouse/2 ;


	//Draw PacmanFill
	ofSetColor(color1_R, color1_G, color1_B);
	ofDrawBitmapString("RIGHT ", 40, 40);
    ofFill();
	ofBeginShape();

		ofVertex(this->posX, this->posY);
		for (int i=circleStar ; i<circleEnd ; i=i+stepResolutionPer){
    		ofVertex( this->posX + this->radius * sin( ofDegToRad(i)), 
						this->posY + this->radius * cos( ofDegToRad(i)) );			
			
		}
    	ofVertex( this->posX + this->radius * sin( ofDegToRad(circleEnd)), 
					this->posY + this->radius * cos( ofDegToRad(circleEnd)) );
		ofVertex(this->posX, this->posY);
	ofEndShape();
 

	//Draw PacMan eye
	this->posEyeX = posX + this->radiusEye;
	this->posEyeY = posY - this->radius/3;
	ofSetColor(color2_R, color2_G, color2_B);
	ofBeginShape();
		for (int i=0 ; i<360 ; i=i+stepResolutionPer){
			ofVertex(	this->posEyeX + this->radiusEye * sin( ofDegToRad(i)), 
						this->posEyeY + this->radiusEye * cos( ofDegToRad(i)) );
		}
		ofVertex(	this->posEyeX + this->radiusEye * sin( ofDegToRad(0)), 
					this->posEyeY + this->radiusEye * cos( ofDegToRad(0)) );
	ofEndShape();



    return;
}


// pmDrawUp Function
//*************************************************************
void PacMan::pmDrawUp(){

	//Draw PacmanFill
	ofSetColor(color1_R, color1_G, color1_B);
	ofDrawBitmapString("UP ", 40, 40);
 	int circleStar = 180 + this->angleMouse/2 ;
	int circleEnd = 360 + 180 - this->angleMouse/2 ;


	//Draw PacmanFill
	ofSetColor(color1_R, color1_G, color1_B);
	ofDrawBitmapString("DOWN ", 40, 40);
    ofFill();
	ofBeginShape();

		ofVertex(this->posX, this->posY);
		for (int i=circleStar ; i<circleEnd ; i=i+stepResolutionPer){
    		ofVertex( this->posX + this->radius * sin( ofDegToRad(i)), 
						this->posY + this->radius * cos( ofDegToRad(i)) );			
			
		}
    	ofVertex( this->posX + this->radius * sin( ofDegToRad(circleEnd)), 
					this->posY + this->radius * cos( ofDegToRad(circleEnd)) );
		ofVertex(this->posX, this->posY);
	ofEndShape();

	//Draw PacMan eye
	this->posEyeX = posX - this->radius/3;
	this->posEyeY = posY - this->radiusEye;
	ofSetColor(color2_R, color2_G, color2_B);
	ofBeginShape();
		for (int i=0 ; i<360 ; i=i+stepResolutionPer){
			ofVertex(	this->posEyeX + this->radiusEye * sin( ofDegToRad(i)), 
						this->posEyeY + this->radiusEye * cos( ofDegToRad(i)) );
		}
		ofVertex(	this->posEyeX + this->radiusEye * sin( ofDegToRad(0)), 
					this->posEyeY + this->radiusEye * cos( ofDegToRad(0)) );
	ofEndShape();


	return;
}


// pmDrawDown Function
//*************************************************************
void PacMan::pmDrawDown(){

	int circleStar = 0 + this->angleMouse/2 ;
	int circleEnd = 360 + 0 - this->angleMouse/2 ;


	//Draw PacmanFill
	ofSetColor(color1_R, color1_G, color1_B);
	ofDrawBitmapString("DOWN ", 40, 40);
    ofFill();
	ofBeginShape();

		ofVertex(this->posX, this->posY);
		for (int i=circleStar ; i<circleEnd ; i=i+stepResolutionPer){
    		ofVertex( this->posX + this->radius * sin( ofDegToRad(i)), 
						this->posY + this->radius * cos( ofDegToRad(i)) );			
			
		}
    	ofVertex( this->posX + this->radius * sin( ofDegToRad(circleEnd)), 
					this->posY + this->radius * cos( ofDegToRad(circleEnd)) );
		ofVertex(this->posX, this->posY);
	ofEndShape();

	//Draw PacMan eye
	this->posEyeX = posX + this->radius/3;
	this->posEyeY = posY - this->radiusEye;
	ofSetColor(color2_R, color2_G, color2_B);
	ofBeginShape();
		for (int i=0 ; i<360 ; i=i+stepResolutionPer){
			ofVertex(	this->posEyeX + this->radiusEye * sin( ofDegToRad(i)), 
						this->posEyeY + this->radiusEye * cos( ofDegToRad(i)) );
		}
		ofVertex(	this->posEyeX + this->radiusEye * sin( ofDegToRad(0)), 
					this->posEyeY + this->radiusEye * cos( ofDegToRad(0)) );
	ofEndShape();

}


// MoveLeft Function
//*************************************************************
void PacMan::MoveLeft(){
    this->posX = this->posX - this->speed;
	this->angleDirection=270;
	return;
}


// MoveRight Function
//*************************************************************
void PacMan::MoveRight(){
	this->posX = this->posX + this->speed;
	this->angleDirection=90;
	return;
};


// MoveUp Function
//*************************************************************
void PacMan::MoveUp(){
	this->posY = this->posY - this->speed;
	this->angleDirection=0;
	return;	
};


// MoveDown Function
//*************************************************************
void PacMan::MoveDown(){
	this->posY = this->posY + this->speed;
	this->angleDirection=180;
	return;
};