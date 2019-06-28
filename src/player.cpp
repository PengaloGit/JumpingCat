#include "player.h"

player::player()
{

    al_init();
    al_init_image_addon();
    jumpState = false;
    gravity = 1;
    vy = 0;
    x = 0;
    offsetY = 98;
    y = 450 - offsetY;

    frameMove = 0;
    frameDead = 0;
    characterJump = al_load_bitmap("image/jump/jump.png");
    characterLanding = al_load_bitmap("image/jump/landing.png");
    characterMove[0] = al_load_bitmap("image/run/Run(1).png");
    characterMove[1] = al_load_bitmap("image/run/Run(2).png");
    characterMove[2] = al_load_bitmap("image/run/Run(3).png");
    characterMove[3] = al_load_bitmap("image/run/Run(4).png");
    characterMove[4] = al_load_bitmap("image/run/Run(5).png");
    characterMove[5] = al_load_bitmap("image/run/Run(6).png");
    characterMove[6] = al_load_bitmap("image/run/Run(7).png");
    characterMove[7] = al_load_bitmap("image/run/Run(8).png");
    characterDeath[0] = al_load_bitmap("image/dead/dead1.png");
    characterDeath[1] = al_load_bitmap("image/dead/dead2.png");
    characterDeath[2] = al_load_bitmap("image/dead/dead3.png");
    characterDeath[3] = al_load_bitmap("image/dead/dead4.png");
}

void player::jump(){
   if(y == 450 - offsetY)
    vy = -14 ;
    jumpState = true ;
}

void player::movePlayer(){

    y += vy;
    vy += gravity;
    if( y >= 450 - offsetY ){
        y = 450 - offsetY;
        jumpState = false;
    }

    if(jumpState == true && vy <= 0)
    {
        al_draw_bitmap(characterJump,x,y,0);
    }
    else if(jumpState == true && vy > 0 ){
        al_draw_bitmap(characterJump,x,y,0);
    }else if(jumpState == false){
        al_draw_bitmap(characterMove[frameMove/3],x,y,0);
        frameMove++;
        frameMove = frameMove%24;
    }

}

bool player::colide(Obstacle o){
    float x1 = o.getX();
    float y1 = o.getY();

    if((x1 - x) <= 32 && (y1 - y) <= 50 && (x1 - x) >= 0 )
        return true;
    else if((x - x1) <= 20 && (y1 - y) <= 50 && (x - x1) >= 0)
        return true;
    else return false;
}

void player::die()
{
    al_draw_bitmap(characterDeath[frameDead/4],x,y,0);
    frameDead++;
    frameDead = frameDead%16;
}

