#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <SDL.h>

#define CHARACTER_COUNT 6

class Character;
extern Character* cha_List[CHARACTER_COUNT];

enum characterIDs
{
    Yeh = 0,
    David,
    Yang,
    Huang,
    Article,
    Li
};

class Character
{
public:
    Character(int ID, const char* skinpath, const char* bulletpath);
    const int chaID;
    const char* skin_path;
    const char* bullet_path;
};


#endif // CHARACTER_H
