#include "main.h"

#ifndef BOSS_H
#define BOSS_H


class Boss {
public:
    Boss() {}
    Boss(float x, float y, float z);
    glm::vec3 position;
    float rotation;
    bounding_cube boss_cube;
    bool is_alive,score_check, has_emerged;
    void emerge_boss();
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick(float x, float z, float orientation);
    double speed_x, speed_z;
private:
    VAO *object1;
    VAO *object2;
    VAO *object3;

};

#endif // BOSS_H
