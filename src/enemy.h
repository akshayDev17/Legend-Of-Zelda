#include "main.h"

#ifndef ENEMY_H
#define ENEMY_H


class Enemy {
public:
    Enemy() {}
    Enemy(float x, float y, float z);
    glm::vec3 position;
    float rotation;
    bounding_cube enemy_cube;
    bool is_alive,score_check;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick(float x, float z, float orientation);
    double speed_x, speed_z;
private:
    VAO *object1;
    VAO *object2;
    VAO *object3;

};

#endif // ENEMY_H
