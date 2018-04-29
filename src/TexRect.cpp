#include "TexRect.h"
#include <iostream>
#include "App.h"

using namespace std;





//TexRect::TexRect (const char* filename, float x=0, float y=0, float w=0.5, float h=0.5){
TexRect::TexRect (const char* filename,const char* filename1,const char* filename2, int rows, int cols, float x=0, float y=0, float w=0.5, float h=0.5){
//TexRect::TexRect(const char* filename, const char* filename1, const char* filename2, float x = 0, float y = 0, float w = 0.5, float h = 0.5) {

    
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    
    texture_id = SOIL_load_OGL_texture (
     filename,
     SOIL_LOAD_AUTO,
     SOIL_CREATE_NEW_ID,
     SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
     );
	 
	texture_id1 = SOIL_load_OGL_texture (
     filename1,
     SOIL_LOAD_AUTO,
     SOIL_CREATE_NEW_ID,
     SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
     );
	 
	texture_id2 = SOIL_load_OGL_texture (
     filename2,
     SOIL_LOAD_AUTO,
     SOIL_CREATE_NEW_ID,
     SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
     );
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    /*
    rising = false;
    movingLeft = true;
	*/
	defPos = true;
	rising = false;
	falling = false;
    
   // xinc = 0.01;
    //yinc = 0.01;
}

void TexRect::moveUp(float rate){

   if (y > .755) {
	   y += 0;
   }
   else {
	   y += rate;
   }
}
void TexRect::moveDown(float rate){
	if ((y - h) < -.79499995) {
		y += 0;
	}
	else {
		y -= rate;
	}
   
}
void TexRect::moveLeft(float rate){
	if (x < -.98){
		x += 0;
	}
	else {
		x -= rate;
	}
}
void TexRect::moveRight(float rate){
	if (x > .65) {
		x += 0;
	}
	else {
		x += rate;
	}
}

//This was for moving with arrow keys


void TexRect::setJavaPos(int value) {
	javaPos = value;
	if (javaPos == 0) {
		defPos = true;
	}
	if (javaPos == 1) {
		//cout << "Spacebar has been pressed" << endl;
		rising = true;

	}
	if (javaPos == 2) {
		falling = true;

	}
}

void TexRect::setJavaState(int power) {

}
/*
void TexRect::jump(){
    if(rising){
        y+=yinc;
        if (movingLeft){
            x -=xinc;
        }
        else {
            x +=xinc;
        }
    }
    else {
        y-=yinc;
        if (movingLeft){
            x -=xinc;
        }
        else{
            x +=xinc;
        }
    }
    
    if (y > 0.99){
        rising = false;
    }
    if ((y-h) < -0.99){
        rising = true;
    }
    if (x < -0.99) {
        movingLeft = false;
       
    }
    if (x+w > 0.99) {
        movingLeft = true;
        
    }
}
*/
/* OUR Jump
void TexRect::jump() {
	if (rising) {
		y += 0.0015;

	}
	if(falling) {
		y -= 0.0015;


	}

	if (y > 0) {
		rising = false;
		falling = true;
	}
	if ((y - h) < -1) { //-1 bottom of screen, 0 is middle
		rising = false;
		falling = false;
		defPos = true;

	}
}
*/


/*
void TexRect::draw(){
    glBindTexture( GL_TEXTURE_2D, texture_id );
    glEnable(GL_TEXTURE_2D);
    
    glBegin(GL_QUADS);
    glColor4f(1, 1, 1, 1);
    glTexCoord2f(0, 0);
    glVertex2f(x, y - h);
    
    glTexCoord2f(0, 1);
    glVertex2f(x, y);
    
    glTexCoord2f(1, 1);
    glVertex2f(x+w, y);
    
    glTexCoord2f(1, 0);
    glVertex2f(x+w, y - h);
    
    glEnd();
    
    glDisable(GL_TEXTURE_2D);
}
*/
void TexRect::draw(){

	if (javaState == 0) { //default java

		glBindTexture(GL_TEXTURE_2D, texture_id);
		glEnable(GL_TEXTURE_2D);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);


		glBegin(GL_QUADS);

		glColor4f(1, 1, 1, 1); // from template

		glTexCoord2f(0, 0);
		glVertex2f(x, y - h);

		glTexCoord2f(0, 1);
		glVertex2f(x, y);

		glTexCoord2f(1, 1);
		glVertex2f(x + w, y);

		glTexCoord2f(1, 0);
		glVertex2f(x + w, y - h);

		glEnd();

		glDisable(GL_TEXTURE_2D);
	}
	if (javaState == 1) { //java cape

		glBindTexture(GL_TEXTURE_2D, texture_id1);
		glEnable(GL_TEXTURE_2D);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);


		glBegin(GL_QUADS);

		glColor4f(1, 1, 1, 1); // from template


		glTexCoord2f(0, 0);
		glVertex2f(x, y - h);

		glTexCoord2f(0, 1);
		glVertex2f(x, y);

		glTexCoord2f(1, 1);
		glVertex2f(x + w, y);

		glTexCoord2f(1, 0);
		glVertex2f(x + w, y - h);

		glEnd();

		glDisable(GL_TEXTURE_2D);

	}

	if (javaState == 2) { //java ball

		glBindTexture(GL_TEXTURE_2D, texture_id2);
		glEnable(GL_TEXTURE_2D);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);


		glBegin(GL_QUADS);

		glColor4f(1, 1, 1, 1); // from template


		glTexCoord2f(0, 0);
		glVertex2f(x, y - h);

		glTexCoord2f(0, 1);
		glVertex2f(x, y);

		glTexCoord2f(1, 1);
		glVertex2f(x + w, y);

		glTexCoord2f(1, 0);
		glVertex2f(x + w, y - h);

		glEnd();

		glDisable(GL_TEXTURE_2D);
	}
    
}


bool TexRect::contains(float mx, float my){
    return mx >= x && mx <= x+w && my <= y && my >= y - h;
}




