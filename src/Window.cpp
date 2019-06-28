#include "Window.h"

Window::Window()
{
   al_init();
   al_init_font_addon();
   al_init_ttf_addon();

   display = al_create_display(800,450);
   al_set_window_position(display, 100, 100);
}
ALLEGRO_DISPLAY* Window::getDisplay()
{
    return display;
}

void Window::update()
{
    al_flip_display();
}

void Window::clearWindow()
{
    al_clear_to_color(al_map_rgba_f(1, 1, 1, 1));
}
