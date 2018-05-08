//
//  PrintText.hpp
//  glutapp
//
//  Created by Tlaloc Barajas on 5/8/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#ifndef PrintText_hpp
#define PrintText_hpp

#include <stdio.h>
#include "libs.h"
#include "highScore.h"
#include <string>     // std::string, std::to_string

class PrintText {
public:
    float x;
    float y;
    int WindowWidth = 600;
    int WindowHeight = 600;
    GLuint texture_id;
    ~PrintText();
    
    PrintText(int x, int y, std::string String);
    void display(int, std::string String);
    void displayFinal(int);

};

#endif /* PrintText_hpp */
