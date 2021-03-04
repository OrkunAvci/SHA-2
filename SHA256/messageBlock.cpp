#include "messageBlock.h"

MessageBlock::MessageBlock(std::string str)
{
	for (unsigned int i = 0; i < str.size(); i++)
	{
		data[i / 4] += str[i];
		data[i / 4] = data[i / 4] << (sizeof(char) * 8);
	}
	next = nullptr;
}

MessageBlock::MessageBlock(std::string str, unsigned int d14, unsigned int d15) : MessageBlock(str)
{
	//	These are the size(s) of the entire message.
	data[14] = d14;
	data[15] = d15;
}

MessageBlock::~MessageBlock()
{
	return;
}

void MessageBlock::addNext(MessageBlock* next)
{
	if (this->next == nullptr)	{	this->next = next;	}
	else						{	next->addNext(next);	}
}

MessageBlock* MessageBlock::getNext()
{
	return this->next;
}

unsigned int* MessageBlock::processBlock()
{
	unsigned int* words = new unsigned int[64];
	for (unsigned int i = 0; i < 16; i++)
	{
		words[i] = data[i];
	}

	for (unsigned int i = 16; i < 64; i++)
	{
		words[i] = add( add( sigma_1( words[i - 16] ), sigma_2( words[i - 2] ) ), add( sigma_3( words[i - 13] ), sigma_4( words[i - 7] ) ) );
	}

	return words;
}
