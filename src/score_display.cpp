#include "score_display.h"
#include "main.h"

static const GLfloat vertex_buffer_data1[] = {
    -0.225f,0.25f,0.0f,
     -0.525f, 0.25f, 0.0f,
     -0.285f, 0.165f, 0.0f,
     -0.525f, 0.25f, 0.0f,
     -0.285f, 0.165f, 0.0f,
     -0.465f, 0.165f, 0.0f
};

static const GLfloat vertex_buffer_data2[] = {
    -0.225f, 0.235f, 0.0f,
    -0.285f, 0.15f, 0.0f,
    -0.285f, 0.04f, 0.0f,
    -0.285f, 0.04f, 0.0f,
    -0.225f, 0.235f, 0.0f,
    -0.225f, 0.0f, 0.0f
};


static const GLfloat vertex_buffer_data3[] = {
    -0.225f, -0.025f,0.0f,
    -0.225f, -0.235f, 0.0f,
    -0.285f, -0.15f, 0.0f,
    -0.285f, -0.15f, 0.0f,
    -0.225f, -0.04f,0.0f,
    -0.285f, -0.15f, 0.0f,
};


static const GLfloat vertex_buffer_data4[] = {
    -0.525f, -0.25f,0.0f,
    -0.465f, -0.165f, 0.0f,
    -0.285f, -0.165f, 0.0f,
    -0.285f, -0.165f, 0.0f,
    -0.525f, -0.25f,0.0f,
    -0.225f, -0.25f, 0.0f
};


static const GLfloat vertex_buffer_data5[] = {
    -0.525f, -0.025f,0.0f,
    -0.525f, -0.235f, 0.0f,
    -0.465f, -0.15f, 0.0f,
    -0.465f, -0.15f, 0.0f,
    -0.525f, -0.04f,0.0f,
    -0.465f, -0.15f, 0.0f,
};


static const GLfloat vertex_buffer_data6[] = {
    -0.525f, 0.235f, 0.0f,
    -0.465f, 0.15f, 0.0f,
    -0.465f, 0.04f, 0.0f,
    -0.465f, 0.04f, 0.0f,
    -0.525f, 0.235f, 0.0f,
    -0.525f, 0.0f, 0.0f
};


static const GLfloat vertex_buffer_data7[] = {
    -0.525f, 0.0f, 0.0f,
    -0.465f, 0.04f, 0.0f,
    -0.285f, 0.04f, 0.0f,
    -0.285f, 0.04f, 0.0f,
    -0.525f, 0.0f, 0.0f,
    -0.225f, 0.0f, 0.0f,

    -0.525f, 0.0f, 0.0f,
    -0.465f, -0.04f, 0.0f,
    -0.285f, -0.04f, 0.0f,
    -0.285f, -0.04f, 0.0f,
    -0.525f, 0.0f, 0.0f,
    -0.225f, 0.0f, 0.0f,
};


static const GLfloat vertex_buffer_data8[] = {
   -0.15f,0.25f,0.0f,
    0.15f, 0.25f, 0.0f,
    -0.09f, 0.165f, 0.0f,
    0.15f, 0.25f, 0.0f,
    -0.09f, 0.165f, 0.0f,
    0.09f, 0.165f, 0.0f
};
static const GLfloat vertex_buffer_data9[] = {
    0.15f, 0.235f, 0.0f,
    0.09f, 0.15f, 0.0f,
    0.09f, 0.04f, 0.0f,
    0.09f, 0.04f, 0.0f,
    0.15f, 0.235f, 0.0f,
    0.15f, 0.0f, 0.0f

};


static const GLfloat vertex_buffer_data10[] = {
    0.15f, -0.025f,0.0f,
    0.15f, -0.235f, 0.0f,
    0.09f, -0.15f, 0.0f,
    0.09f, -0.15f, 0.0f,
    0.15f, -0.04f,0.0f,
    0.09f, -0.15f, 0.0f,
};

static const GLfloat vertex_buffer_data11[] = {
    0.15f, -0.25f,0.0f,
    0.09f, -0.165f, 0.0f,
    -0.09f, -0.165f, 0.0f,
    -0.09f, -0.165f, 0.0f,
    0.15f, -0.25f,0.0f,
    -0.15f, -0.25f, 0.0f
};

