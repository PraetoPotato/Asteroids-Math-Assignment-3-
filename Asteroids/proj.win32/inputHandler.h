#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include<cocos2d.h>

using namespace cocos2d;

enum InputState//enum is a data type full of integral constants
{
	Idle,
	Pressed,
	Released,
	Held
};

#define NUM_KEY_CODES (int)cocos2d::EventKeyboard::KeyCode::KEY_PLAY + 1
typedef cocos2d::EventKeyboard::KeyCode KeyCode;

class InputHandler
{
protected:
	//Constructor
	InputHandler(); 

public:
	//Destructor
	~InputHandler();

	//Keyboard
	bool getKeyPress(KeyCode key) const;
	bool getKeyRelease(KeyCode key) const;
	bool getKey(KeyCode key) const;

	void initInputs();
	void updateInputs();

	static InputHandler* getInstance();
private:
	InputState keyboardStates[NUM_KEY_CODES];

	static InputHandler* inst;
};
#define INPUTS InputHandler::getInstance()
#endif

