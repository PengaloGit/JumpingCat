#ifndef OBSTACLE_H
#define OBSTACLE_H
#include<bits/stdc++.h>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"

using namespace std;


class Obstacle
{
    public:
        Obstacle();
        void moveObstacle();
        float getX();
        float getY();
        float getVX();
        void setVX(float);

    protected:

    private:
        float x;
        float y;
        float vx;
        int frame;
        ALLEGRO_BITMAP *obstacle[6];

};

#endif // OBSTACLE_H
