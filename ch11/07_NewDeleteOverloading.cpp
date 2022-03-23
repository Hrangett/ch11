#include <iostream>
using namespace std;

class Point
{
public:
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y)
	{
		cout << "Point" << endl;
	}
	friend ostream& operator<<(ostream& os, const Point& pos);

	void* operator new(size_t size)//전달된 매개변수 Point 의 인자가 int형 ㅂㅕㄴ수 두개이므로
	{
		cout << "operator new : " << size << endl;
		void* adr = new char[size];
		return adr;
	}
	void operator delete (void* adr)
	{
		cout << "operator delete() " << endl;
		delete[]adr;
	}

};
ostream& operator<<(ostream& os, const Point& pos)
{
	os << "[" << pos.xpos << "," << pos.ypos << "]" << endl;
	return os;
}

int main(void)
{
	//Point p(5,6);
	Point* ptr = new Point(3, 4);
	cout << *ptr;
	delete ptr;

	return 0;
}