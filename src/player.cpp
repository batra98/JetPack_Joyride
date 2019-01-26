#include "player.h"
#include "main.h"

Player::Player(float x,float y, float z, color_t color)
{
    this->position = glm::vec3(x,y,z);
    this->up = 0;
    this->acceleration.y = -2;
    this->acceleration.x = 0;
    this->acceleration.z = 0;

    this->velocity.x = 0;
    this->velocity.y = 0;
    this->velocity.z = 0;
    this->rotation = 0;
    this->flag = 0;

    this->size = 0.20f;
    this->shield = 0;

    GLfloat vertex_buffer_data[] = {
        0.0f, 0.0f, 0.0f,
		0.5f, 0.0f, 0.0f,
		0.0f,  0.5f, 0.0f,
		0.5f, 0.5f, 0.0f,//face
		0.5f, 0.0f, 0.0f,
		0.0f,  0.5f, 0.0f,

        0.0f,0.0f,0.0f,
        0.20f,0.0f,0.0f,
        0.20f,0.20f,0.0f,
        0.0f,0.0f,0.0f,//mask bottom
        0.20f,0.20f,0.0f,
        0.0f,0.20f,0.0f,

        0.0f,0.20f,0.0f,
        0.5f,0.20f,0.0f,
        0.0f,0.5f,0.0f,//mask top
        0.5f,0.20f,0.0f,
        0.0f,0.5f,0.0f,
        0.5f,0.5f,0.0f,

        0.0f,0.5f,0.0f,
        0.25f,0.5f,0.0f,//head
        0.0f,0.75f,0.0f,

        0.0f,0.0f,0.0f,
        0.0f,-0.6f,0.0f,
        0.35f,-0.6f,0.0f,//body
        0.0f,0.0f,0.0f,
        0.35f,-0.6f,0.0f,
        0.35f,0.0f,0.0f,

        0.0f,-0.6f,0.0f,
        0.0f,-0.75f,0.0f,
        0.4f,-0.75,0.0f,
        0.0f,-0.6f,0.0f,
        0.4f,-0.75,0.0f,//feet
        0.4f,-0.6f,0.0f,

        0.0f,-0.3f,0.0f,
        0.0f,-0.4f,0.0f,
        0.35f,-0.4f,0.0f,//belt
        0.0f,-0.3f,0.0f,
        0.35f,-0.4f,0.0f,
        0.35f,-0.3f,0.0f,

        0.4f,-0.6f,0.0f,
        0.4f,-0.75f,0.0f,//toe
        0.5f,-0.75f,0.0f,

        0.0f,0.0f,0.0f,
        0.0f,-0.55f,0.0f,//cape
        -0.35f,-0.55f,0.0f,

        0.5f,0.3f,0.0f,
        0.32f,0.3f,0.0f,//eye
        0.32f,0.35,0.0f,

        -0.35f,-0.55f,0.0f,
        -0.0f,-0.55f,0.0f,//flame out
        -0.17f,-0.85,0.0f,

        
        -0.25f,-0.55f,0.0f,
        -0.1f,-0.55f,0.0f,//flame in
        -0.17f,-0.85,0.0f,

        0.0f,0.0f,0.0f,
        0.0f,-0.55f,0.0f,//jetpack
        -0.35f,-0.55f,0.0f,
        0.0f,0.0f,0.0f,
        -0.35f,-0.55f,0.0f,
        -0.35f,0.0f,0.0f,

        0.65f,0.8f,0.0f,
        0.65f,0.75f,0.0f,
        -0.4f,0.8f,0.0f,

        -0.4f,0.75f,0.0f,//shield
        0.65f,0.75f,0.0f,
        -0.4f,0.8f,0.0f,



        0.65f,0.8f,0.0f,
        0.6f,0.8f,0.0f,
        0.65f,-0.9f,0.0f,

        0.6f,-0.9f,0.0f,
        0.6f,0.8f,0.0f,
        0.65f,-0.9f,0.0f,



        0.65f,-0.9f,0.0f,
        0.65f,-0.85f,0.0f,
        -0.35f,-0.9f,0.0f,

        -0.4f,-0.85f,0.0f,//shield
        0.65f,-0.85f,0.0f,
        -0.4f,-0.9f,0.0f,

        -0.45f,0.8f,0.0f,
        -0.4f,0.8f,0.0f,
        -0.45f,-0.9f,0.0f,

        -0.4f,-0.9f,0.0f,
        -0.4f,0.8f,0.0f,
        -0.45f,-0.9f,0.0f,

    };

    this->object = create3DObject(GL_TRIANGLES,6,vertex_buffer_data,COLOR_BATMAN_SKIN,GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES,6,vertex_buffer_data+18,COLOR_BATMAN_SUIT,GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES,6,vertex_buffer_data+36,COLOR_BATMAN_SUIT,GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES,3,vertex_buffer_data+18*3,COLOR_BATMAN_SUIT,GL_FILL);
    this->object4 = create3DObject(GL_TRIANGLES,6,vertex_buffer_data+18*3+3*3,COLOR_BATMAN_BODY,GL_FILL);
    this->object5 = create3DObject(GL_TRIANGLES,6,vertex_buffer_data+18*4+9,COLOR_BATMAN_SUIT,GL_FILL);
    this->object6 = create3DObject(GL_TRIANGLES,6,vertex_buffer_data+18*5+9,COLOR_BATMAN_BELT,GL_FILL);
    this->object7 = create3DObject(GL_TRIANGLES,3,vertex_buffer_data+18*6+9,COLOR_BATMAN_SUIT,GL_FILL);
    this->object8 = create3DObject(GL_TRIANGLES,3,vertex_buffer_data+18*7,COLOR_BATMAN_CAPE,GL_FILL);
    this->object9 = create3DObject(GL_TRIANGLES,3,vertex_buffer_data+18*7+9,COLOR_BATMAN_EYE,GL_FILL);
    this->object10 = create3DObject(GL_TRIANGLES,3,vertex_buffer_data+18*8,COLOR_FLAME_OUTER,GL_FILL);
    this->object11 = create3DObject(GL_TRIANGLES,3,vertex_buffer_data+18*8 + 9,COLOR_BATMAN_BELT,GL_FILL);
    this->object12 = create3DObject(GL_TRIANGLES,6,vertex_buffer_data+18*9,COLOR_BATMAN_JETPACK,GL_FILL);
    this->object13 = create3DObject(GL_TRIANGLES,6,vertex_buffer_data+18*10,COLOR_BATMAN_JETPACK,GL_FILL);
    this->object14 = create3DObject(GL_TRIANGLES,6,vertex_buffer_data+18*11,COLOR_BATMAN_JETPACK,GL_FILL);
    this->object15 = create3DObject(GL_TRIANGLES,6,vertex_buffer_data+18*12,COLOR_BATMAN_JETPACK,GL_FILL);
    this->object16 = create3DObject(GL_TRIANGLES,6,vertex_buffer_data+18*13,COLOR_BATMAN_JETPACK,GL_FILL);


}

