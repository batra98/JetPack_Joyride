#include "main.h"

#ifndef PLATFORM_H
#define PLATFORM_H

class Platform{
public:
    Platform() {}
    Platform(float x,float y,float z,color_t color);
    void draw(glm::mat4 VP);
    void tick(double dt);
    void set_position(float x, float y);
    glm::vec3 position;
    glm::vec3 velocity;
    float rotation;

private:
    VAO *object;
    VAO *object2;
    VAO *object3;   
};

#endif