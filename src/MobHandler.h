
#ifndef MobHandler_hpp
#define MobHandler_hpp

#include <stdio.h>
#include <vector>
#include "Cloud.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif




class MobHandler{
    
protected:
    std::vector<EntityMob> loadedMobs;
    
    
public:
    void draw();
    
    Cloud * c1;
    
    
};



#endif /* MobHandler_hpp */
