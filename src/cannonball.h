#include "main.h"

#ifndef CANNONBALL_H
#define CANNONBALL_H


class Cannonball {
public:
    Cannonball() {}
    Cannonball(float x, float y, float z,float side, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void fire(float angle);
    void tick(float match_x, float match_y, float match_z, float diff_x, float match_rotation);
    void reorient(float match_x, float match_y, float match_z);
    double speed_x,speed_y,speed_z;
    bool is_launched;
    bounding_cube cannon_cube;
    float vertical_speed,gravity,accceleration_x, acceleration_y, acceleration_z;
private:
    VAO *object1;
};

#endif // CANNONBALL_H
