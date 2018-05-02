
#include "Enemies.h"


Enemies::Enemies(){
    //printf("creating Enemies class");
    speed = .010; // default speed
    
    bones.push_back(new Mob("images/bone.png", 0.99, 0, 0.2, 0.2, speed));
}

void Enemies::Adv(){
    for(int i = 0; i < bones.size(); i++){
        //deletes offscreen bones
        if (bones[i]->x < .99){
            bones.erase(bones.begin() + i-1);
        }
        //make bones move left and be dangerous
        bones[i]->activate();
    }
}
void Enemies::addBone(){
    bones.push_back(new Mob("images/bone.png", 0.99, 0, 0.2, 0.2, speed));
    speed += .001;
}
// spawns/activates Mobs at base(floor) + random time

bool Enemies::ultraContainment(float x, float y){
    for (int i = 0; i < bones.size();i++){
        if (bones[i]->contains(x, y)){
            return false;
        }
    }
    return true;
}

//function that iterates through all mobs and checks if java contains

