#include "platform.h"
#include "main.h"




Platform::Platform(float x,float y,float z,color_t color)
{
    this->position = glm::vec3(x,y,z);
    this->velocity = glm::vec3(1.0f,0.0f,0.0f);

    /*static const GLfloat vertex_buffer_data1[] = {
        -0.5f, -3.5f, 0.0f,
		-0.5f, -3.8f, 0.0f,
		+0.5f,  -3.8f, 0.0f,
		+0.5f, -3.8f, 0.0f,
		-0.5f, -3.5f, 0.0f,
		+0.5f,  -3.5f, 0.0f,


        
    };

    static const GLfloat vertex_buffer_data[] = {
        -1.0f, -3.3f, 0.0f,
		-1.0f, -4.0f, 0.0f,
		+1.0f,  -4.0f, 0.0f,
		+1.0f, -4.0f, 0.0f,
		-1.0f, -3.3f, 0.0f,
		+1.0f,  -3.3f, 0.0f,


        
    };
*/
    GLfloat vertex_buffer_data[1805];
    GLfloat vertex_buffer_data1[1805];

    int k = 0,l = 0,i,j;
    float size = 0.0f;

    for(i=0;i<100;i++)
    {
        vertex_buffer_data[k++] = -5.0f + size;
        vertex_buffer_data[k++] = -7.0f;
        vertex_buffer_data[k++] = 0.0f;

        vertex_buffer_data[k++] = -5.0f + size;
        vertex_buffer_data[k++] = -7.7f;
        vertex_buffer_data[k++] = 0.0f;

        vertex_buffer_data[k++] = +5.0f + size;
        vertex_buffer_data[k++] = -7.7f;
        vertex_buffer_data[k++] = 0.0f;

        vertex_buffer_data[k++] = 5.0f + size;
        vertex_buffer_data[k++] = -7.7f;
        vertex_buffer_data[k++] = 0.0f;

        vertex_buffer_data[k++] = -5.0f + size;
        vertex_buffer_data[k++] = -7.0f;
        vertex_buffer_data[k++] = 0.0f;

        vertex_buffer_data[k++] = 5.0f + size;
        vertex_buffer_data[k++] = -7.0f;
        vertex_buffer_data[k++] = 0.0f;


        vertex_buffer_data1[l++] = -0.5f + size;
        vertex_buffer_data1[l++] = -7.2f;
        vertex_buffer_data1[l++] = 0.0f;

        vertex_buffer_data1[l++] = -0.5f + size;
        vertex_buffer_data1[l++] = -7.5f;
        vertex_buffer_data1[l++] = 0.0f;

        vertex_buffer_data1[l++] = 0.5f + size;
        vertex_buffer_data1[l++] = -7.5f;
        vertex_buffer_data1[l++] = 0.0f;

        vertex_buffer_data1[l++] = 0.5f + size;
        vertex_buffer_data1[l++] = -7.5f;
        vertex_buffer_data1[l++] = 0.0f;

        vertex_buffer_data1[l++] = -0.5f + size;
        vertex_buffer_data1[l++] = -7.2f;
        vertex_buffer_data1[l++] = 0.0f;

        vertex_buffer_data1[l++] = 0.5f + size;
        vertex_buffer_data1[l++] = -7.2f;
        vertex_buffer_data1[l++] = 0.0f;

        size += 2.0f;
        


    }

    this->object = create3DObject(GL_TRIANGLES,600,vertex_buffer_data,color,GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES,600,vertex_buffer_data1,COLOR_GREEN,GL_FILL);
}

void Platform::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(0.5f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object2);
}

void Platform::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Platform::tick(double dt) {
    
    //this->rotation += speed;
    this->position -= this->velocity*(glm::vec3(dt,dt,dt));
    //this->position.y += speed/100;

    
}
