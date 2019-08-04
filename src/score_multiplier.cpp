#include "main.h"
#include "score_multiplier.h"

static const GLfloat vertex_buffer_data1[] = {
    -0.19f, 0.08f, 0.0f,
    -0.29f, 0.08f, 0.0f,
    -0.29f, -0.08f, 0.0f,
    -0.29f, -0.08f, 0.0f,
    -0.19f, 0.08f, 0.0f,
    -0.19f, -0.08f, 0.0f
};

static const GLfloat vertex_buffer_data2[] = {
    -0.07f, 0.08f, 0.0f,
    -0.17f, 0.08f, 0.0f,
    -0.17f, -0.08f, 0.0f,
    -0.17f, -0.08f, 0.0f,
    -0.07f, 0.08f, 0.0f,
    -0.07f, -0.08f, 0.0f
};

static const GLfloat vertex_buffer_data3[] = {
    0.05f, 0.08f, 0.0f,
    -0.05f, 0.08f, 0.0f,
    -0.05f, -0.08f, 0.0f,
    -0.05f, -0.08f, 0.0f,
    0.05f, 0.08f, 0.0f,
    0.05f, -0.08f, 0.0f
};

static const GLfloat vertex_buffer_data4[] = {
    0.17f, 0.08f, 0.0f,
    0.07f, 0.08f, 0.0f,
    0.07f, -0.08f, 0.0f,
    0.07f, -0.08f, 0.0f,
    0.17f, 0.08f, 0.0f,
    0.17f, -0.08f, 0.0f
};

static const GLfloat vertex_buffer_data5[] = {
    0.19f, 0.08f, 0.0f,
    0.29f, 0.08f, 0.0f,
    0.29f, -0.08f, 0.0f,
    0.29f, -0.08f, 0.0f,
    0.19f, 0.08f, 0.0f,
    0.19f, -0.08f, 0.0f
};

Score::Score(float x, float y, float z, color_t color){
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    this->object1 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data1, color, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data2, color, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data3, color, GL_FILL);
    this->object4 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data4, color, GL_FILL);
    this->object5 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data5, color, GL_FILL);
}

void Score::draw(glm::mat4 VP) {
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
}

void Score::set_color(color_t color, int index){
    if(index == 1)
        this->object1 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data1, color, GL_FILL);
    else if(index == 2)
        this->object2 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data2, color, GL_FILL);
    else if(index == 3)
        this->object3 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data3, color, GL_FILL);
    else if(index == 4)
        this->object4 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data4, color, GL_FILL);
    else if(index == 5)
        this->object5 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data5, color, GL_FILL);
}

void Score::set_position(float x, float y, float z){
    this->position = glm::vec3(x, y, z);
}
