#include<iostream>
#include<cstring>

using namespace std;

class Person
{
private:
	char* name;
	int age;

public:
	Person(const char* myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}
	Person& operator=(const Person& ref)
	{
		delete[]name;

		int len = strlen(ref.name) + 1;
		name = new char[len];
		strcpy(name, ref.name);
		age = ref.age;
		return *this;
	}

	void ShowPersonInfo()const
	{
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;

	}
	~Person()
	{
		delete[]name;
		cout << "콜디드 디스트럭터!" << endl;
	}
};

int main()
{
	Person man1("Lee dong woo", 29);
	Person man2("Yoon hi yul", 22);
	man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}
