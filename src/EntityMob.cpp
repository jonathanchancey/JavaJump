//
//  EntityMob.cpp
//  glutapp
//
//  Created by coruscar on 4/24/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#include "EntityMob.h"


EntityMob::EntityMob(){
    this->name = " ";
    this->type = " ";
    this->imagepath = " ";
    this->x = 0; this->y = 0; this->w = 0; this->h = 0;
    
}

EntityMob::EntityMob(std::string name, std::string type, std::string imagepath, float x, float y, float w, float h){
    this->name = name;
    this->type = type;
    this->imagepath = imagepath;
    this->x = x; this->y = y; this->w = w; this->h = h;
}

void EntityMob::setName(std::string n){
    this->name = n;
}
void EntityMob::setType(std::string t){
    this->type = t;
}
void EntityMob::setImagepath(std::string imagepath){
    this->imagepath = imagepath;
}

