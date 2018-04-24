

#ifndef EntityMob_h
#define EntityMob_h

#include <stdio.h>
#include <string>


class EntityMob{
    
protected:
    std::string name;
    std::string type;
    std::string image;
    bool left; bool up; bool down; bool right;
    
    
    //hitbox
    float x, y, w, h;
    
    EntityMob();
    
    EntityMob(std::string name, std::string type, std::string image, float x, float y, float w, float h);
    
    virtual void setName(std::string n);
    virtual void setType(std::string t);
};








#endif
