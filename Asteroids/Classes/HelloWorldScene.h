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

#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "proj.win32/inputHandler.h"
#include "proj.win32/Characters.h"
#include "proj.win32/SpaceShip.h"
#include "proj.win32/Projectiles.h"
#include "proj.win32/Asteroids.h"



class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
	void menuCloseCallback(Ref* pSender);
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
	//Put Init Functions here
	void initSprites();
	void initKeyboardListener();
	void initListeners();
	void initShip();
	
    //put Update functions here
	void update(float deltaTime);

    //Put Callbacks here?
	void keyDownCallback(EventKeyboard::KeyCode keycode, Event* event);
	void keyUpCallback(EventKeyboard::KeyCode keycode, Event* event);
	bool onContactBeginCallback(PhysicsContact& contact);

	//timerr *updateTimer;

private:
	//Engine
	Director* director;

	//Event listeners
	EventListenerKeyboard* keyboardListener;


	//sprites

	

	//Vectors of asteroids N Lazers
	std::vector<Characters*> Lazers;
	std::vector<Characters*> Ast;
	std::vector<Characters*> Enemy;

	
	SpaceShip*shipp;
	Characters *HUD;
	Characters *lazer;
	Characters *planet;
	Characters *ast;
	Characters *enemy;
	Characters *powerups;

	//bool for keyInput
	bool isUp;
	bool isDown;
	bool isLeft;
	bool isRight;
	bool isSpace;
};



#endif // __HELLOWORLD_SCENE_H__
