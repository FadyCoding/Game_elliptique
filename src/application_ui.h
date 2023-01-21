#ifndef APPLICATION_UI_H
#define APPLICATION_UI_H
#include <SDL2/SDL.h> //SDL functions
#include <string>
#include <cmath> // M_PI / cos / sin

extern const int SCREEN_WIDTH, SCREEN_HEIGHT;

SDL_Window* init(std::string windowTitle);
SDL_Surface* loadMedia(std::string path);
void close(SDL_Window* gWindow, SDL_Renderer* renderer);

class Ellipse {
    //parameters
    private:
        //position parameters
        int x, y;                       //x and y position
        int r_x, r_y;                  //radius on x and y

        //color parameters
        Uint8 r, g ,b, a;  

    //methods
    public:
        //calcul of the ellipse perimeter //int perimeter(double r1, double r2){return 2 * M_PI * std::sqrt((r1 * r1 + r2 * r2) / 2);}
        //Ellipse renderer function //void SDL_Renderer_Ellipse(SDL_Renderer *renderer, int x, int y, int r_x, int r_y);

        //Default constructor
        Ellipse() {};

        //Constructor with parameters
        Ellipse(int x, int y, int r_x, int r_y, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

        //Default constructor
        ~Ellipse();

        //methods
        //void draw_Ellipse(SDL_Renderer* renderer, int x, int y, int r_x, int r_y); 

        //void render(SDL_Renderer *renderer){SDL_SetRenderDrawColor(renderer, r, g, b, a); draw_Ellipse(renderer, x, y, r_x, r_y);};

};

//implementation
/* 
void Ellipse::draw_Ellipse(SDL_Renderer* renderer, int x, int y, int r_x, int r_y){
    int x2, y2;
    for (double i = 0; i < 2 * M_PI; i += 0.1) {
        x2 = x + r_x * cos(i); 
        y2 = y + r_y * sin(i);
    SDL_RenderDrawLine(renderer, x, y, x2, y2);
    }
} */
 



#endif