#ifndef GAME_H
#define GAME_H
#include "iostream"
#include <SDL2/SDL.h> //SDL functions

class Ellipse {
public:
    Ellipse(int x, int y, int rx, int ry) : x(x), y(y), rx(rx), ry(ry) {
    }

    void render(SDL_Renderer* renderer) {
        float angle;
        float x1, y1;
        for (angle = 0; angle < 2 * M_PI; angle += 0.01) {
            x1 = x + rx * cos(angle);
            y1 = y + ry * sin(angle);
            SDL_RenderDrawPoint(renderer, x1, y1);
        }
    }

private:
    int x, y;
    int rx, ry;
};


class Game {

private:
    SDL_Window* window;
    SDL_Renderer* renderer;

public:
    Game() {
        running = false;
    }

    ~Game() {
        SDL_Quit();
    }

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
        int flags = 0;
        if (fullscreen) {
            flags = SDL_WINDOW_FULLSCREEN;
        }

        if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
            std::cout << "Subsystems Initialized!" << std::endl;

            window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
            if (window) {
                std::cout << "Window created!" << std::endl;
            }

            renderer = SDL_CreateRenderer(window, -1, 0);
            if (renderer) {
                SDL_SetRenderDrawColor(renderer, 100, 100, 0, 255);
                std::cout << "Renderer created!" << std::endl;
            }

            running = true;
        } else {
            running = false;
        }
    }

    void handleEvents() {
        SDL_Event event;
        SDL_PollEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                running = false;
                break;
            default:
                break;
        }
    }

    void update() {
        // Game logic goes here
    }


    void draw() {

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        // Draw game objects here
        Ellipse ellipse(30, 20, 10, 5);
        ellipse.render(renderer);
        SDL_RenderPresent(renderer);
    }

    void clean() {
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        std::cout << "Game cleaned." << std::endl;
    }

    bool running;


};





#endif