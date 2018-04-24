

#ifndef EntityMob_h
#define EntityMob_h

#include <stdio.h>
#include <string>


class EntityMob{
    
protected:
    std::string name;
    std::string type;
    bool left; bool up; bool down; bool right;
    
    
    //hitbox
    float x, y, w, h;
    
    EntityMob(std::string name, std::string type, float x, float y, float w, float h){
        this->name = name;
        this->type = type;
        this->x = x; this->y = y; this->w = w; this->h = h;
    }
    
    void setName(std::string n){
        this->name = n;
    }
    void setType(std::string t){
        this->type = t;
    }
};








#endif
