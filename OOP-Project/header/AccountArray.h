#ifndef __ACCOUNT_ARRAY__
#define __ACCOUNT_ARRAY__

#include "Account.h"
typedef Account* ACCOUNT_PTR;

class BoundCheckAccountArray
{
private:
	ACCOUNT_PTR *arr;
	int arrlen;

	BoundCheckAccountArray(const BoundCheckAccountArray &arr) {}
	BoundCheckAccountArray& operator=(const BoundCheckAccountArray &arr) {}

public:
	BoundCheckAccountArray(int len = 100);
	ACCOUNT_PTR& operator[](int idx);
	ACCOUNT_PTR operator[](int idx) const;
	int GetArrLen() const;
	~BoundCheckAccountArray();
};

#endif