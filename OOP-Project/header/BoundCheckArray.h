#ifndef __ACCOUNT_ARRAY__
#define __ACCOUNT_ARRAY__

template <typename T>
class BoundCheckArray
{
private:
	T * arr;
	int arrlen;

	BoundCheckArray(const BoundCheckArray &arr) {}
	BoundCheckArray& operator=(const BoundCheckArray &arr) {}

public:
	template <typename T>
	BoundCheckArray(int len = 100) 
		: arrlen(len)
	{
		arr = new T[len];
	}

	template <typename T>
	T& operator[](int idx)
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}

	template <typename T>
	T operator[](int idx) const
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}

	template <typename T>
	int GetArrLen() const
	{
		return arrlen;
	}

	template <typename T>
	~BoundCheckArray()
	{
		delete[] arr;
	}
};

#endif