
//#include <bits/stdc++.h>
//#include <bits/stdc++.h>
//#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
//#include <SDL2/SDL_ttf.h>
using namespace std ;
// Define a pair of SDL_Texture* and image path for each image
typedef std::pair<SDL_Texture*, std::string> ImagePair;

// Create a vector to store the image pairs
std::vector<ImagePair> images;


void ball_green(SDL_Renderer * renderer,double x_center , double y_center, double width,std::vector<ImagePair> images){
    int x = x_center ; int y = y_center ; int width_1=width ;
    SDL_Texture* image = images[0].first; // Get the image from the vector based on its index
    SDL_Rect destinationRect = {x-.04* width, y, .08*width,.08*width}; // Define the destination rectangle
    SDL_RenderCopy(renderer, image, NULL, &destinationRect); // Render the image at the specified coordinates and dimensions


} //ball number 1
void ball_yellow(SDL_Renderer * renderer,double x_center , double y_center,double width,std::vector<ImagePair> images){
    int x = x_center ; int y = y_center ; int width_1=width ;
    SDL_Texture* image = images[1].first; // Get the image from the vector based on its index
    SDL_Rect destinationRect = {x-.04* width, y, .08*width,.08*width}; // Define the destination rectangle
    SDL_RenderCopy(renderer, image, NULL, &destinationRect); // Render the image at the specified coordinates and dimensions

}//ball number 2
void ball_red(SDL_Renderer * renderer,double x_center , double y_center,double width,std::vector<ImagePair> images){
    int x = x_center ; int y = y_center ; int width_1=width ;
    SDL_Texture* image = images[2].first; // Get the image from the vector based on its index
    SDL_Rect destinationRect = {x-.04* width, y, .08*width,.08*width}; // Define the destination rectangle
    SDL_RenderCopy(renderer, image, NULL, &destinationRect); // Render the image at the specified coordinates and dimensions

}//ball number 3
void ball_purple(SDL_Renderer * renderer,double x_center , double y_center,double width,std::vector<ImagePair> images){
    int x = x_center ; int y = y_center ; int width_1=width ;
    SDL_Texture* image = images[3].first; // Get the image from the vector based on its index
    SDL_Rect destinationRect = {x-.04* width, y, .08*width,.08*width}; // Define the destination rectangle
    SDL_RenderCopy(renderer, image, NULL, &destinationRect); // Render the image at the specified coordinates and dimensions

}//ball number 4
void ball_blue(SDL_Renderer * renderer,double x_center , double y_center,double width,std::vector<ImagePair> images){
    int x = x_center ; int y = y_center ; int width_1=width ;
    SDL_Texture* image = images[4].first; // Get the image from the vector based on its index
    SDL_Rect destinationRect = {x-.04* width, y, .08*width,.08*width}; // Define the destination rectangle
    SDL_RenderCopy(renderer, image, NULL, &destinationRect); // Render the image at the specified coordinates and dimensions

}//ball number 5
void ball_red_yellow(SDL_Renderer * renderer,double x_center , double y_center,double width,std::vector<ImagePair> images){
    int x = x_center ; int y = y_center ; int width_1=width ;
    SDL_Texture* image = images[5].first; // Get the image from the vector based on its index
    SDL_Rect destinationRect = {x-.04* width, y, .08*width,.08*width}; // Define the destination rectangle
    SDL_RenderCopy(renderer, image, NULL, &destinationRect); // Render the image at the specified coordinates and dimensions




}//ball number 6
void ball_red_blue(SDL_Renderer * renderer,double x_center , double y_center,double width,std::vector<ImagePair> images){
    int x = x_center ; int y = y_center ; int width_1=width ;
    SDL_Texture* image = images[6].first; // Get the image from the vector based on its index
    SDL_Rect destinationRect = {x-.04* width, y, .08*width,.08*width}; // Define the destination rectangle
    SDL_RenderCopy(renderer, image, NULL, &destinationRect); // Render the image at the specified coordinates and dimensions

}//ball number 7
void ball_red_purple(SDL_Renderer * renderer,double x_center , double y_center,double width,std::vector<ImagePair> images){
    int x = x_center ; int y = y_center ; int width_1=width ;
    SDL_Texture* image = images[7].first; // Get the image from the vector based on its index
    SDL_Rect destinationRect = {x-.04* width, y, .08*width,.08*width}; // Define the destination rectangle
    SDL_RenderCopy(renderer, image, NULL, &destinationRect); // Render the image at the specified coordinates and dimensions

}//ball number 8
void ball_red_green(SDL_Renderer * renderer,double x_center , double y_center,double width,std::vector<ImagePair> images){
    int x = x_center ; int y = y_center ; int width_1=width ;
    SDL_Texture* image = images[8].first; // Get the image from the vector based on its index
    SDL_Rect destinationRect = {x-.04* width, y, .08*width,.08*width}; // Define the destination rectangle
    SDL_RenderCopy(renderer, image, NULL, &destinationRect); // Render the image at the specified coordinates and dimensions

}//ball number 9
void ball_blue_green(SDL_Renderer * renderer,double x_center , double y_center,double width,std::vector<ImagePair> images){
    int x = x_center ; int y = y_center ; int width_1=width ;
    SDL_Texture* image = images[9].first; // Get the image from the vector based on its index
    SDL_Rect destinationRect = {x-.04* width, y, .08*width,.08*width}; // Define the destination rectangle
    SDL_RenderCopy(renderer, image, NULL, &destinationRect); // Render the image at the specified coordinates and dimensions

}//ball number 10
void ball_blue_yellow(SDL_Renderer * renderer,double x_center , double y_center,double width,std::vector<ImagePair> images){
    int x = x_center ; int y = y_center ; int width_1=width ;
    SDL_Texture* image = images[10].first; // Get the image from the vector based on its index
    SDL_Rect destinationRect = {x-.04* width, y, .08*width,.08*width}; // Define the destination rectangle
    SDL_RenderCopy(renderer, image, NULL, &destinationRect); // Render the image at the specified coordinates and dimensions

}//ball number 11
void ball_blue_purple(SDL_Renderer * renderer,double x_center , double y_center,double width,std::vector<ImagePair> images){
    int x = x_center ; int y = y_center ; int width_1=width ;
    SDL_Texture* image = images[11].first; // Get the image from the vector based on its index
    SDL_Rect destinationRect = {x-.04* width, y, .08*width,.08*width}; // Define the destination rectangle
    SDL_RenderCopy(renderer, image, NULL, &destinationRect); // Render the image at the specified coordinates and dimensions

}//ball number 12
void ball_green_yellow(SDL_Renderer * renderer,double x_center , double y_center,double width,std::vector<ImagePair> images){
    int x = x_center ; int y = y_center ; int width_1=width ;
    SDL_Texture* image = images[12].first; // Get the image from the vector based on its index
    SDL_Rect destinationRect = {x-.04* width, y, .08*width,.08*width}; // Define the destination rectangle
    SDL_RenderCopy(renderer, image, NULL, &destinationRect); // Render the image at the specified coordinates and dimensions

}//ball number 13
void ball_green_purple(SDL_Renderer * renderer,double x_center , double y_center,double width,std::vector<ImagePair> images){
    int x = x_center ; int y = y_center ; int width_1=width ;
    SDL_Texture* image = images[13].first; // Get the image from the vector based on its index
    SDL_Rect destinationRect = {x-.04* width, y, .08*width,.08*width}; // Define the destination rectangle
    SDL_RenderCopy(renderer, image, NULL, &destinationRect); // Render the image at the specified coordinates and dimensions

}//ball number 14
void ball_purple_yellow(SDL_Renderer * renderer,double x_center , double y_center,double width,std::vector<ImagePair> images){
    int x = x_center ; int y = y_center ; int width_1=width ;
    SDL_Texture* image = images[14].first; // Get the image from the vector based on its index
    SDL_Rect destinationRect = {x-.04* width, y, .08*width,.08*width}; // Define the destination rectangle
    SDL_RenderCopy(renderer, image, NULL, &destinationRect); // Render the image at the specified coordinates and dimensions

}//ball number 15
void ball_black(SDL_Renderer * renderer,double x_center , double y_center,double width,std::vector<ImagePair> images) {
    int x = x_center ; int y = y_center ; int width_1=width ;
    SDL_Texture* image = images[15].first; // Get the image from the vector based on its index
    SDL_Rect destinationRect = {x-.04* width, y, .08*width,.08*width}; // Define the destination rectangle
    SDL_RenderCopy(renderer, image, NULL, &destinationRect); // Render the image at the specified coordinates and dimensions

}//ball number 16
void ball_lock_green(SDL_Renderer * renderer,double x_center , double y_center,double width,std::vector<ImagePair> images){
    int x = x_center ; int y = y_center ; int width_1=width ;
    SDL_Texture* image = images[16].first; // Get the image from the vector based on its index
    SDL_Rect destinationRect = {x-.04* width, y, .08*width,.08*width}; // Define the destination rectangle
    SDL_RenderCopy(renderer, image, NULL, &destinationRect); // Render the image at the specified coordinates and dimensions

}//ball number 17
void ball_lock_red(SDL_Renderer * renderer,double x_center , double y_center,double width,std::vector<ImagePair> images){
    int x = x_center ; int y = y_center ; int width_1=width ;
    SDL_Texture* image = images[17].first; // Get the image from the vector based on its index
    SDL_Rect destinationRect = {x-.04* width, y, .08*width,.08*width}; // Define the destination rectangle
    SDL_RenderCopy(renderer, image, NULL, &destinationRect); // Render the image at the specified coordinates and dimensions

}//ball number 18
void ball_lock_yellow(SDL_Renderer * renderer,double x_center , double y_center,double width,std::vector<ImagePair> images){
    int x = x_center ; int y = y_center ; int width_1=width ;
    SDL_Texture* image = images[18].first; // Get the image from the vector based on its index
    SDL_Rect destinationRect = {x-.04* width, y, .08*width,.08*width}; // Define the destination rectangle
    SDL_RenderCopy(renderer, image, NULL, &destinationRect); // Render the image at the specified coordinates and dimensions

}//ball number 19
void ball_lock_purple(SDL_Renderer * renderer,double x_center , double y_center,double width,std::vector<ImagePair> images){
    int x = x_center ; int y = y_center ; int width_1=width ;
    SDL_Texture* image = images[19].first; // Get the image from the vector based on its index
    SDL_Rect destinationRect = {x-.04* width, y, .08*width,.08*width}; // Define the destination rectangle
    SDL_RenderCopy(renderer, image, NULL, &destinationRect); // Render the image at the specified coordinates and dimensions

}//ball number 20
void ball_lock_blue(SDL_Renderer * renderer,double x_center , double y_center,double width,std::vector<ImagePair> images){
    int x = x_center ; int y = y_center ; int width_1=width ;
    SDL_Texture* image = images[20].first; // Get the image from the vector based on its index
    SDL_Rect destinationRect = {x-.04* width, y, .08*width,.08*width}; // Define the destination rectangle
    SDL_RenderCopy(renderer, image, NULL, &destinationRect); // Render the image at the specified coordinates and dimensions

}//ball number 21

