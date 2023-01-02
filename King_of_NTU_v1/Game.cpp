#include "Game.h"
#include <iostream>
using namespace std;

Game:: Game()
	:success(1)
{}
Game::~Game()
{
}

void Game::getIDfromUser()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_1) {
					success = 0;
				}
				break;
			default:
				break;
		}
	}
}
	

//void Game::getIDfromUser() 
//{
//	//bool successinput = 1;
//	SDL_Event event;
//	while (SDL_PollEvent(&event)) {
//		switch (event.type) {
//			case SDL_KEYDOWN:
//				if (event.key.keysym.sym == SDLK_1) {
//					//players[i] = new Player(i, 0);
//					//cout << "1" << endl;
//					//successinput = 0;
//				}
//					
//				if (event.key.keysym.sym == SDLK_2) {
//					//players[i] = new Player(i, 1);
//					//cout << "2" << endl;
//					//successinput = 0;
//				}
//					
//				if (event.key.keysym.sym == SDLK_3) {
//					//players[i] = new Player(i, 2);
//					//cout << "3" << endl;
//					//successinput = 0;
//				}
//					
//				if (event.key.keysym.sym == SDLK_4) {
//					//players[i] = new Player(i, 3);
//					//cout << "4" << endl;
//					//successinput = 0;
//				}
//					
//				if (event.key.keysym.sym == SDLK_5) {
//					//players[i] = new Player(i, 4);
//					//cout << "5" << endl;
//					//successinput = 0;
//				}
//					
//				if (event.key.keysym.sym == SDLK_6) {
//					//players[i] = new Player(i, 5);
//					//cout << "6" << endl;
//					//successinput = 0;
//				}
//				break;
//			default:
//				break;
//		}
//	}
//}

//void Game::renderAll()
//{
//	players[0]->render();
//	players[1]->render();
//
//}