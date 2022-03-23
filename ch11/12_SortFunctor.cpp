#include<iostream>
using namespace std;

class SortRule
{
public:
	virtual bool operator()(int num1, int num2) const = 0;
};

class AscendingSort :public SortRule
{
public:
	bool operator()(int num1, int num2) const
	{
		if (num1 > num2)
			return true;
		else
			return false;
	}
};

class DescendingSort :public SortRule
{
public:
	bool operator()(int num1, int num2) const
	{
		if (num1 < num2)
			return true;
		else
			return false;
	}
};

class DataStorage
{

	int* arr;
	int idx;
	const int MAX_LEN;
public:
	DataStorage(int arrlen) :idx(0), MAX_LEN(arrlen)
	{
		arr = new int[MAX_LEN];
	}
	void AddData(int num)
	{
		if (MAX_LEN <= idx)
		{
			cout << "저장공간초가" << endl;
			return;
		}
		arr[idx++] = num;
	}

	void ShowAllData()
	{
		for (int i = 0; i < idx; i++)
		{
			cout << arr[i] << endl;
		}
		cout << endl;
	}

	void SortData(const SortRule& functor)
	{
		for (int i = 0; i < idx; i++)
		{
			for (int j = 0; j < (idx - 1); j++)
			{
				if (functor(arr[j], arr[j + 1]))
				{
					int temp = arr[j];
					
				}
			}
		}
	}

};

