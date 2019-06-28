#ifndef GAME_H
#define GAME_H
#include<bits/stdc++.h>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include"player.h"
#include"Obstacle.h"
#include"Backgorund.h"
#include"Score.h"
#include"Window.h"
#define FPS 60
#define MAXPIXEL 300
#define MINPIXEL 72



using namespace std;


class Game
{
    public:
        Game();
        void run();
        void nextObstacle();
        void increaseSpeed();
        void gameOver();

    protected:

    private:
        int generationTimer ;
        bool redraw;
        int gt;
        int maxGap;

        Window window;
        player character ;
        vector<Obstacle> obstacles;
        Score score;
        Backgorund bg;
        ALLEGRO_TIMER *timer ;
        ALLEGRO_EVENT_QUEUE *event_queue ;
};

#endif // GAME_H
