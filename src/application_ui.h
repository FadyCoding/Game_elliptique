#ifndef APPLICATION_UI_H
#define APPLICATION_UI_H
#include <SDL2/SDL.h>
#include <string>
#include <cmath>

extern const int SCREEN_WIDTH, SCREEN_HEIGHT;

SDL_Window* init(std::string windowTitle);
SDL_Surface* loadMedia(std::string path);
void close(SDL_Window* gWindow, SDL_Renderer* renderer);

class ellipse {
    //parameters
    private:
        //position parameters
        double x;                   //x position
        double y;                   //y position
        double r1;                  //radius on x
        double r2;                  //radius on y

        //color parameters
        double r, g, b;             //red, green, blue
    //methods
    public:
        //calcul of the ellipse perimeter
       
        double perimeter(double r1, double r2){return 2 * M_PI * std::sqrt((r1 * r1 + r2 * r2) / 2);}

        //calcul of the ellipse surface
        double surface(double r1, double r2){return 2 * M_PI * r1 * r2;}

};



#endif