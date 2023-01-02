#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <SDL.h>
#include "Character.h"
#include "LTexture.h"

#define PLAYER_CLIP_NUM 8
#define DEATH_CLIP_NUM 2
#define KEYBOARD_BUTTON_COUNT 4

enum keyBoardButtons
{
    key_up = 0,
    key_left,
    key_right,
    key_fire,
};
enum direction
{
    dir_none = 0,
    dir_left,
    dir_right
};

//not sure
extern LTexture gplayer1;
//

class Player{
public:
	Player(Uint8 pl_index, Uint8 characterID);
	void reset();
    int getID() { return ID; }
    bool you_failed;
    bool death_start;
    int get_full_health() { return P_full_health; }
    int get_cur_health() { return cur_health; }
    int get_pl_dir() { return player_direction; }
    void set_pl_dir(int direction) { player_direction = direction; }
    double get_jump_v() { return P_jump_velocity; }

    void fire();


    Uint8 keyBoardState[KEYBOARD_BUTTON_COUNT];

    SDL_RendererFlip pl_flip;

    void render();
    void updatePosition();
    void checkCollision(Player& opponent);

private:
    //locationx, locationy ?
    int cur_health;
    int player_direction;

    const int  ID;
    const double P_pl_speed;
    const double P_squat_speed;
    const double P_jump_velocity;
    const int P_full_health;

    SDL_Rect skin_clips[PLAYER_CLIP_NUM + DEATH_CLIP_NUM];
    //LTexture& skinSprite;

}
#endif
