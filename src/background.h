#include "main.h"

#ifndef BACKGROUND_H
#define BACKGROUND_H

class Background{
public:
    Background() {}
    Background(float x,float y,float z,color_t color);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void draw2(glm::mat4 VP);
    void setposition(float x,float y,float z);
    void tick();
    double size;
    float rotation;
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
};

#endif