static const GLfloat vertex_buffer_data12[] = {
    -0.15f, -0.025f,0.0f,
    -0.15f, -0.235f, 0.0f,
    -0.09f, -0.15f, 0.0f,
    -0.09f, -0.15f, 0.0f,
    -0.15f, -0.04f,0.0f,
    -0.09f, -0.15f, 0.0f,
};

static const GLfloat vertex_buffer_data13[] = {
    -0.15f, 0.235f, 0.0f,
    -0.09f, 0.15f, 0.0f,
    -0.09f, 0.04f, 0.0f,
    -0.09f, 0.04f, 0.0f,
    -0.15f, 0.235f, 0.0f,
    -0.15f, 0.0f, 0.0f
};

static const GLfloat vertex_buffer_data14[] = {
    0.15f, 0.0f, 0.0f,
    0.09f, 0.04f, 0.0f,
    -0.09f, 0.04f, 0.0f,
    -0.09f, 0.04f, 0.0f,
    0.15f, 0.0f, 0.0f,
    -0.15f, 0.0f, 0.0f,

    0.15f, 0.0f, 0.0f,
    0.09f, -0.04f, 0.0f,
    -0.09f, -0.04f, 0.0f,
    -0.09f, -0.04f, 0.0f,
    0.15f, 0.0f, 0.0f,
    -0.15f, 0.0f, 0.0f,
};

static const GLfloat vertex_buffer_data15[] = {
   0.225f,0.25f,0.0f,
    0.525f, 0.25f, 0.0f,
    0.285f, 0.165f, 0.0f,
    0.525f, 0.25f, 0.0f,
    0.285f, 0.165f, 0.0f,
    0.465f, 0.165f, 0.0f
};

static const GLfloat vertex_buffer_data16[] = {
    0.525f, 0.235f, 0.0f,
    0.465f, 0.15f, 0.0f,
    0.465f, 0.04f, 0.0f,
    0.465f, 0.04f, 0.0f,
    0.525f, 0.235f, 0.0f,
    0.525f, 0.0f, 0.0f

};

static const GLfloat vertex_buffer_data17[] = {
    0.525f, -0.025f,0.0f,
    0.525f, -0.235f, 0.0f,
    0.465f, -0.15f, 0.0f,
    0.465f, -0.15f, 0.0f,
    0.525f, -0.04f,0.0f,
    0.465f, -0.15f, 0.0f,
};

static const GLfloat vertex_buffer_data18[] = {
    0.525f, -0.25f,0.0f,
    0.465f, -0.165f, 0.0f,
    0.285f, -0.165f, 0.0f,
    0.285f, -0.165f, 0.0f,
    0.525f, -0.25f,0.0f,
    0.225f, -0.25f, 0.0f
};

static const GLfloat vertex_buffer_data19[] = {
    0.225f, -0.025f,0.0f,
    0.225f, -0.235f, 0.0f,
    0.285f, -0.15f, 0.0f,
    0.285f, -0.15f, 0.0f,
    0.225f, -0.04f,0.0f,
    0.285f, -0.15f, 0.0f,
};

static const GLfloat vertex_buffer_data20[] = {
    0.225f, 0.235f, 0.0f,
    0.285f, 0.15f, 0.0f,
    0.285f, 0.04f, 0.0f,
    0.285f, 0.04f, 0.0f,
    0.225f, 0.235f, 0.0f,
    0.225f, 0.0f, 0.0f
};

static const GLfloat vertex_buffer_data21[] = {
    0.525f, 0.0f, 0.0f,
    0.465f, 0.04f, 0.0f,
    0.285f, 0.04f, 0.0f,
    0.285f, 0.04f, 0.0f,
    0.525f, 0.0f, 0.0f,
    0.225f, 0.0f, 0.0f,

    0.525f, 0.0f, 0.0f,
    0.465f, -0.04f, 0.0f,
    0.285f, -0.04f, 0.0f,
    0.285f, -0.04f, 0.0f,
    0.525f, 0.0f, 0.0f,
    0.225f, 0.0f, 0.0f,
};



