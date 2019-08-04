#include "main.h"
#include "timer.h"
#include "ball.h"
#include "water.h"
#include "rock.h"
#include "boat.h"
#include "cannonball.h"
#include "stars.h"
#include "score_multiplier.h"
#include "health.h"
#include "enemy.h"
#include "barrel.h"
#include "score_display.h"
#include "boss_enemy.h"
#include "island.h"
#include "human.h"
#include "treasure.h"



#include <stdlib.h>



using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;

/**************************
* Customizable functions *
**************************/

//Ball ball1;

Water wa;

Island land;

Boat b;

Barrel bar[10];

Cannonball b1, b2, boss_monster_ball;

Enemy monsters[4];

Cannonball monster_ball[4];

Stars s[10];

Boss boss_monster;

Score score_object;

Display dip;

Health health_bar;

Human link;

Treasure chest;

int man_count = 0;



Rock roc[25];

int score = 0;

float screen_zoom = 1, screen_center_x = 0, screen_center_y,
screen_center_z = 0, dir_x, dir_y,dir_z, boss_dir_x, boss_dir_y, boss_dir_z,sail_angle = 0;
float camera_x, camera_y, camera_z, target_x, target_y, target_z,
temp_y;
bool follow_up_view_control = true;

bool heli_cam,boat_view,top_view,tower_view, switch_on_booster,
switch_on_multiplier, disembark, kill1,kill2,kill3 = false;

int camera_mode,booster_counter, multiplier_counter,limit_breaker;

int wind_counter, enable_sail = 0;

bool jump_control;

int multiplier = 1,count_dead_enemies = 0, boss_health = 150;

float x_at_firing, z_at_firing;

int nm = rand()%1000;

Timer t60(1.0 / 60);

void set_target(float x, float y, float z){
    target_x = x;
    target_y = y;
    target_z = z;
    /*if(b.rotation > 0){
        target_x -= sin((b.rotation*M_PI)*180);
        target_z -= cos((b.rotation*M_PI)*180);
    }*/
}

/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw() {
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);

    // Eye - Location of camera. Don't change unless you are sure!!
    glm::vec3 eye (camera_x, camera_y, camera_z);
    // Target - Where is the camera looking at.  Don't change unless you are sure!!
    glm::vec3 target (target_x, target_y, target_z);
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
    glm::vec3 up (0, 1, 0);

    // Compute Camera matrix (view)
    Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
    // Don't change unless you are sure!!
    // Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane

    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;  // MVP = Projection * View * Model

    // Scene render
    //ball1.draw(VP);
    wa.draw(VP);
    b.draw(VP);
    b1.draw(VP);
    b2.draw(VP);
    land.draw(VP);
    if(disembark)
        link.draw(VP);
    chest.draw(VP);
    score_object.draw(VP);
    for(int i = 0;i<25;i++)
        roc[i].draw(VP);
    for(int i = 0;i<10;i++)
        s[i].draw(VP);
    health_bar.draw(VP);
    for(int i = 0;i<10;i++)
        bar[i].draw(VP);
    for(int i = 0;i<4;i++){
        monsters[i].draw(VP);
        monster_ball[i].draw(VP);
    }
    dip.draw(VP);
    boss_monster.draw(VP);
    boss_monster_ball.draw(VP);
}

