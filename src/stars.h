#include "main.h"

#ifndef STARS_H
#define STARS_H


class Stars {
public:
    Stars() {}
    Stars(float x, float y, float z);
    glm::vec3 position;
    float rotation;
    int points;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick();
    bounding_cube star_cube;
    double speed;
private:
    VAO *object1;
};

#endif // STARS_H
