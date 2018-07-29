#pragma warning(disable:4996)
#include "BankingCommonDecl.h"
#include "AccountArray.h"

BoundCheckAccountArray::BoundCheckAccountArray(int len): arrlen(len)
{
	arr = new ACCOUNT_PTR[len];
}
ACCOUNT_PTR& BoundCheckAccountArray::operator[](int idx)
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

ACCOUNT_PTR BoundCheckAccountArray::operator[](int idx) const
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}
int BoundCheckAccountArray::GetArrLen() const { return arrlen; }
BoundCheckAccountArray::~BoundCheckAccountArray() { delete[] arr; }