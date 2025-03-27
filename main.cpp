#include "main.h"

void closeApp()
{
  if (renderer)
  {
    SDL_DestroyRenderer(renderer);
  }
  if (window)
  {
    SDL_DestroyWindow(window);
  }
  SDL_Quit();
}

int main(int argc, char *argv[])
{
  if (!SDL_Init(SDL_INIT_VIDEO))
  {
    SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  // Create Window
  window = SDL_CreateWindow("template", SCREEN_WIDTH, SCREEN_HEIGHT, 0);
  if (!window)
  {
    cerr << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
    closeApp();
    return 1;
  }

  // Create Renderer
  renderer = SDL_CreateRenderer(window, NULL);
  if (!renderer)
  {
    cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << endl;
    closeApp();
    return 1;
  }

  SDL_Event evt;
  bool quit = false;

  while (!quit)
  {
    while (SDL_PollEvent(&evt))
    {
      if (evt.type == SDL_EVENT_QUIT)
      {
        quit = true;
      }
    }

    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
  }

  closeApp();

  return 0;
}