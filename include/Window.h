#ifndef WINDOW_H
#define WINDOW_H
#include<bits/stdc++.h>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>

class Window
{
    public:
        Window();
        ALLEGRO_DISPLAY * getDisplay();
        void update();
        void clearWindow();

    protected:

    private:

        ALLEGRO_DISPLAY *display ;
};

#endif // WINDOW_H
