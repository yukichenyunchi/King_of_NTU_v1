#include "Player.h"

Player::Player(Uint8 pl_index, Uint8 characterID)
    :cur_health(1000), ID(characterID), P_pl_speed(1), P_squat_speed(1), P_jump_velocity(1), P_full_health(1000)
{
    if (pl_index == 0) {
        player_direction == dir_right;
    }
    else { player_direction == dir_left; }

    SDL_Rect skin_clips[PLAYER_CLIP_NUM + DEATH_CLIP_NUM];
    //LTexture& skinSprite;

}
void Player::reset() {}
int Player::getID() { return ID; }
bool you_failed;
bool death_start;
int Player::get_full_health() { return P_full_health; }
int Player::get_cur_health() { return cur_health; }
int Player::get_pl_dir() { return player_direction; }
void Player::set_pl_dir(int direction) { player_direction = direction; }
double Player::get_jump_v() { return P_jump_velocity; }

void Player::fire() {}

Uint8 keyBoardState[KEYBOARD_BUTTON_COUNT];

SDL_RendererFlip pl_flip;

void Player::render() {
	gplayer1.loadTexture("img/yeh.png");
	////Set rendering space and render to screen
	//SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	////Set clip rendering dimensions
	//if (clip != nullptr)
	//{
	//	renderQuad.w = clip->w;
	//	renderQuad.h = clip->h;
	//}
	////Render to screen
	//gRenderer.copy(mTexture, clip, &renderQuad);
}
void Player::updatePosition() {}
void Player::checkCollision(Player& opponent) {}
