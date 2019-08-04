#include "enemy.h"
#include "main.h"

Enemy::Enemy(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;

    this->speed_x = (rand()%5 + 1)/100.0f;
    this->speed_z = (rand()%5 + 1)/100.0f;

    this->is_alive = true;
    this->score_check = false;

    this->enemy_cube.width = 1.4;
    this->enemy_cube.height = 1.5;
    this->enemy_cube.length = 1.4;

    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data[] = {
        -0.7f, 0.7f, 0.7f,  //red face start
        -0.7f,-0.7f,0.7f,
        0.7f,0.7f,0.7f,
        0.7f,0.7f,0.7f,
        -0.7f,-0.7f,0.7f,
        0.7f,-0.7f,0.7f,       //red face end


        0.7f, -0.7f, 0.7f,
        0.7f,0.7f,-0.7f,
        0.7f,-0.7f,0.7f,
        0.7f,-0.7f,0.7f,
        0.7f,0.7f,-0.7f,
        0.7f,-0.7f,-0.7f,

        0.7f,0.7f,-0.7f,
        0.7f,-0.7f,-0.7f,
        -0.7f,-0.7f,-0.7f,
        -0.7f,-0.7f,-0.7f,
        0.7f,0.7f,-0.7f,
        -0.7f,0.7f,-0.7f,

        -0.7f,0.7f,-0.7f,
        -0.7f,-0.7f,-0.7f,
        -0.7f,0.7f,0.7f,
        -0.7f,-0.7f,-0.7f,
        -0.7f,0.7f,0.7f,
        -0.7f,-0.7f,0.7f,

        -0.7f,0.7f,0.7f,
        -0.7f,0.7f,-0.7f,
        0.7f,0.7f,0.7f,
        -0.7f,0.7f,-0.7f,
        0.7f,0.7f,0.7f,
        0.7f,0.7f,-0.7f,

        -0.7f,-0.7f,0.7f,
        -0.7f,-0.7f,-0.7f,
        0.7f,-0.7f,0.7f,
        -0.7f,-0.7f,-0.7f,
        0.7f,-0.7f,0.7f,
        0.7f,-0.7f,-0.7f,

        0.0f, 2.5f, 0.0f,
        -0.7f, 0.7f, -0.7f,
        0.7f, 0.7f, -0.7f,

        0.0f, 2.5f, 0.0f,
        0.7f, 0.7f, 0.7f,
        0.7f, 0.7f, -0.7f,

        0.0f, 2.5f, 0.0f,
        -0.7f, 0.7f, 0.7f,
        0.7f, 0.7f, 0.7f,

        0.0f, 2.5f, 0.0f,
        -0.7f, 0.7f, 0.7f,
        -0.7f, 0.7f, -0.7f,

        //eyes start
        0.2f, 0.3f, 0.7f,
        0.6f, 0.5f, 0.7f,
        0.4f, 0.0f, 0.7f,

        -0.2f, 0.3f, 0.7f,
        -0.6f, 0.5f, 0.7f,
        -0.4f, 0.0f, 0.7f,
        //eyes end

        //smile_start
        0.4f, -0.15f, 0.7f,
        0.0f, -0.3f, 0.7f,
        0.0f, -0.55f, 0.7f,

        -0.4f, -0.15f, 0.7f,
        0.0f, -0.3f, 0.7f,
        0.0f, -0.55f, 0.7f
        //smile_end

    };

    this->object1 = create3DObject(GL_TRIANGLES, 48, vertex_buffer_data, COLOR_RED, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data + 144, COLOR_BLACK, GL_FILL);
}

void Enemy::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
}

void Enemy::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Enemy::tick(float x, float z, float orientation) {
    this->position.x += speed_x  * (x/pow(pow(x,2)+pow(z,2),0.5));
    this->position.z += speed_z  * (z/pow(pow(x,2)+pow(z,2),0.5));
    this->rotation = orientation-M_PI/2;

    this->enemy_cube.x = this->position.x;
    this->enemy_cube.y = this->position.y;
    this->enemy_cube.z = this->position.z;

}

