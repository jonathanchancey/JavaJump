
#include "MobHandler.h"



//spawns mobs off screen right that are moving left

//EntityMob * c1 = new EntityMob("boy1","cloud",);
//
//EntityMob::EntityMob(std::string name, std::string type, std::string imagepath, float x, float y, float w, float h){
//

//draws a white square as a test
void MobHandler::draw(){
    //J
    glPolygonMode(GL_FRONT, GL_FILL);
    glColor3f(1.0, 0.0 ,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-.9, .8);
    glVertex2f(-.3, .8);
    glVertex2f(-.3, .7);
    glVertex2f(-.9, .7);
    glEnd();

}

