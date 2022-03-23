#include<iostream>
using namespace std;

class AAA
{
public:
	AAA() 
	{
		cout << "AAA::AAA()" << endl;
	}
	~AAA() 
	{
		cout << "AAA::~AAA()" << endl;

	}

	void func()
	{
		cout << "AAA::func()" << endl;
	}

};

int main()
{
	
	/*unique_ptr<AAA> ptr1 = make_unique<AAA>();
	ptr1->func();*/

	shared_ptr<AAA> ptr11 = make_shared<AAA>();
	ptr11->func();
	cout << "count : " << ptr11.use_count() << endl;
	{
		shared_ptr<AAA>ptr2(ptr11);
		cout << "count{} : " << ptr2.use_count() << endl;
		cout << "count{} : " << ptr11.use_count() << endl;


	}
	shared_ptr<AAA>ptr2(ptr11);
	cout << "count : " << ptr2.use_count() << endl;
	cout << "count : " << ptr11.use_count() << endl; c


	return 0;


}