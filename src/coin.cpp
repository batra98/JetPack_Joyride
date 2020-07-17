#include "coin.h"
#include "main.h"

Coin::Coin(float x,float y,float z,color_t color)
{   
    this->position = glm::vec3(x,y,z);
    int n = 100;
    this->rotation = 0;
    this->visible = 1;
    this->velocity = glm::vec3(-1.0,0.0,0.0);

    
    GLfloat g_vertex_buffer_data[] = {
        0.0f,0.4f,0.0f,
        0.0f,0.0f,0.0f,
        0.4f,0.0f,0.0f,

        0.0f,0.0f,0.0f,
        0.4f,0.0f,0.0f,
        0.4,0.4f,0.0f,

        0.0f,0.0f,0.0f,
        0.4f,0.0f,0.0f,
        0.2f,-0.1f,0.0f,
    };

    this->object = create3DObject(GL_TRIANGLES,9,g_vertex_buffer_data,COLOR_BATMAN_COIN,GL_FILL);



}

void Coin::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(0.5f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0,1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    rotate          = rotate * glm::translate(glm::vec3(0, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Coin::setposition(float x,float y,float z)
{
    this->position = glm::vec3(x,y,z);
}

void Coin::tick(double dt)
{
    this->rotation += 1;
    this->position = this->position + (this->velocity)*(glm::vec3(dt,dt,dt));
    
}

bounding_box_t Coin::bounding_box()
{
    float x = this->position.x, y = this->position.y;
    float w = 0.1, h = 0.1;
    bounding_box_t bbox = { x,y,2*w,2*h };
    return bbox;
}