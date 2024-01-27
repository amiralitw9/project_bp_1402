#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL2_gfx.h>
#include "C:\function\balls\main.cpp"
#include "C:\function\location\main.cpp"
#include <fstream>
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
// Load the images and store their textures
    for (int i = 1; i <= 22; ++i) {
        std::string imagePath = "C:/function/pic_balls/" + std::to_string(i) + ".png";
        SDL_Surface *imageSurface = IMG_Load(imagePath.c_str());
        SDL_Texture *texture = SDL_CreateTextureFromSurface(m_renderer, imageSurface);
        SDL_FreeSurface(imageSurface);
        images.push_back(std::make_pair(texture, imagePath));
    }

    //***********************************************************************
    double x[2][10]={{adad_sabet_x+ghotr_dayere,adad_sabet_x+2*ghotr_dayere,adad_sabet_x+3*ghotr_dayere,adad_sabet_x+4*ghotr_dayere,adad_sabet_x+5*ghotr_dayere,adad_sabet_x+6*ghotr_dayere,adad_sabet_x+7*ghotr_dayere,adad_sabet_x+8*ghotr_dayere,adad_sabet_x+9*ghotr_dayere,adad_sabet_x+10*ghotr_dayere},
                     {adad_sabet_x+ghotr_dayere-width*.04,adad_sabet_x+2*ghotr_dayere-width*.04,adad_sabet_x+3*ghotr_dayere-width*.04,adad_sabet_x+4*ghotr_dayere-width*.04,adad_sabet_x+5*ghotr_dayere-width*.04,adad_sabet_x+6*ghotr_dayere-width*.04,adad_sabet_x+7*ghotr_dayere-width*.04,adad_sabet_x+8*ghotr_dayere-width*.04,adad_sabet_x+9*ghotr_dayere-width*.04,adad_sabet_x+10*ghotr_dayere-width*.04}};
    double y[13]={(.04*width-2*fasele_do_dayere),(.04*width-fasele_do_dayere),(.04*width),.04*width+fasele_do_dayere,.04*width+2*fasele_do_dayere,.04*width+3*fasele_do_dayere,.04*width+4*fasele_do_dayere,.04*width+5*fasele_do_dayere,.04*width+6*fasele_do_dayere,.04*width+7*fasele_do_dayere,.04*width+8*fasele_do_dayere,.04*width+9*fasele_do_dayere,.04*width+10*fasele_do_dayere};
    int in_cannon = rand() % 5 + 1, out_cannon = rand() % 5 + 1;

    int counter_Setting = 0;

    //********************************
    // نقاط اصلی صفحه
    int list_toop[13][10];//لیست دو بعدی توپ ها
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
    struct division_of_the_page {
        int x[3];//تقسیم بندی طول صفحه
        int y[12]; //تقسیم بندی عرض صفحه
    };
//*********************************
    int music_num = 6, volume = 32;
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 1, 2048);
    vector<Mix_Music *> musics;
    for (int i = 1; i <= 6; ++i) {
        string m = "C:/function/music/" + to_string(i) + ".mp3";
        musics.push_back(Mix_LoadMUS(m.c_str()));
    }
//******************************************************** وکتور آهنگ ها


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
    for (int i = 2; i <= 32; ++i) {
        std::string imagePath =
                "C:/function/menu_pictures/" + to_string(i) + ".png";//عکس های منو داخل وکتور هم آپلود میشه.
        SDL_Surface *imageSurface = IMG_Load(imagePath.c_str());
        SDL_Texture *texture = SDL_CreateTextureFromSurface(m_renderer, imageSurface);
        SDL_FreeSurface(imageSurface);
        tasavir.push_back(std::make_pair(texture, imagePath));
    }
    //*************************************************************************************

    division_of_the_page p; //فراخوانی استراکت تقسیم بندی طولی و عرضی صفحه تحت عنوان p
    for (int i = 0; i < 12; i++) {
        p.y[i] = (height / 12 * i) - 50;//اینجا اعضای آرایه طول یا قد صفحه مقدار دهی میشن.
    }
    for (int j = 0; j < 3; j++) {
        p.x[j] = width / 3 * j;//اینجا اعضای آرایه عرض یا پهنای صفحه مقدار دهی میشن.
    }
    //***********
    SDL_Texture *image = tasavir[0].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه //تصویر پس زمینه
    SDL_Rect destinationRect = {0, 0, width, height}; // اینجا تصویر پس زمینه شروع بازی تعریف و قرار میگیره
    SDL_RenderCopy(m_renderer, image, NULL,
                   &destinationRect); // تصویر در مختصات و ابعاد مشخص شده رندر میشه
    //**********
    SDL_RenderPresent(m_renderer);

        bool isRunning = true;
        SDL_Event event;
