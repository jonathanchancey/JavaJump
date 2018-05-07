#include "App.h"

static App* singleton;
static Enemies* secondton;

int gameTick = 0;
void app_timer(int value){
    gameTick++;
    if (singleton->game_over){
        singleton->gameOver->advance();
    }
    if (singleton->java->animating && (gameTick % 8 == 1)){
//        printf("value = \n",gameTick);
        singleton->java->advanceFrame();
    }
    
    if (singleton->moving){ // if gave is still going
        singleton->java->Adv();
//        singleton->java->animate();
        secondton->Adv(); // allows java to move, this is her tick loop thing
        if (secondton->ultraContainment(singleton->java->x+singleton->java->w/2, singleton->java->y-singleton->java->h/2)){ // checks if java is touching enemies
            singleton->moving = false;
            singleton->game_over = true;
            singleton->gameOver->animate();
        }
    }
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
    
    if (singleton->game_over){
        singleton->redraw();
        glutTimerFunc(100, app_timer, value);
    }
    else{
        // everything below here allows the game to progress, in terms of drawing itself and calling the next tick
        if (singleton->up || singleton->down || singleton->left || singleton->right || singleton->moving && !singleton->game_over){
            singleton->redraw();
            glutTimerFunc(16, app_timer, value);
        }
    }
    
    
}

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    secondton = new Enemies();
    singleton = this;
    mx = 0.0;
    my = 0.0;
//    gameTick = 0;
    
    background = new TexRect("images/sky.png", -1, 1, 2, 2);
//    secondton->addBone();
    
    ball = new TexRect("images/bone.png", 0.99, 0, 0.2, 0.2);

    java = new playerController("images/javaRunningBig.png", 1, 2, -.75, 0, 0.4, 0.3);
    
    gameOver = new AnimatedRect("images/gameOverJavaWobble.png", 8, 1, -1.0, 0.8, 2, 1.2);
    
    up = down = left = right = false;
    
    moving = true;
    game_over = false;
    
    app_timer(1);

}

void App::specialKeyPress(int key){
    if (!game_over){
        if (key == 100){
            //left = true;
        }
        if (key == 101){
            if (java->jumps > 0 && !java->isJumpDisabled){
                java->gravity = .003;
                java->jumps -= 1;
                java->velY = .06;
            }
            //up = true;
        }
        if (key == 102){
            //right = true;
        }
        if (key == 103){
            java->velY -= .015;
            if (java->y <= 0){
                java->duck = true;
            }
            //down = true;
        }
    }
}

void App::specialKeyUp(int key){
    if (key == 100) {
        left = false;
    }
    if (key == 101) {
        java->gravity = .006;
        if (java->jumps == 0){
            java->isJumpDisabled = 1;
        }
        up = false;
    }
    if (key == 102) {
        right = false;
    }
    if (key == 103) {
        down = false;
        if (java->y <= 0){
            java->duck = false;
        }
    }
}

void App::draw() {

    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Set background color to a disgusting pink
    glClearColor(1.0, .5, 0.5, 1.0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    background->draw();
    secondton->draw();
    java->draw();
    ball->draw();
    gameOver->draw();
    
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

}

void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        
        delete ball;
        delete java;
        delete gameOver;
        delete background;
        delete this;
        
        delete secondton;
        
        exit(0);
    }
    if (key == 'r'){ // TODO delete the current bones
        
        game_over = false;
        gameOver->stop();
        moving = true;
        secondton->reset();
        
    }
    if (key == 'a'){
        secondton->addBone();
    }
    
    if (key == ' '){
//        secondton->addBone();
//        if (java->jumps > 0){
//            java->jumps -= 1;
//            java->velY = .06;
//        }
//        ball->x = 0;
//        ball->y = 0.67;
//        ball->yinc = 0.01;
//        ball->xinc = 0.01;
//        ball->rising = false;
//        game_over = false;
//        gameOver->stop();
//        moving = true;
    }
}
void App::keyUp(unsigned char key) {
//    if (key == ' '){
//        java->gravity = .006;
//    }
}
