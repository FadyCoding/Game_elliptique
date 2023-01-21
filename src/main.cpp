#include "application_ui.h"
#include "Game.h"
#include "SDL2_gfxPrimitives.h"


// void draw(SDL_Renderer* renderer)
// {
//     /* Remplissez cette fonction pour faire l'affichage du jeu */
    
//     /* 
//     filledEllipseRGBA(
//         renderer, ... ?
//     ); */

   
// }

// bool handleEvent()
// {
//     /* Remplissez cette fonction pour gérer les inputs utilisateurs */
//     SDL_Event e; 
//     while (SDL_PollEvent(&e)){ 
//         if (e.type == SDL_QUIT) 
//             return false; 
//     }
//     return true;
// }


// int main(int argc, char** argv) {
//     SDL_Window* gWindow;
//     SDL_Renderer* renderer;
//     bool is_running = true; 

//     // Creation de la fenetre
//     gWindow = init("Awesome Game");

//     if (!gWindow)
//     {
//         SDL_Log("Failed to initialize!\n");
//         exit(1);
//     }

//     renderer = SDL_CreateRenderer(gWindow, -1, 0); // SDL_RENDERER_PRESENTVSYNC

//     /*  GAME LOOP  */
//     while(true)
//     {
//         // INPUTS
//         is_running = handleEvent();
//         if (!is_running)
//             break;

//         // GESTION ACTEURS

//         // ...
        
//         // EFFACAGE FRAME
//         SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//         SDL_RenderClear(renderer);
        
//         // DESSIN
//         //Ellipse ellipse(320, 240, 100, 50, 255, 0, 0, 1);
//         //ellipse.render(renderer);
//         // VALIDATION FRAME
//         SDL_RenderPresent(renderer);

//         // PAUSE en ms
//         SDL_Delay(1000/30); 
//     }

//     //Free resources and close SDL
//     close(gWindow, renderer);

//     return 0;
// }

int main(int argc, char* argv[]) {
    Game game;

    game.init("Ace's Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    while (game.running) {
        game.handleEvents();
        game.update();
        game.render();
    }

    game.clean();

    return 0;
}
