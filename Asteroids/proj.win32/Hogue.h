#pragma once

#include "cocos2d.h"
#include "Characters.h"

using namespace cocos2d;

class Hogue : public Characters//class spaceship is gonna inherit from characters class
{
public:
	Hogue() = default;
	Hogue(Vec2 position, std::string texturePath);
	
private:

};
