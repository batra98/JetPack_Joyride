#include "main.h"

#ifndef LASER_H
#define LASER_H

class Laser{
public:
    Laser() {};
    Laser(float x,float y,float z,color_t color,glm::vec3 velocity);
    glm::vec3 position;
    glm::vec3 velocity;
    glm::vec3 acceleration;
    void draw(glm::mat4 VP);
    void setposition(float x,float y,float z);
    bounding_box_t bounding_box();
    void tick(double dt,glm::vec3 player_pos);
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