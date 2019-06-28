#include "Obstacle.h"

Obstacle::Obstacle()
{
    al_init();
    al_init_image_addon();
    x = 800;
    y = 450-64;
    vx = 3;
    frame = 0;
    obstacle[0] = al_load_bitmap("image/fire/fire1.png");
    obstacle[1] = al_load_bitmap("image/fire/fire2.png");
    obstacle[2] = al_load_bitmap("image/fire/fire3.png");
    obstacle[3] = al_load_bitmap("image/fire/fire4.png");
    obstacle[4] = al_load_bitmap("image/fire/fire5.png");
    obstacle[5] = al_load_bitmap("image/fire/fire6.png");
}

void Obstacle::moveObstacle(){
    x -= vx;
    al_draw_bitmap(obstacle[frame/4],x,y,0);
    frame++;
    frame = frame%24;
}

float Obstacle::getX()
{
    return x;
}
float Obstacle::getY()
{
    return y;
}

void Obstacle::setVX(float newVX)
{
    vx = newVX;
}

float Obstacle::getVX()
{
    return vx;
}
