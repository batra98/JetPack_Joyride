#include "firebeams.h"
#include "main.h"

Firebeams::Firebeams(float x,float y,float z,color_t color)
{
    this->position = glm::vec3(x,y,z);
    this->velocity = glm::vec3(1.0f,0.0f,0.0f);

    static const GLfloat vertex_buffer_data[] = {
        -3.0f, 0.0f, 0.0f,
		-2.5f, 0.0f, 0.0f,
		-3.0f,  0.5f, 0.0f,
		-2.5f, 0.5f, 0.0f,
		-2.5f, 0.0f, 0.0f,
		-3.0f,  0.5f, 0.0f,

        3.0f, 0.0f, 0.0f,
		2.5f, 0.0f, 0.0f,
		3.0f,  0.5f, 0.0f,
		2.5f, 0.5f, 0.0f,
		2.5f, 0.0f, 0.0f,
		3.0f,  0.5f, 0.0f,

        -2.5f, 0.1f, 0.0f,
		2.5f, 0.1f, 0.0f,
		-2.5f,  0.4f, 0.0f,
		2.5f, 0.4f, 0.0f,
		2.5f, 0.1f, 0.0f,
		-2.5f,  0.4f, 0.0f,
    };

    this->object = create3DObject(GL_TRIANGLES,6,vertex_buffer_data,COLOR_DARK_RED,GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES,6,vertex_buffer_data+18,COLOR_DARK_RED,GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES,6,vertex_buffer_data+18*2,COLOR_YELLOW,GL_FILL);
}

void Firebeams::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(0.5f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
    
}

void Firebeams::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Firebeams::tick(double dt) {
    
    //this->rotation += speed;
    //this->position -= this->velocity*(glm::vec3(dt,dt,dt));
    //this->position.y += speed/100;

    
}

