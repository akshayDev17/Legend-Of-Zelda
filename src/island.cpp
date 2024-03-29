#include "island.h"
#include "main.h"

Island::Island(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;

    this->island_cube.x = position.x;
    this->island_cube.y = position.y;
    this->island_cube.z = position.z;
    this->island_cube.width = 600.0f;
    this->island_cube.height = 60.0f;
    this->island_cube.length = 200.0f;

    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data[] = {
        -300.0f, 30.0f, 100.0f,  //red face start
        -300.0f,-30.0f,100.0f,
        300.0f,30.0f,100.0f,
        300.0f,30.0f,100.0f,
        -300.0f,-30.0f,100.0f,
        300.0f,-30.0f,100.0f,       //red face end


        300.0f, -30.0f, 100.0f,
        300.0f,30.0f,-100.0f,
        300.0f,-30.0f,100.0f,
        300.0f,-30.0f,100.0f,
        300.0f,30.0f,-100.0f,
        300.0f,-30.0f,-100.0f,
        300.0f,30.0f,-100.0f,
        300.0f,-30.0f,-100.0f,
        -300.0f,-30.0f,-100.0f,
        -300.0f,-30.0f,-100.0f,
        300.0f,30.0f,-100.0f,
        -300.0f,30.0f,-100.0f,
        -300.0f,30.0f,-100.0f,
        -300.0f,-30.0f,-100.0f,
        -300.0f,30.0f,100.0f,
        -300.0f,-30.0f,-100.0f,
        -300.0f,30.0f,100.0f,
        -300.0f,-30.0f,100.0f,
        -300.0f,30.0f,100.0f,
        -300.0f,30.0f,-100.0f,
        300.0f,30.0f,100.0f,
        -300.0f,30.0f,-100.0f,
        300.0f,30.0f,100.0f,
        300.0f,30.0f,-100.0f,
        -300.0f,-30.0f,100.0f,
        -300.0f,-30.0f,-100.0f,
        300.0f,-30.0f,100.0f,
        -300.0f,-30.0f,-100.0f,
        300.0f,-30.0f,100.0f,
        300.0f,-30.0f,-100.0f
    };

    this->object1 = create3DObject(GL_TRIANGLES, 36, vertex_buffer_data, COLOR_ISLAND, GL_FILL);
}

void Island::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
}

void Island::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

