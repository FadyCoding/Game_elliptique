#ifndef APPLICATION_UI_H
#define APPLICATION_UI_H
#include <SDL2/SDL.h> //SDL functions
#include <string>
#include <cmath> // M_PI / cos / sin

extern const int SCREEN_WIDTH, SCREEN_HEIGHT;

SDL_Window* init(std::string windowTitle);
SDL_Surface* loadMedia(std::string path);
void close(SDL_Window* gWindow, SDL_Renderer* renderer);

template<typename T>
class Ellipse {
    //parameters
    private:
        //position parameters
        T x, y;                       //x and y position
        T r_x, r_y;                  //radius on x and y

        //color parameters
        SDL_Color color; 

    //methods
    public:
        //calcul of the ellipse perimeter //int perimeter(double r1, double r2){return 2 * M_PI * std::sqrt((r1 * r1 + r2 * r2) / 2);}
        //Ellipse renderer function //void SDL_Renderer_Ellipse(SDL_Renderer *renderer, int x, int y, int r_x, int r_y);

        //Default constructor
        Ellipse() { x = 0; y = 0; r_x = 0; r_y = 0;};

        //Constructor with parameters
        Ellipse(T x, T y, T r_x, T r_y);

        //Default constructor
        ~Ellipse();
        
        //Setters
        void setX(T x);
        void setY(T y);

        void setR_x(T r_x);
        void setR_y(T r_y);

        //Getters
        T getX() { return x; };
        T getY() { return y; };

        T getR_x() { return r_x; };
        T getR_y() { return r_y; };
        
        //methods
        void draw_Ellipse(SDL_Renderer* renderer, T x, T y, T r_x, T r_y);

};

//implementation
/* void SDL_Renderer_Ellipse(SDL_Renderer* renderer, int x, int y, int r_x, int r_y){
        int x2, y2;
        for (double i = 0; i < 2 * M_PI; i += 0.1) {
            x2 = x + r_x * cos(i); 
            y2 = y + r_y * sin(i);
        SDL_RenderDrawLine(renderer, x, y, x2, y2);
    }
} */

template <typename T>
void Ellipse<T>::draw_Ellipse(SDL_Renderer* renderer, T x, T y, T r_x, T r_y){
    int x2, y2;
    for (double i = 0; i < 2 * M_PI; i += 0.1) {
        x2 = x + r_x * cos(i); 
        y2 = y + r_y * sin(i);
    SDL_RenderDrawLine(renderer, x, y, x2, y2);
    }
}


#endif