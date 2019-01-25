#include "ring.h"
#include "main.h"

Ring::Ring(float x,float y,float z,color_t color)
{
    this->position = glm::vec3(x,y,-3);
    this->velocity = glm::vec3(0,0,0);

    this->rotation = 0;
    this->visible = 0;

    int n = 100;

    GLfloat g_vertex_buffer_data[1005];

    int k = 0;
    for(int i=0;i<n;i++)
    {
        g_vertex_buffer_data[k++] = +2.1f;
		g_vertex_buffer_data[k++] = 0.0f;
		g_vertex_buffer_data[k++] = 0.0f;

		g_vertex_buffer_data[k++] = +2.1f + 1.8*sin(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = 0.0f + 1.8*cos(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = 0.0f;

		g_vertex_buffer_data[k++] = +2.1f + 1.8*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 0.0f + 1.8*cos(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 0.0f;
    }

    GLfloat g_vertex_buffer_data1[1005];

    k = 0;
    for(int i=0;i<n;i++)
    {
        g_vertex_buffer_data1[k++] = 2.1f;
		g_vertex_buffer_data1[k++] = 0.0f;
		g_vertex_buffer_data1[k++] = 0.0f;

		g_vertex_buffer_data1[k++] = 2.1f + 2*sin(2*M_PI/n*i);
		g_vertex_buffer_data1[k++] = 0.0f + 2*cos(2*M_PI/n*i);
		g_vertex_buffer_data1[k++] = 0.0f;

		g_vertex_buffer_data1[k++] = 2.1f + 2*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data1[k++] = 0.0f + 2*cos(2*M_PI/n*(i+1));
		g_vertex_buffer_data1[k++] = 0.0f;
    }

    this->object = create3DObject(GL_TRIANGLES,3*n/2,g_vertex_buffer_data,COLOR_BACKGROUND,GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES,3*n/2,g_vertex_buffer_data1,COLOR_BOOMERANG,GL_FILL);

}

void Ring::draw(glm::mat4 VP)
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

void Ring::setposition(float x,float y,float z)
{
    this->position = glm::vec3(x,y,z);
}

void Ring::tick(double dt)
{
   //this->position += this->velocity * (glm::vec3(dt,dt,dt));


    
}

bounding_box_t Ring::bounding_box()
{
    float x = this->position.x+2.1, y = this->position.y-2.1;
    /*if(this->rotation <= -180)
    {
        y = this->position.y + 2;
    }*/
    float w = 0.05, h = 0.05;
    bounding_box_t bbox = { x,y,2*w,2*h };
    return bbox;
}

bounding_box_t Ring::bounding_box2()
{
    float x = this->position.x+2.1, y = this->position.y+2.1;
    /*if(this->rotation <= -180)
    {
        y = this->position.y + 2;
    }*/
    float w = 0.05, h = 0.05;
    bounding_box_t bbox = { x,y,2*w,2*h };
    return bbox;
}