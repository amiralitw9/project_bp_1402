#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL2_gfx.h>
#include "C:\function\location\main.cpp"
#include <cmath>
using namespace std ;

struct division_of_the_page
        {
            int x[3];//تقسیم بندی طول صفحه
            int y[12]; //تقسیم بندی عرض صفحه
        };
int main( int argc, char * argv[] ) {
    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER;
    Uint32 WND_flags = SDL_WINDOW_SHOWN;//SDL_WINDOW_FULLSCREEN_DESKTOP ;//SDL_WINDOW_BORDERLESS ;// SDL_WINDOW_FULLSCREEN_DESKTOP ; ;
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

    // Define a pair of SDL_Texture* and image path for each image
    typedef std::pair<SDL_Texture *, std::string> ImagePair;

// Create a vector to store the image pairs
    std::vector<ImagePair> tasavir;//اسم وکتور و تعریف
//*************************************** تعریف وکتور
    std::string imagePath = "C:/function/menu_pictures/1.jpg";//عکس پس زمینه اینجا آپلود میشه
    SDL_Surface *imageSurface = IMG_Load(imagePath.c_str());
    SDL_Texture *texture = SDL_CreateTextureFromSurface(m_renderer, imageSurface);
    SDL_FreeSurface(imageSurface);
    tasavir.push_back(std::make_pair(texture, imagePath));
    for (int i = 2; i <= 7; ++i) {
        std::string imagePath = "C:/function/menu_pictures/" + std::to_string(i) + ".png";//عکس های منو داخل وکتور هم آپلود میشه.
        SDL_Surface *imageSurface = IMG_Load(imagePath.c_str());
        SDL_Texture *texture = SDL_CreateTextureFromSurface(m_renderer, imageSurface);
        SDL_FreeSurface(imageSurface);
        tasavir.push_back(std::make_pair(texture, imagePath));
    }
    //*************************************************************************************
    bool isRunning = true;
    SDL_Event event;

    division_of_the_page p ; //فراخوانی استراکت تقسیم بندی طولی و عرضی صفحه تحت عنوان p
    for (int i = 0 ; i < 12  ; i ++)
    {
        p.y[i] = (height / 12 * i) - 50;//اینجا اعضای آرایه طول یا قد صفحه مقدار دهی میشن.
    }
    for (int j = 0 ; j < 3 ; j ++)
    {
        p.x[j] = width / 3 * j;//اینجا اعضای آرایه عرض یا پهنای صفحه مقدار دهی میشن.
    }
    SDL_Texture *image = tasavir[0].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه //تصویر پس زمینه
    SDL_Rect destinationRect = { 0, 0, width , height}; // اینجا تصویر پس زمینه شروع بازی تعریف و قرار میگیره
    SDL_RenderCopy(m_renderer, image, NULL,
                   &destinationRect); // تصویر در مختصات و ابعاد مشخص شده رندر میشه
    SDL_RenderPresent(m_renderer);
    SDL_Delay(2000);
    while (isRunning) {
        if (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    isRunning = false;
                    break;
                case SDL_MOUSEBUTTONDOWN://اینجا مختصات مکانی که موس کلیک میشه گرفته میشه و داخل متغیر های mouse_X و mouse_Y ذخیره میشه
                    int mouse_X, mouse_Y;
                    SDL_GetMouseState(&mouse_X, &mouse_Y);
                    break;
            }

        }


        SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
        SDL_RenderClear(m_renderer);
        SDL_Texture *image = tasavir[0].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه //تصویر پس زمینه
        SDL_Rect destinationRect = { 0, 0, width , height}; // اینجا تصویر پس زمینه شروع بازی تعریف و قرار میگیره
        SDL_RenderCopy(m_renderer, image, NULL,
                       &destinationRect); // تصویر  در مختصات و ابعاد مشخص شده رندر میشه
         image = tasavir[1].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه  //تصویر شروع بازی
         destinationRect = { p.x[1], p.y[2]   , width / 3 , height / 9}; //مکان و مختصات دکمه و مستطیل جدید تعریف میشه
        SDL_RenderCopy(m_renderer, image, NULL,
                       &destinationRect); // تصویر  در مختصات و ابعاد مشخص شده رندر میشه
        image = tasavir[2].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه  //تصویر مود های بازی
        destinationRect = { p.x[1], p.y[4] , width / 3 , height / 9}; // مکان و مختصات دکمه و مستطیل جدید تعریف میشه
        SDL_RenderCopy(m_renderer, image, NULL,
                       &destinationRect); // تصویر  در مختصات و ابعاد مشخص شده رندر میشه
        image = tasavir[3].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه   //تصویر جدول امتیازات
        destinationRect = { p.x[1], p.y[6], width / 3 , height / 9}; //مکان و مختصات دکمه و مستطیل جدید تعریف میشه
        SDL_RenderCopy(m_renderer, image, NULL,
                       &destinationRect); // Render the image at the specified coordinates and dimensions
        image = tasavir[4].first; // Get the image from the vector based on its index //تصویر تم های بازی
        destinationRect = { p.x[1], p.y[8], width / 3 , height / 9}; // Define the destination rectangle
        SDL_RenderCopy(m_renderer, image, NULL,
                       &destinationRect); // Render the image at the specified coordinates and dimensions
        image = tasavir[5].first; // Get the image from the vector based on its index //تصویر سازندگان بازی
        destinationRect = { p.x[1], p.y[10], width / 3 , height / 9}; // Define the destination rectangle
        SDL_RenderCopy(m_renderer, image, NULL,
                       &destinationRect); // Render the image at the specified coordinates and dimensions
        image = tasavir[6].first; // Get the image from the vector based on its index //تصویر تنظیمات بازی
        destinationRect = { p.x[0], p.y[11], 80, 80}; // Define the destination rectangle
        SDL_RenderCopy(m_renderer, image, NULL,
                       &destinationRect); // Render the image at the specified coordinates and dimensions
                       SDL_RenderPresent(m_renderer);
        //SDL_Delay(2000);
        bool isRunning = true;
        SDL_Event event;

        while (isRunning) {
            if (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_QUIT:
                        isRunning = false;
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        int mouseX, mouseY;
                        SDL_GetMouseState(&mouseX, &mouseY);


                        // Check if the mouse click is within a specific area
                        if (mouseX >= p.x[1] && mouseX <= p.x[1] + (width / 3) && mouseY >= p.y[2] && mouseY <= p.y[2] + (height / 9)) {

                        }//تصویر استارت بازی
                        if (mouseX >= p.x[1] && mouseX <= p.x[1] + (width / 3) && mouseY >= p.y[4] && mouseY <= p.y[4] + (height / 9)) {

                        }//تصویر مود های بازی
                        if (mouseX >= p.x[1] && mouseX <= p.x[1] + (width / 3) && mouseY >= p.y[6] && mouseY <= p.y[6] + (height / 9)) {

                        }//تصویر جدول امتیازات
                        if (mouseX >= p.x[1] && mouseX <= p.x[1] + (width / 3) && mouseY >= p.y[8] && mouseY <= p.y[8] + (height / 9)) {

                        }//تصویر تم های بازی
                        if (mouseX >= p.x[1] && mouseX <= p.x[1] + (width / 3) && mouseY >= p.y[10] && mouseY <= p.y[10] + (height / 9)) {

                        }//تصویر سازندگان بازی
                        if ( pow((mouseX - (p.x[0] + 80 / 2)) , 2) +  pow ((mouseY - (p.y[11] + 80 / 2)) , 2) <= 1600){

                        }//تصویر تنظیمات
                        break;
                }
            }


            SDL_RenderPresent(m_renderer);
        }



    }




}
