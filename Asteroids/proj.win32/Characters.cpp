#include "Characters.h"
#include <iostream>
Characters::Characters() {}
Characters::Characters(Vec2 position, std::string texturePath)
{
	sprite = Sprite::create(texturePath); //Load the handle
	sprite->setPosition(position);
	sprite->setScale(0.25f); //Scale the bird since it loads in quite large 
	sprite->setAnchorPoint(Vec2(0.5f, 0.5f)); //Ensure the middle of the bird is the anchor point
	auto body = PhysicsBody::createCircle((sprite->getSpriteFrame()->getRectInPixels().size.height) * 0.5f * 0.65f); //Use a circle since the bird is roughly circular
	//auto body = PhysicsBody::createCircle(32.0f); //Use a circle since the bird is roughly circular
	std::cout << sprite->getSpriteFrame()->getRectInPixels().size.height * sprite->getScale() * 0.5f << std::endl;
	body->setContactTestBitmask(0xFFFFFFFF);
	sprite->setPhysicsBody(body); //Connect the physics body and the sprite
}

void Characters::update(float deltaTime)
{
	velocity += acceleration * deltaTime;
	position = sprite->getPosition();
	position += velocity * deltaTime;
	sprite->setPosition(position);
	//this can be expressed in a single a line but it isn't recommended
}
Sprite* Characters::getSprite() {
	return sprite;
}

PhysicsBody* Characters::getBody() {
	return sprite->getPhysicsBody();
}

Vec2 Characters::getPosition() {
	return sprite->getPosition();
}

Characters::~Characters()
{
	//delete sprite;
	sprite = NULL;
}