void tick_input(GLFWwindow *window) {
    int w = glfwGetKey(window, GLFW_KEY_W);
    int s = glfwGetKey(window, GLFW_KEY_S);
    int a = glfwGetKey(window, GLFW_KEY_A);
    int d = glfwGetKey(window, GLFW_KEY_D);
    int fire = glfwGetKey(window, GLFW_KEY_P);
    int v = glfwGetKey(window, GLFW_KEY_V);
    int up = glfwGetKey(window, GLFW_KEY_UP);
    int B = glfwGetKey(window, GLFW_KEY_B);
    int down = glfwGetKey(window, GLFW_KEY_DOWN);
    int right = glfwGetKey(window, GLFW_KEY_RIGHT);
    int left = glfwGetKey(window, GLFW_KEY_LEFT);
    int follow_cam = glfwGetKey(window, GLFW_KEY_F);
    int jump = glfwGetKey(window, GLFW_KEY_SPACE);
    int reset = glfwGetKey(window, GLFW_KEY_R);
    if(reset){
    }
    if(w){
        b.position.z -= b.speed_z*cos((b.rotation*M_PI)/180);
        b1.position.z -= b.speed_z*cos((b.rotation*M_PI)/180);
        b2.position.z -= b.speed_z*cos((b.rotation*M_PI)/180);

        b.position.x -= b.speed_x*sin((b.rotation*M_PI)/180);
        b1.position.x -= b.speed_x*sin((b.rotation*M_PI)/180);
        b2.position.x -= b.speed_x*sin((b.rotation*M_PI)/180);

        if(!(heli_cam || tower_view)){
            camera_z -= b.speed_z*cos((b.rotation*M_PI)/180);
            camera_x -= b.speed_x*sin((b.rotation*M_PI)/180);

            score_object.position.z -= b.speed_z*cos((b.rotation*M_PI)/180);
            score_object.position.x -= b.speed_x*sin((b.rotation*M_PI)/180);

            health_bar.position.z -= b.speed_z*cos((b.rotation*M_PI)/180);
            health_bar.position.x -= b.speed_x*sin((b.rotation*M_PI)/180);

            dip.position.z -= b.speed_z*cos((b.rotation*M_PI)/180);
            dip.position.x -= b.speed_x*sin((b.rotation*M_PI)/180);


        }
        if(boat_view){
            target_x = b.position.x - 2*sin((b.rotation*M_PI)/180);
            target_z = b.position.z - 2*cos((b.rotation*M_PI)/180);
        }
        if(!boat_view)
            set_target(b.position.x, temp_y, b.position.z);
    }
    if(s){
        b.position.z += 0.1*cos((b.rotation*M_PI)/180);
        b1.position.z += 0.1*cos((b.rotation*M_PI)/180);
        b2.position.z += 0.1*cos((b.rotation*M_PI)/180);

        b.position.x += 0.1*sin((b.rotation*M_PI)/180);
        b1.position.x += 0.1*sin((b.rotation*M_PI)/180);
        b2.position.x += 0.1*sin((b.rotation*M_PI)/180);

        if(!heli_cam || !tower_view){
            camera_z += 0.1*cos((b.rotation*M_PI)/180);
            camera_x += 0.1*sin((b.rotation*M_PI)/180);

            score_object.position.z += 0.1*cos((b.rotation*M_PI)/180);
            score_object.position.x += 0.1*sin((b.rotation*M_PI)/180);

            health_bar.position.z += 0.1*cos((b.rotation*M_PI)/180);
            health_bar.position.x += 0.1*sin((b.rotation*M_PI)/180);


            dip.position.z += 0.1*cos((b.rotation*M_PI)/180);
            dip.position.x += 0.1*sin((b.rotation*M_PI)/180);
        }
        set_target(b.position.x, temp_y, b.position.z);


    }
    if(a){
        b.rotation += 0.9;
        b1.rotation += 0.9;
        b2.rotation += 0.9;

        score_object.rotation += 0.9;
        score_object.set_position(b.position.x + 2*sin((b.rotation * M_PI)/180),
                                  score_object.position.y,
                                  b.position.z + 2 - 2*(1-cos((b.rotation * M_PI)/180)));

        health_bar.rotation += 0.9;
        health_bar.set_position(b.position.x + 2*sin((b.rotation * M_PI)/180),
                                health_bar.position.y,
                                b.position.z + 2 - 2*(1-cos((b.rotation * M_PI)/180)));

        dip.rotation += 0.9;
        dip.set_position(b.position.x + 2*sin((b.rotation * M_PI)/180),
                                dip.position.y,
                                b.position.z + 2 - 2*(1-cos((b.rotation * M_PI)/180)));

        if(!tower_view){
            camera_x = b.position.x + 4*sin((b.rotation * M_PI)/180);
            camera_z = b.position.z + 4 -4*(1-cos((b.rotation * M_PI)/180));

        }
        /*set_target(b.position.x - sin((b.rotation * M_PI)/180),
                   b.position.y,
                   b.position.z - cos((b.rotation * M_PI)/180));*/
        if(boat_view){
            target_x = b.position.x - 2*sin((b.rotation*M_PI)/180);
            target_z = b.position.z - 2*cos((b.rotation*M_PI)/180);
        }
        if(!boat_view)
            set_target(b.position.x, b.position.y, b.position.z);
    }
    if(d){
        b.rotation -= 0.9;
        b1.rotation -= 0.9;
        b2.rotation -= 0.9;

        score_object.rotation -= 0.9;
        score_object.set_position(b.position.x + 2*sin((b.rotation * M_PI)/180),
                                  score_object.position.y,
                                  b.position.z + 2 - 2*(1-cos((b.rotation * M_PI)/180)));

        health_bar.rotation -= 0.9;
        health_bar.set_position(b.position.x + 2*sin((b.rotation * M_PI)/180),
                                  health_bar.position.y,
                                  b.position.z + 2 - 2*(1-cos((b.rotation * M_PI)/180)));

        dip.rotation -= 0.9;
        dip.set_position(b.position.x + 2*sin((b.rotation * M_PI)/180),
                                  dip.position.y,
                                  b.position.z + 2 - 2*(1-cos((b.rotation * M_PI)/180)));

        if(!tower_view){
            camera_x = b.position.x + 4*sin((b.rotation * M_PI)/180);
            camera_z = b.position.z + 4 -4*(1-cos((b.rotation * M_PI)/180));

        }
        /*set_target(b.position.x - sin((b.rotation * M_PI)/180),
                   b.position.y,
                   b.position.z - cos((b.rotation * M_PI)/180));*/
        set_target(b.position.x, b.position.y, b.position.z);
    }
    if(jump){
        jump_control = true;
    }
    if(!follow_up_view_control){
        if(follow_cam){
            follow_up_view_control = true;
            camera_z = b.position.z + 2;
        }
    }
    if(fire){
        b1.is_launched = true;
        b2.is_launched = true;
        b2.speed_x = -b1.speed_x;
        x_at_firing = b1.position.x;
        z_at_firing = b1.position.z;
    }
    if(up && detect_collision(land.island_cube,b.boat_cube) && !disembark){
        disembark = true;
        link.position.x = b.position.x;
        link.position.z = b.position.z - 1;
        jump_control = true;
    }
    if(disembark){
        if(up){
            link.movement(1);
            camera_z -= 0.05*cos((link.rotation*M_PI)/180);
            camera_x -= 0.05*sin((link.rotation*M_PI)/180);
            set_target(link.position.x, 4, link.position.z);
        }
        if(down){
            link.movement(-1);
            camera_z += 0.05*cos((link.rotation*M_PI)/180);
            camera_x += 0.05*sin((link.rotation*M_PI)/180);
            set_target(link.position.x, 4, link.position.z);
        }
        if(left){
            link.rotation += 10;
            camera_x = link.position.x + 4*sin((link.rotation * M_PI)/180);
            camera_z = link.position.z + 4 -4*(1-cos((link.rotation * M_PI)/180));
            set_target(link.position.x, 4, link.position.z);
        }
        if(right){
            link.rotation -= 10;
            camera_x = link.position.x + 4*sin((link.rotation * M_PI)/180);
            camera_z = link.position.z + 4 -4*(1-cos((link.rotation * M_PI)/180));
            set_target(link.position.x, 4, link.position.z);
        }
        if(B && disembark)
            disembark = false;
    }
}


