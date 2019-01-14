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
    void draw(glm::mat4 VP);
    void setposition(float x,float y,float z);
    void tick(double dt);
    double size;
    float rotation;
    int up;

private:
    VAO *object;

};

#endif