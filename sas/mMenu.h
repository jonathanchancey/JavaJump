

#ifndef mMenu_hpp
#define mMenu_hpp

#include <stdio.h>
#include "TexRect.h"
#include <iostream>
#include "GlutApp.h"
//#include "libs.h"

//#include "GlutApp.h"
//#include "TexRect.h"
//#include "AnimatedRect.h"

class mMenu: public GlutApp {
    // Maintain app state here
    float mx;
    float my;
public:
    // Constructor, to initialize state
    mMenu(const char* label, int x, int y, int w, int h);
    
    // These are the events we want to handle
    void draw();
    void keyPress(unsigned char key);
    void mouseDown(float x, float y);
    void mouseDrag(float x, float y);
    
    void specialKeyPress(int key);
    
    void specialKeyUp(int key);
    
    void idle();
    
    TexRect* main_menu;

    
    bool up;
    bool down;
    bool left;
    bool right;
    
    bool moving;
    bool game_over;
    
    
};


#endif /* mMenu_hpp */


