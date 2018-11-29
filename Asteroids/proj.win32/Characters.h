#pragma once
#include "cocos2d.h"
using namespace cocos2d;

typedef struct _CharacterSize
{
	float width, height;
	float normalizedWidth, normalizedHeight;
}SpriteSize;

class Characters
{
public:
	Characters();
	virtual ~Characters();
	Characters(Vec2 position, std::string spritePath);
	void update(float deltaTime);//get delta time so we don't have to keep calling elapsed time per seconds
	void setCharacterFrameSize();//set the framesize of the character and also get the coordinates of the corners
	Sprite* getSprite();
	Vec2 getPosition();
	Vec2 position;
	Vec2 acceleration;
	Vec2 velocity;
	float theta;

	//void kill(float delay = 0.0f);
protected:
	Sprite* sprite;
private:

};
