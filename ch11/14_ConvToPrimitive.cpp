#include <iostream>
using namespace std;

class Number
{
private:
	int num;

public:
	Number(int n = 0) :num(n)
	{
		cout << "Number(int n = 0)" << endl;
	}

	Number& operator=(const Number& ref)
	{
		cout << "operator=( )" << endl;
		num = ref.num;
		return *this;
	}
	operator int()//형변환 연산자 오버로딩
	{
		return num;
	}
	void ShowNum()
	{
		cout << num << endl;
	}

};

int main()
{
	Number num1;//int->Number 형변환 필요!
	num1 = 30;
	Number num2 = num1 + 20;//Number->int 로 형변환 후 연산 실행 후 다시 int ->Number type으로 변환
	//num1.ShowNum();
	num2.ShowNum();
	return 0;
}