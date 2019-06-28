#ifndef BACKGORUND_H
#define BACKGORUND_H
#include<bits/stdc++.h>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"

using namespace std;

class Backgorund
{
    public:
        Backgorund();
        void moveBackground();
        void setVX(float);
        float getVX();

    protected:

    private:

        float vx;
        float x;
        float y;
        ALLEGRO_BITMAP  *background[2];
};

#endif // BACKGORUND_H
