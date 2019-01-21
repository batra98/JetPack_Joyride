#include "main.h"
#include "timer.h"
#include "ball.h"
#include "player.h"
#include "platform.h"
#include "firebeams.h"
#include "background.h"
#include "coin.h"
#include "magnet.h"
#include "firelines.h"




using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;

/**************************
* Customizable functions *
**************************/

Player player;
Platform platform;
Firebeams firebeams;
Firebeams firebeam2;
Background background;
//Coin coin;
vector<Coin> coins;
vector<Firelines> firelines;
Magnet magnet;


int counter = 0;
int range;
float screen_zoom = 0.7, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 0;
int n = 7,m = 3,total = 50;
int total_firelines = 50;
int i = 0,l;
float magnet_x=4.0;
float magnet_y=4.5f;
int flag = 1;

Timer t60(1.0 / 60);
double dt = (1.0/60);


/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw() {
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);
    //screen_zoom-=0.01;
    reset_screen();
    // Eye - Location of camera. Don't change unless you are sure!!
    glm::vec3 eye (0,0,1);
    // Target - Where is the camera looking at.  Don't change unless you are sure!!
    glm::vec3 target (0, 0, 0);
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
    glm::vec3 up (0,1,0);
    //reset_screen();
    // Compute Camera matrix (view)
    Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
    // Don't change unless you are sure!!
    //Matrices.view = glm::lookAt(glm::vec3(0, 0, 1), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane

    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;  // MVP = Projection * View * Model

    // Scene render
    
    background.draw(VP);
    background.draw2(VP);
    platform.draw(VP);

    if(magnet.visible == 1)
    {
        magnet.draw(VP);
        //if(flag == 1)
        //{
            if(player.position.x < magnet_x && player.position.y < magnet_y)
            {
                player.acceleration = glm::vec3(magnet_x*2,magnet_y*2,0.0);
                player.up = 0;
                player.velocity = glm::vec3(1.0,1.0,0.0);
                flag = 0;
            }
            else if(player.position.x > magnet_x && player.position.y > magnet_y)
            {
                //cout << "hello" <<'\n';
                player.acceleration = glm::vec3(-magnet_x*2,-magnet_y*2,0.0);
                player.up = 0;
                player.velocity = glm::vec3(-1.0,-1.0,0.0);
                flag = 0;
            }
            else if(player.position.x < magnet_x && player.position.y > magnet_y)
            {
                player.acceleration = glm::vec3(magnet_x*2,-magnet_y*2,0.0);
                player.up = 0;
                player.velocity = glm::vec3(1.0,-1.0,0.0);
                flag = 0;
            }
            else if(player.position.x > magnet_x && player.position.y < magnet_y)
            {
                player.acceleration = glm::vec3(-magnet_x*2,magnet_y*2,0.0);
                player.up = 0;
                player.velocity = glm::vec3(-1.0,1.0,0.0);
                flag = 0;
            }
        //}
    }
    for(i=0;i<n*m*total;i++)
    {
        //cout << coins[i].position.x << '\n';
        if(coins[i].visible == 1)
        coins[i].draw(VP);
    }
    for(i=0;i<total_firelines;i++)
    {
        firelines[i].draw(VP);
    }
    //coins[0].draw(VP);
    //coins[1].draw(VP);
    //coin.draw(VP);
    if(firebeams.visible == 0)
        firebeams.draw2(VP);
    else if(firebeams.visible == 1)
        firebeams.draw(VP);

    if(firebeam2.visible == 0)    
        firebeam2.draw2(VP);
    else if(firebeam2.visible == 1)
        firebeam2.draw(VP);
    if(player.up == 0)
        player.draw2(VP);
    else if(player.up == 1)
        player.draw(VP);    
   
}



void tick_input(GLFWwindow *window) {
    int left  = glfwGetKey(window, GLFW_KEY_LEFT);
    int right = glfwGetKey(window, GLFW_KEY_RIGHT);
    int up = glfwGetKey(window, GLFW_KEY_UP);
    int w = glfwGetKey(window,GLFW_KEY_W);
    int s = glfwGetKey(window,GLFW_KEY_S);
    //cout << scroll << '\n';
    if(magnet.visible == 0)
    {
        if(player.acceleration.x * player.velocity.x > 0)
        {
            player.velocity.x = 0;
            player.acceleration.x = 0;
        }

        if(left==1)
        {
            player.velocity.x = -2;
            player.acceleration.x = 1;
        }
        if(right == 1)
        {
            player.velocity.x = 2;
            player.acceleration.x = -1;
        }
        if(up == 1)
        {
            player.up = 1;
            player.velocity.y = 2;
        }
    }
    else if(magnet.visible == 1)
    {

        if(left==1)
        {
            player.velocity.x = -20;
            //player.acceleration.x += -1;
        }
        if(right == 1)
        {
            player.velocity.x = 20;
            //player.acceleration.x += 1;
        }
        if(up == 1)
        {
            player.up = 1;
            player.velocity.y = 20;
        }
    }
    if(w==1)
    {
        if(screen_zoom>0)
        screen_zoom-=0.01;
    }
    if(s==1)
    {
        screen_zoom+=0.01;
    }
    

}

