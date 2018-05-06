//
//  rand.h
//  glutapp
//
//  Created by coruscar on 5/5/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#ifndef rand_hpp
#define rand_hpp

#include <stdio.h>
#include <random>
#include "rand.h"

class RandomNum{
    
    int minNum;
    int maxNum;
    RandomNum();
    RandomNum(int min, int max);
    int genRandom();
    int genRandom(int minimum, int maximum);
    
    int getMinNum();
    int getMaxNum();
    
    int randomInt(int exclusiveMax);
    
    int randomInt(int min, int max);
    
    bool randomBool();
    
    int rollDie(int num, int die);
};

#endif /* rand_hpp */
