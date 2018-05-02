#ifndef Enemy_h
#define Enemy_h

#include "GlutApp.h"
//#include "libs.h"

class Mob {
public:
    float x;
    float y;
    float w;
    float h;
    GLuint texture_id;


    Mob (const char*, float, float, float, float, float);
    
    void draw();
    
    bool contains(float, float);
    
    void moveUp(float rate=0.01);
    void moveDown(float rate=0.01);
    void moveLeft(float rate=0.01);
    void moveRight(float rate=0.01);
    
    void jump();
    void java();
    void activate();
    
    bool rising;
    bool movingLeft;
   
    float xinc;
    float yinc;
    
    
    float velY;
    float gravity;
    
    int jumpAmount;
    int jumps;
};

#endif
