#include "stars.h"
#include "main.h"

Stars::Stars(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    double rad = 2*M_PI / 5;
    static const GLfloat vertex_buffer_data[] = {
        -0.5f, -0.5f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.5f, -0.5f, 0.0f,
        -0.5f, 0.5f, 0.0f,
        0.5f, 0.5f, 0.0f,
        0.0f, -1.0f, 0.0f
    };
    this->star_cube.width = 1.0f;
    this->star_cube.height = 1.0f;
    this->star_cube.length = 1.0f;
    this->object1 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_STAR, GL_FILL);
}

void Stars::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
}

void Stars::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Stars::tick() {
    this->rotation += speed;
    this->star_cube.x = this->position.x;
    this->star_cube.y = this->position.y;
    this->star_cube.z = this->position.z;
    // this->position.x -= speed;
    // this->position.y -= speed;
}
