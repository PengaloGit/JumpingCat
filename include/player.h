#ifndef PLAYER_H
#define PLAYER_H
#include<bits/stdc++.h>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include"Obstacle.h"

using namespace std;

class player
{
    public:
        player();
        void jump();
        void movePlayer();
        void die();
        bool colide(Obstacle);

    protected:

    private:

        int frameMove;
        int frameDead;
        float x;
        float y;
        float offsetY;
        float vy;
        float gravity;
        float jumpState;
        ALLEGRO_BITMAP  *characterMove[8];
        ALLEGRO_BITMAP  *characterDeath[4];
        ALLEGRO_BITMAP  *characterJump;
        ALLEGRO_BITMAP  *characterLanding;

};

#endif // PLAYER_H
