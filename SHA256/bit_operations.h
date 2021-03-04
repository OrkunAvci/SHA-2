#pragma once
#ifndef __BIT_OPERATIONS_H__
#define __BIT_OPERATIONS_H__

/*
	These are operations on bits, not necessarily a manipulation of bits.
	Never destroys the original.
*/


unsigned int shr(unsigned int, unsigned int);


unsigned int shl(unsigned int, unsigned int);


unsigned int rtr(unsigned int, unsigned int);


unsigned int rtl(unsigned int, unsigned int);


unsigned int add(unsigned int, unsigned int);


unsigned int maj(unsigned int, unsigned int, unsigned int);


unsigned int cho(unsigned int, unsigned int, unsigned int);

#endif // !__BIT_OPERATIONS_H__
