#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y)
	{
		//cout << "Point" << endl;
	}
	friend ostream& operator<<(ostream& os, const Point& pos);

	static void* operator new (size_t size)
	{
		cout << "operator new : " << size << endl;
		void* adr = new char[size];
		return adr;
	}

	static void* operator new[](size_t size)
	{
		cout << "operator new[] : " << size << endl;
		void* adr = new char[size];
		return adr;
	}

		static void operator delete (void* adr)
	{
		cout << "operator delete() " << endl;
		delete[]adr;
	}

	static void operator delete[](void* adr)
	{
		cout << "operator delet[] ()" << endl;
		delete[]adr;
	}
	static void Point_Static();
	void Point_func();
};
void Point::Point_Static()
{
	cout << "Point::Point_Static()" << endl;
}

void Point::Point_func()
{
	cout << "Point::Point_func()" << endl;
}

ostream& operator<<(ostream& os, const Point& pos)
{
	os << "[" << pos.xpos << "," << pos.ypos << "]" << endl;
	return os;
}

int main()
{
	//Point* ptr = new Point(3, 4);
	//Point* arr = new Point[3];
	//ptr->Point_Static();
	//delete ptr;
	//delete[]arr;
	//Point::operator new(3);

	Point::Point_Static();
	//Point::Point_func();//static이 선언되지 않은 클래스 내부 함수는 객체를 생성한 후 호출할 수 있따
	return 0;
}