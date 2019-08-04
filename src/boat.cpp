#include "boat.h"
#include "main.h"

GLfloat vertex_buffer_data_sail[9]={
    0.0f, 3.0f, 0.0f,
    0.0f, 1.7f, 0.0f,
    0.0f, 3.0f, 1.4f,
};

Boat::Boat(float x, float y) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    this->horizontal_wobble = 0;
    this->acceleration_y = -0.0001;
    this->speed_y = 0.02;
    this->gravity = -0.004;

    this->vertical_speed = 0.05;
    this->speed = 0.25;

    this->speed_x = 0.1;
    this->speed_z = 0.1;

    this->health = 10;

    vertex_buffer_data_sail[0] = 0.0f;
    vertex_buffer_data_sail[1] = 3.0f;
    vertex_buffer_data_sail[2] = 0.0f;
    vertex_buffer_data_sail[3] = 0.0f;
    vertex_buffer_data_sail[4] = 1.7f;
    vertex_buffer_data_sail[5] = 0.0f;
    vertex_buffer_data_sail[6] = 0.0f;
    vertex_buffer_data_sail[7] = 3.0f;
    vertex_buffer_data_sail[8] = 1.4f;


    static const GLfloat vertex_buffer_data[] = {
        -0.5f, 0.9f, 1.0f,
        0.5f, 0.9f, 1.0f,
        -0.5f, -0.9f, 1.0f,
        -0.5f, -0.9f, 1.0f,
        0.5f, 0.9f, 1.0f,
        0.5f, -0.9f, 1.0f,

        0.5f, 0.9f, 1.0f,
        0.5f, 0.9f, -1.0f,
        0.5f, -0.9f, 1.0f,
        0.5f, -0.9f, 1.0f,
        0.5f, 0.9f, -1.0f,
        0.5f, -0.9f, -1.0f,

        0.5f, 0.9f, -1.0f,
        0.5f, -0.9f, -1.0f,
        -0.5f, -0.9f, -1.0f,
        -0.5f, -0.9f, -1.0f,
        0.5f, 0.9f, -1.0f,
        -0.5f, 0.9f, -1.0f,

        -0.5f, -0.9f, -1.0f,
        -0.5f, 0.9f, -1.0f,
        -0.5f, 0.9f, 1.0f,
        -0.5f, 0.9f, 1.0f,
        -0.5f, -0.9f, -1.0f,
        -0.5f, -0.9f, 1.0f,

        -0.5f, 0.9f, -1.0f,
        0.5f, 0.9f, -1.0f,
        -0.5f, 0.9f, 1.0f,
        -0.5f, 0.9f, 1.0f,
        0.5f, 0.9f, -1.0f,
        0.5f, 0.9f, 1.0f,

        -0.5f, -0.9f, -1.0f,
        0.5f, -0.9f, -1.0f,
        0.5f, -0.9f, 1.0f,
        0.5f, -0.9f, 1.0f,
        -0.5f, -0.9f, -1.0f,
        -0.5f, -0.9f, 1.0f,

        -0.5f, 0.9f, -1.0f,
        0.5f, 0.9f, -1.0f,
        0.0f, 2.0f, -1.5f,

        -0.5f, 0.9f, -1.0f,
        -0.5f, -0.9f, -1.0f,
        0.0f, 2.0f, -1.5f,

        -0.5f, -0.9f, -1.0f,
        0.5f, -0.9f, -1.0f,
        0.0f, 2.0f, -1.5f,

        0.5f, 0.9f, -1.0f,
        0.5f, -0.9f, -1.0f,
        0.0f, 2.0f, -1.5f,

        0.0f, 2.0f, 1.5f,
        -0.5f, 0.9f, 1.0f,
        0.5f, 0.9f, 1.0f,

        0.0f, 2.0f, 1.5f,
        0.5f, 0.9f, 1.0f,
        0.5f, -0.9f, 1.0f,

        0.0f, 2.0f, 1.5f,
        -0.5f, -0.9f, 1.0f,
        0.5f, -0.9f, 1.0f,

        0.0f, 2.0f, 1.5f,
        -0.5f, 0.9f, 1.0f,
        -0.5f, -0.9f, 1.0f,

        //sail start

        //top face
        0.03f, 3.3f, 0.03f,
        -0.03f, 3.3f, 0.03f,
        -0.03f, 3.3f, -0.05,
        -0.03f, 3.3f, -0.05,
        0.03f, 3.3f, 0.03f,
        0.03f, 3.3f, -0.03f,
        //top face end

        //bottom face
        0.03f, 3.3f, 0.03f,
        -0.03f, 3.3f, 0.03f,
        -0.03f, 3.3f, -0.05,
        -0.03f, 3.3f, -0.05,
        0.03f, 3.3f, 0.03f,
        0.03f, 3.3f, -0.03f,
        //bottom face end

        //right face
        0.03f, 3.3f, 0.03f,
        0.03f, 3.3f, -0.03f,
        0.03f, 0.5f, -0.03f,
        0.03f, 0.5f, -0.03f,
        0.03f, 3.3f, 0.03f,
        0.03f, 0.5f, 0.03f,
        //right face end

        //left face
        -0.03f, 3.3f, 0.03f,
        -0.03f, 3.3f, -0.03f,
        -0.03f, 0.5f, -0.03f,
        -0.03f, 0.5f, -0.03f,
        -0.03f, 3.3f, 0.03f,
        -0.03f, 0.5f, 0.03f,
        //left face end

        //front face
        -0.03f, 3.3f, -0.03f,
        0.03f, 3.3f, -0.03f,
        0.03f,0.5f, -0.03f,
        0.03f,0.5f, -0.03f,
        -0.03f, 3.3f, -0.03f,
        -0.03f, 0.5f, -0.03f,
        //front face end

        //back face
        -0.03f, 3.3f, 0.03f,
        0.03f, 3.3f, 0.03f,
        0.03f,0.5f, 0.03f,
        0.03f,0.5f, 0.03f,
        -0.03f, 3.3f, 0.03f,
        -0.03f, 0.5f, 0.03f,
        //back face end

        //sail end

        //right cannon top face
        0.3f, 0.65f, -0.75f,
        0.95f, 0.65f, -0.75f,
        0.3f, 0.45f, 0.75f,
        0.95f, 0.65f, -0.75f,
        0.3f, 0.45f, 0.75f,
        0.75f, 0.45f, 0.75f,

        //right cannon right face
        0.75f, 0.45f, 0.75f,
        0.95f, 0.65f, -0.75f,
        0.75f, 0.1f, 0.75f,
        0.95f, 0.65f, -0.75f,
        0.75f, 0.1f, 0.75f,
        0.95f, 0.1f, -0.75f,

        //right cannon bottom face
        0.3f, 0.1f, -0.75f,
        0.95f, 0.1f, -0.75f,
        0.3f, 0.25f, 0.75f,
        0.95f, 0.1f, -0.75f,
        0.3f, 0.25f, 0.75f,
        0.75f, 0.1f, 0.75f,




        //left cannon top face
        -0.3f, 0.65f, -0.75f,
        -0.95f, 0.65f, -0.75f,
        -0.3f, 0.45f, 0.75f,
        -0.95f, 0.65f, -0.75f,
        -0.3f, 0.45f, 0.75f,
        -0.75f, 0.45f, 0.75f,

        //left cannon right face
        -0.75f, 0.45f, 0.75f,
        -0.95f, 0.65f, -0.75f,
        -0.75f, 0.1f, 0.75f,
        -0.95f, 0.65f, -0.75f,
        -0.75f, 0.1f, 0.75f,
        -0.95f, 0.1f, -0.75f,

        //left cannon bottom face
        -0.3f, 0.1f, -0.75f,
        -0.95f, 0.1f, -0.75f,
        -0.3f, 0.25f, 0.75f,
        -0.95f, 0.1f, -0.75f,
        -0.3f, 0.25f, 0.75f,
        -0.75f, 0.1f, 0.75f,
    };

    this->boat_cube.width = 1.0f;
    this->boat_cube.height = 2.4f;
    this->boat_cube.length = 2.6f;

    this->object1 = create3DObject(GL_TRIANGLES, 60, vertex_buffer_data, COLOR_BROWN, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 36, vertex_buffer_data+180, COLOR_FLAGPOLE, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, 36, vertex_buffer_data+288, COLOR_GREEN, GL_FILL);
    this->object4 = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data_sail, COLOR_SAIL, GL_FILL);
}

