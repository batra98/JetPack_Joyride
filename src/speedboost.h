#include "main.h"

#ifndef SPEEDBOOST_H
#define SPEEDBOOST_H

class SpeedBoost{
public:
    SpeedBoost() {}
    SpeedBoost(float x,float y,float z,color_t color);
    glm::vec3 position;
    glm::vec3 velocity;
    void draw(glm::mat4 VP);
    void setposition(float x,float y,float z);
    bounding_box_t bounding_box();
    void tick(double dt);

    float rotation;
    int visible;

private:
    VAO *object;
    VAO *object1;
};

#endif