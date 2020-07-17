#include "main.h"

#ifndef FIREBEAMS_H
#define FIREBEAMS_H

class Firebeams{
public:
    Firebeams() {}
    Firebeams(float x,float y,float z,color_t color);
    void draw(glm::mat4 VP);
    void draw2(glm::mat4 VP);
    void tick(double dt,int range);
    void tick2(double dt,int range);
    void set_position(float x,float y);
    bounding_box_t bounding_box();
    glm::vec3 position;
    glm::vec3 velocity;
    float rotation;
    int flag;
    int visible;
private:
    VAO *object;
    VAO *object1;
    VAO *object2;
    VAO *object3;
    VAO *object4;

};

#endif

