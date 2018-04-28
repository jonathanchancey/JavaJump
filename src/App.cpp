#include "App.h"
#include "MobHandler.h"
#include "Line.h"
#include <iostream>

using namespace std;

static App* singleton;


void move(int value){
    if (singleton->up){
        singleton->painting->moveUp(0.05);
    }
    if (singleton->down){
        singleton->painting->moveDown(0.05);
    }
    if (singleton->left){
        singleton->painting->moveLeft(0.05);
    }
    if (singleton->right){
        singleton->painting->moveRight(0.05);
    }
    if (singleton->up || singleton->down || singleton->left || singleton->right){
        singleton->redraw();
        glutTimerFunc(32, move, value);
    }
}




App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    
    singleton = this;
    mx = 0.0;
    my = 0.0;
    
    
    
    //background = new TexRect("wall.bmp", -1, 1, 2, 2);//-.5
    painting = new TexRect("defJava.bmp","javaCape.bmp","javaBall.bmp", 6, 6, -.85, -.295, 0.3, 0.3);
	line1 = new Line(-.9, -.8, .9, -.8);
	// ^ bottom line
	//keep the X's numbers at .9
	line2 = new Line(-.9, .8, .9, .8);
	// ^ top line
	

    up = down = left = right = false;
    
    
    moving = false;

}



void App::specialKeyPress(int key){
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
//formerly void App::specialKeyUp(int key){
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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(255, 255, 255, 1.0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Set Color
    glColor3d(1.0, 1.0, 1.0);


    
    painting->draw();
   
    d->draw();
	line1->draw();
	line2->draw();

	
	

	
		
    
    
    
    //background->draw();
    
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

    // Redraw the scene
   // redraw();
}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    // Redraw the scene
    //redraw();
}

void App::idle(){
    if (moving){
       // painting->jump();
        redraw();
    }
	moving = !moving;
}

bool App::setMoving(bool value) {
	moving = value;

	return moving;

} 



void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        
        //delete background;
        delete painting;
        
        exit(0);
    }
    
    if (key == ' '){
		//painting->setJavaPos(1);
        moving = !moving;
    }


    
}

