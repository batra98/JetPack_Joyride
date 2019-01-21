#include "firebeams.h"
#include "main.h"

Firebeams::Firebeams(float x,float y,float z,color_t color)
{
    this->position = glm::vec3(x,y,z);
    this->velocity = glm::vec3(0.0f,1.0f,0.0f);
    int n = 100;
    this->visible = 0;
    this->flag = 0;
    /*static const GLfloat vertex_buffer_data[] = {
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
    };*/

    GLfloat g_vertex_buffer_data[1005];
    GLfloat g_vertex_buffer_data1[1005];
    GLfloat g_vertex_buffer_data3[1005];
    GLfloat g_vertex_buffer_data4[1005];
    int k = 0;
	for(int i = 0;i<n;i++)
	{
		g_vertex_buffer_data[k++] = -5.0f;
		g_vertex_buffer_data[k++] = 0.0f;
		g_vertex_buffer_data[k++] = 0.0f;

		g_vertex_buffer_data[k++] = -5.0f + 0.5*sin(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = 0.0f + 0.5*cos(2*M_PI/n*i);
		g_vertex_buffer_data[k++] = 0.0f;

		g_vertex_buffer_data[k++] = -5.0f + 0.5*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 0.0f + 0.5*cos(2*M_PI/n*(i+1));
		g_vertex_buffer_data[k++] = 0.0f;
	}
    k=0;
    for(int i=0;i<n;i++)
    {
        g_vertex_buffer_data1[k++] = 5.0f;
		g_vertex_buffer_data1[k++] = 0.0f;
		g_vertex_buffer_data1[k++] = 0.0f;

		g_vertex_buffer_data1[k++] = 5.0f + 0.5*sin(2*M_PI/n*i);
		g_vertex_buffer_data1[k++] = 0.0f + 0.5*cos(2*M_PI/n*i);
		g_vertex_buffer_data1[k++] = 0.0f;

		g_vertex_buffer_data1[k++] = 5.0f + 0.5*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data1[k++] = 0.0f + 0.5*cos(2*M_PI/n*(i+1));
		g_vertex_buffer_data1[k++] = 0.0f;
    }
    k=0;
    for(int i=0;i<n;i++)
    {
        g_vertex_buffer_data3[k++] = 5.0f;
		g_vertex_buffer_data3[k++] = 0.0f;
		g_vertex_buffer_data3[k++] = 0.0f;

		g_vertex_buffer_data3[k++] = 5.0f + 0.25*sin(2*M_PI/n*i);
		g_vertex_buffer_data3[k++] = 0.0f + 0.25*cos(2*M_PI/n*i);
		g_vertex_buffer_data3[k++] = 0.0f;

		g_vertex_buffer_data3[k++] = 5.0f + 0.25*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data3[k++] = 0.0f + 0.25*cos(2*M_PI/n*(i+1));
		g_vertex_buffer_data3[k++] = 0.0f;
    }
    k=0;
    for(int i=0;i<n;i++)
    {
        g_vertex_buffer_data4[k++] = -5.0f;
		g_vertex_buffer_data4[k++] = 0.0f;
		g_vertex_buffer_data4[k++] = 0.0f;

		g_vertex_buffer_data4[k++] = -5.0f + 0.25*sin(2*M_PI/n*i);
		g_vertex_buffer_data4[k++] = 0.0f + 0.25*cos(2*M_PI/n*i);
		g_vertex_buffer_data4[k++] = 0.0f;

		g_vertex_buffer_data4[k++] = -5.0f + 0.25*sin(2*M_PI/n*(i+1));
		g_vertex_buffer_data4[k++] = 0.0f + 0.25*cos(2*M_PI/n*(i+1));
		g_vertex_buffer_data4[k++] = 0.0f;
    }
    GLfloat g_vertex_buffer_data2[] = {
        -5.0f,-0.25f,0.0f,
        -5.0f,0.25f,0.0f,
        5.0f,-0.25,0.0f,

        -5.0f,0.25f,0.0f,
        5.0f,-0.25,0.0f,
        5.0f,0.25f,0.0f,


    };

    this->object = create3DObject(GL_TRIANGLES,3*n,g_vertex_buffer_data,COLOR_DARK_RED,GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES,3*n,g_vertex_buffer_data1,COLOR_DARK_RED,GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES,6,g_vertex_buffer_data2,COLOR_YELLOW,GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES,3*n,g_vertex_buffer_data3,COLOR_YELLOW,GL_FILL);
    this->object4 = create3DObject(GL_TRIANGLES,3*n,g_vertex_buffer_data4,COLOR_YELLOW,GL_FILL);
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
    draw3DObject(this->object3);
    draw3DObject(this->object4);
    
}

void Firebeams::draw2(glm::mat4 VP) {
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
    /*draw3DObject(this->object2);
    draw3DObject(this->object3);
    draw3DObject(this->object4);*/
    
}

void Firebeams::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Firebeams::tick(double dt,int range) {


    if(this->position.y < -10)
    {
        this->velocity.y = this->velocity.y*-1;
        
    }
    else if(this->position.y > -range)
    {
        
        this->visible = 1;
        this->velocity.y = this->velocity.y*0;
        if(this->flag == 1)
        {
            //std::cout << "hello1" << '\n';
            this->velocity.y = -1;
            this->visible = 0;
            this->flag = 0;
        }
    }
    else
    {
        this->flag = 0;
    }

    this->position += this->velocity*(glm::vec3(dt,dt,dt));
}

void Firebeams::tick2(double dt,int range)
{
    //std::cout << range << '\n';
    if(this->position.y > 10)
    {
        this->velocity.y = this->velocity.y*-1; 
        
    }
    else if(this->position.y < range)
    {
        this->visible = 1;
        this->velocity.y = this->velocity.y*0;
        if(this->flag == 1)
        {
            //std::cout << "hello2" <<'\n';
            this->velocity.y = -1;
            this->visible = 0;
            this->flag = 0;
        }
    }
    else
    {
        this->flag = 0;
    }
    this->position -= this->velocity*(glm::vec3(dt,dt,dt));
}



bounding_box_t Firebeams::bounding_box()
{
    float x = this->position.x, y = this->position.y;
    float w = 5, h = 0.25;
    bounding_box_t bbox = { x,y,2*w,2*h };
    return bbox;
}