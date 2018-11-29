#include "Characters.h"
#include "2d/CCNode.h"

#include <algorithm>
#include <string>
#include <regex>



Characters::Characters() {}
Characters::Characters(Vec2 position, std::string texturePath)
{
	sprite = Sprite::create(texturePath); //Load the handle
	sprite->setPosition(position);
	sprite->setScale(0.10f); //Scale the bird since it loads in quite large 
	sprite->setAnchorPoint(Vec2(0.5, 0.5));//the point which the sprite rotates around

	auto body = PhysicsBody::createCircle((sprite->getSpriteFrame()->getRectInPixels().size.height) * 0.5f * 0.65f); //Use a circle since the bird is roughly circular
	//auto body = PhysicsBody::createCircle(32.0f); //Use a circle since the bird is roughly circular
	/*std::cout << sprite->getSpriteFrame()->getRectInPixels().size.height * sprite->getScale() * 0.5f << std::endl;*/
	
;
}

void Characters::update(float deltaTime)
{
	
	velocity += acceleration * deltaTime;
	position = sprite->getPosition();
	position += velocity * deltaTime;
	//recomputeCorners of sprite
	sprite->setPosition(position);

	
	

	//this can be expressed in a single a line but it isn't recommended
}
Sprite* Characters::getSprite() {
	return sprite;
}


Vec2 Characters::getPosition() {
	return sprite->getPosition();
}

void Characters::setCharacterFrameSize()
{

}

Characters::~Characters()
{
	//delete sprite;
	sprite = NULL;
}