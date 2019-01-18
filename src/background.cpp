#include "background.h"
#include "main.h"

Background::Background(float x,float y,float z,color_t color)
{
    this->position = glm::vec3(x,y,z);
    int n = 5;

	/*static const GLfloat g_vertex_buffer_data[] = { 
		0.0f, 0.0f, 0.0f,
		0.5f, 0.0f, 0.0f,
		0.0f,  0.5f, 0.0f,
		0.5f, 0.5f, 0.0f,
		0.5f, 0.0f, 0.0f,
		0.0f,  0.5f, 0.0f,
	};*/
    this->rotation = 108;
    //this->rotation = 0;
	GLfloat g_vertex_buffer_data[105];
    GLfloat g_vertex_buffer_data1[]={
        0.0f,2.427f,-1.0f,
        0.0f,0.0f,-1.0f,
        -1.7633f,2.427f,-1.0f,

        0.0f,0.0f,-1.0f,
        -1.7633f,2.427f,-1.0f,
        -2.8531f,-0.92705f,-1.0f,

        -2.8531f,-0.92705f,-1.0f,
        0.0f,-3.0f,-1.0f,
        0.0f,0.0f,-1.0f,

        0.0f,2.427f,-1.0f,
        -1.3f,2.427f,-1.0f,
        -1.3f,3.5f,-1.0f,

    };
	int k = 0;
	for(int i = 0;i<n;i++)
	{
		g_vertex_buffer_data[k++] = 0.0f;
		g_vertex_buffer_data[k++] = 0.0f;
		g_vertex_buffer_data[k++] = -1.0f;

		g_vertex_buffer_data[k++] = 0.0f + 3*sin(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = 0.0f + 3*cos(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = -1.0f;

		g_vertex_buffer_data[k++] = 0.0f + 3*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 0.0f + 3*cos(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = -1.0f;
	}

    

    for(int i = 0;i<n;i++)
	{
		g_vertex_buffer_data[k++] = 0.0f;
		g_vertex_buffer_data[k++] = 0.0f;
		g_vertex_buffer_data[k++] = -1.0f;

		g_vertex_buffer_data[k++] = 0.0f + 2.8*sin(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = 0.0f + 2.8*cos(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = -1.0f;

		g_vertex_buffer_data[k++] = 0.0f + 2.8*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 0.0f + 2.8*cos(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = -1.0f;
	}


    




    this->object = create3DObject(GL_TRIANGLES,3*n,g_vertex_buffer_data,COLOR_BATMAN_SUIT,GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES,3*n,g_vertex_buffer_data+9*n,COLOR_BACKGROUND_OUTER,GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES,12,g_vertex_buffer_data1,COLOR_BATMAN_BODY,GL_FILL);
}

void Background::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(0.5f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    //rotate          = rotate * glm::translate(glm::vec3(0, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object1);
    //draw3DObject(this->object2);
}

void Background::draw2(glm::mat4 VP)
{
    Matrices.model = glm::mat4(0.5f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (0 * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    //rotate          = rotate * glm::translate(glm::vec3(0, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object2);
}

void Background::setposition(float x,float y,float z)
{
    this->position = glm::vec3(x,y,z);
}

void Background::tick()
{
    
    
}