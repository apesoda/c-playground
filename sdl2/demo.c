#include <stdio.h>
#include "SDL.h"
#include "SDL_timer.h"
#include "SDL_image.h"

//4x the GBA's resolution
#define WINDOW_WIDTH (960)
#define WINDOW_HEIGHT (640)

//this just seemed like a nice speed
#define SPEED (200)

int main(void) {
	//init SDL, self explanatory
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0 ) {
		printf("Error initing SDL: %s \n", SDL_GetError());
		return 1;
	}
	//create a window that spawns in the center of the screen, automatically adopt the window width and height
	SDL_Window* win = SDL_CreateWindow("Dud", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
	if (!win) {
		printf("Error creating window: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	//create renderer with acceleration and vsync
	Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
	SDL_SetRenderDrawColor(rend, 180, 200, 200, 120);
	if (!rend) {
		printf("Error creating renderer: %s\n", SDL_GetError());
		SDL_DestroyWindow(win);
		SDL_Quit();
		return 1;
	}

	//load our main image file for our little guy
	SDL_Surface* surface = IMG_Load("assets/sprites/sprite_sheet.png");
	if (!surface) {
		printf("Error rendering image: %s\n", SDL_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return 1;
	}

	//map our little guy to a texture
	SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);
	if (!tex) {
		printf("Error mapping surface to texture: %s\n", SDL_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return 1;
	}

	//create a rectangle for our little guy to sit on

	SDL_Rect active;

	//front facing
	SDL_Rect srcFront;
	srcFront.x = 16;
	srcFront.y = 0;
	srcFront.h = 32;
	srcFront.w = 16;

	//back facing
	SDL_Rect srcBack;
	srcBack.x = 0;
	srcBack.y = 0;
	srcBack.h = 32;
	srcBack.w = 16;

	//left facing
	SDL_Rect srcLeft;
	srcLeft.x = 32;
	srcLeft.y = 0;
	srcLeft.h = 32;
	srcLeft.w = 16;

	
	//right facing
	SDL_Rect srcRight;
	srcRight.x = 48;
	srcRight.y = 0;
	srcRight.h = 32;
	srcRight.w = 16;

	SDL_Rect dest;
	dest.h = 32;
	dest.w = 16;

	//upscale 4x to fit with the theme
	dest.w *= 4;
	dest.h *= 4;

	//center our guy
	float x_pos = (WINDOW_WIDTH - dest.w) / 2;
	float y_pos = (WINDOW_HEIGHT - dest.h) / 2;
	float x_vel = 0;
	float y_vel = 0;

	//initialize state for movement
	int up = 0;
	int down = 0;
	int left = 0;
	int right = 0;
	
	//foundation so we can actually quit the program
	int close_requested = 0;

	active = srcFront;

	//input handling
	while (!close_requested) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT:
					close_requested = 1;
					break;
				//movement when key is pressed
				case SDL_KEYDOWN:
					switch (event.key.keysym.scancode) {
						case SDL_SCANCODE_W:
						case SDL_SCANCODE_UP:
							up = 1;
							active = srcBack;					
							break;
						case SDL_SCANCODE_A:
						case SDL_SCANCODE_LEFT:
							left = 1;
							active = srcLeft;					
							break;
						case SDL_SCANCODE_S:
						case SDL_SCANCODE_DOWN:
							down = 1;
							active = srcFront;					
							break;
						case SDL_SCANCODE_D:
						case SDL_SCANCODE_RIGHT:
							active = srcRight;					
							right = 1;
							break;
				}
				break;

				//stop moving upon releasing the buttons
				case SDL_KEYUP:
					switch (event.key.keysym.scancode) {
						case SDL_SCANCODE_W:
						case SDL_SCANCODE_UP:
							up = 0;
							break;
						case SDL_SCANCODE_A:
						case SDL_SCANCODE_LEFT:
							left = 0;
							break;
						case SDL_SCANCODE_S:
						case SDL_SCANCODE_DOWN:
							down = 0;
							break;
						case SDL_SCANCODE_D:
						case SDL_SCANCODE_RIGHT:
							right = 0;
							break;
				}
				break;
			}
		}
	
		//set movement speed
		x_vel = y_vel = 0;
		if (up && !down) y_vel = -SPEED;
		if (down && !up) y_vel = SPEED;
		if (left && !right) x_vel = -SPEED;
		if (right && !left) x_vel = SPEED;

		//diagonal movement
		if (up && left) y_vel = -SPEED / 1.4;
		if (left && up) x_vel = -SPEED / 1.4;

		if (up && right) y_vel = -SPEED / 1.4;
		if (right && up) x_vel = SPEED / 1.4;

		if (down && left) y_vel = SPEED / 1.4;
		if (left && down) x_vel = -SPEED / 1.4;

		if (down && right) y_vel = SPEED / 1.4;
		if (right && down) x_vel = SPEED / 1.4;

		x_pos += x_vel / 60;
		y_pos += y_vel / 60;

		if (x_pos <= 0) x_pos = 0;
		if (y_pos <= 0) y_pos = 0;
		if (x_pos >= WINDOW_WIDTH - dest.w) x_pos = WINDOW_WIDTH - dest.w;
		if (y_pos >= WINDOW_HEIGHT - dest.h) y_pos = WINDOW_HEIGHT - dest.h;

		dest.y = (int) y_pos;
		dest.x = (int) x_pos;

		//clear the screen
		SDL_RenderClear(rend);

		//draw again
		SDL_RenderCopy(rend, tex, &active, &dest);
		SDL_RenderPresent(rend);
		
		//wait 1 frame
		SDL_Delay(1000/60);
	}

	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
	SDL_Quit();
}
