// #define GLAD_GL_IMPLEMENTATION
// #include <glad/glad.h>
// #include <GLFW/glfw3.h>

#include <SDL.h>
#include <iostream>

using namespace std;

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 768;

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

void closeApp();