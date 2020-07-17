#include "main.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player{
public:
    Player() {}
    Player(float x,float y,float z,color_t color);
    glm::vec3 position;
    glm::vec3 acceleration;
    glm::vec3 velocity;
    int shield;
    void draw2(glm::mat4 VP);
    void draw(glm::mat4 VP);
    void setposition(float x,float y,float z);
    void tick(double dt,int visible,int ring_touch);
    bounding_box_t bounding_box();
    double size;
    float rotation;
    int flag;
    int up;

private:
    VAO *object;
    VAO *object1;
    VAO *object2;
    VAO *object3;
    VAO *object4;
    VAO *object5;
    VAO *object6;
    VAO *object7;
    VAO *object8;
    VAO *object9;
    VAO *object10;
    VAO *object11;
    VAO *object12;
    VAO *object13;
    VAO *object14;
    VAO *object15;
    VAO *object16;
    VAO *object17;

};

#endif