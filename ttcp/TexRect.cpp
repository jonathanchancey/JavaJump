#include "TexRect.h"


TexRect::TexRect (const char* filename, float x=0, float y=0, float w=0.5, float h=0.5){

	int image_width = 0;
	int image_height = 0;

	unsigned char* image = SOIL_load_image(filename, &image_width, &image_height, NULL, SOIL_LOAD_RGBA);
    

	GLuint texture0;
	glGenTextures(1, &texture0);
	glBindTexture(GL_TEXTURE_2D, texture0);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	if (image) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

		//glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "ERROR::TEXTURE_LOADING_FAILED" << "\n";
	}

	//glActiveTexture(0);
	glBindTexture(GL_TEXTURE_2D, 0);
	SOIL_free_image_data(image);




    glClearColor (0.0, 0.0, 0.0, 0.0);
    //glShadeModel(GL_FLAT);
    //glEnable(GL_DEPTH_TEST);
    //
    //texture_id = SOIL_load_OGL_texture (
    // filename,
    // SOIL_LOAD_AUTO,
    // SOIL_CREATE_NEW_ID,
    // SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    // );
    //
    //glEnable(GL_BLEND);
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    //
    //glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    
    rising = false;
    movingLeft = true;
    
    xinc = 0.01;
    yinc = 0.01;
}

void TexRect::moveUp(float rate){
    y += rate;
}
void TexRect::moveDown(float rate){
    y -= rate;
}
void TexRect::moveLeft(float rate){
    x -= rate;
    if (x < -0.99){
        x = -0.99;
    }
}
void TexRect::moveRight(float rate){
    x += rate;
    if (x + w > 0.99){
        x = 0.99 - w;
    }
}

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


bool TexRect::contains(float mx, float my){
    return mx >= x && mx <= x+w && my <= y && my >= y - h;
}




