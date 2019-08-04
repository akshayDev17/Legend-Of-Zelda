#include "main.h"

#ifndef BOAT_H
#define BOAT_H


class Boat {
public:
    Boat() {}
    Boat(float x, float y);
    glm::vec3 position;
    float rotation;
    float horizontal_wobble;
    int health;

    GLfloat vertex_buffer_data_sail[9];

    void draw(glm::mat4 VP);
    void bounce();
    void set_position(float x, float y, float z);
    void tick();
    void blow_sail(float theta);
    bounding_cube boat_cube;
    double speed;
    float speed_x;
    float speed_y;
    float speed_z;
    float vertical_speed;
    float gravity;
    float acceleration_y;
private:
    VAO *object1;
    VAO *object2;
    VAO *object3;
    VAO *object4;
};

#endif // BOAT_H
