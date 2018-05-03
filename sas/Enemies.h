
#ifndef Enemies_hpp
#define Enemies_hpp

#include <stdio.h>
#include "libs.h"
#include "Mob.h"
#include <vector>
#include <cstdlib>


class Enemies {
public:
    Enemies();
    float speed;
    float maxSpeed;
    int mobTimer;
    int minTimeBetwnMob;
    int rTime;
    
    std::vector<Mob*> bones;
    void Adv();
    void addBone();
    bool ultraContainment(float, float);
    void draw();
    ~Enemies();
    
};

#endif /* Enemies_hpp */
