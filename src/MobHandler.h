
#ifndef MobHandler_hpp
#define MobHandler_hpp

#include <stdio.h>

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif




class MobHandler{

public:
    void draw();
};



#endif /* MobHandler_hpp */