void tick_elements(int width,int height) {

    if(counter%360 == 0)
    {
        if(magnet.visible == 1)
        {
            magnet.visible = 0;
        }
        
    }

    if(counter%300 == 0)
    {
        if(firebeam2.flag == 0)
        {
            firebeam2.flag = 1;
            //firebeam2.visible = ;
        }
        if(firebeams.flag == 0)
        {
            firebeams.flag = 1;
            //firebeams.visible = 0;
        }
    }

    if(counter%(480*4) == 0)
    {
        if(magnet.visible == 1)
            magnet.visible = 0;
        else
            magnet.visible = 1;
          
    }
    player.tick(dt,magnet.visible);
    platform.tick(dt);
    firebeams.tick(dt,range);
    firebeam2.tick2(dt,range);
    background.tick();
    magnet.tick(dt);

    

    //cout << "size =" +coins.size() << '\n';
    
    for(i = 0;i<n*m*total;i++)
    {
        coins[i].tick(dt);
        if(coins[i].visible == 1)
        {
            if(detect_collision(coins[i].bounding_box(),player.bounding_box(),0) == 1)
            {
                //cout << i << '\n';
                coins[i].visible = 0;
            }
        }
    }
    
    for(i=0;i<total_firelines;i++)
    {
        firelines[i].tick(dt);

        if(detect_collision(player.bounding_box(),firelines[i].bounding_box(),firelines[i].rotation)==1)
        {
            cout << i << '\n';
        }
    }
    //cout << firebeam2.position.y << '\n';

    if(detect_collision(player.bounding_box(),firebeam2.bounding_box(),0) == 1)
    {
        //if(firebeam2.visible == 1)
        //cout << "touch 2" << '\n';
    }
    if(detect_collision(player.bounding_box(),firebeams.bounding_box(),0) == 1)
    {
        //if(firebeams.visible == 1)
        //cout << "touch 1" << '\n';
    }

    
    //coins[0].tick(dt);
    //coins[1].tick(dt);
    //coin.tick(dt);
    //cout << player.acceleration.x << " " << player.acceleration.y << " " << player.acceleration.z << " "<< screen_zoom << '\n';
    //cout << player.position.x << " " << player.position.y << " " << player.position.z << " "<< screen_zoom << '\n';
   
    

}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models
    
    
    player = Player(-2,-2,0,COLOR_RED);
    platform = Platform(0,0,0,COLOR_BLACK);
    firebeams = Firebeams(0,-5,0,COLOR_RED);
    firebeam2 = Firebeams(0,5,0,COLOR_RED);
    background = Background(0,0,0,COLOR_BATMAN_BELT);
    magnet = Magnet(magnet_x,magnet_y,0,COLOR_COIN);

    n = rand() % 15 + 1;
    m = rand() % 7 + 1;
    range = rand() % 5 + 1;

    for(l=0;l<total;l++)
    {
        for(i=0;i<n;i++)
        {
            /*coins.push_back(Coin((i+l*20)/2.0,0,0,COLOR_COIN));
            coins.push_back(Coin((i+l*20)/2.0,1.0,0.0,COLOR_COIN));
            coins.push_back(Coin((i+l*20)/2.0,2.0,0.0,COLOR_COIN));*/
            for(int g = 0;g<m;g++)
            {
                coins.push_back(Coin((i+l*20)/2.0,(float)(rand()%3+1),0,COLOR_COIN));
            }
        }
    }

    for(i=0;i<total_firelines/2;i++)
    {
        firelines.push_back(Firelines(rand()%200+1,(float)(rand()%3+1),0,COLOR_BATMAN_EYE));
    }

    for(l=i;l<total_firelines;l++)
    {
        firelines.push_back(Firelines(rand()%200+1,-(float)(rand()%3+1),0,COLOR_BATMAN_EYE));
    }
    
    
   
   
    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}


int main(int argc, char **argv) {
    srand(time(0));
    int width  = 900;
    int height = 800;


    window = initGLFW(width, height);
    

    initGL (window, width, height);

    

    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {
        // Process timers
        
        if (t60.processTick()) {
            // 60 fps
            // OpenGL Draw commands
            counter++;

            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            tick_elements(width,height);
            tick_input(window);
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

/*bool detect_collision(bounding_box_t a, bounding_box_t b) {    

    return (abs(a.x - b.x) * 1 < (a.width + b.width)) &&
           (abs(a.y - b.y) * 1 < (a.height + b.height));
}*/

bool detect_collision(bounding_box_t a, bounding_box_t b, float rotation) {
    if(rotation == 0)
    {
        return (abs(a.x - b.x) * 1 < (a.width + b.width)) && (abs(a.y - b.y) * 1 < (a.height + b.height));
    }
    else if (rotation > 0)
    {
        float b_x_new = b.x - cos(rotation * M_PI / 180.0f) * (a.y-b.y);
        float b_width_new = abs(cos(rotation * M_PI / 180.0f) * b.width);
        return (abs(a.x - b_x_new) * 2 < (a.width + b.width)) && (abs(a.y - b.y) * 2 < (a.height + b.height));
    }
    else if (rotation < 0)
    {
        float b_x_new = b.x + cos(rotation * M_PI / 180.0f) * (a.y-b.y);
        float b_width_new = abs(cos(rotation * M_PI / 180.0f) * b.width);
        return (abs(a.x - b_x_new) * 2 < (a.width + b.width)) && (abs(a.y - b.y) * 2 < (a.height + b.height));
   }
}

void reset_screen() {
    float top    = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left   = screen_center_x - 4 / screen_zoom;
    float right  = screen_center_x + 4 / screen_zoom;
    Matrices.projection = glm::ortho(left, right, bottom, top, 0.1f, 500.0f);
}
