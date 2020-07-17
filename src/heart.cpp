#include "heart.h"
#include "main.h"

Heart::Heart(float x,float y,float z,color_t color)
{
    this->position = glm::vec3(x,y,z);
    this->rotation = 0;
    this->visible = 0;
    
    int n = 100;

    GLfloat g_vertex_buffer_data[1005];

    int k = 0;
    for(int i=0;i<n;i++)
    {
        g_vertex_buffer_data[k++] = -0.15f;
		g_vertex_buffer_data[k++] = 0.0f;
		g_vertex_buffer_data[k++] = 0.0f;

		g_vertex_buffer_data[k++] = -0.15f + 0.15*sin(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = 0.0f + 0.15*cos(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = 0.0f;

		g_vertex_buffer_data[k++] = -0.15f + 0.15*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 0.0f + 0.15*cos(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 0.0f;
    }

    GLfloat g_vertex_buffer_data1[1005];

    k = 0;
    for(int i=0;i<n;i++)
    {
        g_vertex_buffer_data1[k++] = 0.15f;
		g_vertex_buffer_data1[k++] = 0.0f;
		g_vertex_buffer_data1[k++] = 0.0f;

		g_vertex_buffer_data1[k++] = 0.15f + 0.15*sin(2*M_PI/n*i);
		g_vertex_buffer_data1[k++] = 0.0f + 0.15*cos(2*M_PI/n*i);
		g_vertex_buffer_data1[k++] = 0.0f;

		g_vertex_buffer_data1[k++] = 0.15f + 0.15*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data1[k++] = 0.0f + 0.15*cos(2*M_PI/n*(i+1));
		g_vertex_buffer_data1[k++] = 0.0f;
    }

    GLfloat g_vertex_buffer_data2[] = {
        0.3f,0.0f,0.0f,
        -0.3f,0.0f,0.0f,
        0.0f,-0.5f,0.0f,
    };

    this->object = create3DObject(GL_TRIANGLES,3*n,g_vertex_buffer_data,COLOR_SUPERMAN_CAPE,GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES,3*n,g_vertex_buffer_data1,COLOR_SUPERMAN_CAPE,GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES,3,g_vertex_buffer_data2,COLOR_SUPERMAN_CAPE,GL_FILL);
}

void Heart::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(0.5f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0,0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    rotate          = rotate * glm::translate(glm::vec3(0, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
    //draw3DObject(this->object1);
    //draw3DObject(this->object2);
    /*draw3DObject(this->object3);
    draw3DObject(this->object4);*/
}

void Heart::setposition(float x,float y,float z)
{
    this->position = glm::vec3(x,y,z);
}

void Heart::tick(double dt)
{
    //this->rotation += 1;
    //this->velocity += this->acceleration*(glm::vec3(dt,dt,dt));
    //this->position = this->position + this->velocity*(glm::vec3(dt,dt,dt));
    
}

bounding_box_t Heart::bounding_box()
{
    float x = this->position.x, y = this->position.y;
    float w = 0.25, h = 0.25;
    bounding_box_t bbox = { x,y,2*w,2*h };
    return bbox;
}