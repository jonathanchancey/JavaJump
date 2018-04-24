#ifndef tRMob_h
#define tRMob_h

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include "RgbImage.h"

class tRMob {
    float x;
    float y;
    float w;
    float h;
    GLuint texture_id;
    
public:
    tRMob (const char*, int, int, float, float, float, float);
    
    void draw();
    
    bool contains(float, float);
    //    void moveUp(float rate=0.01);
    //    void moveDown(float rate=0.01);
    //    void moveLeft(float rate=0.01);
    //    void moveRight(float rate=0.01);
    
    
    void jump();
    
    void setJavaPos(int);
    
    bool rising;
    bool falling;
    bool defPos;
    int javaPos;
    
    
};

#endif

