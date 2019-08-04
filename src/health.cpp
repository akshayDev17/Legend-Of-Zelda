#include "health.h"
#include "main.h"

static const GLfloat vertex_buffer_data1[] = {
    -0.38f, 0.05f, 0.0f,
    -0.24f, 0.05f, 0.0f,
    -0.38f, -0.05f, 0.0f,
    -0.24f, 0.05f, 0.0f,
    -0.38f, -0.05f, 0.0f,
    -0.24f, -0.05f, 0.0f
};

static const GLfloat vertex_buffer_data2[] = {
    -0.305f, 0.05f, 0.0f,
    -0.165f, 0.05f, 0.0f,
    -0.305f, -0.05f, 0.0f,
    -0.165f, 0.05f, 0.0f,
    -0.305f, -0.05f, 0.0f,
    -0.165f, -0.05f, 0.0f
};

static const GLfloat vertex_buffer_data3[] = {
    -0.23f, 0.05f, 0.0f,
    -0.09f, 0.05f, 0.0f,
    -0.23f, -0.05f, 0.0f,
    -0.09f, 0.05f, 0.0f,
    -0.23f, -0.05f, 0.0f,
    -0.09f, -0.05f, 0.0f
};

static const GLfloat vertex_buffer_data4[] = {
    -0.155f, 0.05f, 0.0f,
    -0.015f, 0.05f, 0.0f,
    -0.155f, -0.05f, 0.0f,
    -0.015f, 0.05f, 0.0f,
    -0.155f, -0.05f, 0.0f,
    -0.015f, -0.05f, 0.0f
};

static const GLfloat vertex_buffer_data5[] = {
    -0.08f, 0.05f, 0.0f,
    0.06f, 0.05f, 0.0f,
    -0.08f, -0.05f, 0.0f,
    0.06f, 0.05f, 0.0f,
    -0.08f, -0.05f, 0.0f,
    0.06f, -0.05f, 0.0f
};

static const GLfloat vertex_buffer_data6[] = {
    -0.005f, 0.05f, 0.0f,
    0.135f, 0.05f, 0.0f,
    -0.005f, -0.05f, 0.0f,
    0.135f, 0.05f, 0.0f,
    -0.005f, -0.05f, 0.0f,
    0.135f, -0.05f, 0.0f
};

static const GLfloat vertex_buffer_data7[] = {
    0.07f, 0.05f, 0.0f,
    0.21f, 0.05f, 0.0f,
    0.07f, -0.05f, 0.0f,
    0.21f, 0.05f, 0.0f,
    0.07f, -0.05f, 0.0f,
    0.21f, -0.05f, 0.0f
};

static const GLfloat vertex_buffer_data8[] = {
    0.145f, 0.05f, 0.0f,
    0.285f, 0.05f, 0.0f,
    0.145f, -0.05f, 0.0f,
    0.285f, 0.05f, 0.0f,
    0.145f, -0.05f, 0.0f,
    0.285f, -0.05f, 0.0f
};

static const GLfloat vertex_buffer_data9[] = {
    0.22f, 0.05f, 0.0f,
    0.362f, 0.05f, 0.0f,
    0.22f, -0.05f, 0.0f,
    0.362f, 0.05f, 0.0f,
    0.22f, -0.05f, 0.0f,
    0.362f, -0.05f, 0.0f
};

static const GLfloat vertex_buffer_data10[] = {
    0.295f, 0.05f, 0.0f,
    0.437f, 0.05f, 0.0f,
    0.295f, -0.05f, 0.0f,
    0.437f, 0.05f, 0.0f,
    0.295f, -0.05f, 0.0f,
    0.437f, -0.05f, 0.0f
};


Health::Health(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices


    this->object1 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data1, COLOR_RED, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data2, COLOR_RED, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data3, COLOR_RED, GL_FILL);
    this->object4 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data4, COLOR_SAIL, GL_FILL);
    this->object5 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data5, COLOR_SAIL, GL_FILL);
    this->object6 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data6, COLOR_SAIL, GL_FILL);
    this->object7 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data7, COLOR_GREEN, GL_FILL);
    this->object8 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data8, COLOR_GREEN, GL_FILL);
    this->object9 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data9, COLOR_GREEN, GL_FILL);
    this->object10 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data10, COLOR_GREEN, GL_FILL);
}

void Health::draw(glm::mat4 VP) {
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
    draw3DObject(this->object3);
    draw3DObject(this->object4);
    draw3DObject(this->object5);
    draw3DObject(this->object6);
    draw3DObject(this->object7);
    draw3DObject(this->object8);
    draw3DObject(this->object9);
    draw3DObject(this->object10);
}

void Health::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Health::reduce_health(int index){
    if(index == 1)
        this->object1 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data1, COLOR_BLACK, GL_FILL);
    else if(index == 2)
        this->object2 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data2, COLOR_BLACK, GL_FILL);
    else if(index == 3)
        this->object3 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data3, COLOR_BLACK, GL_FILL);
    else if(index == 4)
        this->object4 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data4, COLOR_BLACK, GL_FILL);
    else if(index == 5)
        this->object5 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data5, COLOR_BLACK, GL_FILL);
    else if(index == 6)
        this->object6 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data6, COLOR_BLACK, GL_FILL);
    else if(index == 7)
        this->object7 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data7, COLOR_BLACK, GL_FILL);
    else if(index == 8)
        this->object8 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data8, COLOR_BLACK, GL_FILL);
    else if(index == 9)
        this->object9 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data9, COLOR_BLACK, GL_FILL);
    else if(index == 10)
        this->object10 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data10, COLOR_BLACK, GL_FILL);
}

void Health::increase_health(int index){
    if(index == 1)
        this->object1 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data1, COLOR_RED, GL_FILL);
    else if(index == 2)
        this->object2 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data2, COLOR_RED, GL_FILL);
    else if(index == 3)
        this->object3 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data3, COLOR_RED, GL_FILL);
    else if(index == 4)
        this->object4 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data4, COLOR_SAIL, GL_FILL);
    else if(index == 5)
        this->object5 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data5, COLOR_SAIL, GL_FILL);
    else if(index == 6)
        this->object6 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data6, COLOR_SAIL, GL_FILL);
    else if(index == 7)
        this->object7 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data7, COLOR_GREEN, GL_FILL);
    else if(index == 8)
        this->object8 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data8, COLOR_GREEN, GL_FILL);
    else if(index == 9)
        this->object9 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data9, COLOR_GREEN, GL_FILL);
    else if(index == 10)
        this->object10 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data10, COLOR_GREEN, GL_FILL);
}
