#include "App.h"
#include "MobHandler.h"
#include "Line.h"
#include <iostream>

using namespace std;

static App* singleton;


void app_timer(int value){
//    if (singleton->game_over){
//        singleton->gameOver->advance();
//    }
//
//    if (singleton->moving){
//        singleton->ball->jump();
//        float bx = singleton->ball->x + singleton->ball->w/2;
//        float by = singleton->ball->y - singleton->ball->h + 0.1;
//        if (singleton->platform->contains(bx, by)){
//            singleton->ball->rising = true;
//            singleton->ball->yinc +=0.005;
//            singleton->ball->xinc = singleton->ball->yinc;
//            if (singleton->ball->yinc > 0.15){
//                singleton->ball->yinc = 0.15;
//            }
//        }
//
//        if (singleton->ball->y - singleton->ball->h < -0.99){
//            singleton->moving = false;
//            singleton->game_over = true;
//            singleton->gameOver->animate();
//
//        }
//    }
    if (singleton->up){
        singleton->java->moveUp(0.05);
    }
    if (singleton->down){
        singleton->java->moveDown(0.05);
    }
    if (singleton->left){
        singleton->java->moveLeft(0.05);
    }
    if (singleton->right){
        singleton->java->moveRight(0.05);
    }
//
    if (singleton->game_over){
        singleton->redraw();
        glutTimerFunc(100, app_timer, value);
    }
    else{
        if (singleton->up || singleton->down || singleton->left || singleton->right || singleton->moving && !singleton->game_over){
            singleton->redraw();
            glutTimerFunc(16, app_timer, value);
        }
    }
//
//
}


App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    
    singleton = this;
    mx = 0.0;
    my = 0.0;
	
	
	java = new TexRect("images/defJava.png","images/javaCape.png","images/javaBall.png", 6, 6, -.85, -.295, 0.3, 0.3);
	//painting = new TexRect("images/defJava.png", "images/javaCape.png", "images/javaBall.png", -.85, -.295, 0.3, 0.3);
	line1 = new Line(-1, -.8, 1, -.8);
	// ^ bottom line
	//keep the X's numbers at .9
	line2 = new Line(-.9, .8, .9, .8);
	// ^ top line
    
	/*
    background = new TexRect("images/sky.png", -1, 1, 2, 2);
    ball = new TexRect("images/mushroom.png", 0, 0.67, 0.2, 0.2);

    platform = new TexRect("images/board.png", 0, -0.7, 0.6, 0.2);
    
    gameOver = new AnimatedRect("images/game_over.png", 7, 1, -1.0, 0.8, 2, 1.2);
	*/
    
    up = down = left = right = false;
    
    moving = false; //true in template
    game_over = false;
    
    app_timer(1);

}

void App::specialKeyPress(int key){
   if (!game_over){
        if (key == 100){
            left = true;
        }
        if (key == 101){
            up = true;
        }
        if (key == 102){
            right = true;
        }
        if (key == 103){
            down = true;
        }
		move(1);
    }
}

void App::specialKeyUp(int key){
    if (key == 100) {
        left = false;
    }
    if (key == 101) {
        up = false;
    }
    if (key == 102) {
        right = false;
    }
    if (key == 103) {
        down = false;
    }
}

void App::draw() {

    // Clear the screen
   // glClear(GL_COLOR_BUFFER_BIT); from template
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    
    // Set background color to white
    glClearColor(255, 255, 255, 1.0);    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	    // Set Color
   // glColor3d(1.0, 1.0, 1.0); From Original Code
    /*
    background->draw();
    platform->draw();
    ball->draw();
    gameOver->draw();
	*/
	painting->draw();
   
    mobHandlTest->draw();
	line1->draw();
	line2->draw();
    
	glDisable(GL_TEXTURE_2D);

    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}

void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;

}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;

}

void App::idle(){
	    if (moving){
       // painting->jump();
        redraw();
    }
	moving = !moving;
}



void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        /*
        delete ball;
        delete platform;
        delete gameOver;
        delete background;
        delete this;
		*/
		delete painting;
        
        exit(0);
    }
    
    if (key == ' '){
		/*
        ball->x = 0;
        ball->y = 0.67;
        ball->yinc = 0.01;
        ball->xinc = 0.01;
        ball->rising = false;
        game_over = false;
        gameOver->stop();
        moving = true;
		*/
		moving = !moving;
    }
}
