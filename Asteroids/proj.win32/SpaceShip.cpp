#include "SpaceShip.h"
#include "proj.win32/tags.h"

SpaceShip::SpaceShip(Vec2 position, std::string spritePath)
{
	load(position,spritePath);
	//sprite->getPhysicsBody()->setDynamic(false);//this means it isn't affected by gravity I think
	//sprite->getPhysicsBody()->setTag(tags::ship);

}