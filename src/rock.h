#include "main.h"

#ifndef ROCK_H
#define ROCK_H


class Rock {
public:
    Rock() {}
    Rock(float x, float y, float z);
    glm::vec3 position;
    float rotation;
    bool is_alive;
    bool has_collided;
    int damage;
    bounding_cube rock_cube;
    void reset_damage();
    bool check_collision(bounding_cube c);
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
private:
    VAO *object1;
};

#endif // ROCK_H
