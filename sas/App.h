#ifndef App_hpp
#define App_hpp

#include "GlutApp.h"
#include "TexRect.h"
#include "AnimatedRect.h"
#include "Enemies.h"
#include "playerController.h"
#include <vector>
#include <cstdlib>
#include "highScore.h"


class App: public GlutApp {
    // Maintain app state here
    float mx;
    float my;
public:
    // Constructor, to initialize state
    App(const char* label, int x, int y, int w, int h);

    // These are the events we want to handle
    void draw();
    void keyPress(unsigned char key);
    void PrintText(int x, int y, std::string String);
    void keyUp(unsigned char key);
    void mouseDown(float x, float y);
    void mouseDrag(float x, float y);

    void specialKeyPress(int key);

    void specialKeyUp(int key);


    void idle();

    TexRect* ball;

    playerController* java;

    TexRect* background;

    TexRect* mainMenu;

    AnimatedRect* gameOver;

    highScore* hiScore;



//    int gameTick;

    bool up;
    bool down;
    bool left;
    bool right;

    bool moving;
    bool game_over;
    bool main_menu = true;          //enables the main menu to be shown
    bool inGame = false;
    int enterPress;

};

#endif
