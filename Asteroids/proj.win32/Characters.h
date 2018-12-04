#pragma once
#include "cocos2d.h"
#include "proj.win32/matrix.h"
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
	void load(Vec2 position, std::string spritePath);//basically the same thing as constructor above//makes it so that the constructor from characters can be called
	void update(float deltaTime);//get delta time so we don't have to keep calling elapsed time per seconds
	void setCharacterFrameSize();//set the framesize of the character and also get the coordinates of the corners
	Sprite* getSprite();
	Vec2 getPosition();
	void addForce(Vec2 force);
	Vec2 position;
	Vec2 acceleration;
	Vec2 velocity;
	float theta/*=0.0f*/;//gets the rotation(no duh)//Stephen put this in the protected 
	
protected: //we're using protected so that spaceship, projectiles, and asteroid can still access of the objects from character
	Sprite* sprite;
	mat4 rotation;
	float maxVelocity = 100.0f;
	float maxAcceleration = 1000.0f;
	float rotationSpeed = 100.0f;
private:

};