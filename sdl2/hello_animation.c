#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>

#define WINDOW_WIDTH (640)
#define WINDOW_HEIGHT (480)

#define SCROLL_SPEED (50)

int main(void) {
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) !=0 ) {
		printf("Error initing SDL: %s \n", SDL_GetError());
		return 1;
	}
	SDL_Window* win = SDL_CreateWindow("Hello, Mr. Soda!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
	if (!win) {
		printf("Error creating window: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
	if (!rend) {
		printf("Error creating renderer: %s\n", SDL_GetError());
		SDL_DestroyWindow(win);
		SDL_Quit();
		return 1;
	}

	SDL_Surface* surface = IMG_Load("../game/src/sprite.bmp");
	if (!surface) {
		printf("Error rendering image: %s\n", SDL_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return 1;
	}

	SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	if (!tex) {
		printf("Error mapping surface to texture: %s\n", SDL_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return 1;
	}

	SDL_Rect dest;
	SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);

	dest.x = (WINDOW_WIDTH - dest.w) / 2;
	float y_pos = WINDOW_HEIGHT;

	while (dest.y >= -dest.h) {
		SDL_RenderClear(rend);
		dest.y = (int) y_pos;
		SDL_RenderCopy(rend, tex, NULL, &dest);
		SDL_RenderPresent(rend);
		y_pos -= (float) SCROLL_SPEED / 60;
		SDL_Delay(1000/60);
	}

	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
	SDL_Quit();
}
