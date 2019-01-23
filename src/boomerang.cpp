#include "boomerang.h"
#include "main.h"

Boomerang::Boomerang(float x,float y,float z,color_t color)
{
    this->position = glm::vec3(x,y,z);
    this->velocity = glm::vec3(-2,0,0);

    this->rotation = 0;
    this->visible = 0;

    int n = 100;

    GLfloat g_vertex_buffer_data[1005];

    int k = 0;
    for(int i=0;i<n;i++)
    {
        g_vertex_buffer_data[k++] = 0.0f;
		g_vertex_buffer_data[k++] = -2.0f;
		g_vertex_buffer_data[k++] = 0.0f;

		g_vertex_buffer_data[k++] = 0.0f + 0.25*sin(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = -2.0f + 0.25*cos(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = 0.0f;

		g_vertex_buffer_data[k++] = 0.0f + 0.25*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = -2.0f + 0.25*cos(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 0.0f;
    }

    GLfloat g_vertex_buffer_data1[] = {
        0.0f,-1.75f,0.0f,
        0.0f,-2.25,0.0f,
        0.75f,-2.0f,0.0f,
    };

    this->object = create3DObject(GL_TRIANGLES,3*n/2,g_vertex_buffer_data,COLOR_BACKGROUND,GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES,3,g_vertex_buffer_data1,COLOR_BOOMERANG,GL_FILL);


}

void Boomerang::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(0.5f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0,0,1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    rotate          = rotate * glm::translate(glm::vec3(0, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    
    draw3DObject(this->object1);
    draw3DObject(this->object);
    //draw3DObject(this->object2);
    /*draw3DObject(this->object3);
    draw3DObject(this->object4);*/
}

void Boomerang::setposition(float x,float y,float z)
{
    this->position = glm::vec3(x,y,z);
}

void Boomerang::tick(double dt)
{
    if(this->position.x < 0)
    {
        if(this->rotation > -180)
        {
            this->rotation -= 5;
        }
        else
        {
            this->position.x = 0.1;
            this->velocity *= -1;
        }
            
    }
    if(this->position.x > 12)
    {
        if(this->rotation < 0)
        {
            this->rotation += 5;
        }
        else
        {
            this->position.x = 11.9;
            this->velocity *= -1;
        }
    }

    //this->velocity += this->acceleration*(glm::vec3(dt,dt,dt));
    this->position = this->position + this->velocity*(glm::vec3(dt,dt,dt));
    
}

bounding_box_t Boomerang::bounding_box()
{
    float x = this->position.x-0.25, y = this->position.y-2;
    if(this->rotation <= -180)
    {
        y = this->position.y + 2;
    }
    float w = 0.15, h = 0.15;
    bounding_box_t bbox = { x,y,2*w,2*h };
    return bbox;
}