#include "playerController.h"


playerController::playerController (const char* filename, int rows, int cols, float x=0, float y=0, float w=0.5, float h=0.5){
    
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    
    texture_id = SOIL_load_OGL_texture (
     filename,
     SOIL_LOAD_AUTO,
     SOIL_CREATE_NEW_ID,
     SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
     );
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    
    this->rows = rows;
    this->cols = cols;
    curr_row = 1;
    curr_col = 1;
    complete = false;
    animating = false;
    
    
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    
    rising = false;
    movingLeft = true;
    
    xinc = 0.018;
    yinc = 0.01;
    
    jumpAmount = 1;
    duck = false;
    gravity = .003; // more descriptive than yinc, but basically yinc
}

void playerController::moveUp(float rate){
    y += rate;
    if (y > 0.99){
        y = 0.99;
    }
}
void playerController::moveDown(float rate){
    y -= rate;
    if (y - h < -0.99){
        y = -0.99 + h;
    }
}
void playerController::moveLeft(float rate){
    x -= rate;
    if (x < -0.99){
        x = -0.99;
    }
}
void playerController::moveRight(float rate){
    x += rate;
    if (x + w > 0.99){
        x = 0.99 - w;
    }
}

void playerController::jump(){
    // we don't need this anymore thanks to the power of velocity oriented programming.
}
//loop of action
void playerController::Adv(){
    y += velY;
    if (y>0){
        velY -= gravity;
    } else {
        velY = 0;
        y = 0;
        isJumpDisabled = false;
        jumps = jumpAmount; // this is for future implementations of powerups.
    }
}

void playerController::activate(){
//        y+=yinc;
    if (movingLeft){
        x -=xinc;
    }
    else {
        x +=xinc;
    }
    if (x+w > 0.99) {
        movingLeft = true;
        
    }
}

void playerController::advanceFrame(){
    if (curr_col < cols){
        curr_col++;
    }
    else {
        if (curr_row < rows){
            curr_row++;
            curr_col = 1;
        }
        else{
            curr_row = 1;
            curr_col = 1;
        }
    }
    
    if (curr_row == rows && curr_col == cols){
        complete = true;
    }
}
void playerController::reset(){
    complete = false;
}

void playerController::animate(){
    animating = true;
}

void playerController::stop(){
    animating = false;
}


void playerController::draw(){
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

playerController::~playerController(){
//    SOIL_free_image_data(filename); not sure which to free
    
}


bool playerController::contains(float mx, float my){
    return mx >= x && mx <= x+w && my <= y && my >= y - h;
}





