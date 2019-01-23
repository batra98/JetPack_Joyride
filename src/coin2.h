#include "main.h"

#ifndef COIN2_H
#define COIN2_H

class Coin2{
public:
    Coin2() {}
    Coin2(float x,float y,float z,color_t color);
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