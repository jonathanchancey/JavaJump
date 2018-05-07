#include "playerController.h"


GLuint playerController::texId(const char* filename){
    GLuint texture_id = SOIL_load_OGL_texture (
                                        filename,
                                        SOIL_LOAD_AUTO,
                                        SOIL_CREATE_NEW_ID,
                                        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                                        );
    return texture_id;
}

playerController::playerController (int row, int col, float x=0, float y=0, float w=0.5, float h=0.5){
    const char* filename[2] = {"images/javaRunningBig.png","images/javaJumpingBig.png"};
    
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    
//    texture_id = SOIL_load_OGL_texture (
//     filename,
//     SOIL_LOAD_AUTO,
//     SOIL_CREATE_NEW_ID,
//     SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
//     );
    
    for (int i = 0; i < 4; i++){
        texture_id[i] = texId(filename[i]);
    }
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    
    this->rows = row;
    this->cols = col;
    curr_row = 1;
    curr_col = 1;
    complete = false;
    animating = true;
    
    
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


void playerController::advanceFrame(){
    if (!(jumps<jumpAmount)){
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
    } else {
        curr_col = 2;
        curr_row = 1;
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

bool playerController::done() {
    return complete;
}

void playerController::draw(){
    if (animating){
        
        //if java's jumps are less than the amount of jumps she should have, then she's in the air and should use her jumping animation
        if (jumps<jumpAmount){
            glBindTexture( GL_TEXTURE_2D, texture_id[1] );
            curr_row = 1; curr_col = 2;
//            rows = 1;
//            cols = 2;
        }
        else{
            glBindTexture( GL_TEXTURE_2D, texture_id[0] );
//            rows = 1;
//            cols = 2;
        }
        glEnable(GL_TEXTURE_2D);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        
        
        float xinc = 1.0/cols;
        float yinc = 1.0/rows;
        
        
        float top = 1 - yinc * (curr_row - 1);
        float bottom = 1 - yinc * curr_row;
        
        float left = xinc * (curr_col - 1);
        float right = xinc * curr_col;
        
        
        glBegin(GL_QUADS);
        
        glTexCoord2f(left, bottom);
        glVertex2f(x, y - h);
        
        glTexCoord2f(left, top);
        glVertex2f(x, y);
        
        glTexCoord2f(right, top);
        glVertex2f(x+w, y);
        
        glTexCoord2f(right, bottom);
        glVertex2f(x+w, y - h);
        
        glEnd();
        
        glDisable(GL_TEXTURE_2D);
    }
//    glBindTexture( GL_TEXTURE_2D, texture_id );
//    glEnable(GL_TEXTURE_2D);
//
//    glBegin(GL_QUADS);
//    glColor4f(1, 1, 1, 1);
//    glTexCoord2f(0, 0);
//    glVertex2f(x, y - h);
//
//    glTexCoord2f(0, 1);
//    glVertex2f(x, y);
//
//    glTexCoord2f(1, 1);
//    glVertex2f(x+w, y);
//
//    glTexCoord2f(1, 0);
//    glVertex2f(x+w, y - h);
//
//    glEnd();
//
//    glDisable(GL_TEXTURE_2D);
}

playerController::~playerController(){
//    SOIL_free_image_data(filename); not sure which to free
    
}


bool playerController::contains(float mx, float my){
    return mx >= x && mx <= x+w && my <= y && my >= y - h;
}