Display::Display(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices

    this->object1 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data1, COLOR_BLACK, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data2, COLOR_BLACK, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data3, COLOR_BLACK, GL_FILL);
    this->object4 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data4, COLOR_BLACK, GL_FILL);
    this->object5 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data5, COLOR_BLACK, GL_FILL);
    this->object6 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data6, COLOR_BLACK, GL_FILL);
    this->object7 = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data7, COLOR_BLACK, GL_FILL);


    this->object8 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data8, COLOR_BLACK, GL_FILL);
    this->object9 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data9, COLOR_BLACK, GL_FILL);
    this->object10 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data10, COLOR_BLACK, GL_FILL);
    this->object11 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data11, COLOR_BLACK, GL_FILL);
    this->object12 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data12, COLOR_BLACK, GL_FILL);
    this->object13 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data13, COLOR_BLACK, GL_FILL);
    this->object14 = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data14, COLOR_BLACK, GL_FILL);

    this->object15 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data15, COLOR_BLACK, GL_FILL);
    this->object16 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data16, COLOR_BLACK, GL_FILL);
    this->object17 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data17, COLOR_BLACK, GL_FILL);
    this->object18 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data18, COLOR_BLACK, GL_FILL);
    this->object19 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data19, COLOR_BLACK, GL_FILL);
    this->object20 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data20, COLOR_BLACK, GL_FILL);
    this->object21 = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data21, COLOR_BLACK, GL_FILL);

}

void Display::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centeRED at 0, 0, 0 of cube arouund which we waant to rotate
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
    draw3DObject(this->object11);
    draw3DObject(this->object12);
    draw3DObject(this->object13);
    draw3DObject(this->object14);
    draw3DObject(this->object15);
    draw3DObject(this->object16);
    draw3DObject(this->object17);
    draw3DObject(this->object18);
    draw3DObject(this->object19);
    draw3DObject(this->object20);
    draw3DObject(this->object21);
}

