#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include <string>
#include "LTexture.h"
#include "LButton.h"
LButton::LButton(int w, int h)
{
    mPosition.x = 0;
    mPosition.y = 0;
    work = 0;
    mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
    BUTTON_WIDTH = w;
    BUTTON_HEIGHT = h;
}

void LButton::setPosition(int x, int y)
{
    mPosition.x = x;
    mPosition.y = y;
}

void LButton::handleEvent(SDL_Event& e)
{
    if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
    {
        if (work)
        {
            int x, y;
            SDL_GetMouseState(&x, &y);

            bool inside = true;

            if (x < mPosition.x)
            {
                inside = false;
            }
            else if (x > mPosition.x + BUTTON_WIDTH)
            {
                inside = false;
            }
            else if (y < mPosition.y)
            {
                inside = false;
            }
            else if (y > mPosition.y + BUTTON_HEIGHT)
            {
                inside = false;
            }
            if (!inside)
            {
                mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
            }
            else
            {
                switch (e.type)
                {
                case SDL_MOUSEMOTION:
                    mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
                    break;

                case SDL_MOUSEBUTTONUP:
                    mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
                    break;
                }
            }
        }
    }
}

