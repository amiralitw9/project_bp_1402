#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL2_gfx.h>
#include "C:\function\balls\main.cpp"
#include "C:\function\screen\main.cpp"
using namespace std ;

using namespace std;
int main( int argc, char * argv[] ) {
   Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER;
    Uint32 WND_flags = SDL_WINDOW_SHOWN ;//SDL_WINDOW_FULLSCREEN_DESKTOP ;//SDL_WINDOW_BORDERLESS ;// SDL_WINDOW_FULLSCREEN_DESKTOP ; ;
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Texture *bkImg = NULL;
//Texture for loading image

    int img_w, img_h;
    SDL_Rect img_rect;
    SDL_DisplayMode DM;
    int W = DM.w;
    int H = DM.h;

    SDL_Init(SDL_flags);
    SDL_CreateWindowAndRenderer(1850, 1000, WND_flags, &m_window, &m_renderer);
//Pass the focus to the drawing window
    SDL_RaiseWindow(m_window);
//Get screen resolution
    SDL_GetCurrentDisplayMode(0, &DM);
//این بخش از کد طول و عرض صفحه رو در دو متغیر ذخیره میکنه
    int width, height;
    SDL_GetRendererOutputSize(m_renderer, &width, &height);
    //***********************************************************************
    line_1_2 line ;
    first_second_line(line);
    int counter = 0 ;
    for(int i = 0 ; i<4 ; i++) {
        for (int j = 0; j < 3; j++) {
            if (i % 2 == 1) {
                if (j == 2)
                    continue;
            }
            counter+=1 ;
            main_balls(m_renderer,line.line_1[i],width*.2+width*.08*counter-width*.04,100+width*.07,width);
        }
    }//کشیدن خط اول - y center باید درست شود
    counter = 0 ;
    for(int i = 0 ; i<4 ; i++) {
        for (int j = 0; j < 3; j++) {
            if (i % 2 == 1) {
                if (j == 2)
                    continue;
            }
            counter+=1 ;
            main_balls(m_renderer,line.line_2[i],width*.2+width*.08*counter-width*.08,100,width);
        }
    }//کشیدن خط دوم-y center باید درست شود

}