void Display::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Display::make_number(int num){
    int ones = num % 10;
    int tens = (num / 10) % 10;
    int hundREDs = (num / 100) % 10;

    if(hundREDs == 0 || hundREDs == 2 || hundREDs == 3 || hundREDs == 5 || hundREDs == 6 || hundREDs == 7
            || hundREDs == 8 || hundREDs == 9){
        this->object1 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data1, COLOR_RED, GL_FILL);
    }
    else{
        this->object1 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data1, COLOR_BLACK, GL_FILL);
    }

    if(hundREDs == 0 || hundREDs == 1 || hundREDs == 2 || hundREDs == 3 || hundREDs == 4|| hundREDs == 7 || hundREDs == 8 || hundREDs == 9)
        this->object2 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data2, COLOR_RED, GL_FILL);
    else
        this->object2 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data2, COLOR_BLACK, GL_FILL);

    if(hundREDs == 0 || hundREDs == 1 ||hundREDs == 3 || hundREDs == 4|| hundREDs == 5 || hundREDs == 6
            || hundREDs == 7 || hundREDs == 8 || hundREDs == 9)
        this->object3 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data3, COLOR_RED, GL_FILL);
    else
        this->object3 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data3, COLOR_BLACK, GL_FILL);

    if(hundREDs == 0 || hundREDs == 2 || hundREDs == 3 || hundREDs == 5 || hundREDs == 6 ||hundREDs == 8 || hundREDs == 9)
        this->object4 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data4, COLOR_RED, GL_FILL);
    else
        this->object4 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data4, COLOR_BLACK, GL_FILL);

    if(hundREDs == 0 || hundREDs == 2 ||hundREDs == 6|| hundREDs == 8)
        this->object5 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data5, COLOR_RED, GL_FILL);
    else
        this->object5 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data5, COLOR_BLACK, GL_FILL);

    if(hundREDs == 0 ||hundREDs == 4||hundREDs == 5 || hundREDs == 6 ||hundREDs == 8 || hundREDs == 9)
        this->object6 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data6, COLOR_RED, GL_FILL);
    else
        this->object6 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data6, COLOR_BLACK, GL_FILL);

    if(hundREDs == 2 || hundREDs == 3 ||hundREDs == 4|| hundREDs == 5 || hundREDs == 6||hundREDs == 8 || hundREDs == 9)
        this->object7 = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data7, COLOR_RED, GL_FILL);
    else
        this->object7 = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data7, COLOR_BLACK, GL_FILL);

    if(tens == 0 || tens == 2 || tens == 3 || tens == 5 || tens == 6 || tens == 7
            || tens == 8 || tens == 9){
        this->object8 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data8, COLOR_RED, GL_FILL);
    }
    else{
        this->object8 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data8, COLOR_BLACK, GL_FILL);
    }

    if(tens == 0 || tens == 1 || tens == 2 || tens == 3 || tens == 4|| tens == 7 || tens == 8 || tens == 9)
        this->object9 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data9, COLOR_RED, GL_FILL);
    else
        this->object9 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data9, COLOR_BLACK, GL_FILL);

    if(tens == 0 || tens == 1 ||tens == 3 || tens == 4|| tens == 5 || tens == 6
            || tens == 7 || tens == 8 || tens == 9)
        this->object10 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data10, COLOR_RED, GL_FILL);
    else
        this->object10 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data10, COLOR_BLACK, GL_FILL);

    if(tens == 0 || tens == 2 || tens == 3 || tens == 5 || tens == 6 ||tens == 8 || tens == 9)
        this->object11 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data11, COLOR_RED, GL_FILL);
    else
        this->object11 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data11, COLOR_BLACK, GL_FILL);

    if(tens == 0 || tens == 2 ||tens == 6|| tens == 8)
        this->object12 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data12, COLOR_RED, GL_FILL);
    else
        this->object12 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data12, COLOR_BLACK, GL_FILL);

    if(tens == 0 ||tens == 4||tens == 5 || tens == 6 ||tens == 8 || tens == 9)
        this->object13 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data13, COLOR_RED, GL_FILL);
    else
        this->object13 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data13, COLOR_BLACK, GL_FILL);

    if(tens == 2 || tens == 3 ||tens == 4|| tens == 5 || tens == 6||tens == 8 || tens == 9)
        this->object14 = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data14, COLOR_RED, GL_FILL);
    else
        this->object14 = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data14, COLOR_BLACK, GL_FILL);










































    if(ones == 0 || ones == 2 || ones == 3 || ones == 5 || ones == 6 || ones == 7
            || ones == 8 || ones == 9){
        this->object15 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data15, COLOR_RED, GL_FILL);
    }
    else{
        this->object15 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data15, COLOR_BLACK, GL_FILL);
    }

    if(ones == 0 || ones == 1 || ones == 2 || ones == 3 || ones == 4|| ones == 7 || ones == 8 || ones == 9)
        this->object16 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data16, COLOR_RED, GL_FILL);
    else
        this->object16 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data16, COLOR_BLACK, GL_FILL);

    if(ones == 0 || ones == 1 ||ones == 3 || ones == 4|| ones == 5 || ones == 6
            || ones == 7 || ones == 8 || ones == 9)
        this->object17 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data17, COLOR_RED, GL_FILL);
    else
        this->object17 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data17, COLOR_BLACK, GL_FILL);

    if(ones == 0 || ones == 2 || ones == 3 || ones == 5 || ones == 6 ||ones == 8 || ones == 9)
        this->object18 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data18, COLOR_RED, GL_FILL);
    else
        this->object18 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data18, COLOR_BLACK, GL_FILL);

    if(ones == 0 || ones == 2 ||ones == 6|| ones == 8)
        this->object19 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data19, COLOR_RED, GL_FILL);
    else
        this->object19 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data19, COLOR_BLACK, GL_FILL);

    if(ones == 0 ||ones == 4||ones == 5 || ones == 6 ||ones == 8 || ones == 9)
        this->object20 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data20, COLOR_RED, GL_FILL);
    else
        this->object20 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data20, COLOR_BLACK, GL_FILL);

    if(ones == 2 || ones == 3 ||ones == 4|| ones == 5 || ones == 6||ones == 8 || ones == 9)
        this->object21 = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data21, COLOR_RED, GL_FILL);
    else
        this->object21 = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data21, COLOR_BLACK, GL_FILL);

}
