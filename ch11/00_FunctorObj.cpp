#include<iostream>
using namespace std;


class CTest
{
	int money;
public:
	CTest(int m = 0) :money(m)
	{
		cout << "CTest 생성자" << endl;
	}

	//
	int operator()()
	{
		return money;
	}

	void operator()(int m)
	{
		money += m;
	}

};

int main()
{
	CTest m;
	cout << m() << "머니" << endl;
	m(100);
	cout << m() << "머니" << endl;
}