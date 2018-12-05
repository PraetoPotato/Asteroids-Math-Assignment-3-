/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "proj.win32/Characters.h"
#include <iostream>


//float theta;


  

USING_NS_CC;


Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
	//Ensure the parent init function was called first. If it wasn't, exit this one
    if ( !Scene::init() )
    {
        return false;
    }

	//Get the director from cocos so we can use it when needed
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

	//Init the event handlers
	initListeners();
	initSprites();

	//Allow for the update() function to be called by cocos
	this->scheduleUpdate();

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("background.png");
    if (sprite == nullptr)
    {
        problemLoading("'background.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }
    return true;
}
void HelloWorld::initSprites()
{
	shipp= new SpaceShip({ 100,100 }, "Asteroids/Ship/Space_Ship.png");

	this->addChild(shipp->getSprite(), 2);



	HUD= new Characters({ 20,275 }, "Asteroids/HUD/hud.png");


	this->addChild(HUD->getSprite(), 2);

	HUD = new Characters({ 50,275 }, "Asteroids/HUD/life.png");


	this->addChild(HUD->getSprite(), 2);

	HUD = new Characters({ 75,275 }, "Asteroids/HUD/life.png");


	this->addChild(HUD->getSprite(), 2);

	HUD = new Characters({ 100,275 }, "Asteroids/HUD/life.png");


	this->addChild(HUD->getSprite(), 2);


	HUD = new Characters({ 200,275 }, "Asteroids/HUD/score.png");


	this->addChild(HUD->getSprite(), 2);

	
	ast = new Characters({ 200,100 }, "Asteroids/ast/ast.png");


	this->addChild(ast->getSprite(), 2);

	ast = new Characters({ 200,130}, "Asteroids/ast/ast.png");


	this->addChild(ast->getSprite(), 2);




	planet = new Characters({ 300,200 }, "Asteroids/onscreen/planet.png");


	this->addChild(planet->getSprite(), 2);

	planet = new Characters({ 400,200 }, "Asteroids/onscreen/bh.png");


	this->addChild(planet->getSprite(), 2);

	enemy = new Characters({ 400,150 }, "Asteroids/enemy ship/enemy1.png");


	this->addChild(enemy->getSprite(), 2);

	

	enemy = new Characters({ 400,130 }, "Asteroids/enemy ship/enemy2.png");


	this->addChild(enemy->getSprite(), 2);

	//addChild-This is basically like the addToSpriteToDrawList in the previous math assignment parameters are the sprite and the layer number
}



void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}



void HelloWorld::initListeners()
{
	//Init the keyboard listener
	initKeyboardListener();

}

void HelloWorld::initKeyboardListener()
{
	//Create the keyboard listener
	keyboardListener = EventListenerKeyboard::create();

	//Setting up callbacks
	keyboardListener->onKeyPressed = CC_CALLBACK_2(HelloWorld::keyDownCallback, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(HelloWorld::keyUpCallback, this);

	//Add the keyboard listener to the dispatcher
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);
}


//Main update loop
void HelloWorld::update(float deltaTime)
{
	//velocity += acceleration * deltaTime;
	//position = ship->getPosition();
	//position += velocity * deltaTime;
	//ship->setPosition(position);

	ast->velocity += Vec2(-0.01, 0.01);
	

	if (isUp == true)
	{
		shipp->velocity += Vec2(0,100)*deltaTime;
		
		
		//ship->setPosition(position);
	}

	if (isDown == true)
	{
		shipp->velocity += Vec2(0,-100)*deltaTime;
		
		/*ship->setPosition(position);*/
	}

	if (isSpace == true)
	{
		
		lazer = new Characters(shipp->getPosition(), "Asteroids/Projectiles/lazer.png");
		lazer->velocity += Vec2(0, 500);
		Lazers.push_back(lazer);
		this->addChild(lazer->getSprite(), 1);
		///*ship->setPosition(position);*/
	}
	for (int i = 0;i < Lazers.size();i++)
	{
		Lazers[i]->update(deltaTime);
	}
	/*lazer->update(deltaTime);*/
	

	if (isLeft == true)
	{
		shipp->theta -= 1 * deltaTime;
		shipp->getSprite()->setRotation((shipp->getSprite()->getRotation()) + shipp->theta);
		//shipp->velocity += Vec2(-2, 0);
		
		
		//ship->setPosition(position);
		//testSprite->theta += 250 * dt;
	}

	if (isRight == true)
	{
		/*shipp->velocity += Vec2(1, 0);*/
		shipp->theta += 1 * deltaTime;
		shipp->getSprite()->setRotation((shipp->getSprite()->getRotation())+shipp->theta);
		/*ship->setPosition(position);*/
	}

	shipp->update(deltaTime);
	ast->update(deltaTime);
	ast->update(deltaTime);
}
void HelloWorld::keyDownCallback(EventKeyboard::KeyCode keyCode, Event* event)//keydown
{
	//float dt = updateTimer->getElapsedTimeSeconds();
	if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)
	{
		/*Vec2 pos(0, 10);*/
		isUp = true;
		
		
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
	{
		/*Vec2 pos(0, -10);*/
		isDown = true;

	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		isLeft = true;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		isRight = true;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_SPACE)
	{
		isSpace = true;
	}
}

void HelloWorld::keyUpCallback(EventKeyboard::KeyCode keyCode, Event* event)//key up(releasing key)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)
	{
		/*Vec2 pos(0, 10);*/
		isUp = false;


	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
	{
		/*Vec2 pos(0, -10);*/
		isDown = false;

	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)

	{
		//Vec2 pos(-10,0);
		//ship->setPosition(ship->getPosition() + (pos));

		isLeft = false;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		//Vec2 pos(10, 0);
		//ship->setPosition(ship->getPosition() + (pos));
		isRight = false;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_SPACE)
	{
		isSpace = false;
		//Vec2 pos(10, 0);
		//ship->setPosition(ship->getPosition() + (pos));
	}
}