//        play_music(musics, music_num, volume);


        while (isRunning) {
            if (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_QUIT:
                        isRunning = false;
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        int mouseX, mouseY;
                        SDL_GetMouseState(&mouseX, &mouseY);


                        SDL_Texture *image = tasavir[0].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه //تصویر پس زمینه
                        SDL_Rect destinationRect = {0, 0, width, height}; // اینجا تصویر پس زمینه شروع بازی تعریف و قرار میگیره
                        SDL_RenderCopy(m_renderer, image, NULL,
                                       &destinationRect); // تصویر  در مختصات و ابعاد مشخص شده رندر میشه
                        image = tasavir[1].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه  //تصویر شروع بازی
                        destinationRect = {p.x[1], p.y[2], width / 3, height / 9}; //مکان و مختصات دکمه و مستطیل جدید تعریف میشه
                        SDL_RenderCopy(m_renderer, image, NULL,
                                       &destinationRect); // تصویر  در مختصات و ابعاد مشخص شده رندر میشه
                        image = tasavir[2].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه  //تصویر مود های بازی
                        destinationRect = {p.x[1], p.y[4], width / 3, height / 9}; // مکان و مختصات دکمه و مستطیل جدید تعریف میشه
                        SDL_RenderCopy(m_renderer, image, NULL,
                                       &destinationRect); // تصویر  در مختصات و ابعاد مشخص شده رندر میشه
                        image = tasavir[3].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه   //تصویر جدول امتیازات
                        destinationRect = {p.x[1], p.y[6], width / 3, height / 9}; //مکان و مختصات دکمه و مستطیل جدید تعریف میشه
                        SDL_RenderCopy(m_renderer, image, NULL,
                                       &destinationRect); // Render the image at the specified coordinates and dimensions
                        image = tasavir[4].first; // Get the image from the vector based on its index //تصویر تم های بازی
                        destinationRect = {p.x[1], p.y[8], width / 3, height / 9}; // Define the destination rectangle
                        SDL_RenderCopy(m_renderer, image, NULL,
                                       &destinationRect); // Render the image at the specified coordinates and dimensions
                        image = tasavir[5].first; // Get the image from the vector based on its index //تصویر سازندگان بازی
                        destinationRect = {p.x[1], p.y[10], width / 3, height / 9}; // Define the destination rectangle
                        SDL_RenderCopy(m_renderer, image, NULL,
                                       &destinationRect); // Render the image at the specified coordinates and dimensions
                        image = tasavir[6].first; // Get the image from the vector based on its index //تصویر تنظیمات بازی
                        destinationRect = {p.x[0], p.y[11], 80, 80}; // Define the destination rectangle
                        SDL_RenderCopy(m_renderer, image, NULL,
                                       &destinationRect); // Render the image at the specified coordinates and dimensions
                        image = tasavir[25].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه  //تصویر خروج یا اگزیت
                        destinationRect = {820, 770, 45, 45}; //مکان و مختصات دکمه و مستطیل جدید تعریف میشه
                        SDL_RenderCopy(m_renderer, image, NULL,
                                       &destinationRect); //// تصویر  در مختصات و ابعاد مشخص شده رندر میشه

                        SDL_RenderPresent(m_renderer);
                        //SDL_Delay(2000);
                        bool exit = true;
                        // Check if the mouse click is within a specific area
                        if (mouseX >= p.x[1] && mouseX <= p.x[1] + (width / 3) && mouseY >= p.y[2] &&
                            mouseY <= p.y[2] + (height / 9)) {
                            if (true) {//نوع مود بازی
                                bool quit = false;
                                SDL_Event e;
                                double enteghali = .1;
                                int c = 0;//برای به هم نریختن هنگام سوییچ نوشته شده
                                //play_music(musics, music_num, volume);
                                while (!quit) {
                                    Mix_VolumeMusic(volume);
                                    while (SDL_PollEvent(&e) != 0) {
                                        if (e.type == SDL_QUIT) {
                                            quit = true; // خروج از حلقه در صورت بستن پنجره
                                        }
                                        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
                                            quit = true; // خروج از حلقه در صورت فشردن دکمه ESC
                                        }
                                        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE) {
                                            for (int i = 0; i < 10; i++)
                                                list_toop[11][i] = 0;

                                        }
                                        if (e.type == SDL_MOUSEWHEEL) {
                                            if (e.wheel.y > 0 && volume < 128) {
                                                volume += 4; // Scroll right

                                            } else if (e.wheel.y < 0 && volume > 0) {
                                                volume -= 4; // Scroll left
                                            }
//                                            cout << volume << endl;

                                        }
                                        int mouseX1, mouseY1;
                                        SDL_GetMouseState(&mouseX1, &mouseY1); // Get the current mouse position
                                        int normalizedMouseX = static_cast<double>(mouseX1);
                                        int normalizedMouseY = static_cast<double>(mouseY1);
                                        SDL_SetRenderDrawColor(m_renderer, 72, 191, 238, 255); // تنظیم رنگ مشکی بکگراند
                                        SDL_RenderClear(m_renderer); // پاک کردن صفحه
                                        boxRGBA(m_renderer, 0, 0, .2 * width - .05 * width, 900, 220, 160, 41, 255);
                                        boxRGBA(m_renderer, 0, .05 * width + 10 * fasele_do_dayere, 900, 900, 220, 160,
                                                41, 255);
                                        list_toop_ha(list_toop, enteghali, width, c, normalizedMouseX,
                                                     normalizedMouseY);
                                        enteghali += .1;
                                        for (int i = 0; i < 13; i++) {
                                            int d = (i % 2);
                                            for (int j = 0; j < 10; j++) {
                                                main_balls(m_renderer, list_toop[i][j], x[(d + c) % 2][j],
                                                           y[i] + enteghali, width, height, images);
                                            }

                                        }
                                        //**********************************

                                        if (normalizedMouseY > 600 && normalizedMouseX < .2 * width - .05 * width) {
                                            normalizedMouseY = 600, normalizedMouseX = .2 * width - .05 * width;
                                        }
                                        if (normalizedMouseY > 600)
                                            normalizedMouseY = 600;
                                        double angle = atan2(normalizedMouseX - 503, 740 - normalizedMouseY) * 180 /
                                                       M_PI; // Calculate the angle based on mouse position
                                        //cout<<angle<<endl;
                                        SDL_Texture *image = images[21].first; // Get the image from the vector based on its index
                                        SDL_Rect destinationRect = {443, 635, 110,
                                                                    200}; // Define the destination rectangle with dimensions 80x80
                                        SDL_Point center = {55,
                                                            100}; // Set the center of rotation to the center of the rectangle
                                        SDL_RenderCopyEx(m_renderer, image, NULL, &destinationRect, angle, &center,
                                                         SDL_FLIP_NONE); // Render the image at the specified coordinates and dimensions with rotation based on mouse position
                                        angle = atan2(normalizedMouseX - (470 + .04 * width),
                                                      745 + .04 * width - normalizedMouseY) * 180 / M_PI;
                                        //**************************************************خود cannon
                                        int x_neshan = 1; //اگه پرتاب شد بشه 0
                                        SDL_Event event_1;
                                        while (SDL_PollEvent(&event_1) != 0) {
                                            if (event_1.type == SDL_KEYDOWN && event_1.key.keysym.sym == SDLK_SPACE) {
                                                x_neshan = 0;
                                                in_cannon = out_cannon;
                                                out_cannon = cannon_random(list_toop, normalizedMouseX);
                                            }
                                            if (event_1.type == SDL_MOUSEBUTTONDOWN) {
                                                SDL_GetMouseState(&mouseX, &mouseY);
                                                if ((mouseX - (200 + .04 * width)) * (mouseX - (200 + .04 * width)) +
                                                    (mouseY - (745 + .04 * width)) * (mouseY - (745 + .04 * width)) <=
                                                    (.04 * width) * (.04 * width))
                                                    swap(in_cannon, out_cannon);
                                            }

                                        }

                                        image = images[in_cannon -
                                                       1].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه  //تصویر مود های بازی
                                        destinationRect = {464, 735, .08 * width,
                                                           .08 * width}; // مکان و مختصات دکمه و مستطیل جدید تعریف میشه
                                        center = {34, 0}; // Set the center of rotation to the center of the rectangle
                                        SDL_RenderCopyEx(m_renderer, image, NULL, &destinationRect, angle, &center,
                                                         SDL_FLIP_NONE); // Render the image at the specified coordinates and dimensions with rotation based on mouse position
                                        image = images[out_cannon -
                                                       1].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه  //تصویر مود های بازی
                                        destinationRect = {200, 745, .08 * width,
                                                           .08 * width}; // مکان و مختصات دکمه و مستطیل جدید تعریف میشه
                                        SDL_RenderCopy(m_renderer, image, NULL,
                                                       &destinationRect); // تصویر  در مختصات و ابعاد مشخص شده رندر میشه


                                        aalineRGBA(m_renderer, .2 * width - .05 * width,
                                                   .05 * width + 10 * fasele_do_dayere, width,
                                                   .05 * width + 10 * fasele_do_dayere, 255, 255, 255, 255);
                                        aalineRGBA(m_renderer, .2 * width - .05 * width, 0, .2 * width - .05 * width,
                                                   .05 * width + 10 * fasele_do_dayere, 255, 255, 255, 255);

//                                    ofstream fout("C:\\function\\data.txt",ios::app) ;
//                                    fout<<cannon_random(list_toop,normalizedMouseX)<<" ";
//                                    fout.close();
                                        //cout<<cannon_random(list_toop,normalizedMouseX);


                                        //***************************************
                                        //خط های دور صفحه
                                        for (int j = 0; j < 10; j++) {//خطی که برای سوختن استفاده شد .
                                            if (list_toop[12][j] !=
                                                0) { // شرط باخت- این حلقه درصورت پایان پیدا کردن دیگه توپ تولید نمیکنه
                                                //" چیزای هنگام باختن قرار هست نمایش داده بشه"
                                                //" باز شدن منو برای بازی مجدد"
                                                //"ذخیره امتیازات و چیزای مورد نیاز دیگه"
                                                return 0;
                                            }
                                        }


                                        SDL_RenderPresent(m_renderer);
//                                    for (int i = 0; i < 13; i++) {
//                                        for (int j = 0; j < 10; j++) {
//                                            cout<<list_toop[i][j]<<" ";
//                                        }
//                                        cout<<endl ;
//                                    }
//                                    cout<<"****************************"<<endl;
                                    }

                                }
//                            if(true){}//شرط بعدی
                            }
                        }//تصویر استارت بازی
                        if (mouseX >= p.x[1] && mouseX <= p.x[1] + (width / 3) && mouseY >= p.y[4] &&
                            mouseY <= p.y[4] + (height / 9)) {}//تصویر مود های بازی
                        if (mouseX >= p.x[1] && mouseX <= p.x[1] + (width / 3) && mouseY >= p.y[6] &&
                            mouseY <= p.y[6] + (height / 9)) {}//تصویر جدول امتیازات
                        if (mouseX >= p.x[1] && mouseX <= p.x[1] + (width / 3) && mouseY >= p.y[8] &&
                            mouseY <= p.y[8] + (height / 9)) {}//تصویر تم های بازی
                        if (exit && mouseX >= p.x[1] && mouseX <= p.x[1] + (width / 3) && mouseY >= p.y[10] &&
                            mouseY <= p.y[10] + (height / 9)) {
                            SDL_RenderClear(m_renderer);
                            SDL_SetRenderDrawColor(m_renderer,150,150,250,255);
                            SDL_Event Event;
                            while (exit) {
                                if (SDL_PollEvent(&Event)) {
                                    if (Event.type == SDL_MOUSEBUTTONDOWN) {
                                        int mouse_X2, mouse_Y2;
                                        SDL_GetMouseState(&mouse_X2, &mouse_Y2);
                                        if (mouse_X2 >= 820 && mouse_X2 <= 820 + 45 && mouse_Y2 >= 770 &&
                                            mouse_Y2 <= 770 + 45) {
                                            exit = false;
                                            counter_Setting = 0;
                                        }
                                    }
                                image = tasavir[26].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه  //تصویر شروع بازی
                                destinationRect = {p.x[0], p.y[2], 300, 400}; //مکان و مختصات دکمه و مستطیل جدید تعریف میشه
                                SDL_RenderCopy(m_renderer, image, NULL,
                                               &destinationRect); // تصویر  در مختصات و ابعاد مشخص شده رندر میشه
                                image = tasavir[27].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه  //تصویر شروع بازی
                                destinationRect = {p.x[2], p.y[2], 300, 400}; //مکان و مختصات دکمه و مستطیل جدید تعریف میشه
                                SDL_RenderCopy(m_renderer, image, NULL,
                                               &destinationRect); // تصویر  در مختصات و ابعاد مشخص شده رندر میشه
                                image = tasavir[25].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه  //تصویر شروع بازی
                                destinationRect = {820, 770, 45, 45}; //مکان و مختصات دکمه و مستطیل جدید تعریف میشه
                                SDL_RenderCopy(m_renderer, image, NULL,
                                               &destinationRect); //// تصویر  در مختصات و ابعاد مشخص شده رندر میشه
                                    image = tasavir[30].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه  //تصویر شروع بازی
                                    destinationRect = {30+p.x[1], 200, 250, 50}; //مکان و مختصات دکمه و مستطیل جدید تعریف میشه
                                    SDL_RenderCopy(m_renderer, image, NULL,
                                                   &destinationRect); //// تصویر  در مختصات و ابعاد مشخص شده رندر میشه
                                    image = tasavir[29].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه  //تصویر شروع بازی
                                    destinationRect = {50+p.x[2], 500, 200, 100}; //مکان و مختصات دکمه و مستطیل جدید تعریف میشه
                                    SDL_RenderCopy(m_renderer, image, NULL,
                                                   &destinationRect); //// تصویر  در مختصات و ابعاد مشخص شده رندر میشه
                                    image = tasavir[31].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه  //تصویر شروع بازی
                                    destinationRect = {30+p.x[1], 400, 250, 50}; //مکان و مختصات دکمه و مستطیل جدید تعریف میشه
                                    SDL_RenderCopy(m_renderer, image, NULL,
                                                   &destinationRect); //// تصویر  در مختصات و ابعاد مشخص شده رندر میشه
                                    image = tasavir[28].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه  //تصویر شروع بازی
                                    destinationRect = {50+p.x[0], 500, 200, 100}; //مکان و مختصات دکمه و مستطیل جدید تعریف میشه
                                    SDL_RenderCopy(m_renderer, image, NULL,
                                                   &destinationRect); //// تصویر  در مختصات و ابعاد مشخص شده رندر میشه

                                }
                                SDL_RenderPresent(m_renderer);
                            }



                            }//تصویر سازندگان بازی
                        if (exit &&
                            pow((mouseX - (p.x[0] + 80 / 2)), 2) + pow((mouseY - (p.y[11] + 80 / 2)), 2) <= 1600) {

                            if (counter_Setting == 0) {
                                SDL_RenderClear(m_renderer);
                                image = tasavir[24].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه //تصویر پس زمینه
                                destinationRect = {p.x[0], p.y[0], 900,
                                                   900}; // اینجا تصویر پس زمینه شروع بازی تعریف و قرار میگیره
                                SDL_RenderCopy(m_renderer, image, NULL,
                                               &destinationRect); // تصویر  در مختصات و ابعاد مشخص شده رندر میشه
                                SDL_RenderPresent(m_renderer);
                                SDL_Delay(1500);
                                counter_Setting = 1;
                            }

                            //SDL_RenderClear(m_renderer); // پاک کردن صفحه
                            //گر اگزیت کلیک شد اگزیت به فالس تبدیل میشه و کانتر ستینگ برابر با صفر شود در انتها
                            //SDL_Delay(2000);
                            image = tasavir[18].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه //تصویر ااولین اهنگ
                            destinationRect = {p.x[0], p.y[2], 300,
                                               300}; // اینجا تصویر پس زمینه شروع بازی تعریف و قرار میگیره
                            SDL_RenderCopy(m_renderer, image, NULL,
                                           &destinationRect); // تصویر  در مختصات و ابعاد مشخص شده رندر میشه
                            image = tasavir[19].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه  //تصویر دملین اهنگ
                            destinationRect = {p.x[1], p.y[2], 300,
                                               300}; //مکان و مختصات دکمه و مستطیل جدید تعریف میشه
                            SDL_RenderCopy(m_renderer, image, NULL,
                                           &destinationRect); // تصویر  در مختصات و ابعاد مشخص شده رندر میشه
                            image = tasavir[20].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه  //تصویر سومین اهنگ
                            destinationRect = {p.x[2], p.y[2], 300,
                                               300}; //مکان و مختصات دکمه و مستطیل جدید تعریف میشه
                            SDL_RenderCopy(m_renderer, image, NULL,
                                           &destinationRect); // تصویر  در مختصات و ابعاد مشخص شده رندر میشه
                            image = tasavir[21].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه  //تصویر چهارمین اهنگ
                            destinationRect = {p.x[0], p.y[6], 300,
                                               300}; //مکان و مختصات دکمه و مستطیل جدید تعریف میشه
                            SDL_RenderCopy(m_renderer, image, NULL,
                                           &destinationRect); // تصویر  در مختصات و ابعاد مشخص شده رندر میشه
                            image = tasavir[22].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه  //تصویر پنجمین اهنگ
                            destinationRect = {p.x[1], p.y[6], 300,
                                               300}; //مکان و مختصات دکمه و مستطیل جدید تعریف میشه
                            SDL_RenderCopy(m_renderer, image, NULL,
                                           &destinationRect); // تصویر  در مختصات و ابعاد مشخص شده رندر میشه
                            image = tasavir[23].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه  //تتصویر ششمین اهنگ
                            destinationRect = {p.x[2], p.y[6], 300,
                                               300}; //مکان و مختصات دکمه و مستطیل جدید تعریف میشه
                            SDL_RenderCopy(m_renderer, image, NULL,
                                           &destinationRect); // تصویر  در مختصات و ابعاد مشخص شده رندر میشه
                            image = tasavir[7].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه  //تصویر تنظیم حجم صدا
                            destinationRect = {375, 750, 206, 50}; //مکان و مختصات دکمه و مستطیل جدید تعریف میشه
                            SDL_RenderCopy(m_renderer, image, NULL,
                                           &destinationRect); //// تصویر  در مختصات و ابعاد مشخص شده رندر میشه
                            image = tasavir[25].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه  //تصویر خروج یا اگزیت
                            destinationRect = {820, 770, 45, 45}; //مکان و مختصات دکمه و مستطیل جدید تعریف میشه
                            SDL_RenderCopy(m_renderer, image, NULL,
                                           &destinationRect); //// تصویر  در مختصات و ابعاد مشخص شده رندر میشه
                            SDL_RenderPresent(m_renderer);
                            SDL_Event Event;
                            while (exit) {
                                Mix_VolumeMusic(volume);
                                if (SDL_PollEvent(&Event)) {
                                    if (Event.type==SDL_MOUSEBUTTONDOWN) {
                                            int mouse_X2, mouse_Y2;
                                            SDL_GetMouseState(&mouse_X2, &mouse_Y2);
                                            if (mouse_X2 >= p.x[0] && mouse_X2 <= p.x[0] + 300 && mouse_Y2 >= p.y[2] && mouse_Y2 <= p.y[2] + 300 )
                                            {
                                                music_num = 1;
                                                Mix_HaltMusic();
                                                play_music(musics,music_num,volume);
                                            }
                                            if (mouse_X2 >= p.x[1] && mouse_X2 <= p.x[1] + 300 && mouse_Y2 >= p.y[2] && mouse_Y2 <= p.y[2] + 300 )
                                            {
                                                music_num = 2;
                                                Mix_HaltMusic();
                                                play_music(musics,music_num,volume);

                                            }
                                            if (mouse_X2 >= p.x[2] && mouse_X2 <= p.x[2] + 300 && mouse_Y2 >= p.y[2] && mouse_Y2 <= p.y[2] + 300 )
                                            {
                                                music_num = 3;
                                                Mix_HaltMusic();
                                                play_music(musics,music_num,volume);

                                            }
                                            if (mouse_X2 >= p.x[0] && mouse_X2 <= p.x[0] + 300 && mouse_Y2 >= p.y[6] && mouse_Y2 <= p.y[6] + 300 )
                                            {
                                                music_num = 4;
                                                Mix_HaltMusic();
                                                play_music(musics,music_num,volume);

                                            }
                                            if (mouse_X2 >= p.x[1] && mouse_X2 <= p.x[1] + 300 && mouse_Y2 >= p.y[6] && mouse_Y2 <= p.y[6] + 300 )
                                            {
                                                music_num = 5;
                                                Mix_HaltMusic();
                                                play_music(musics,music_num,volume);

                                            }
                                            if (mouse_X2 >= p.x[2] && mouse_X2 <= p.x[2] + 300 && mouse_Y2 >= p.y[6] && mouse_Y2 <= p.y[6] + 300 )
                                            {
                                                music_num = 6;
                                                Mix_HaltMusic();
                                                play_music(musics,music_num,volume);
                                            }
                                            //گر اگزیت کلیک شد اگزیت به فالس تبدیل میشه و کانتر ستینگ برابر با صفر شود در انتها
                                            if (mouse_X2 >= 820 && mouse_X2 <= 820 + 45 && mouse_Y2 >= 770 && mouse_Y2 <= 770 + 45)
                                            {
                                                exit = false;
                                                counter_Setting = 0;
                                            }
                                        if (mouse_X2 >= 820 && mouse_X2 <= 820 + 45 && mouse_Y2 >= 770 && mouse_Y2 <= 770 + 45)
                                        {
                                            exit = false;
                                            counter_Setting = 0;
                                        }
                                    }
                                    if (Event.type == SDL_MOUSEWHEEL) {
                                        if (Event.wheel.y > 0 && volume < 128) {
                                            volume += 4; // Scroll right

                                        } else if (Event.wheel.y < 0 && volume > 0) {
                                            volume -= 4; // Scroll left
                                        }
//                                        cout << volume << endl;
                                        Mix_VolumeMusic(volume);

                                    }
                                }

                                if (volume < 12) {
                                    boxRGBA(m_renderer,377,757,397,787,255,255,255,255);
                                }
                                if (volume < 24){
                                    boxRGBA(m_renderer,397,757,397,787,255,255,255,255);
                                }
                                if (volume < 36) {
                                    boxRGBA(m_renderer,417,757,397,787,255,255,255,255);
                                }
                                if (volume < 48) {
                                    boxRGBA(m_renderer,437,757,397,787,255,255,255,255);
                                }
                                if (volume < 60) {
                                    boxRGBA(m_renderer,457,757,397,787,255,255,255,255);
                                }
                                if (volume < 74) {
                                    boxRGBA(m_renderer,477,757,397,787,255,255,255,255);
                                }
                                if (volume < 88) {
                                    boxRGBA(m_renderer,497,757,397,787,255,255,255,255);
                                }
                                if (volume < 102) {
                                    boxRGBA(m_renderer,517,757,397,787,255,255,255,255);
                                }
                                if (volume < 116) {
                                    boxRGBA(m_renderer,537,757,397,787,255,255,255,255);
                                }
                                if (volume < 129) {
                                    boxRGBA(m_renderer,557,757,397,787,255,255,255,255);
                                    boxRGBA(m_renderer,577,757,397,787,255,255,255,255);
                                }
                                if (volume > 12) {
                                        image = tasavir[8].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه  //تصویر اولین حجم صدا
                                        destinationRect = {377, 757, 20,
                                                           30}; //مکان و مختصات دکمه و مستطیل جدید تعریف میشه
                                        SDL_RenderCopy(m_renderer, image, NULL,
                                                       &destinationRect); //// تصویر  در مختصات و ابعاد مشخص شده رندر میشه
                                    }
                                    if (volume > 24) {
                                        image = tasavir[10].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه  //تصویر اولین حجم صدا
                                        destinationRect = {397, 757, 20,
                                                           30}; //مکان و مختصات دکمه و مستطیل جدید تعریف میشه
                                        SDL_RenderCopy(m_renderer, image, NULL,
                                                       &destinationRect); //// تصویر  در مختصات و ابعاد مشخص شده رندر میشه
                                    }

                                if (volume > 36) {
                                        image = tasavir[11].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه  //تصویر اولین حجم صدا
                                        destinationRect = {417, 757, 20,
                                                           30}; //مکان و مختصات دکمه و مستطیل جدید تعریف میشه
                                        SDL_RenderCopy(m_renderer, image, NULL,
                                                       &destinationRect); //// تصویر  در مختصات و ابعاد مشخص شده رندر میشه
                                    }

                                if (volume > 48) {
                                        image = tasavir[12].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه  //تصویر اولین حجم صدا
                                        destinationRect = {437, 757, 20,
                                                           30}; //مکان و مختصات دکمه و مستطیل جدید تعریف میشه
                                        SDL_RenderCopy(m_renderer, image, NULL,
                                                       &destinationRect); //// تصویر  در مختصات و ابعاد مشخص شده رندر میشه
                                    }

                                if (volume > 60) {
                                        image = tasavir[12].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه  //تصویر اولین حجم صدا
                                        destinationRect = {457, 757, 20,
                                                           30}; //مکان و مختصات دکمه و مستطیل جدید تعریف میشه
                                        SDL_RenderCopy(m_renderer, image, NULL,
                                                       &destinationRect); //// تصویر  در مختصات و ابعاد مشخص شده رندر میشه
                                    }

                                if (volume > 74) {
                                        image = tasavir[13].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه  //تصویر اولین حجم صدا
                                        destinationRect = {477, 757, 20,
                                                           30}; //مکان و مختصات دکمه و مستطیل جدید تعریف میشه
                                        SDL_RenderCopy(m_renderer, image, NULL,
                                                       &destinationRect); //// تصویر  در مختصات و ابعاد مشخص شده رندر میشه
                                    }

                                if (volume > 88) {
                                        image = tasavir[14].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه  //تصویر اولین حجم صدا
                                        destinationRect = {497, 757, 20,
                                                           30}; //مکان و مختصات دکمه و مستطیل جدید تعریف میشه
                                        SDL_RenderCopy(m_renderer, image, NULL,
                                                       &destinationRect); //// تصویر  در مختصات و ابعاد مشخص شده رندر میشه
                                    }

                                if (volume > 102) {
                                        image = tasavir[15].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه  //تصویر اولین حجم صدا
                                        destinationRect = {517, 757, 20,
                                                           30}; //مکان و مختصات دکمه و مستطیل جدید تعریف میشه
                                        SDL_RenderCopy(m_renderer, image, NULL,
                                                       &destinationRect); //// تصویر  در مختصات و ابعاد مشخص شده رندر میشه
                                    }

                                if (volume > 116) {
                                        image = tasavir[16].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه  //تصویر اولین حجم صدا
                                        destinationRect = {537, 757, 20,
                                                           30}; //مکان و مختصات دکمه و مستطیل جدید تعریف میشه
                                        SDL_RenderCopy(m_renderer, image, NULL,
                                                       &destinationRect); //// تصویر  در مختصات و ابعاد مشخص شده رندر میشه
                                    }

                                if (volume == 124 || volume==128) {
                                        image = tasavir[17].first; // تصویر را از وکتور حاوی تصاویر بر اساس شاخص و اصطلاحا index  اون دریافت میکنه  //تصویر اولین حجم صدا
                                        destinationRect = {557, 757, 20,
                                                           30}; //مکان و مختصات دکمه و مستطیل جدید تعریف میشه
                                        SDL_RenderCopy(m_renderer, image, NULL,
                                                       &destinationRect); //// تصویر  در مختصات و ابعاد مشخص شده رندر میشه
                                    }

                                SDL_RenderPresent(m_renderer);
                                    //تصویر تنظیمات
                                }
                            exit= true ;

                            }
                        if(mouseX >= 820 && mouseX <= 820 + 45 && mouseY >= 770 && mouseY <= 770 + 45){
                            return 0 ;
                        }
                            SDL_RenderPresent(m_renderer);
                            exit= true ;
                        }

            }
            SDL_RenderPresent(m_renderer);
        }
    }