#ifndef TexRect_h
#define TexRect_h

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include "RgbImage.h"

class TexRect {
    float x;
    float y;
    float w;
    float h;
    GLuint texture_id;
	GLuint texture_id1;
	GLuint texture_id2;

public:
    TexRect (const char*, const char*, const char*, int, int, float, float, float, float);
    
    void draw();
    
    bool contains(float, float);
    void moveUp(float rate=0.002); //speed of the movements
    void moveDown(float rate=0.002);
    void moveLeft(float rate=0.001);
    void moveRight(float rate=0.002);
    
    
    void jump();
    
	void setJavaPos(int);

	bool rising;
	bool falling;
	bool defPos;
	int javaPos;
	void setJavaState(int);
	int javaState = 0; //0 = default Java, 1 = Cape Java, 2 = Ball Java


};

#endif
