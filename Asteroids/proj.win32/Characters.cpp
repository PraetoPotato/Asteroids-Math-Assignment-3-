#include "Characters.h"
#include "2d/CCNode.h"

#include <algorithm>
#include <string>
#include <regex>



Characters::Characters() {}
Characters::Characters(Vec2 position, std::string texturePath)
{
	load(position,texturePath);

}

void Characters::load(Vec2 position, std::string spritePath)
{
	sprite = Sprite::create(spritePath); //Load the handle
	sprite->setPosition(position);
	sprite->setScale(0.10f); //Scale the bird since it loads in quite large 
	sprite->setAnchorPoint(Vec2(0.5, 0.5));//the point which the sprite rotates around

	auto body = PhysicsBody::createCircle((sprite->getSpriteFrame()->getRectInPixels().size.height) * 0.5f * 0.65f); //Use a circle since the bird is roughly circular
	//auto body = PhysicsBody::createCircle(32.0f); //Use a circle since the bird is roughly circular
	/*std::cout << sprite->getSpriteFrame()->getRectInPixels().size.height * sprite->getScale() * 0.5f << std::endl;*/
}

void Characters::update(float deltaTime)
{
	
	velocity += acceleration * deltaTime;
	position = sprite->getPosition();//in stephen's vid it's vec2 position= *(vec2*)&GetPosition();
	position += velocity * deltaTime;
	//recomputeCorners of sprite
	sprite->setPosition(position);
	acceleration = Vec2(0.0f,0.0f);//set acceleration to 0 so that force doesn't getting applied for the rest of the program// vec2(0.0f)
	
	

	//this can be expressed in a single a line but it isn't recommended
}
Sprite* Characters::getSprite() {
	return sprite;
}


Vec2 Characters::getPosition() {
	return sprite->getPosition();
}

void Characters::addForce(Vec2 force)
{
	acceleration += force;
}

void Characters::setCharacterFrameSize()
{

}

Characters::~Characters()
{
	//delete sprite;
	sprite = NULL;
}