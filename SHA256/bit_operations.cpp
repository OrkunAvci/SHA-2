#include "bit_operations.h"

unsigned int shr(unsigned int var, unsigned int count)
{
	return (var >> count);
}

unsigned int shl(unsigned int var, unsigned int count)
{
	return (var << count);
}

unsigned int rtr(unsigned int var, unsigned int count)
{
	unsigned int control = 1;
	unsigned int addon = 1 << (sizeof(addon) * 8 - 1);
	for (unsigned int i = 0; i < count; i++, control = 1)
	{
		control = control & var;
		var = var >> 1;
		var += (control) ? addon : 0;
	}
	return var;
}

unsigned int rtl(unsigned int var, unsigned int count)
{
	unsigned int control = 1 << (sizeof(control) * 8 - 1);
	unsigned int addon = 1;
	for (unsigned int i = 0; i < count; i++, control = 1 << (sizeof(unsigned int) * 8 - 1))
	{
		control = control & var;
		var = var << 1;
		var += (control) ? addon : 0;
	}
	return var;
}

unsigned int add(unsigned int var1, unsigned int var2)	//	Full name is controlled_add(), a work around for overflow issues.
{
	unsigned int excess = (var1 & 1) + (var2 & 1);
	return excess + shl( shr(var1, 1) + shr(var2, 1), 1);
}


unsigned int maj(unsigned int var1, unsigned int var2, unsigned int var3)
{
	//	Majority bit value among three, for each bit.
	return (var1 & var2) | (var1 & var3) | (var2 & var3);
}

unsigned int cho(unsigned int var1, unsigned int var2, unsigned int var3)
{
	unsigned int output = 0;
	for (unsigned int filter = 1; filter != 0; filter = shl(filter, 1))
	{
		//	To determine which variable's bit will be chosen to copy over, use var1's bit.
		if ( (filter & var1) != 0 )
		{
			output = output ^ (filter & var3);
		}
		else
		{
			output = output ^ (filter & var2);
		}
	}
	return output;
}
