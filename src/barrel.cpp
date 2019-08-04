#include "barrel.h"
#include "main.h"


Barrel::Barrel(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;

    speed_x = 0.03;
    speed_z = 0.02;

    this->horizontal_wobble = 0.0f;
    this->speed = 0.25;

    this->gift_num = rand()%3;

    this->tick_control = true;

    this->movement_decider = rand()%4;

    this->barrel_cube.height = 0.7;
    this->barrel_cube.width = 1.0f;
    this->barrel_cube.length = 2.0f;

    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
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
    };

    GLfloat health_array_data[369];
    double rad = M_PI/20.0;
    for(int i = 0; i < 20; i++){
        health_array_data[9*i] = cos(i*rad)*0.2+0.2;
        health_array_data[9*i + 1] = sin(i*rad)*0.2+1.2;
        health_array_data[9*i + 2] = 0.0f;
        health_array_data[9*i + 3] = cos((i+1)*rad)*0.2+0.2;
        health_array_data[9*i + 4] = sin((i+1)*rad)*0.2+1.2;
        health_array_data[9*i + 5] = 0.0f;
        health_array_data[9*i + 6] = 0.2f;
        health_array_data[9*i + 7] = 1.2f;
        health_array_data[9*i + 8] = 0.0f;
    }

    for(int i = 0; i < 20; i++){
        health_array_data[9*(i+20)] = cos(i*rad)*0.2-0.2;
        health_array_data[9*(i+20) + 1] = sin(i*rad)*0.2+1.2;
        health_array_data[9*(i+20) + 2] = 0.0f;
        health_array_data[9*(i+20) + 3] = cos((i+1)*rad)*0.2-0.2;
        health_array_data[9*(i+20) + 4] = sin((i+1)*rad)*0.2+1.2;
        health_array_data[9*(i+20) + 5] = 0.0f;
        health_array_data[9*(i+20) + 6] = -0.2f;
        health_array_data[9*(i+20) + 7] = 1.2f;
        health_array_data[9*(i+20) + 8] = 0.0f;
    }
    health_array_data[360] = -0.4f;
    health_array_data[361] = 1.2f;
    health_array_data[362] = 0.0f;
    health_array_data[363] = 0.4f;
    health_array_data[364] = 1.2f;
    health_array_data[365] = 0.0f;
    health_array_data[366] = 0.0f;
    health_array_data[367] = 0.9f;
    health_array_data[368] = 0.0f;

    static const GLfloat multiplier_meter_data[] = {
        -0.5f, 1.4f, 0.0f,
        0.0f, 2.9f, 0.0f,
        0.5f, 1.4f, 0.0f,
        -0.5f, 2.4f, 0.0f,
        0.5f, 2.4f, 0.0f,
        0.0f, 0.9f, 0.0f
    };

    GLfloat speed_boost_data[18];
    speed_boost_data[0] = -0.3f;
    speed_boost_data[1] = 1.6f;
    speed_boost_data[2] = 0.0f;
    speed_boost_data[3] = 0.1f;
    speed_boost_data[4] = 2.3f;
    speed_boost_data[5] = 0.0f;
    speed_boost_data[6] = 0.1f;
    speed_boost_data[7] = 1.6f;
    speed_boost_data[8] = 0.0f;

    speed_boost_data[9] = -0.1f;
    speed_boost_data[10] = 1.6f;
    speed_boost_data[11] = 0.0f;
    speed_boost_data[12] = 0.3f;
    speed_boost_data[13] = 1.6f;
    speed_boost_data[14] = 0.0f;
    speed_boost_data[15] = -0.1f;
    speed_boost_data[16] = 0.9f;
    speed_boost_data[17] = 0.0f;


    this->object1 = create3DObject(GL_TRIANGLES, 36, vertex_buffer_data, COLOR_BARREL, GL_FILL);
    if(gift_num == 0)
        this->object2 = create3DObject(GL_TRIANGLES, 123, health_array_data, COLOR_RED, GL_FILL);
    else if(gift_num == 1)
        this->object2 = create3DObject(GL_TRIANGLES, 6, multiplier_meter_data, COLOR_GREEN, GL_FILL);
    else{
        this->object2 = create3DObject(GL_TRIANGLES, 6, speed_boost_data, COLOR_SAIL, GL_FILL);
    }
}

void Barrel::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate1    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    glm::mat4 rotate2    = glm::rotate((float) (this->horizontal_wobble* M_PI / 180.0f),
                                       glm::vec3(this->position.x,
                                                 this->position.y,
                                                 this->position.z - 0.5));
    glm::mat4 rotate = rotate1 * rotate2;
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
}

void Barrel::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Barrel::tick() {
    this->barrel_cube.x = position.x;
    this->barrel_cube.y = position.y;
    this->barrel_cube.z = position.z;

    if(tick_control){
        if(movement_decider == 0){
            this->position.x -= speed_x;
            this->position.z -= speed_z;
        }
        if(movement_decider == 1){
            this->position.x -= speed_x;
            this->position.z += speed_z;
        }
        if(movement_decider == 2){
            this->position.x += speed_x;
            this->position.z -= speed_z;
        }
        if(movement_decider == 3){
            this->position.x += speed_x;
            this->position.z += speed_z;
        }
        if(horizontal_wobble < -5.0f || horizontal_wobble > 5.0f )
            speed = -speed;
        this->horizontal_wobble += speed;
    }
}

