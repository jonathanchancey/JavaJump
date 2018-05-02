#ifndef TexRect_h
#define TexRect_h

#include "libs.h"

#include "RgbImage.h"

class TexRect {
public:
    float x;
    float y;
    float w;
    float h;
    GLuint texture_id;
	GLuint texture_id1;
	GLuint texture_id2;


  //  TexRect (const char*, float, float, float, float);
   TexRect (const char*, const char*, const char*, int, int, float, float, float, float);
	//TexRect(const char*, const char*, const char*, float, float, float, float); // mix our ours & template, w/o rows & columns

    
    void draw();
    
    bool contains(float, float);
    
    void moveUp(float rate=0.01);
    void moveDown(float rate=0.01);
    void moveLeft(float rate=0.01);
    void moveRight(float rate=0.01);
	/* altered jump
	void moveUp(float rate=0.002); //speed of the movements
    void moveDown(float rate=0.002);
    void moveLeft(float rate=0.001);
    void moveRight(float rate=0.002);
    */
    
    void jump();
    
   // bool rising;
 //   bool movingLeft;
 	void setJavaPos(int);

	bool rising;
	bool falling;
	bool defPos;
	int javaPos;
	void setJavaState(int);
	int javaState = 0; //0 = default Java, 1 = Cape Java, 2 = Ball Java

   
   // float xinc;
   // float yinc;
};

#endif
