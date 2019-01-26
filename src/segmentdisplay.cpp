#include "segmentdisplay.h"
#include "main.h"
#include <cstring>

Segmentdisplay::Segmentdisplay()
{
    this->score = 0;
    this->digslen = 0;
    this->position.x = 0;
    this->position.y = 3.5;
}


void Segmentdisplay::set_position(float x, float y){
    this->position = glm::vec3(x, y, 0);
}
void Segmentdisplay::draw(glm::mat4 VP) {
    for (int i = 0; i < digslen; i++)
        digs[i].draw(VP);
}


void Segmentdisplay::update(int score) {
    
    char scorestr[50];
    sprintf(scorestr, "%d", score);
    this->score = score;
    digslen = strlen(scorestr);
    int i = digslen - 1;
    while(i >= 0)
    {
        digs[i] = Digit(scorestr[i], 4 - 0.3*(digslen - i) + position.x, position.y);
        i--;
    }
}