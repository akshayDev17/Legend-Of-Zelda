#include "main.h"

#ifndef TREASURE_H
#define TREASURE_H


class Treasure {
public:
    Treasure() {}
    Treasure(float x, float y, float z);
    glm::vec3 position;
    bool give_gift;
    bounding_cube treasure_cube;
    int bonus;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void open_treasure();
private:
    VAO *object1;

};

#endif // TREASURE_H
