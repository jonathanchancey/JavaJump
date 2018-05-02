#ifndef AnimatedRect_h
#define AnimatedRect_h

#include "libs.h"


class AnimatedRect {
    float x;
    float y;
    float w;
    float h;
    GLuint texture_map_id;
    
    int rows;
    int cols;
    
    int curr_row;
    int curr_col;
    
    bool complete;
    bool animating;
public:
    AnimatedRect (const char*, int, int, float, float, float, float);
    
    bool done();
    
    void draw();
    
    void advance();
    
    void incY();
    
    void reset();
    
    void animate();
    
    void stop();
};

#endif
