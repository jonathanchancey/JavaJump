
#ifndef MobHandler_hpp
#define MobHandler_hpp

#include <stdio.h>
#include <vector>
#include "EntityMob.h"
#include "tRMob.h"

#include "libs.h"



class MobHandler{
    
protected:
//    std::vector<EntityMob> loadedMobs;
    std::vector<tRMob> mobs;
    
    
public:
    void draw();
    
    
    
};



#endif /* MobHandler_hpp */
