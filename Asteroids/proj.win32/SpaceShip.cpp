#include "SpaceShip.h"
#include "proj.win32/tags.h"

SpaceShip::SpaceShip(Vec2 position) : Characters(position, "Asteroids/Ship/Space_Ship.png")
{
	
	sprite->getPhysicsBody()->setDynamic(false);//this means it isn't affected by gravity I think
	sprite->getPhysicsBody()->setTag(tags::ship);

}