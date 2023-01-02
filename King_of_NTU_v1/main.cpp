#include <SDL.h>
#include <stdio.h>
#include "LWindow.h"
#include "LTexture.h"
#include "LButton.h"
#include "Character.h"
#include "Game.h"
#include <iostream>
using namespace std;

enum scenario {
    starting = 0,
    ruleintro = 1,
    playing = 2,
    choosechar = 3,
    gameover = 4,
};

SDL_Renderer* gRenderer = NULL;
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
LWindow gWindow;
LTexture test;
LTexture gSceneTexture;
//not sure
//LTexture gplayer1;
//
LTexture StartTexture;
LTexture RuleTexture;
LTexture BackTexture;
LButton Rule(402, 151);
LButton Start(402, 151);
LButton Back(198, 113);
bool ruleon, starton, backon;
Character* cha_List[CHARACTER_COUNT];
bool havechosen = 1;
Game game; 

bool init()
{
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            printf("Warning: Linear texture filtering not enabled!");
        }
        if (!gWindow.init())
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            gRenderer = gWindow.createRenderer();
            if (gRenderer == NULL)
            {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
            else
            {
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags)) 
                {
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                    success = false;
                }
                //initilize character list
                cha_List[Yeh] = new Character(Yeh,
                    "img/yeh.png",
                    "img/b_yeh.png");

                cha_List[David] = new Character(David,
                    "img/david.png",
                    "img/b_david.png");

                cha_List[Huang] = new Character(Huang,
                    "img/huang.png",
                    "img/b_huang.png");

                cha_List[Yang] = new Character(Yang,
                    "img/yang.png",
                    "img/b_yang.png");

                cha_List[Article] = new Character(Article,
                    "img/article.png",
                    "img/b_article.png");

                cha_List[Li] = new Character(Li,
                    "img/li.png",
                    "img/b_li.png");
            }
        }
    }
    return success;
}

bool loadMedia()
{
    bool success = true;
    if (!test.loadFromFile("img/welcomepage.png"))
    {
        printf("Failed to load window texture!\n");
        success = false;
    }
    test.free();
    return success;
}

void putMedia(scenario s)
{
    switch (s)
    {
    case starting:
        gSceneTexture.free();
        BackTexture.free();
        gSceneTexture.loadTexture("img/welcomepage.png");
        if (!starton) StartTexture.loadFromFile("img/startbtn.png");
        else StartTexture.loadTexture2("img/startbtn.png", 401, 151); //loadTexture2 is for btn, 1 is for window
        if (!ruleon) RuleTexture.loadFromFile("img/rulebtn.png");
        else RuleTexture.loadTexture2("img/rulebtn.png", 401, 151);
        gSceneTexture.render((gWindow.getWidth() - gSceneTexture.getWidth()) / 2, (gWindow.getHeight() - gSceneTexture.getHeight()) / 2);
        StartTexture.render(gWindow.getWidth() * 11 / 20, gWindow.getHeight() * 3 / 5, NULL, 0, NULL, SDL_FLIP_NONE);
        RuleTexture.render(gWindow.getWidth() * 6 / 20, gWindow.getHeight() * 3 / 5, NULL, 0, NULL, SDL_FLIP_NONE);
        Start.work = 1;
        Rule.work = 1;
        Back.work = 0;
        Back.mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
        break;
    case ruleintro:
        gSceneTexture.free();
        StartTexture.free();
        RuleTexture.free();
        gSceneTexture.loadTexture("img/rulepage.png");
        if (!backon) BackTexture.loadFromFile("img/backbtn.png");
        else BackTexture.loadTexture2("img/backbtn.png", 281, 95);
        gSceneTexture.render((gWindow.getWidth() - gSceneTexture.getWidth()) / 2, (gWindow.getHeight() - gSceneTexture.getHeight()) / 2);
        BackTexture.render(gWindow.getWidth() * 18 / 40, gWindow.getHeight() * 8 / 10);
        Start.work = 0;
        Start.mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
        Rule.work = 0;
        Rule.mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
        Back.work = 1;
        break;
    case choosechar:
        gSceneTexture.free();
        StartTexture.free();
        RuleTexture.free();
        BackTexture.free();
        gSceneTexture.loadTexture("img/choosecharpage.png");
        gSceneTexture.render((gWindow.getWidth() - gSceneTexture.getWidth()) / 2, (gWindow.getHeight() - gSceneTexture.getHeight()) / 2);
        Start.work = 0;
        Start.mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
        Rule.work = 0;
        Rule.mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
        Back.work = 0;
        Back.mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
        break;
    case playing:
        gSceneTexture.free();
        gSceneTexture.loadTexture("img/fightpage.png");
        gSceneTexture.render((gWindow.getWidth() - gSceneTexture.getWidth()) / 2, (gWindow.getHeight() - gSceneTexture.getHeight()) / 2);
        break;

    /*case gameover:
        break;*/
    }
}

void close()
{
    for (int i = 0; i < 6; i++)
        delete cha_List[i];
    gSceneTexture.free();
    StartTexture.free();
    RuleTexture.free();
    SDL_DestroyRenderer(gRenderer);
    gWindow.free();
    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char* args[]) {
    scenario s = starting;

    if (!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        if (!loadMedia())
        {
            printf("Failed to load media!\n");
        }
        else
        {
            bool quit = false;
            SDL_Event e;
            while (!quit)
            {
                while (SDL_PollEvent(&e) != 0)
                {
                    if (e.type == SDL_QUIT)
                    {
                        quit = true;
                    }
                    gWindow.handleEvent(e);
                    Start.handleEvent(e);
                    Rule.handleEvent(e);
                    Back.handleEvent(e);
                }
                SDL_RenderClear(gRenderer);
                Start.setPosition(gWindow.getWidth() * 11 / 20, gWindow.getHeight() * 3 / 5);
                Rule.setPosition(gWindow.getWidth() * 6 / 20, gWindow.getHeight() * 3 / 5);
                Back.setPosition(gWindow.getWidth() * 18 / 40, gWindow.getHeight() * 8 / 10);
                //continuously update gRender (may lead to player update questions?)
                putMedia(s);
                SDL_RenderPresent(gRenderer);
                //rule
                if (Rule.mCurrentSprite == BUTTON_SPRITE_MOUSE_UP)
                {
                    s = ruleintro;
                }
                if (Rule.mCurrentSprite == BUTTON_SPRITE_MOUSE_OVER_MOTION)
                {
                    ruleon = true;
                }
                else
                {
                    ruleon = false;
                }
                //start
                if (Start.mCurrentSprite == BUTTON_SPRITE_MOUSE_OVER_MOTION)
                {
                    starton = true;
                }
                else
                {
                    starton = false;
                }
                //back
                if (Back.mCurrentSprite == BUTTON_SPRITE_MOUSE_OVER_MOTION)
                {
                    backon = true;
                }
                else
                {
                    backon = false;
                }
                if (Back.mCurrentSprite == BUTTON_SPRITE_MOUSE_UP)
                {
                    s = starting;
                }
                //press start to choosechar
                if (Start.mCurrentSprite == BUTTON_SPRITE_MOUSE_UP)
                {
                    s = choosechar;
                }
            }
        }
    }
    close();
	return 0;
}