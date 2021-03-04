#include "math_functions.h"


unsigned int sigma_1(unsigned int var)
{
	const unsigned int rtr_c = 13;
	const unsigned int rtl_c = 19;
	const unsigned int shr_c = 7;
	return rtr(var, rtr_c) ^ rtl(var, rtl_c) ^ shr(var, shr_c);
}


unsigned int sigma_2(unsigned int var)
{
	const unsigned int rtr_c = 17;
	const unsigned int rtl_c = 3;
	const unsigned int shl_c = 11;
	return rtr(var, rtr_c) ^ rtl(var, rtl_c) ^ shl(var, shl_c);
}


unsigned int sigma_3(unsigned int var)
{
	const unsigned int rtr1_c = 11;
	const unsigned int rtl_c = 29;
	const unsigned int rtr2_c = 13;
	return rtr(var, rtr1_c) ^ rtl(var, rtl_c) ^ rtr(var, rtr2_c);
}


unsigned int sigma_4(unsigned int var)
{
	const unsigned int rtr1_c = 5;
	const unsigned int rtl_c = 17;
	const unsigned int rtl2_c = 23;
	return rtr(var, rtr1_c) ^ rtl(var, rtl_c) ^ rtr(var, rtl2_c);
}
