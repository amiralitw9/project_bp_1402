
#include <bits/stdc++.h>
#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
using namespace std ;

void ball_green(){} //ball number 1
void ball_yellow(){}//ball number 2
void ball_red(){}//ball number 3
void ball_purple(){}//ball number 4
void ball_blue(){}//ball number 5
void ball_red_yellow(){}//ball number 6
void ball_red_blue(){}//ball number 7
void ball_red_purple(){}//ball number 8
void ball_red_green(){}//ball number 9
void ball_blue_green(){}//ball number 10
void ball_blue_yellow(){}//ball number 11
void ball_blue_purple(){}//ball number 12
void ball_green_yellow(){}//ball number 13
void ball_green_purple(){}//ball number 14
void ball_purple_yellow(){}//ball number 15
void ball_black() {}//ball number 16
void ball_lock_green(){}//ball number 17
void ball_lock_red(){}//ball number 18
void ball_lock_yellow(){}//ball number 19
void ball_lock_purple(){}//ball number 20
void ball_lock_blue(){}//ball number 21

void main_balls(int a ){
    switch(a) {
        case 1:
            ball_yellow();
            break ;
        case 2:
            ball_red();
            break ;

        case 3:
            ball_purple();
            break ;
        case 4:
             ball_blue();
            break ;
        case 5:
             ball_blue();
            break ;
        case 6:
             ball_red_yellow();
            break ;
        case 7:
             ball_red_blue();
            break ;
        case 8:
             ball_red_purple();
            break ;
        case 9:
             ball_red_green();
            break ;
        case 10:
             ball_blue_green();
            break ;
        case 11:
            ball_blue_yellow();
            break ;
        case 12:
             ball_blue_purple();
            break ;
        case 13:
             ball_green_yellow();
            break ;
        case 14:
             ball_green_purple();
            break ;
        case 15:
             ball_purple_yellow();
            break ;
        case 16:
            ball_black();
            break ;
        case 17:
            ball_lock_green();
            break ;
        case 18:
            ball_lock_red();
            break ;
        case 19:
            ball_lock_yellow();
            break ;
        case 20:
            ball_lock_purple();
            break ;
        case 21:
            ball_lock_blue();
            break ;

    }
} 
