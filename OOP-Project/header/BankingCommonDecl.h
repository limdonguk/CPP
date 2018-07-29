#ifndef __BANKING_COMMON_DECL_H__
#define __BANKING_COMMON_DECL_H__

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;
const int NAME_LEN = 20;

enum
{
	LEVEL_A = 7,
	LEVEL_B = 4,
	LEVEL_C = 2
};

enum
{
	MAKE = 1,
	DEPOSIT,
	WITHDRAW,
	INQUIRE,
	EXIT
};

enum
{
	NORMAL = 1,
	CREDIT = 2
};

#endif