#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL2_gfx.h>
#include "C:\function\balls\main.cpp"
#include "C:\function\location\main.cpp"
using namespace std ;

using namespace std;
int main( int argc, char * argv[] ) {
   Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER;
    Uint32 WND_flags = SDL_WINDOW_SHOWN  ;// SDL_WINDOW_FULLSCREEN_DESKTOP ;//SDL_WINDOW_BORDERLESS ;// SDL_WINDOW_FULLSCREEN_DESKTOP ; ;
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
    SDL_CreateWindowAndRenderer(900, 900, WND_flags, &m_window, &m_renderer);
//Pass the focus to the drawing window
    SDL_RaiseWindow(m_window);
//Get screen resolution
    SDL_GetCurrentDisplayMode(0, &DM);
//این بخش از کد طول و عرض صفحه رو در دو متغیر ذخیره میکنه
    int w, h;
    SDL_GetRendererOutputSize(m_renderer, &w, &h);
    const int width = w , height = h ;
    double adad_sabet_x=width*.2-width*.04 ;
    double ghotr_dayere = .08*width;
    double fasele_do_dayere = .075*width ;
    //***********************************************************************
    double x[2][10]={{adad_sabet_x+ghotr_dayere,adad_sabet_x+2*ghotr_dayere,adad_sabet_x+3*ghotr_dayere,adad_sabet_x+4*ghotr_dayere,adad_sabet_x+5*ghotr_dayere,adad_sabet_x+6*ghotr_dayere,adad_sabet_x+7*ghotr_dayere,adad_sabet_x+8*ghotr_dayere,adad_sabet_x+9*ghotr_dayere,adad_sabet_x+10*ghotr_dayere},
                         {adad_sabet_x+ghotr_dayere-width*.04,adad_sabet_x+2*ghotr_dayere-width*.04,adad_sabet_x+3*ghotr_dayere-width*.04,adad_sabet_x+4*ghotr_dayere-width*.04,adad_sabet_x+5*ghotr_dayere-width*.04,adad_sabet_x+6*ghotr_dayere-width*.04,adad_sabet_x+7*ghotr_dayere-width*.04,adad_sabet_x+8*ghotr_dayere-width*.04,adad_sabet_x+9*ghotr_dayere-width*.04,adad_sabet_x+10*ghotr_dayere-width*.04}};
    double y[13]={(.04*width-2*fasele_do_dayere),(.04*width-fasele_do_dayere),(.04*width),.04*width+fasele_do_dayere,.04*width+2*fasele_do_dayere,.04*width+3*fasele_do_dayere,.04*width+4*fasele_do_dayere,.04*width+5*fasele_do_dayere,.04*width+6*fasele_do_dayere,.04*width+7*fasele_do_dayere,.04*width+8*fasele_do_dayere,.04*width+9*fasele_do_dayere,.04*width+10*fasele_do_dayere};
    //********************************
    // نقاط اصلی صفحه
    aalineRGBA(m_renderer,.2*width-.05*width,.04*width+10*fasele_do_dayere,width,.04*width+10*fasele_do_dayere,255,255,255,255);
    aalineRGBA(m_renderer,.2*width-.05*width,0,.2*width-.05*width,.04*width+10*fasele_do_dayere,255,255,255,255);
//***************************************
//خط های دور صفحه
    int list_toop [13][10];//لیست دو بعدی توپ ها
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 10; j++) {
            list_toop[i][j] = 0;
        }
    } // تعریف اولیه برای اینکه همه خانه ها 0 باشد
    line_1_2 line;
    first_second_line(line);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == 0 && j < 3) {
                list_toop[0][j] = line.line_1[0];
            } else if (i == 0 && j < 5) {
                list_toop[0][j] = line.line_1[1];
            } else if (i == 0 && j < 8) {
                list_toop[0][j] = line.line_1[2];
            } else if (i == 0 && j < 10) {
                list_toop[0][j] = line.line_1[3];
            }
            if (i == 1 && j < 3) {
                list_toop[1][j] = line.line_2[0];
            } else if (i == 1 && j < 5) {
                list_toop[1][j] = line.line_2[1];
            } else if (i == 1 && j < 8) {
                list_toop[1][j] = line.line_2[2];
            } else if (i == 1 && j < 10) {
                list_toop[1][j] = line.line_2[3];
            }
        }
    } // تعریف دو خط اول

//*********************************
    bool quit = false;
    SDL_Event e;
    double enteghali = 0 ;
    int c = 0 ;//برای به هم نریختن هنگام سوییچ نوشته شده
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true; // خروج از حلقه در صورت بستن پنجره
            }
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
                quit = true; // خروج از حلقه در صورت فشردن دکمه ESC
            }
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE) {
                for(int i = 0 ; i<10;i++)
                    list_toop[12][i]=0 ;
            }

        }

        SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255); // تنظیم رنگ مشکی بکگراند
        SDL_RenderClear(m_renderer); // پاک کردن صفحه
        list_toop_ha(list_toop, enteghali, width ,c );
        enteghali += .1 ;
        for (int i = 0; i < 13; i++) {
            int d=(i%2);
            for (int j = 0; j < 10; j++) {
                main_balls(m_renderer,list_toop[i][j],x[(d+c)%2][j],y[i]+enteghali,width,height,1);
            }

            }
        for(int j = 0 ; j<10 ; j++) {//خطی که برای سوختن استفاده شد .
            if (list_toop[12][j] != 0) { // شرط باخت- این حلقه درصورت پایان پیدا کردن دیگه توپ تولید نمیکنه
                //" چیزای هنگام باختن قرار هست نمایش داده بشه"
                //" باز شدن منو برای بازی مجدد"
                //"ذخیره امتیازات و چیزای مورد نیاز دیگه"
                return 0 ;
            }
        }


        SDL_RenderPresent(m_renderer);
    }
}