void tick_elements() {
    dip.make_number(score);
    if(detect_collision(link.human_cube,chest.treasure_cube) && disembark){
        score+=chest.bonus;
        chest.bonus = 0;
    }
    if(!disembark){
        if(follow_up_view_control){
            set_target(b.position.x,0.9,b.position.z);
        }
        for(int i = 0; i < 4;i++){
            if(monsters[i].is_alive){
                monsters[i].tick(b.position.x - monsters[i].position.x,
                                 b.position.z - monsters[i].position.z,
                                 b.rotation);
                if(!monster_ball[i].is_launched)
                    monster_ball[i].set_position(monsters[i].position.x
                                             ,monsters[i].position.y+3,
                                             monsters[i].position.z);
                if(distance(abs(monsters[i].position.x - b.position.x),abs(monsters[i].position.y - b.position.y),
                            abs(monsters[i].position.z - b.position.z)) <= 8){
                    monster_ball[i].is_launched = true;
                    dir_x = b.position.x - monster_ball[i].position.x;
                    dir_y = b.position.y - monster_ball[i].position.y;
                    dir_z = b.position.z - monster_ball[i].position.z;
                }
                if(monster_ball[i].is_launched){

                    float cos_theta = dir_y / pow(pow(dir_x,2)+pow(dir_y,2)+pow(dir_z,2),0.5);
                    float sin_theta = pow(1-pow(cos_theta,2),0.5);

                    float cos_phi = dir_x / pow(pow(dir_x,2)+pow(dir_z,2),0.5);
                    float sin_phi = dir_z / pow(pow(dir_x,2)+pow(dir_z,2),0.5);

                    monster_ball[i].position.y += cos_theta*0.15;

                    monster_ball[i].position.x += sin_theta*cos_phi*0.2;
                    monster_ball[i].position.z += sin_theta*sin_phi*0.2;

                }
                if(distance(abs(monster_ball[i].position.x-b.position.x),
                            abs(monster_ball[i].position.y-b.position.y),
                            monster_ball[i].position.z-b.position.z) < 2 && monster_ball[i].is_launched){
                    reduce_health();
                    monster_ball[i].is_launched = false;

                }
                if(distance(abs(monster_ball[i].position.x-b.position.x),
                            abs(monster_ball[i].position.y-b.position.y),
                            monster_ball[i].position.z-b.position.z) > 10 ){
                    monster_ball[i].is_launched = false;
                }
            }

            if(!monsters[i].is_alive && !monsters[i].score_check){
                count_dead_enemies++;
                score += 10;
                limit_breaker += 10;
                monsters[i].score_check = true;
            }

            if((detect_collision(monsters[i].enemy_cube, b1.cannon_cube) &&
                b1.is_launched)
                    || (detect_collision(monsters[i].enemy_cube, b2.cannon_cube) &&
                        b2.is_launched)){
                monsters[i].set_position(-100+10*i, 0.9, -50-10*i);
                monsters[i].is_alive = false;
            }

            if(detect_collision(monsters[i].enemy_cube, b.boat_cube) && monsters[i].is_alive){
                reduce_health();reduce_health();
                float x = monsters[i].position.x - b.position.x;
                float z = monsters[i].position.z - b.position.z;
                float cos_phi = x/pow(pow(x,2)+pow(z,2),0.5);
                float sin_phi = z/pow(pow(x,2)+pow(z,2),0.5);
                b.position.x -= b.speed_x*30*cos_phi;
                b.position.z += b.speed_z*30*sin_phi;
            }
        }

        if(count_dead_enemies == 4){
            boss_monster.emerge_boss();
        }


















        if(boss_monster.has_emerged){

            if(boss_monster.is_alive){
                boss_monster.tick(b.position.x - boss_monster.position.x,
                                  b.position.z - boss_monster.position.z,
                                  b.rotation);
                if(!boss_monster_ball.is_launched)
                    boss_monster_ball.set_position(boss_monster.position.x,
                                               boss_monster.position.y+3.5,
                                               boss_monster.position.z);
                if(distance(abs(boss_monster.position.x - b.position.x),abs(boss_monster.position.y - b.position.y),
                            abs(boss_monster.position.z - b.position.z)) <= 13){
                    boss_monster_ball.is_launched = true;
                    boss_dir_x = b.position.x - boss_monster_ball.position.x;
                    boss_dir_y = b.position.y - boss_monster_ball.position.y;
                    boss_dir_z = b.position.z - boss_monster_ball.position.z;
                }
                if(boss_monster_ball.is_launched){

                    float cos_theta = boss_dir_y / pow(pow(boss_dir_x,2)+pow(boss_dir_y,2)+pow(boss_dir_z,2),0.5);
                    float sin_theta = pow(1-pow(cos_theta,2),0.5);

                    float cos_phi = boss_dir_x / pow(pow(boss_dir_x,2)+pow(boss_dir_z,2),0.5);
                    float sin_phi = boss_dir_z / pow(pow(boss_dir_x,2)+pow(boss_dir_z,2),0.5);

                    boss_monster_ball.position.y += cos_theta*0.15;

                    boss_monster_ball.position.x += sin_theta*cos_phi*0.2;
                    boss_monster_ball.position.z += sin_theta*sin_phi*0.2;

                }
                if(distance(abs(boss_monster_ball.position.x-b.position.x),
                            abs(boss_monster_ball.position.y-b.position.y),
                            boss_monster_ball.position.z-b.position.z) < 2 && boss_monster_ball.is_launched){
                    boss_monster_ball.is_launched = false;
                    reduce_health();reduce_health();
                }
                if(distance(abs(boss_monster_ball.position.x-b.position.x),
                            abs(boss_monster_ball.position.y-b.position.y),
                            boss_monster_ball.position.z-b.position.z) > 10 ){
                    boss_monster_ball.is_launched = false;
                }
            }


            if(!boss_monster.is_alive && !boss_monster.score_check){
                score += 20;
                limit_breaker += 20;
                boss_monster.score_check = true;
            }

            if((detect_collision(boss_monster.boss_cube, b1.cannon_cube) &&
                b1.is_launched)
                    || (detect_collision(boss_monster.boss_cube, b2.cannon_cube) &&
                        b2.is_launched)){
                if(boss_health <= 0){
                    boss_monster.set_position(0, -9, -20);
                    boss_monster.is_alive = false;
                    count_dead_enemies = 0;
                    boss_monster.has_emerged = false;
                }
                else
                    boss_health -= 20;
            }

            if(detect_collision(boss_monster.boss_cube, b.boat_cube) && boss_monster.is_alive){
                reduce_health();reduce_health();reduce_health();reduce_health();
                float x = boss_monster.position.x - b.position.x;
                float z = boss_monster.position.z - b.position.z;
                float cos_phi = x/pow(pow(x,2)+pow(z,2),0.5);
                float sin_phi = z/pow(pow(x,2)+pow(z,2),0.5);
                b.position.x -= b.speed_x*40*cos_phi;
                b.position.z += b.speed_z*40*sin_phi;
            }
        }





















        for(int i = 0;i<10;i++)
            s[i].tick();
        for(int i = 0;i<10;i++){
            bar[i].tick();
            if(bar[i].position.x < -18.0f || bar[i].position.x > 18.0f
                    || bar[i].position.z < -60  || bar[i].position.z > 10){
                bar[i].speed_x = -bar[i].speed_x;
                bar[i].speed_z = -bar[i].speed_z;
            }
        }
        for(int i = 0;i<25;i++){
            if(roc[i].check_collision(b.boat_cube) && roc[i].damage){
                b.health -= roc[i].damage;
                health_bar.reduce_health(b.health+1);
                roc[i].reset_damage();
                float x = b.position.x - roc[i].position.x;
                float z = b.position.z - roc[i].position.x;
                float cos_phi = x/pow(pow(x,2)+pow(z,2),0.5);
                float sin_phi = z/pow(pow(x,2)+pow(z,2),0.5);
                b.position.x -= b.speed_x*15*cos_phi;
                b.position.z += b.speed_z*15*sin_phi;
                if(!heli_cam){
                    camera_z += b.speed_z*15*sin_phi;
                    camera_x -= b.speed_x*15*cos_phi;

                    score_object.position.z += b.speed_z*15*sin_phi;
                    score_object.position.x -= b.speed_x*15*cos_phi;

                    health_bar.position.z += b.speed_z*15*sin_phi;
                    health_bar.position.x -= b.speed_x*15*cos_phi;

                }

            }
            if(distance(abs(b.position.x - roc[i].position.x),
                        abs(b.position.y - roc[i].position.y),
                        abs(b.position.z - roc[i].position.z)) > 2.5
                    && !roc[i].damage)
                roc[i].damage = 1;

        }
        if(b1.is_launched && distance(abs(b1.position.x - x_at_firing),0,
                                      abs(b1.position.z - z_at_firing))
                > 5){
            b1.is_launched = false;
            b2.is_launched = false;
        }
        for(int i = 0;i<10; i++){
            if(detect_collision(b.boat_cube, s[i].star_cube)){
                score += s[i].points*multiplier;
                if(multiplier == 1)
                    limit_breaker += s[i].points;
                s[i].points = 0;
                if(limit_breaker>=10)
                    score_object.set_color(COLOR_RED,1);
                if(limit_breaker>=20)
                    score_object.set_color(COLOR_RED,2);
                if(limit_breaker>=30)
                    score_object.set_color(COLOR_RED,3);
                if(limit_breaker>=40)
                    score_object.set_color(COLOR_RED,4);
                if(limit_breaker>=50)
                    score_object.set_color(COLOR_RED,5);
                int n = rand() % 48 + 1;
                int temp_z = n / 8;
                n = n % 7 + 1;
                if(n == 1)
                    s[i].set_position( -12, 0.7, -70 + 10*temp_z);
                else if(n == 2)
                    s[i].set_position( -7, 0.7, -70 + 10*temp_z);
                else if(n == 3)
                    s[i].set_position( -2, 0.7, -70 + 10*temp_z);
                else if(n == 4)
                    s[i].set_position( 3, 0.7, -70+ 10*temp_z);
                else if(n == 5)
                    s[i].set_position( 5, 0.7, -70+ 10*temp_z);
                else if(n == 6)
                    s[i].set_position( 8, 0.7, -70+ 10*temp_z);
                else if(n == 7)
                    s[i].set_position(-18, 0.7, -70+ 10*temp_z);
                s[i].points = rand()%10 + 1;
                if(limit_breaker > 50){
                    switch_on_multiplier = true;
                    limit_breaker = 0;
                }
            }
        }
        if(limit_breaker>=10)
            score_object.set_color(COLOR_RED,1);
        if(limit_breaker>=20)
            score_object.set_color(COLOR_RED,2);
        if(limit_breaker>=30)
            score_object.set_color(COLOR_RED,3);
        if(limit_breaker>=40)
            score_object.set_color(COLOR_RED,4);
        if(limit_breaker>=50)
            score_object.set_color(COLOR_RED,5);
        if(switch_on_multiplier && multiplier_counter <= 450){
            multiplier = 2;
            multiplier_counter++;
        }
        if(multiplier_counter > 450){
            multiplier = 1;
            multiplier_counter = 0;
            switch_on_multiplier = false;
            score_object.set_color(COLOR_BLACK,1);
            score_object.set_color(COLOR_BLACK,2);
            score_object.set_color(COLOR_BLACK,3);
            score_object.set_color(COLOR_BLACK,4);
            score_object.set_color(COLOR_BLACK,5);
        }
        for(int i = 0;i<10; i++){
            if(detect_collision(b.boat_cube, bar[i].barrel_cube)){
                printf("%d\n",bar[i].gift_num);
                if(b.health < 10 && bar[i].gift_num == 0){
                    b.health += 1;
                    bar[i].tick_control = false;
                    health_bar.increase_health(b.health);
                    int n = rand() % 64 + 1;
                    int temp_z = n / 8;
                    n = n % 7 + 1;
                    if(n == 1)
                        bar[i].set_position(-13, 0, -70 + 10*temp_z);
                    else if(n == 2)
                        bar[i].set_position( -11, 0, -70 + 10*temp_z);
                    else if(n == 3)
                        bar[i].set_position( -18, 0, -70 + 10*temp_z);
                    else if(n == 4)
                        bar[i].set_position( 4, 0, -70+ 10*temp_z);
                    else if(n == 5)
                        bar[i].set_position( 7, 0, -70+ 10*temp_z);
                    else if(n == 6)
                        bar[i].set_position( 10, 0, -70+ 10*temp_z);
                    else if(n == 7)
                        bar[i].set_position( -18, 0, -70+ 10*temp_z);
                    bar[i].tick_control = true;
                }
                else if(bar[i].gift_num == 2){
                    switch_on_booster = true;
                }
                else if(bar[i].gift_num == 1){
                    score += 20;
                    limit_breaker += 20;
                    bar[i].tick_control = false;
                    if(limit_breaker>=10)
                        score_object.set_color(COLOR_RED,1);
                    if(limit_breaker>=20)
                        score_object.set_color(COLOR_RED,2);
                    if(limit_breaker>=30)
                        score_object.set_color(COLOR_RED,3);
                    if(limit_breaker>=40)
                        score_object.set_color(COLOR_RED,4);
                    if(limit_breaker>=50)
                        score_object.set_color(COLOR_RED,5);
                    int n = rand() % 64 + 1;
                    int temp_z = n / 8;
                    n = n % 7 + 1;
                    if(n == 1)
                        bar[i].set_position(-13, 0, -70 + 10*temp_z);
                    else if(n == 2)
                        bar[i].set_position( -11, 0, -70 + 10*temp_z);
                    else if(n == 3)
                        bar[i].set_position( -18, 0, -70 + 10*temp_z);
                    else if(n == 4)
                        bar[i].set_position( 4, 0, -70+ 10*temp_z);
                    else if(n == 5)
                        bar[i].set_position( 7, 0, -70+ 10*temp_z);
                    else if(n == 6)
                        bar[i].set_position( 10, 0, -70+ 10*temp_z);
                    else if(n == 7)
                        bar[i].set_position( -18, 0, -70+ 10*temp_z);
                    bar[i].tick_control = true;

                }
            }
        }
        if(switch_on_booster && booster_counter <= 480){
            booster_counter++;
            b.speed_x = 0.3;
            b.speed_z = 0.3;
        }
        if(booster_counter> 480){
            b.speed_x = 0.1;
            b.speed_z = 0.1;
            switch_on_booster = false;
            booster_counter = 0;
        }
        if(jump_control){
            b.horizontal_wobble = 0.0f;
            b.set_position(b.position.x, 0.9, b.position.z);
            b.bounce();
            if(b.position.y < 0.7){
                b.set_position(b.position.x, 0.9, b.position.z);
                b.vertical_speed = 0.05;
                jump_control = false;
            }
        }
        else
            b.tick();
        if(!b1.is_launched){
            b1.tick(b.position.x, b.position.y, b.position.z, 0.7, -b.rotation);
        }
        else
            b1.fire((b.rotation*M_PI)/180);
        if(!b2.is_launched){
            b2.tick(b.position.x, b.position.y, b.position.z, -0.7,-b.rotation);
        }
        else
            b2.fire((b.rotation*M_PI)/180);
        wind_counter++;
        if(wind_counter % 1200 <= 600 && wind_counter % 1200 >= 300){
            enable_sail = rand()%2 + 1 ;
        }
        else{
            enable_sail = 0;
            wind_counter = 0;
        }
        if(enable_sail == 1){
            sail_angle += 1;
            b.blow_sail(sail_angle);
        }
        else if(enable_sail == 2){
            sail_angle -= 1;
            b.blow_sail(sail_angle);
        }
        else if(enable_sail == 0){
            sail_angle = 0;
            b.vertex_buffer_data_sail[6] = 0.0f;
            b.vertex_buffer_data_sail[8] = 1.4f;
        }
    }
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models

    //ball1       = Ball(0, 0);

    wa = Water(0, -30);

    land = Island(0, -29, -200);

    link = Human(-1, 4, -200);

    chest = Treasure(-1, 2, -130);

    for(int i = 0;i<10;i++){
        int n = rand() % 64 + 1;
        int temp_z = n / 8;
        n = n % 7 + 1;
        if(n == 1)
            bar[i] = Barrel( -13, 0, -70 + 10*temp_z);
        else if(n == 2)
            bar[i] = Barrel( -11, 0, -70 + 10*temp_z);
        else if(n == 3)
            bar[i] = Barrel( -18, 0, -70 + 10*temp_z);
        else if(n == 4)
            bar[i] = Barrel( 4, 0, -70+ 10*temp_z);
        else if(n == 5)
            bar[i] = Barrel( 7, 0, -70+ 10*temp_z);
        else if(n == 6)
            bar[i] = Barrel( 10, 0, -70+ 10*temp_z);
        else if(n == 7)
            bar[i] = Barrel( -18, 0, -70+ 10*temp_z);
    }

    b = Boat(0, 0.9);

    boss_monster = Boss(0, -9, -20);

    dip = Display(-13,4, -9);

    for(int i = 0;i<4;i++){
        int n = rand() % 48 + 1;
        int temp_z = n / 8;
        n = n % 7 + 1;
        if(n == 1)
            monsters[i] = Enemy( -12, 0.7, -70 + 10*temp_z);
        else if(n == 2)
            monsters[i] = Enemy( -7, 0.7, -70 + 10*temp_z);
        else if(n == 3)
            monsters[i] = Enemy( -2, 0.7, -70 + 10*temp_z);
        else if(n == 4)
            monsters[i] = Enemy( 3, 0.7, -70+ 10*temp_z);
        else if(n == 5)
            monsters[i] = Enemy( 5, 0.7, -70+ 10*temp_z);
        else if(n == 6)
            monsters[i] = Enemy( 8, 0.7, -70+ 10*temp_z);
        else if(n == 7)
            monsters[i] = Enemy( -18, 0.7, -70+ 10*temp_z);
        monster_ball[i] = Cannonball(monsters[i].position.x,
                                     monsters[i].position.y+3,
                                     monsters[i].position.z,
                                     0.18,COLOR_PURPLE);
    }

    b1 = Cannonball(0.7, 1.3, -0.5, 0.11, COLOR_RED);

    b2 = Cannonball(-0.7, 1.3, -0.5, 0.11, COLOR_RED);

    boss_monster_ball = Cannonball(0, -6.5 , -20,0.5,COLOR_NEUTRAL);

    for(int i = 0;i<10;i++){
        int n = rand() % 48 + 1;
        int temp_z = n / 8;
        n = n % 7 + 1;
        if(n == 1)
            s[i] = Stars( -12, 0.7, -70 + 10*temp_z);
        else if(n == 2)
            s[i] = Stars( -7, 0.7, -70 + 10*temp_z);
        else if(n == 3)
            s[i] = Stars( -2, 0.7, -70 + 10*temp_z);
        else if(n == 4)
            s[i] = Stars( 3, 0.7, -70+ 10*temp_z);
        else if(n == 5)
            s[i] = Stars( 5, 0.7, -70+ 10*temp_z);
        else if(n == 6)
            s[i] = Stars( 8, 0.7, -70+ 10*temp_z);
        else if(n == 7)
            s[i] = Stars( -18, 0.7, -70+ 10*temp_z);
        s[i].points = rand()%5 + 1;
    }


    health_bar = Health(-4, 3, -1);

    for(int i = 0;i<25;i++){
        int n = rand() % 48 + 1;
        int temp_z = n / 8;
        n = n % 7 + 1;
        if(n == 1)
            roc[i] = Rock( -15, 0.7, -70 + 10*temp_z);
        else if(n == 2)
            roc[i] = Rock( -10, 0.7, -70 + 10*temp_z);
        else if(n == 3)
            roc[i] = Rock( -5, 0.7, -70 + 10*temp_z);
        else if(n == 4)
            roc[i] = Rock( 0, 0.7, -70+ 10*temp_z);
        else if(n == 5)
            roc[i] = Rock( 5, 0.7, -70+ 10*temp_z);
        else if(n == 6)
            roc[i] = Rock( 10, 0.7, -70+ 10*temp_z);
        else if(n == 7)
            roc[i] = Rock( -15, 0.7, -70+ 10*temp_z);
    }

    //r1 = Rock(0, 0.9, -7);

    camera_x = b.position.x;camera_y = b.position.y + 4;camera_z = b.position.z + 4;

    temp_y = b.position.y;
    set_target(b.position.x, temp_y, b.position.z);

    score_object = Score(-4, 4, -1, COLOR_BLACK);

    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}


