#include "main.h"

#ifndef FIREBEAMS_H
#define FIREBEAMS_H

class Firebeams{
public:
    Firebeams() {}
    Firebeams(float x,float y,float z,color_t color);
    void draw(glm::mat4 VP);
    void tick(double dt);
    void set_position(float x,float y);
    glm::vec3 position;
    glm::vec3 velocity;
    float rotation;
private:
    VAO *object;
    VAO *object1;
    VAO *object2;

};

#endif

