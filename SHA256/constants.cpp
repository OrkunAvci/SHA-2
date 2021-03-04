#include "constants.h"

void get_constants(unsigned int* output)
{
	unsigned int primes[] =
						{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
						31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
						73, 79, 83, 89, 97, 101, 103, 107, 109, 113,
						127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
						179, 181, 191, 193, 197, 199, 211, 223, 227, 229,
						233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
						283, 293, 307, 311 };		//	64 in total.

	
	double helper;
	double dump;
	for (unsigned int i = 0; i < 64; i++)
	{
		helper = (double)primes[i];
		helper = cbrt(helper);
		dump = 1.0;
		helper = modf(helper, &dump);
		helper = helper * 1000000000;	//	helper * pow(10,9)
		output[i] = (int) helper;
	}

}

void initial_hash(unsigned int* output)
{
	unsigned int primes[] =	{ 2, 3, 5, 7, 11, 13, 17, 19 };		//	8 in total.

	double helper;
	double dump;
	for (unsigned int i = 0; i < 8; i++)
	{
		helper = (double)primes[i];
		helper = sqrt(helper);
		dump = 1.0;
		helper = modf(helper, &dump);
		helper = helper * 1000000000;	//	helper * pow(10,9)
		output[i] = (int)helper;
	}
}
