#ifndef TexRect_h
#define TexRect_h

#include "libs.h"

class TexRect {
public:
    float x;
    float y;
    float w;
    float h;
    GLuint texture_id;


    TexRect (const char*, float, float, float, float);
    ~TexRect();
    
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
