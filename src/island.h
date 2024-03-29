#include "main.h"

#ifndef ISLAND_H
#define ISLAND_H


class Island {
public:
    Island() {}
    Island(float x, float y, float z);
    glm::vec3 position;
    float rotation;
    bounding_cube island_cube;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
private:
    VAO *object1;
};

#endif // ISLAND_H
