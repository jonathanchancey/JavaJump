

#ifndef EntityMob_h
#define EntityMob_h

#include <stdio.h>
#include <string>


class EntityMob{
    
protected:
    std::string name;
    int damage;
    
    
    //hitbox
    float x, y, w, h;
    
    EntityMob(std::string name, int damage, float x, float y, float w, float h){
        this->name = name;
        this->damage = damage;
        this->x = x; this->y = y; this->w = w; this->h = h;
    }
    
    
};








#endif