void Player::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(0.5f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    rotate          = rotate * glm::translate(glm::vec3(0, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
    draw3DObject(this->object3);
    draw3DObject(this->object4);
    draw3DObject(this->object5);
    draw3DObject(this->object6);
    draw3DObject(this->object7);
    //draw3DObject(this->object8);
    draw3DObject(this->object9);
    draw3DObject(this->object10);
    draw3DObject(this->object11);
    draw3DObject(this->object12);

    if(this->shield == 1)
    {
        draw3DObject(this->object13);
        draw3DObject(this->object14);
        draw3DObject(this->object15);
        draw3DObject(this->object16);
    }
    
}




void Player::draw2(glm::mat4 VP)
{
    Matrices.model = glm::mat4(0.5f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    rotate          = rotate * glm::translate(glm::vec3(0, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
    draw3DObject(this->object3);
    draw3DObject(this->object4);
    draw3DObject(this->object5);
    draw3DObject(this->object6);
    draw3DObject(this->object7);
    draw3DObject(this->object8);
    draw3DObject(this->object9);
    if(this->shield == 1)
    {
        draw3DObject(this->object13);
        draw3DObject(this->object14);
        draw3DObject(this->object15);
        draw3DObject(this->object16);
    }
}

void Player::setposition(float x,float y,float z)
{
    this->position = glm::vec3(x,y,z);
}

void Player::tick(double dt,int visible,int ring_touch)
{
    if(ring_touch == 0)
    {
        if(visible==0)
        {
            if(this->position.y > -6.5)
            {
                
                    this->acceleration.y = -2;
                    this->up = 0;
                
            }
            else if(this->position.y < -6.5)
            {
                if(this->up == 0)
                    this->velocity.y = 0;
                this->acceleration.y = 0;
            }

            if(this->position.y > 7)
                this->velocity.y = 0;

        }
        else if(visible == 1)
        {
            if(this->position.y > 5 || this->position.y < -4) 
            {
                //std::cout << position.y << '\n';
                this->velocity.y = 0;
                this->acceleration.y = 0;
            }

        }
        this->velocity = this->velocity + this->acceleration*(glm::vec3(dt,dt,dt));
        this->position = this->position + this->velocity*(glm::vec3(dt,dt,dt));
    }
    else if(ring_touch == 1)
    {
        if(this->flag == 0)
        {
            //std::cout << "hello" << '\n';
            this->velocity = glm::vec3(1,+1,0);
        }
        if(this->position.x > 4.2)
        {
            this->velocity.x = -1;
            this->position.x = 4;
            this->flag = 1;
        }
        this->position += this->velocity*(glm::vec3(dt,dt,dt));
    }
    else if(ring_touch == 2)
    {
        if(this->flag == 0)
        {
            //std::cout << "hello" << '\n';
            this->velocity = glm::vec3(1,-1,0);
        }
        if(this->position.x > 4.2)
        {
            this->velocity.x = -1;
            this->position.x = 4;
            this->flag = 1;
        }
        this->position += this->velocity*(glm::vec3(dt,dt,dt));
    }
    
    
}

bounding_box_t Player::bounding_box() {
    float x = this->position.x, y = this->position.y;
    float w = 0.2, h = 0.5;
    bounding_box_t bbox = { x,y,2*w,2*h };
    return bbox;
}