#pragma once
#include "cocos2d.h"
using namespace cocos2d;

class Characters
{
public:
	Characters();
	virtual ~Characters();
	Characters(Vec2 position, std::string spritePath);
	void update(float deltaTime);//get delta time so we don't have to keep calling elapsed time per seconds
	Sprite* getSprite();
	Vec2 getPosition();
	Vec2 position;
	Vec2 acceleration;
	Vec2 velocity;
	//void kill(float delay = 0.0f);
protected:
	Sprite* sprite;

};
