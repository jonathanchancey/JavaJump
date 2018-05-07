#ifndef playerController_h
#define playerController_h

#include "libs.h"

class playerController {
public:
    float x;
    float y;
    float w;
    float h;
    GLuint texture_id;


    playerController (const char*, int, int, float, float, float, float);
    ~playerController();
    
    void draw();
    
    bool contains(float, float);
    
    void moveUp(float rate=0.01);
    void moveDown(float rate=0.01);
    void moveLeft(float rate=0.01);
    void moveRight(float rate=0.01);
    
    void jump();
    void Adv();
    
    bool rising;
    bool movingLeft;
   
    float xinc;
    float yinc;
    
    
    float velY;
    float gravity;
    
    int jumpAmount;
    int jumps;
    
    bool duck;
    bool isJumpDisabled;
    
    int rows, cols, curr_row, curr_col;
    bool complete, animating;
    
    void advanceFrame();
    void reset();
    void animate();
    void stop();
    bool done();
};

#endif

