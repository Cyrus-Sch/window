//
// Created by Jed Knauer on 22.12.22.
//

#include "Screen.h"


void Screen::pixel(int x, int y) {
    SDL_Point point = {x, y};
    points.push_back(point);
}

void Screen::show() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawPoints(renderer, points.data(), points.size());
    SDL_RenderPresent(renderer);
    points.clear();
}

void Screen::input() {
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            exit(0);
        }
    }
}

void Screen::handleKeys() {
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_W]) {
        std::cout << "W" << std::endl;
    }
    if (state[SDL_SCANCODE_A]) {
        std::cout << "A" << std::endl;
    }
    if (state[SDL_SCANCODE_S]) {
        std::cout << "S" << std::endl;
    }
    if (state[SDL_SCANCODE_D]) {
        std::cout << "D" << std::endl;
    }
    if (state[SDLK_UP]) {
        std::cout << "UP" << std::endl;
    }
    if (state[SDLK_DOWN]) {
        std::cout << "DOWN" << std::endl;
    }
    if (state[SDLK_LEFT]) {
        std::cout << "LEFT" << std::endl;
    }
    if (state[SDLK_RIGHT]) {
        std::cout << "RIGHT" << std::endl;
    }
}
void Screen::handleInput() {
    input();
    handleKeys();
}


