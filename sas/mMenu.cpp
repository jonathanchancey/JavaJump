#include "mMenu.h"

static mMenu* singleton;

void app_timer(int value){
    
    if (singleton->moving){
        
        if (singleton->ball->y - singleton->ball->h < -0.99){
            singleton->moving = false;
            singleton->game_over = true;
            singleton->gameOver->animate();
        }
    }
    
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
    
    
}

mMenu::mMenu(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    
    singleton = this;
    mx = 0.0;
    my = 0.0;
    
    main_menu = new TexRect("images/main_menu.png", -1, 1, 2, 2);
    moving = true;
    game_over = false;
    
    app_timer(1);
    
}

void mMenu::specialKeyPress(int key){
    if (!game_over){
        if (key == 100){
            left = true;
        }
        if (key == 101){
            //up = true;
        }
        if (key == 102){
            right = true;
        }
        if (key == 103){
            //down = true;
        }
    }
}

void mMenu::specialKeyUp(int key){
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

void mMenu::draw() {
    
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(0.0, 0.0, 1.0, 1.0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    background->draw();
    platform->draw();
    ball->draw();
    gameOver->draw();
    
    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}
//
//void mMenu::mouseDown(float x, float y){
//    // Update app state
//    mx = x;
//    my = y;
//
//}
//
//void mMenu::mouseDrag(float x, float y){
//    // Update app state
//    mx = x;
//    my = y;
//
//}

void mMenu::idle(){
    
}

void mMenu::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        delete main_menu;
        delete this;
        
        exit(0);
    }
    
    if (key == ' '){
//        ball->x = 0;
//        ball->y = 0.67;
//        ball->yinc = 0.01;
//        ball->xinc = 0.01;
//        ball->rising = false;
        game_over = false;
//        gameOver->stop();
        moving = true;
    }
}



