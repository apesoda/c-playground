#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>

#define WINDOW_WIDTH (640)
#define WINDOW_HEIGHT (480)

#define SPEED (150)

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
	dest.w *= 4;
	dest.h *= 4;

	float x_pos = (WINDOW_WIDTH - dest.w) / 2;
	float y_pos = (WINDOW_HEIGHT - dest.h) / 2;
	float x_vel = SPEED;
	float y_vel = SPEED;


	int close_requested = 0;

	while (!close_requested) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				close_requested = 1;
			}
		}
	
		if (x_pos <= 0) {
			x_pos = 0;
			x_vel = -x_vel;
		}

		if (y_pos <= 0) {
			y_pos= 0;
			y_vel = -y_vel;
		}

		if (x_pos >= WINDOW_WIDTH - dest.w) {
			x_pos = WINDOW_WIDTH - dest.w;
			x_vel = -x_vel;
		}

		if (y_pos >= WINDOW_HEIGHT - dest.h) {
			y_pos = WINDOW_HEIGHT - dest.h;
			y_vel = -y_vel;
		}

		x_pos += x_vel / 60;
		y_pos += y_vel / 60;

		dest.y = (int) y_pos;
		dest.x = (int) x_pos;

		SDL_RenderClear(rend);
		SDL_RenderCopy(rend, tex, NULL, &dest);
		SDL_RenderPresent(rend);
		SDL_Delay(1000/60);
	}

	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
	SDL_Quit();
}
