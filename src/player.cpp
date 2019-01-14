#include "player.h"
#include "main.h"

Player::Player(float x,float y, float z, color_t color)
{
    this->position = glm::vec3(x,y,z);
    this->up = 0;
    this->acceleration.y = -1;
    this->acceleration.x = 0;
    this->acceleration.z = 0;

    this->velocity.x = 0;
    this->velocity.y = 0;
    this->velocity.z = 0;

    this->size = 0.25f;

    static const GLfloat vertex_buffer_data[] = {
       -size,-size,-size, // triangle 1 : begin
        -size,-size, size,
        -size, size, size, // triangle 1 : end
        size, size,-size, // triangle 2 : begin
        -size,-size,-size,
        -size, size,-size, // triangle 2 : end
        size,-size, size,
        -size,-size,-size,
        size,-size,-size,
        size, size,-size,
        size,-size,-size,
        -size,-size,-size,
        -size,-size,-size,
        -size, size, size,
        -size, size,-size,
        size,-size, size,
        -size,-size, size,
        -size,-size,-size,
        -size, size, size,
        -size,-size, size,
        size,-size, size,
        size, size, size,
        size,-size,-size,
        size, size,-size,
        size,-size,-size,
        size, size, size,
        size,-size, size,
        size, size, size,
        size, size,-size,
        -size, size,-size,
        size, size, size,
        -size, size,-size,
        -size, size, size,
        size, size, size,
        -size, size, size,
        size,-size, size
    };

    this->object = create3DObject(GL_TRIANGLES,12*3,vertex_buffer_data,color,GL_FILL);


}

void Player::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);

}

void Player::setposition(float x,float y,float z)
{
    this->position = glm::vec3(x,y,z);
}

void Player::tick(double dt)
{
    if(this->position.y > -3 && this->position.y < 3)
    {
        this->acceleration.y = -1;
        this->up = 0;
    }
    else
    {
        if(this->up == 0)
            this->velocity.y = 0;
        this->acceleration.y = 0;
    }
    
    this->velocity = this->velocity + this->acceleration*(glm::vec3(dt,dt,dt));
    this->position = this->position + this->velocity*(glm::vec3(dt,dt,dt));
    
}