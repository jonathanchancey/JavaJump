
#include "Enemies.h"


Enemies::Enemies(){
    //printf("creating Enemies class");
    speed = .02; // default speed // global speed
    maxSpeed = .15; // how fast these bones can go
    mobTimer = 0;
    minTimeBetwnMob = 42;
    addBone();
    bgCounter = -2;
    firstRun = true;
    displayFirstBG = true;
    //bg = new TexRect3d("images/groundThinHalfBig.png", -1.0, -.090, 10, .3);
    bgs.push_back(new TexRect3d("images/groundThinHalfBig.png", -1.0, -.090, 10, .3));
    bgs.push_back(new TexRect3d("images/groundThinHalfBig.png", 9.0, -.090, 10, .3));
    
}
void Enemies::reset(){
    speed = .02;
    mobTimer = 0;
    bones.clear();
    addBone();
}

void Enemies::Adv(){
    mobTimer += 1;
    bgCounter += speed;
    
    
//    if (firstRun){
//        if (bgCounter > 10){
//            printf("FirstRun\n");
//            displayFirstBG = !displayFirstBG;
//            bgs[1]->x = 1;
//            bgCounter = -2;
//            firstRun = false;
//        }
//    }
//    else {
        if (bgCounter > 8 && displayFirstBG){
            printf("dfBG true\n");
            bgs[0]->x = 1;
            bgCounter = -2;
            displayFirstBG = !displayFirstBG;
        }
        if (bgCounter > 8 && !displayFirstBG){
            printf("dfBG false\n");
            bgs[1]->x = 1;
            bgCounter = -2;
            displayFirstBG = !displayFirstBG;
        }
//    }
    
//    bg->moveLeft(speed);
//    bg->draw(1);
    
    
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
//    std::uniform_int_distribution<> distr(0, 40); // define the range
    std::uniform_int_distribution<int> uid(0,40); // random dice
    rTime = uid(eng); // use rng as a generator
    
    

//    rTime = (rand() % 100);
    
    if (mobTimer > (minTimeBetwnMob + rTime)){
//        printf("rTime = %d\n",rTime);
        
        if (mobTimer % 3 == 0){
            addBone();
        } else if (mobTimer % 3 == 1){
            addLongBone();
        } else {
            addThiccBone();
        }
        mobTimer = 0;
    }
    for(int i = 0; i < bgs.size(); i++){
//        if(bgs[i]->x < 10){
//            bgs.erase(bgs.begin()+i-1);
//        }
        bgs[i]->moveLeft(speed);
        bgs[i]->draw(1);
    }
    for(int i = 0; i < bones.size(); i++){
        bones[i]->setSpeed(speed);
        //deletes offscreen bones
        if (bones[i]->x < -1.5){
            bones.erase(bones.begin() + i-1);
        }
        //make bones move left and be dangerous
        bones[i]->activate();
    }
}
void Enemies::addBone(){
    bones.push_back(new Mob("images/moanBone.png", 0.99, 0, 0.3, 0.3, speed));
    if (speed < maxSpeed)
        speed += .001;
}

void Enemies::addLongBone(){
    bones.push_back(new Mob("images/longBone.png", 0.99, 0, 0.3, 0.3, speed));
    if (speed < maxSpeed)
        speed += .001;
}

void Enemies::addThiccBone(){
    bones.push_back(new Mob("images/thiccBone.png", 0.99, 0, 0.3, 0.3, speed));
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
//    bg->draw(1);

    for (int i = 0; i < bgs.size(); i++){
        bgs[i]->draw(1);
    }
    for (int i = 0; i < bones.size(); i++){
        bones[i]->draw();
    }
}


Enemies::~Enemies(){
    bones.clear();
}

