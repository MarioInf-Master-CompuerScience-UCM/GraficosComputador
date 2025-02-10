#include "game_scene.h" 
 

        //SetupScene function
    //*****************************************************
    void Game_scene::setupScene(){

    }


        //DrawScene function
    //*****************************************************
    void Game_scene::drawScene(){

    }


        //UpdateScene function
    //*****************************************************
    void Game_scene::updateScene(){
        
        if(ofGetKeyPressed('d') ){
            this->player.moveRight();
        }
        if(ofGetKeyPressed('a') ){
            this->player.moveLeft();
        }


    }