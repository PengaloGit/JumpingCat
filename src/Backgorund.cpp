#include "Backgorund.h"

Backgorund::Backgorund()
{
    al_init();
    al_init_image_addon();
    background[0] = al_load_bitmap("image/background1.png");
    background[1] = al_load_bitmap("image/background1.png");
    if(background[0] == NULL)
        cout << "NULL" << endl;
    vx = 3;
    x = 1996;
    y = 0;
}
void Backgorund::moveBackground()
{
    al_draw_bitmap(background[0],x,0,0);
    al_draw_bitmap(background[1],y,0,0);
    x -=vx ;
    y -=vx ;
    if(x <= -1996 ){
        x = 1996;
    }
    if(y <= -1996 ){
        y = 1996;
    }
}
void Backgorund::setVX(float newVX)
{
    vx = newVX;
}

float Backgorund::getVX()
{
    return vx;
}



