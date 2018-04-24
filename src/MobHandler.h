
#ifndef MobHandler_hpp
#define MobHandler_hpp

#include <stdio.h>
#include <vector>
#include "EntityMob.h"
#include "tRMob.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif




class MobHandler{
    
protected:
//    std::vector<EntityMob> loadedMobs;
    std::vector<tRMob> mobs;
    
    
public:
    void draw();
    
    
    
};



#endif /* MobHandler_hpp */
