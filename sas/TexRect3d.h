#ifndef TexRect3d_h
#define TexRect3d_h

#include "libs.h"

class TexRect3d {
public:
    float x;
    float y;
    float w;
    float h;
    GLuint texture_id;


    TexRect3d (const char*, float, float, float, float);
    ~TexRect3d();
    
    void draw(float);
    
    bool contains(float, float);
    
    void moveUp(float rate=0.01);
    void moveDown(float rate=0.01);
    void moveLeft(float rate=0.01);
    void moveRight(float rate=0.01);
    
    void jump();
    void Adv();
    void activate();
    
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
};

#endif
