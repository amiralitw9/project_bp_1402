
//#include <bits/stdc++.h>
//#include <bits/stdc++.h>
//#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
//#include <SDL2/SDL_ttf.h>
using namespace std ;

void ball_green(SDL_Renderer * renderer,double x_center , double y_center, double width){
    aacircleRGBA(renderer,x_center,y_center,width*.04,0,255,0,255);
} //ball number 1
void ball_yellow(SDL_Renderer * renderer,double x_center , double y_center,double width){
    aacircleRGBA(renderer,x_center,y_center,width*.04,255,255,0,255);

}//ball number 2
void ball_red(SDL_Renderer * renderer,double x_center , double y_center,double width){
    aacircleRGBA(renderer,x_center,y_center,width*.04,255,0,0,255);

}//ball number 3
void ball_purple(SDL_Renderer * renderer,double x_center , double y_center,double width){
    aacircleRGBA(renderer,x_center,y_center,width*.04,128,0,128,255);

}//ball number 4
void ball_blue(SDL_Renderer * renderer,double x_center , double y_center,double width){
    aacircleRGBA(renderer,x_center,y_center,width*.04,0,0,255,255);

}//ball number 5
void ball_red_yellow(SDL_Renderer * renderer,double x_center , double y_center,double width){}//ball number 6
void ball_red_blue(SDL_Renderer * renderer,double x_center , double y_center,double width){}//ball number 7
void ball_red_purple(SDL_Renderer * renderer,double x_center , double y_center,double width){}//ball number 8
void ball_red_green(SDL_Renderer * renderer,double x_center , double y_center,double width){}//ball number 9
void ball_blue_green(SDL_Renderer * renderer,double x_center , double y_center,double width){}//ball number 10
void ball_blue_yellow(SDL_Renderer * renderer,double x_center , double y_center,double width){}//ball number 11
void ball_blue_purple(SDL_Renderer * renderer,double x_center , double y_center,double width){}//ball number 12
void ball_green_yellow(SDL_Renderer * renderer,double x_center , double y_center,double width){}//ball number 13
void ball_green_purple(SDL_Renderer * renderer,double x_center , double y_center,double width){}//ball number 14
void ball_purple_yellow(SDL_Renderer * renderer,double x_center , double y_center,double width){}//ball number 15
void ball_black(SDL_Renderer * renderer,double x_center , double y_center,double width) {}//ball number 16
void ball_lock_green(SDL_Renderer * renderer,double x_center , double y_center,double width){}//ball number 17
void ball_lock_red(SDL_Renderer * renderer,double x_center , double y_center,double width){}//ball number 18
void ball_lock_yellow(SDL_Renderer * renderer,double x_center , double y_center,double width){}//ball number 19
void ball_lock_purple(SDL_Renderer * renderer,double x_center , double y_center,double width){}//ball number 20
void ball_lock_blue(SDL_Renderer * renderer,double x_center , double y_center,double width){}//ball number 21

void main_balls(SDL_Renderer * renderer,int a ,double x_center , double y_center,double width,double height ,int visibility){//a نوع رنگ توپ است
    //visibility اگر 0 نمایش میده
    //اگر 1 همون جا محو میشه
    //اگه 2 میوفته زمین
    switch(a) {
        case 1: {
            if(visibility!=0)
                ball_green(renderer, x_center, y_center, width);
            break;
        }
        case 2: {
            if(visibility!=0)
                ball_yellow(renderer, x_center, y_center, width);
            break;
        }
        case 3: {
            if(visibility!=0)
                ball_red(renderer, x_center, y_center, width);
            break;
        }
        case 4: {
            if(visibility!=0)
                ball_purple(renderer, x_center, y_center, width);
            break;
        }
        case 5: {
            if(visibility!=0)
                ball_blue(renderer, x_center, y_center, width);
            break;
        }
        case 6: {
            if(visibility!=0)
                ball_red_yellow(renderer, x_center, y_center, width);
            break;
        }
        case 7: {
            if(visibility!=0)
                ball_red_blue(renderer, x_center, y_center, width);
            break;
        }
        case 8: {
            if(visibility!=0)
                ball_red_purple(renderer, x_center, y_center, width);
            break;
        }
        case 9: {
            if(visibility!=0)
                ball_red_green(renderer, x_center, y_center, width);
            break;
        }
        case 10: {
            if(visibility!=0)
                ball_blue_green(renderer, x_center, y_center, width);
            break;
        }
        case 11: {
            if(visibility!=0)
                ball_blue_yellow(renderer, x_center, y_center, width);
            break;
        }
        case 12: {
            if(visibility!=0)
                ball_blue_purple(renderer, x_center, y_center, width);
            break;
        }
        case 13: {
            if(visibility!=0)
                ball_green_yellow(renderer, x_center, y_center, width);
            break;
        }
        case 14: {
            if(visibility!=0)
                ball_green_purple(renderer, x_center, y_center, width);
            break;
        }
        case 15:{
            if(visibility!=0)
                ball_purple_yellow(renderer, x_center, y_center, width);
            break;
        }
        case 16: {
            if(visibility!=0)
                ball_black(renderer, x_center, y_center, width);
            break;
        }
        case 17: {
            if(visibility!=0)
                ball_lock_green(renderer, x_center, y_center, width);
            break;
        }
        case 18: {
            if(visibility!=0)
                ball_lock_red(renderer, x_center, y_center, width);
            break;
        }
        case 19: {
            if(visibility!=0)
                ball_lock_yellow(renderer, x_center, y_center, width);
            break;
        }
        case 20: {
            if(visibility!=0)
                ball_lock_purple(renderer, x_center, y_center, width);
            break;
        }
        case 21: {
            if(visibility!=0)
                ball_lock_blue(renderer, x_center, y_center, width);
            break;
        }

    }
}
