#pragma once
#include "cocos2d.h"
#include "Characters.h"

using namespace cocos2d;

class SpaceShip : public Characters//class spaceship is gonna inherit from characters class
{
public:
	SpaceShip()=default;
	SpaceShip(Vec2 position, std::string texturePath);

	int shield = 4;
	int lives = 3;
	float speedMultiplier = 100.0f;//determines how fast the ship is moving 
private:
	
};