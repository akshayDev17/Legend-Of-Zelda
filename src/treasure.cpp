#include "main.h"
#include "treasure.h"

Treasure::Treasure(float x, float y, float z){
    this->position = glm::vec3(x, y, z);
    this->give_gift = true;

    this->treasure_cube.height = 3.0f;
    this->treasure_cube.width = 3.0f;
    this->treasure_cube.length = 3.0f;

    this->treasure_cube.x = position.x;
    this->treasure_cube.y = position.y;
    this->treasure_cube.z = position.z;

    this->bonus = 100;

    static const GLfloat vertex_buffer_data[] = {
        -1.5f, 1.5f, 1.5f,  //red face start
        -1.5f,-1.5f,1.5f,
        1.5f,1.5f,1.5f,
        1.5f,1.5f,1.5f,
        -1.5f,-1.5f,1.5f,
        1.5f,-1.5f,1.5f,       //red face end


        1.5f, -1.5f, 1.5f,
        1.5f,1.5f,-1.5f,
        1.5f,-1.5f,1.5f,
        1.5f,-1.5f,1.5f,
        1.5f,1.5f,-1.5f,
        1.5f,-1.5f,-1.5f,
        1.5f,1.5f,-1.5f,
        1.5f,-1.5f,-1.5f,
        -1.5f,-1.5f,-1.5f,
        -1.5f,-1.5f,-1.5f,
        1.5f,1.5f,-1.5f,
        -1.5f,1.5f,-1.5f,
        -1.5f,1.5f,-1.5f,
        -1.5f,-1.5f,-1.5f,
        -1.5f,1.5f,1.5f,
        -1.5f,-1.5f,-1.5f,
        -1.5f,1.5f,1.5f,
        -1.5f,-1.5f,1.5f,
        -1.5f,1.5f,1.5f,
        -1.5f,1.5f,-1.5f,
        1.5f,1.5f,1.5f,
        -1.5f,1.5f,-1.5f,
        1.5f,1.5f,1.5f,
        1.5f,1.5f,-1.5f,
        -1.5f,-1.5f,1.5f,
        -1.5f,-1.5f,-1.5f,
        1.5f,-1.5f,1.5f,
        -1.5f,-1.5f,-1.5f,
        1.5f,-1.5f,1.5f,
        1.5f,-1.5f,-1.5f
    };
    this->object1 = create3DObject(GL_TRIANGLES, 36, vertex_buffer_data, COLOR_RED, GL_FILL);
}

void Treasure::draw(glm::mat4 VP){
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
}

void Treasure::set_position(float x, float y, float z){
    this->position = glm::vec3(x, y, z);
}