int main(int argc, char **argv) {
    srand(time(0));
    int width  = 1800;
    int height = 1000;

    window = initGLFW(width, height);

    initGL (window, width, height);


    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {
        // Process timers


        if (t60.processTick()) {
            // 60 fps
            // OpenGL Draw commands
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            tick_elements();
            tick_input(window);
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

bool detect_collision(bounding_cube a, bounding_cube b) {
    return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
           (abs(a.y - b.y) * 2 < (a.height + b.height) &&
            abs(a.z - b.z) * 2 < (a.length + b.length));
}

void reset_screen() {
    Matrices.projection = glm::perspective(90.0f, 1.1f, 0.1f, 100.0f);
}

void keyboard(GLFWwindow *window, int key, int scancode, int action, int mods) {
    // Function is called first on GLFW_PRESS.

    if (action == GLFW_RELEASE) {
        // switch (key) {
        // case GLFW_KEY_C:
        // rectangle_rot_status = !rectangle_rot_status;
        // break;
        // case GLFW_KEY_P:
        // triangle_rot_status = !triangle_rot_status;
        // break;
        // case GLFW_KEY_X:
        //// do something ..
        // break;
        // default:
        // break;
        // }
    } else if (action == GLFW_PRESS) {
        switch (key) {
        case GLFW_KEY_ESCAPE:
            quit(window);
            break;
        case GLFW_KEY_V:
            camera_mode ++;
            camera_mode = camera_mode % 4;
            if(camera_mode == 0){
                follow_up_view_control = true;
                boat_view = false;
                tower_view = false;
                heli_cam = false;
                top_view = false;
                camera_x = b.position.x + 4.5*sin((b.rotation * M_PI)/180);
                camera_z = b.position.z + 4.5 - 4.5*(1-cos((b.rotation * M_PI)/180));
                camera_y = b.position.y + 5.5;
                set_target(b.position.x,b.position.y,b.position.z);
                score_object.set_position(b.position.x + 2*sin((b.rotation * M_PI)/180),
                                          b.position.y+ 3,
                                          b.position.z + 2 - 2*(1-cos((b.rotation * M_PI)/180)));
                health_bar.set_position(b.position.x + 2*sin((b.rotation * M_PI)/180),
                                          b.position.y+ 5,
                                          b.position.z + 2 - 2*(1-cos((b.rotation * M_PI)/180)));

                dip.set_position(b.position.x + 2*sin((b.rotation * M_PI)/180),
                                          b.position.y+ 4,
                                          b.position.z + 2 - 2*(1-cos((b.rotation * M_PI)/180)));

            }
            else if(camera_mode == 1)
            {
                follow_up_view_control = false;
                tower_view = true;
                boat_view = false;
                heli_cam = false;
                camera_x = b.position.x + 6*sin((b.rotation*M_PI)/180);
                camera_y = b.position.y+ 6;
                camera_z = b.position.z+ 6*cos((b.rotation*M_PI)/180);
                target_x = b.position.x;
                target_y = b.position.y;
                target_z = b.position.z;

                score_object.set_position(b.position.x + 2*sin((b.rotation*M_PI)/180),
                                          b.position.y+ 3,
                                          b.position.z+ 2*cos((b.rotation*M_PI)/180));
            }
            else if(camera_mode == 2){
                follow_up_view_control = false;
                tower_view = false;
                heli_cam = true;
                boat_view = false;
                top_view = false;

            }
            else if(camera_mode == 3){                
                follow_up_view_control = false;
                heli_cam = false;
                boat_view = false;
                tower_view = false;
                top_view = true;
                camera_x = b.position.x + 4.5*sin((b.rotation * M_PI)/180);
                camera_z = b.position.z + 4.5 - 4.5*(1-cos((b.rotation * M_PI)/180));
                set_target(b.position.x,b.position.y,b.position.z);
                camera_y = b.position.y + 15;

            }
            break;
        case GLFW_KEY_B:
            follow_up_view_control = false;
            heli_cam = false;
            boat_view = true;
            printf("\n\ncamera change!!!\n\n");
            camera_x = b.position.x;
            camera_z = b.position.z-1;
            target_y = 0.45;
            camera_y = b.position.y+1.4;
            target_x = b.position.x + 2*sin((b.rotation*M_PI)/180);
            target_z = b.position.z - 2*cos((b.rotation*M_PI)/180);
            break;
        default:
            break;
        }
    }
}

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset) {
    // Do something
    if(heli_cam){
        float d = distance(abs(camera_x-b.position.x),
                           abs(camera_y-b.position.y),
                           abs(camera_z-b.position.z));
        float cos_theta = abs(camera_y-b.position.y)/d;
        float sin_theta = pow(1-pow(cos_theta,2),0.5);
        float cos_alpha = abs(camera_x-b.position.x)/pow(pow(abs(camera_x-b.position.x),2)
                                                         + pow(abs(camera_y-b.position.y),2), 0.5);
        float sin_alpha = pow(1-pow(cos_alpha,2), 0.5);
    if(yoffset > 0){
        camera_y -= cos_theta;
        camera_x -= sin_theta*cos_alpha;
        camera_z -= sin_theta*sin_alpha;
    }
    else{
        camera_y += cos_theta;
        camera_x += sin_theta*cos_alpha;
        camera_z += sin_theta*sin_alpha;
    }
    }
}

void cursor_callback(GLFWwindow *window, double xpos, double ypos){
    if(heli_cam){
        camera_x = xpos/100-9;
        camera_y = ypos/100;
    }
}

float distance(float x, float y, float z){
    return pow(pow(x,2)+pow(y,2)+pow(z,2),0.5);
}

void reduce_health(){
    if(b.health > 0){
        b.health -= 1;
        health_bar.reduce_health(b.health+1);
    }
}
