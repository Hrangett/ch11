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
	operator int()//����ȯ ������ �����ε�
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
	Number num1;//int->Number ����ȯ �ʿ�!
	num1 = 30;
	Number num2 = num1 + 20;//Number->int �� ����ȯ �� ���� ���� �� �ٽ� int ->Number type���� ��ȯ
	//num1.ShowNum();
	num2.ShowNum();
	return 0;
}