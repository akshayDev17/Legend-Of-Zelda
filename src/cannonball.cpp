#include "cannonball.h"
#include "main.h"

Cannonball::Cannonball(float x, float y, float z,float side, color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    this->is_launched = false;

    this->acceleration_y = -0.0001;
    this->speed_y = 0.02;

    this->vertical_speed = 0.09;
    this->gravity = -0.005;

    this->speed_x = 0.03;
    this->speed_z = 0.25;

    this->cannon_cube.width = 2*side;
    this->cannon_cube.height = 2*side;
    this->cannon_cube.length = 2*side;

    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data[] = {
        -side, side, side,  //red face start
        -side,-side,side,
        side,side,side,
        side,side,side,
        -side,-side,side,
        side,-side,side,       //red face end


        side, -side, side,
        side,side,-side,
        side,-side,side,
        side,-side,side,
        side,side,-side,
        side,-side,-side,
        side,side,-side,
        side,-side,-side,
        -side,-side,-side,
        -side,-side,-side,
        side,side,-side,
        -side,side,-side,
        -side,side,-side,
        -side,-side,-side,
        -side,side,side,
        -side,-side,-side,
        -side,side,side,
        -side,-side,side,
        -side,side,side,
        -side,side,-side,
        side,side,side,
        -side,side,-side,
        side,side,side,
        side,side,-side,
        -side,-side,side,
        -side,-side,-side,
        side,-side,side,
        -side,-side,-side,
        side,-side,side,
        side,-side,-side
    };

    this->object1 = create3DObject(GL_TRIANGLES, 36, vertex_buffer_data, color, GL_FILL);
}

void Cannonball::draw(glm::mat4 VP) {
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

void Cannonball::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Cannonball::tick(float match_x, float match_y, float match_z, float diff_x,float match_rotation) {
    this->position.y = match_y + 0.4;
    this->position.x = diff_x * cos((match_rotation*M_PI)/180) - (-0.5) * sin((match_rotation*M_PI)/180)
            + match_x;
    this->position.z = diff_x * sin((match_rotation*M_PI)/180) + (-0.5) * cos((match_rotation*M_PI)/180)
            + match_z;
    this->cannon_cube.x = position.x;
    this->cannon_cube.y = position.y;
    this->cannon_cube.z = position.z;
    //this->rotation = match_rotation;

}

void Cannonball::fire(float angle){
    this->is_launched = true;
    this->cannon_cube.x = position.x;
    this->cannon_cube.y = position.y;
    this->cannon_cube.z = position.z;
    this->position.x += (speed_x*cos(angle) - speed_z*sin(angle));
    this->position.z -= (speed_z*cos(angle) + sin(angle)*speed_x);
    /*this->position.x += speed_x;
    this->position.z -= speed_z;*/

}
