
#include "Enemies.h"


Enemies::Enemies(){
    //printf("creating Enemies class");
    speed = .015; // default speed
    maxSpeed = .1; // how fast these bones can go
    mobTimer = 0;
    minTimeBetwnMob = 50;
    
    bones.push_back(new Mob("images/bone.png", 0.89, 0, 0.2, 0.2, speed));
}

void Enemies::Adv(){
    mobTimer += 1;
    rTime = (rand() % 20);
    if (mobTimer > (minTimeBetwnMob + rTime)){
        addBone();
        mobTimer = 0;
    }
    for(int i = 0; i < bones.size(); i++){
        //deletes offscreen bones
        if (bones[i]->x < -1.1){
            bones.erase(bones.begin() + i-1);
        }
        //make bones move left and be dangerous
        bones[i]->activate();
    }
}
void Enemies::addBone(){
    bones.push_back(new Mob("images/bone.png", 0.99, 0, 0.2, 0.2, speed));
    if (speed < maxSpeed)
        speed += .001;
}
// spawns/activates Mobs at base(floor) + random time
//do this ^ in app


//function that iterates through all mobs and checks if java contains
bool Enemies::ultraContainment(float x, float y){
    for (int i = 0; i < bones.size(); i++){
        if (bones[i]->contains(x, y)){
            return true;
        }
    }
    return false;
}

void Enemies::draw(){
    for (int i = 0; i < bones.size(); i++){
        bones[i]->draw();
    }
}


Enemies::~Enemies(){
    bones.clear();
}