void main_balls(SDL_Renderer * renderer,int a ,double x_center , double y_center,double width,double height,std::vector<ImagePair> images){//a نوع رنگ توپ است
    //visibility اگر 0 نمایش میده
    //اگر 1 همون جا محو میشه
    //اگه 2 میوفته زمین
    switch(a) {
        case 1: {
                ball_green(renderer, x_center, y_center, width,images);
            break;
        }
        case 2: {
                ball_yellow(renderer, x_center, y_center, width,images);
            break;
        }
        case 3: {
                ball_red(renderer, x_center, y_center, width,images);
            break;
        }
        case 4: {
                ball_purple(renderer, x_center, y_center, width,images);
            break;
        }
        case 5: {
                ball_blue(renderer, x_center, y_center, width,images);
            break;
        }
        case 6: {
                ball_red_yellow(renderer, x_center, y_center, width,images);
            break;
        }
        case 7: {
                ball_red_blue(renderer, x_center, y_center, width,images);
            break;
        }
        case 8: {
                ball_red_purple(renderer, x_center, y_center, width,images);
            break;
        }
        case 9: {
                ball_red_green(renderer, x_center, y_center, width,images);
            break;
        }
        case 10: {
                ball_blue_green(renderer, x_center, y_center, width,images);
            break;
        }
        case 11: {
                ball_blue_yellow(renderer, x_center, y_center, width,images);
            break;
        }
        case 12: {
                ball_blue_purple(renderer, x_center, y_center, width,images);
            break;
        }
        case 13: {
                ball_green_yellow(renderer, x_center, y_center, width,images);
            break;
        }
        case 14: {
                ball_green_purple(renderer, x_center, y_center, width,images);
            break;
        }
        case 15:{
                ball_purple_yellow(renderer, x_center, y_center, width,images);
            break;
        }
        case 16: {
                ball_black(renderer, x_center, y_center, width,images);
            break;
        }
        case 17: {
                ball_lock_green(renderer, x_center, y_center, width,images);
            break;
        }
        case 18: {
                ball_lock_red(renderer, x_center, y_center, width,images);
            break;
        }
        case 19: {
                ball_lock_yellow(renderer, x_center, y_center, width,images);
            break;
        }
        case 20: {
                ball_lock_purple(renderer, x_center, y_center, width,images);
            break;
        }
        case 21: {
                ball_lock_blue(renderer, x_center, y_center, width,images);
            break;
        }

    }
}
