#include "rock.h"
#include "main.h"

Rock::Rock(float x, float y, float z){
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    this->is_alive = true;
    this->has_collided = false;
    this->damage = 1;
    this->rock_cube.x = this->position.x;
    this->rock_cube.y = this->position.y;
    this->rock_cube.z = this->position.z;
    this->rock_cube.width = 1.4;
    this->rock_cube.height = 2.2;
    this->rock_cube.length = 1.0;
    static const GLfloat vertex_buffer_data[] = {


       -0.7f, 0.0f, 0.5f,
       -0.7f, 0.0f, -0.5f,
        -0.4f, 1.4f, 0.0f,

        0.7f, 0.0f, 0.5f,
        0.7f, 0.0f, -0.5f,
        0.4f, 1.4f, 0.0f,

        -0.25f, 0.8f, 0.5f,
        -0.25f, 0.8f, -0.5f,
        0.0f, 2.2f, 0.0f,

        0.25f, 0.8f, 0.5f,
        0.25f, 0.8f, -0.5f,
        0.0f, 2.2f, 0.0f,


        -0.7f, 0.0f, 0.5f,
        -0.4f, 1.4f, 0.0f,
        0.0f, 0.0f, 0.5f,
        -0.25f, 0.8f, 0.5f,
        0.25f, 0.8f, 0.5f,
        0.0f, 0.0f, 0.5f,
        -0.25f, 0.8f, 0.5f,
        0.25f, 0.8f, 0.5f,
        0.0f, 2.2f, 0.0f,
        0.0f, 0.0f, 0.5f,
        0.4f, 1.4f, 0.0f,
        0.7f, 0.0f, 0.5f,

        -0.7f, 0.0f, -0.5f,
        -0.4f, 1.4f, 0.0f,
        0.0f, 0.0f, -0.5f,
        -0.25f, 0.8f, -0.5f,
        0.25f, 0.8f, -0.5f,
        0.0f, 0.0f, -0.5f,
        -0.25f, 0.8f, -0.5f,
        0.25f, 0.8f, -0.5f,
        0.0f, 2.2f, 0.0f,
        0.0f, 0.0f, -0.5f,
        0.4f, 1.4f, 0.0f,
        0.7f, 0.0f, -0.5f,
    };

    this->object1 = create3DObject(GL_TRIANGLES, 30, vertex_buffer_data, COLOR_GREY, GL_FILL);
}

void Rock::draw(glm::mat4 VP){
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

void Rock::set_position(float x, float y, float z){
    this->position = glm::vec3(x, y, z);
}

void Rock::reset_damage(){
    this->damage = 0;
}

bool Rock::check_collision(bounding_cube c){
    return ((abs(c.x - rock_cube.x) * 2 < c.width + rock_cube.width)
            && (abs(c.y - rock_cube.y) * 2 < c.height + rock_cube.height)
            && (abs(c.z - rock_cube.z) * 2 < c.length + rock_cube.length));
}
