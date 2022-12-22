//
// Created by Jed Knauer on 22.12.22.
//

#ifndef WINDOW_SCREEN_H
#define WINDOW_SCREEN_H
#include <SDL.h>
#include <array>
#include <vector>
#include <cmath>
#include <iostream>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define SCREEN_BPP 32
#define FRAMES_PER_SECOND 60
#define MAX_SPEED 10
#define MAX_ACCELERATION 1
#define MAX_DECELERATION 1
#define ROTATION_SPEED 0.0314159265358979323846
#define SCALING_X 2.0
#define SCALING_Y 2.0
class Screen {
    SDL_Event e;
    SDL_Window *window;
    SDL_Renderer *renderer;
    std::vector<SDL_Point> points;
public:
    Screen();
    void pixel(int x, int y);
    void show();
    void input();
    void handleKeys();
    void handleInput();
    void clear();

    ~Screen() {
        SDL_DestroyRenderer(renderer);

    }
};


#endif //WINDOW_SCREEN_H
