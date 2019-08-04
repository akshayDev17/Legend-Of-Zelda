#include "main.h"

#ifndef DISPLAY_H
#define DISPLAY_H


class Display{
public:
    Display() {}
    Display(float x, float y, float z);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y,float z);
    void make_number(int num);
private:
    VAO *object1;
    VAO *object2;
    VAO *object3;
    VAO *object4;
    VAO *object5;
    VAO *object6;
    VAO *object7;
    VAO *object8;
    VAO *object9;
    VAO *object10;
    VAO *object11;
    VAO *object12;
    VAO *object13;
    VAO *object14;
    VAO *object15;
    VAO *object16;
    VAO *object17;
    VAO *object18;
    VAO *object19;
    VAO *object20;
    VAO *object21;

};

#endif // DISPLAY_H
