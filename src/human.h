#include "main.h"

#ifndef HUMAN_H
#define HUMAN_H

class Human{
public:
    Human(){}
    Human(float x, float y, float z);
    glm::vec3 position;
    bounding_cube human_cube;
    void draw(glm::mat4 VP);
    void movement(int direction);
    float rotation;
private:
    VAO* object1;

};

#endif //HUMAN_H
