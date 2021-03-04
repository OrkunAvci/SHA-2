#include <iostream>
#include <string>
#include <sstream>

#include "bit_operations.h"
#include "math_functions.h"
#include "constants.h"
#include "messageBlock.h"

using namespace std;

void conmpression(unsigned int* output, unsigned int* word_schedule, unsigned int* constants)
{
	//	Save the current state:
	unsigned int prev_state[8];
	for (unsigned int i = 0; i < 8; i++)	{	prev_state[i] = output[i];	}

	unsigned int intermediate1, intermediate2;
	for (unsigned int i = 0; i < 64;i++)
	{
		//	intermediate1:
		intermediate1 = add( sigma_1( output[4] ), cho( output[4], output[5], output[6] ) );
		intermediate1 += add( word_schedule[i], constants[i] );

		//	intermediate2:
		intermediate2 = add( sigma_2( output[0] ), maj( output[0], output[1], output[2] ) );

		//	Shift the output array:
		for (unsigned int j = 7; j > 0; j--)	{	output[j - 1] = output[j];		}

		//	Insert intermediates:
		output[0] = add(intermediate1, intermediate2);
		output[4] = add(output[4], intermediate1);
	}

	//	Add the previous state's values to the output:
	for (unsigned int i = 0; i < 8; i++)	{	output[i] = add( output[i], prev_state[i] );	}

	//	Destroy used up schedule:
	delete [] word_schedule;
}

int main()
{
	//	Input string:
	string input_str;
	cout << "Enter input: ";
	getline(cin, input_str);

	//	Input string into blocks:
	string sub_str = "";
	MessageBlock* blocks = new MessageBlock(sub_str);
	for (unsigned int i = 0; i < input_str.size() / 64; i++)
	{
		sub_str = input_str.substr(i * 64, (i + 1) * 64);
		blocks->addNext( new MessageBlock(sub_str) );
	}
	sub_str = input_str.substr( (input_str.size() / 64) * 64, input_str.size() );
	blocks->addNext( new MessageBlock(sub_str, input_str.size() / UINT32_MAX, input_str.size() % UINT32_MAX) );

	//	Hash every block:
	MessageBlock* next;
	unsigned int* hash_out = new unsigned int[8];
	initial_hash(hash_out);
	unsigned int* constants = new unsigned int[64];
	get_constants(constants);
	while (blocks != nullptr)
	{
		next = blocks->getNext();
		conmpression(hash_out, blocks->processBlock(), constants);
		delete blocks;
		blocks = next;
	}

	//	Output:
	cout << endl << "Output= ";
	stringstream str_stream;
	for (unsigned int i = 0; i < 8;i++)
	{
		str_stream << hex << hash_out[i];
	}
	cout << str_stream.str() << endl << endl;

	
	delete [] constants;
	delete [] hash_out;
	system("pause");
	return 0;
}
