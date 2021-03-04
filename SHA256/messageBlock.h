#pragma once
#ifndef __MESSAGE_BLOCK_H__
#define __MESSAGE_BLOCK_H__

#include <iostream>
#include <string>

#include "math_functions.h"

class MessageBlock
{
private:
	unsigned int marker;
	unsigned int data[16];
	MessageBlock* next;

public:
	MessageBlock(std::string);
	MessageBlock(std::string, unsigned int, unsigned int);
	~MessageBlock();

	void addNext(MessageBlock*);
	MessageBlock* getNext();

	unsigned int* processBlock();
};

#endif // !__MESSAGE_BLOCK_H__
