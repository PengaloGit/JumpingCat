#include "Game.h"

Game::Game()
{
    al_install_keyboard();
    al_install_mouse();

    timer = al_create_timer(1.0 / FPS);
    gt = 34;
    maxGap = 100;
    event_queue = al_create_event_queue();
    redraw = true;
    generationTimer = 0;
    Obstacle temp;
    obstacles.push_back(temp);

    al_register_event_source(event_queue, al_get_display_event_source(window.getDisplay()));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_start_timer(timer);

}

void Game::run()
{
    bool running = true;
    srand(time(0));
    while(running){


      ALLEGRO_EVENT ev;
      al_wait_for_event(event_queue, &ev);

      if(ev.type == ALLEGRO_EVENT_TIMER) {
            redraw =  true;
      }
      else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
         break;
    }
      if(redraw && al_is_event_queue_empty(event_queue)) {

        generationTimer++;
        nextObstacle();
        redraw = false;
        if(character.colide(obstacles.at(0))){
            gameOver();
            running = false;
        }else{
        if(generationTimer > gt){
            float v =rand()%100;
            if(v < 1 )
            {
                Obstacle temp;
                temp.setVX(bg.getVX());
                generationTimer = 0;
                obstacles.push_back(temp);
            }
            else if(generationTimer > maxGap){
            generationTimer = 0;
            Obstacle temp;
            temp.setVX(bg.getVX());
            generationTimer = 0;
            obstacles.push_back(temp);
        }
        }
        window.clearWindow();
        bg.moveBackground();
        for(int i = 0;i < obstacles.size();i++)
            obstacles.at(i).moveObstacle();
        character.movePlayer();
        score.showScore();
        if(score.incScore() && score.getScore()%100 == 0)
            increaseSpeed();
        window.update();
        }
      }else{
      if (ev.type =  ALLEGRO_EVENT_KEY_DOWN){
        switch(ev.keyboard.keycode) {
            case ALLEGRO_KEY_SPACE:
               character.jump();
               break;

         }
         }
      }
   }

   al_rest(2);
}

void Game::nextObstacle()
{
    float x = obstacles.at(0).getX();
    if( x < - 20)
        obstacles.erase(obstacles.begin());
}

void Game::increaseSpeed()
{
    float newVX = bg.getVX() + 0.2;

    maxGap = (MAXPIXEL / newVX) ;
    gt = (MINPIXEL / newVX) + 1;

    cout << gt <<" " << maxGap << endl;

    bg.setVX(newVX);
    for(int i = 0;i < obstacles.size();i++)
            obstacles.at(i).setVX(newVX);
}


void Game::gameOver()
{
    for(int i = 0; i< 16 ;i++)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        if(al_is_event_queue_empty(event_queue)){
        //bg.setVX(0);
        window.clearWindow();
        bg.moveBackground();
        for(int i = 0;i < obstacles.size();i++)
            {

                obstacles.at(i).moveObstacle();
            }
        character.die();
        score.showScore();
        window.update();
        }
    }

}
