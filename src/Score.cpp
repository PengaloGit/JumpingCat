#include "Score.h"

Score::Score()
{
    font = al_load_ttf_font("font/YARDSALE.ttf", 20, 0);
    x = 650;
    y = 10;
    score = 0 ;
    timerInc = 0;
}

void Score::showScore()
{
    string scoreS;
    scoreS = "Score : " + to_string(score);
    char charScore[scoreS.size() + 1];
    strcpy(charScore, &scoreS[0]);
    al_draw_text(font, al_map_rgb(255, 255, 255), 650, 10, 0, charScore);
}

bool Score::incScore()
{
    timerInc ++;
    if(timerInc %60 == 0){
        score += 10;
        return true;
    }
    else return false;
}

int Score::getScore()
{
    return score;
}
