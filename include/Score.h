#ifndef SCORE_H
#define SCORE_H
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include<bits/stdc++.h>

using namespace std;


class Score
{
    public:
        Score();
        void showScore();
        bool incScore();
        int getScore();

    protected:

    private:
        float x;
        float y;
        int timerInc;
        int score;
        ALLEGRO_FONT * font;
};

#endif // SCORE_H
