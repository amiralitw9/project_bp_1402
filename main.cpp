#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL2_gfx.h>
#include "C:\function\location\main.cpp"
#include <cmath>
using namespace std ;

using namespace std;
int main( int argc, char * argv[] ) {
    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER;
    Uint32 WND_flags = SDL_WINDOW_SHOWN;// SDL_WINDOW_FULLSCREEN_DESKTOP ;//SDL_WINDOW_BORDERLESS ;// SDL_WINDOW_FULLSCREEN_DESKTOP ; ;
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
    const int width = w, height = h;
    double adad_sabet_x = width * .2 - width * .04;
    double ghotr_dayere = .08 * width;
    double fasele_do_dayere = .075 * width;
    //***********************************************************************
    double x[2][10] = {{adad_sabet_x + ghotr_dayere,               adad_sabet_x + 2 * ghotr_dayere,
                               adad_sabet_x + 3 * ghotr_dayere,               adad_sabet_x + 4 * ghotr_dayere,
                                                                                           adad_sabet_x +
                                                                                           5 * ghotr_dayere,
                                                                                                        adad_sabet_x +
                                                                                                        6 *
                                                                                                        ghotr_dayere,
                               adad_sabet_x + 7 * ghotr_dayere,               adad_sabet_x + 8 * ghotr_dayere,
                                                                                           adad_sabet_x +
                                                                                           9 * ghotr_dayere,
                                                                                                        adad_sabet_x +
                                                                                                        10 *
                                                                                                        ghotr_dayere},
                       {adad_sabet_x + ghotr_dayere - width * .04, adad_sabet_x + 2 * ghotr_dayere - width * .04,
                               adad_sabet_x + 3 * ghotr_dayere - width * .04, adad_sabet_x + 4 * ghotr_dayere -
                                                                              width * .04, adad_sabet_x +
                                                                                           5 * ghotr_dayere -
                                                                                           width * .04, adad_sabet_x +
                                                                                                        6 *
                                                                                                        ghotr_dayere -
                                                                                                        width * .04,
                               adad_sabet_x + 7 * ghotr_dayere - width * .04, adad_sabet_x + 8 * ghotr_dayere -
                                                                              width * .04, adad_sabet_x +
                                                                                           9 * ghotr_dayere -
                                                                                           width * .04, adad_sabet_x +
                                                                                                        10 *
                                                                                                        ghotr_dayere -
                                                                                                        width * .04}};
    double y[13] = {(.04 * width - 2 * fasele_do_dayere), (.04 * width - fasele_do_dayere), (.04 * width),
                    .04 * width + fasele_do_dayere, .04 * width + 2 * fasele_do_dayere,
                    .04 * width + 3 * fasele_do_dayere, .04 * width + 4 * fasele_do_dayere,
                    .04 * width + 5 * fasele_do_dayere, .04 * width + 6 * fasele_do_dayere,
                    .04 * width + 7 * fasele_do_dayere, .04 * width + 8 * fasele_do_dayere,
                    .04 * width + 9 * fasele_do_dayere, .04 * width + 10 * fasele_do_dayere};
    //********************************
    // نقاط اصلی صفحه
    //load the image
    SDL_Surface* imageSurface = IMG_Load("C:\\Users\\Autamn\\Downloads\\red.png");
    if (imageSurface == nullptr) {
        std::cerr << "IMG_Load Error: " << IMG_GetError() << std::endl;
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return 1;
    }

    // Create a texture from the image
    SDL_Texture* imageTexture = SDL_CreateTextureFromSurface(m_renderer, imageSurface);
    if (imageTexture == nullptr) {
        std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(imageSurface);
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return 1;
    }

    // Main event loop
    bool isRunning = true;
    SDL_Event event;
    while (isRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isRunning = false;
            } else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                isRunning = false;
            }

        }SDL_SetRenderDrawColor(m_renderer, 0, 0, 210, 255); // تنظیم رنگ مشکی بکگراند
        SDL_RenderClear(m_renderer); // پاک کردن صفحه




        // Set the destination rectangle for rendering
        SDL_Rect destRect;
        destRect.x = 300;// X position of the destination rectangle
        destRect.y = 300; // Y position of the destination rectangle
        destRect.w = 80; // Width of the destination rectangle
        destRect.h = 80; // Height of the destination rectangle

        // Copy the texture to the renderer with the destination rectangle
        SDL_RenderCopy(m_renderer, imageTexture, NULL, &destRect);

        // Render the changes



        SDL_RenderPresent(m_renderer);
    }

    // Clean up
    SDL_DestroyTexture(imageTexture);
    SDL_FreeSurface(imageSurface);
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();


}




