#include "TexRect.h"
#include <iostream>
#include "App.h"

using namespace std;




TexRect::TexRect (const char* filename,const char* filename1,const char* filename2, int rows, int cols, float x=0, float y=0, float w=0.5, float h=0.5){
					//name of bitmap, rows, columns, x in the world, y in the world, width in the world, height in the world
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    
    
    RgbImage theTex( filename ); //default java
    
    glGenTextures( 1, &texture_id );
    glBindTexture( GL_TEXTURE_2D, texture_id );
    
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, theTex.GetNumCols(), theTex.GetNumRows(),
                      GL_RGB, GL_UNSIGNED_BYTE, theTex.ImageData() );
    //this->texture_map_id = texture_id;

	RgbImage theTex1(filename1); //cape java

	glGenTextures(1, &texture_id1);
	glBindTexture(GL_TEXTURE_2D, texture_id1);

	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, theTex1.GetNumCols(), theTex1.GetNumRows(),
		GL_RGB, GL_UNSIGNED_BYTE, theTex1.ImageData());

	RgbImage theTex2(filename2); //ball java

	glGenTextures(1, &texture_id2);
	glBindTexture(GL_TEXTURE_2D, texture_id2);

	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, theTex2.GetNumCols(), theTex2.GetNumRows(),
		GL_RGB, GL_UNSIGNED_BYTE, theTex2.ImageData());
    
    
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    
	defPos = true;
	rising = false;
	falling = false;

}


void TexRect::moveUp(float rate){

   if (y > .75) {
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
    x -= rate;
}
void TexRect::moveRight(float rate){
    x += rate;
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

// Jump no longer used
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

	






void TexRect::draw(){

	if (javaState == 0) { //default java

		glBindTexture(GL_TEXTURE_2D, texture_id);
		glEnable(GL_TEXTURE_2D);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);


		glBegin(GL_QUADS);

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




