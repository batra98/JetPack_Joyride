#include "main.h"

#ifndef RING_H
#define RING_H

class Ring{
public:
    Ring() {};
    Ring(float x,float y,float z,color_t color);
    glm::vec3 position;
    glm::vec3 velocity;
    glm::vec3 acceleration;
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