#include "main.h"

#ifndef BARREL_H
#define BARREL_H


class Barrel {
public:
    Barrel() {}
    Barrel(float x, float y, float z);
    glm::vec3 position;
    float rotation;
    int movement_decider;
    bounding_cube barrel_cube;
    bool tick_control;
    int gift_num;
    void draw(glm::mat4 VP);
    void set_position(float x, float y,float z);
    void tick();
    double speed_x, speed_z, speed_y, acceleration_y, speed;
    float horizontal_wobble;
private:
    VAO *object1;
    VAO *object2;

};

#endif // BARREL_H
