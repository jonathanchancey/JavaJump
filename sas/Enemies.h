
#ifndef Enemies_hpp
#define Enemies_hpp

#include <stdio.h>
#include "libs.h"
#include "Mob.h"
#include <vector>


class Enemies {
public:
    Enemies();
    float speed;
    std::vector<Mob*> bones;
    void Adv();
    void addBone();
    bool ultraContainment(float, float);
    
};

#endif /* Enemies_hpp */