void Boat::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate1    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    glm::mat4 rotate2    = glm::rotate((float) (this->horizontal_wobble * M_PI / 180.0f),
                                       glm::vec3(this->position.x, this->position.y, this->position.z-1.4));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    glm::mat4 rotate = rotate1 * rotate2;
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
    draw3DObject(this->object3);
    draw3DObject(this->object4);
}

void Boat::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Boat::tick() {
    this->boat_cube.x = this->position.x;
    this->boat_cube.y = this->position.y;
    this->boat_cube.z = this->position.z;
    if(this->acceleration_y > 0){
        if(this->position.y + speed_y > 0.7){
            acceleration_y = -acceleration_y;
            speed_y = 0.02;
        }
        else{
            this->position.y += speed_y;
            speed_y -= acceleration_y;}
    }
    if(this->acceleration_y < 0){
        if(this->position.y - speed_y < 0.1){
            acceleration_y = -acceleration_y;
            speed_y = 0.02;
        }
        else{
            this->position.y -= speed_y;
            speed_y += acceleration_y;
        }
    }
    if(horizontal_wobble < -5.0f || horizontal_wobble > 5.0f )
        speed = -speed;
    this->horizontal_wobble += speed;

    // this->position.x -= speed;
    // this->position.y -= speed;
}

void Boat::bounce(){
    if(this->position.y >= 0.7){
        this->position.y += vertical_speed;
        vertical_speed += gravity;
    }
}

void Boat::blow_sail(float theta){

    vertex_buffer_data_sail[6] = 1.4*sin((theta*M_PI)/180);
    vertex_buffer_data_sail[8] = 1.4*cos((theta*M_PI)/180);
    this->object4 = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data_sail, COLOR_SAIL, GL_FILL);
}
