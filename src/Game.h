#ifndef GAME_H
#define GAME_H
#include "iostream"
#include <SDL2/SDL.h> //SDL functions

class Game {
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
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
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

    void render() {
        SDL_RenderClear(renderer);
        // Draw game objects here
        SDL_RenderPresent(renderer);
    }

    void clean() {
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        std::cout << "Game cleaned." << std::endl;
    }

    bool running;

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};



#endif