#include "main.h"

#ifndef FIRELINES_H
#define FIRELINES_H

class Firelines{
public:
    Firelines() {};
    Firelines(float x,float y,float z,color_t color);
    glm::vec3 position;
    glm::vec3 velocity;
    void draw(glm::mat4 VP);
    void draw2(glm::mat4 VP);
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