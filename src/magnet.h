#include "main.h"

#ifndef MAGNET_H
#define MAGNET_H

class Magnet{
public:
    Magnet() {}
    Magnet(float x,float y,float z,color_t color);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void setposition(float x,float y,float z);
    bounding_box_t bounding_box();
    void tick(double dt);
    float rotation;
    int visible;

private:
    VAO *object;
    VAO *object1;
    VAO *object2;
    VAO *object3;
    VAO *object4;  
};

#endif