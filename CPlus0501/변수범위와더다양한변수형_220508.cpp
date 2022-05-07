#include <iostream>
#include <string>
#include <cstdint>
#include <vector>
using namespace std;

// 4.1
namespace Work1 //Work1::Work1_1 �����Ϸ� �ֽ�(?)���������� ��� ����
{
	namespace Work1_1
	{
		int a = 0;
		void doSometing()
		{
			a += 4;
		}
	}
}
namespace Work2
{
	int a = 0;
	void doSometing()
	{
		a += 5;
	}
}

int value = 1;

void doSomethings()
{
	int a = 1;
	++a;
	cout << a<<endl;
}
void doSomethingstatic()
{
	static int a = 1; // �ٸ������� �����ϱ� �����. �� �ʿ䵵 ����
	++a;
	cout << a << endl;
}

// 4.2
/*������ Ű���� extern */void DoSometingTest(); //���漱��
extern int TestA; //���漱�� ���⼭�� �ʱ�ȭ�� ���ָ� �ȵ�! �ʱ�ȭ �ϸ� �浹�� ���ܹ����� �̰͵� �������� ����� ����õ�ϴ� ����� �ϳ�

#include "���.h"
// using namespace Constants;

void DoHeaderExternalTest();

// 4.3
int add(int a_, int b_) // return�� auto ��� ����. but �Ű������� auto ��� �Ұ�. ������ ���� �� ���� Ÿ���� �������� �����̱� ������!
{						//Template���� ���� ��� ��� ����
	return a_+ b_;
}

auto add2(int a_, int b_) ->int;
auto add2(int a_, int b_) ->int //���� ������ ���... �ڵ� ������ �� ������
{						
	return a_ + b_;
}

// 4.7
enum Color //����� ���� �ڷ����� �ϳ�
{
	COLOR_BLACK,
	COLOR_RED,
	COLOR_BLUE = 3,
	COLOR_GREEN = 3, // �����ϰ� �� ���� ����  �������� X
	COLOR_END /* ,�� �־ ��� ��� ����*/
};//�����ݷ� ������ ����
// ���� �빮�ڷ� ���
enum Feeling
{
	HAPPY =-1,
	SAD = 3,
	JOY,
	//BLUE //������ ���� ������ enum class�� ������
};

int computeDamage(int weapon_id)
{
	if (weapon_id == 0)
	{
		return 1;
	}
	if (weapon_id == COLOR_RED) // 1-> COLOR_RED   enum���� �������ָ� ������good
	{
		return 2;
	}
}



int main()
{
// 4.1 ���������� ������ ���ӱⰣ
	//�����Ҵ� �������� ����-���ӱⰣ�� ���̰��°�

	//apple =3 ; ->undefined
	int apple = 5;
/*
	return;
}
apple =4; // �߰�ȣ ���̶� �Ҵ� ���� ����
*/
	{
		apple = 11; // �ٱ�apple�� ������ apple
		int apple = 33;
		cout << apple << endl;  //��� ��� �ȿ��� ����� apple 
		//�߰�ȣ �ȿ��� ������ ������ ����Ǹ� ���� ������ �̸��� ��������.
		//�̸��� �ٸ��� ����^^
	}
	cout << apple << endl; //ó�� ����� apple

	//������ �������� ���͵� ��������
	//���Ǵ� �ݵ�� �� ������ ����

	Work2::doSometing();
	//namespace�� ����ü. Ŭ������ ����ȴ�
	Work1::Work1_1::doSometing();
	//namespace �ȿ� namespace ��� ����
	//��������Ŷ �̷��� ���̿�


	
// 4.2 ��������, �������� |  ���ο���, �ܺο���
	//global	 static	   internal  external(extern)

	//���������� ������ ������� �ʾƾ� �Ѵ�
	//��Ȯ�� ���� �ƴϴ�

	//obj ��ŷ�� ����� ����

	//���ϴ����� ����ϴ°� �������ִ�? ���ñ�?

	cout << value << endl;

	int value = 1;
	//���������� ������ value�� �� value�� ������ �Ŀ��� ������·� �ȴ�

	cout << value << endl;

	cout << ::value << endl; //������ �ҷ����� ��� ::


	doSomethings(); //2
	doSomethings(); //2
	doSomethingstatic(); //2
	doSomethingstatic(); //3

	//static == �Ҵ���� �޸𸮰� static 
	//doSomethings �� a �� 1ȸ�� ����ȭ �ߵǸ� ������ �޸𸮸� �ְ�����...
	//doSomethingstatic �� a �� �ʱ�ȭ�� �� ���� �Ѵ� 

	// os�� �޸𸮸� �Ҵ� �޾�
	// �ٽ� ������ ��򰡿� �Ҵ�޾Ҿ��ٴ� ����� �����־�
	// static int a =1; ���� ��ġ�� �ʰ� ����ȴ�.

	// ���������� ����� �ʾ�����. ���ԵǴ� �ϵ� ���� ����
	// g_a �������� ���������¹�

	// ��Ŀ�� ��ŷ�� ���� �� local valuable
	// ��ŷ ��Ű��...?
	// ��ŷ - obj ���� ��ŷ �ܰ迡�� local valuable ���� ������ �ʿ� ���� �۾�(��������) #���ؾȵ�
	// local valuable ��Ű���� ����.
	// 
	// internal link ���� cpp �ȿ����� ��밡��
	// static ���������� �ٸ� cpp ���Ͽ��� ��� �� �� ������ ������  but static�� ��� !=���� ����
	// external link

	// include"" �� �ҷ��� �� ������ �׷��� �ʴ���...? ��ȭ?

	DoSometingTest();
	cout << TestA << endl;

	cout <<"�����Լ�" << &Constants::Pipi << endl;
	DoHeaderExternalTest();//�� �ּҰ�(Constants::pi)�� �ٸ��� ���´�. 

	
// 4.3 using ���� ��ȣ��

	// using namespace std; -><iostream> namespace�� ����Ѵٴ°�
	using std::endl; //�̷������� ��� ����

	// �ٸ� namespace�� ������ �Լ��� ������ ���� ��  ex)doSometing();
	// using namespace ~~; �� ���ԵǸ�

	Work2::doSometing();
	//or
	{
		using namespace Work2; // �ۿ��� using namespace Work1::Work1_1;�� �ϸ� X
		doSometing();
	}
	//�� ���������� using namespace ����� �ﰡ�ϱ�
	//�׶��׶� �����ϰ� �� ����^^


// 4.4 Auto Ű����� �ڷ��� �߷�

	int b = 123; // 123==���� int==����
	auto b1 = 123; // �ʱ�ȭ �� �� auto�� �������� �������°�
	auto b2 = 1.23;
	auto b3 = 1+2.0; // ������ ���(����ȯ)�� �Ǵ� ���
	auto result2 = add(1, 2);


// 4.5 ����ȯ

	cout << typeid(b).name() << endl; //���� �� �˷���

	int x = 123.0; //������ �Ͻ��� ����ȯ. numeric conversion
	double y = x;	//numeric promotion ū ���������� ���°� ū ������ ����
	short s = 2;	//numeric conversion
	int i = 1000;
	char c = i; //�����ؼ� ����.
	cout << static_cast<int>(c) << endl; //48 ����� ����ȯ

	double dd = 0.123456789;
	float nopp = dd;	//double ���е� ���� ���ڸ� float�� ���� ����ȯ ��Ű�� ���е��� ������.

	float fpi = 3.14;
	int _i = fpi; //�Ҽ��� �߶����;

	cout << 5u - 10 << endl; // u == unsigned  ����ȯ�� �켱������ ����

	//�켱����
	//int,	unsigned int, long, unsigned long,
	//long long, unsigned long long, float, double ,long double

	int t1 = int(4.0);	// c++ ��Ÿ��
	int t2 = (int)4.0;	// c ��Ÿ��
	int t3 = static_cast<int>(4.0); // ��õ��Ÿ��


// 4.6 ���ڿ� �Ұ�  std::string 
	
	cout << "Hello World" << endl; // ���ڿ� ������ ǥ�ð� ����������

	//#include <string>
	const string my_hello = "Hello, World";
	cout << my_hello << endl;
	//string �� ����� ���� �ڷ���
	
	
	const char my_hello_arr[] = "Hello, World";
	cout << my_hello_arr << endl;

	const string my_hello_init1{ "Hello, World" };
	string ID = "123";  // 123 ������ ���� �ȵ�!

	string Name;
	cout << "Your Name? ";
	//cin >> Name;

	//jack jack ���ۿ� �����ߴٰ� �ڿ����� �Ѱ��ش�??  #���ؾȵ�

	std::getline(std::cin, Name); //string �Է¿� ���


	string Age;
	cout << "Your Age? ";
	cin >> Age;


	cout << "Your ID? ";
	std::getline(std::cin, ID);	// ����;; 	cin >> Age;���� ù ��° �Է� �޾Ҵ��� �Ѱܹ����� std::cin.ignore(32767, '\n'); �� ������(�Է¹ޱ� ����) �������ָ� ��


	cout << Name << " " << Age << " " << ID << endl;


	std::cin.ignore(32767, '\n'); //  32767magic number�� �ڵ忡 ���°� �����Ƿ� std::numeric_limits<std::streamsize> �̷��� ���°� �����ѵ�... ���̺귯���� ���� ���� ���� �� �����Ͱ���~~

	string str_a("Hello, ");
	string str_b("World");
	string str_c = str_a + str_b;
	str_c += " Hell";
	cout << str_c << endl;
	//+ �����ڰ� string Ŭ���� ���ο� ���ǵǾ�����

	cout << str_c.length() << endl; // 17  ���ڿ� ���� ��ȯ�Լ� \n ����!  .~() ���� �Լ� ȣ�� 


// 4.7 ������ enumerated

	Color paint = COLOR_BLACK;
	Color house(COLOR_BLUE);
	Color car{COLOR_GREEN};
	int colortest = COLOR_BLACK; // �� ����
	Color int_test; /* = 3  �Ұ���*/

	//cin���� ���� ��� �Ұ�
	//�ٸ� ���� ����ؼ� ���ǹ����� ��ȸ�ϴ� ������ ���
	//���� 6�� ���ڿ� ��Ÿ�� �ΰ����� ������ �������ٰ� ��
	//���� ����� �־ include ���


// 4.8 ���� ���� ������ (������ Ŭ���� Enum Class) c++11
	//Enum Struct�� �ִµ� class�� ���� ���� ��
	enum class Testenum
	{
		ONE,
		TWO
	};
	
	enum class Fruit
	{
		BANANA,
		APPLE,
	};
	//if (Testenum::ONE == Fruit::BANANA) 	//Testenum �� Fruit�� �� �� �� ���� ������
	{
		//static_cast<int> �� ���� �񱳴� ����
	}

	Fruit fruit1 = Fruit::BANANA;
	Fruit fruit2 = Fruit::APPLE;
	//namespace�� �����.


// 4.9 �ڷ������� ���� �ٿ��ֱ� Type aliases

	//Typedef 
	typedef double distance_t;
	typedef unsigned int u_int;

	//�����ʺ�Ҽ� <cstdint>
	double my_distance;
	distance_t homework;
	//�ڵ� ���Ǹ� ���Ѱ�

	//�������� ������ �����ϱ� ����
	vector<pair<string, int>> pairtest;
	
	typedef vector<pair<string, int>> str_intVec; 
	
	using pairlist_t = vector<pair<string, int>>; //�����Ϸ����� �̸� ������ִ°� ����������� �޸������� �ٸ�!


// 4.10 ����ü struct

	//���� ��ҵ��� �����ִ°�
	/*
	double height1;
	float weight;
	int age;
	string name;
	*/
	// �Լ�(double height1, float weight, int age, string name);
	struct MyStruct
	{
		double height1; //���
		float weight;
		int age;
		string name;

		void print()
		{
			cout << height1 << weight << age << name << endl;
		}
	};
	MyStruct info{2.2, 2.2, 2 ,"name"};
	// �Լ�(MyStruct myinfo);
	info.age; //��� ���� ���۷�����
	
	//�����Ϳ� ����� ����
	info.print();

	MyStruct info2{ 23.0, 1.2, 5 ,"namee" };
	info = info2; // ������ ������ �Ŀ��� ������ ���� �� ���� �ǵ���� �������� ���� �� ����.

	struct InMyStruct
	{
		MyStruct inMy_info;
	};
	// �Լ� return, �Ű������� ��� ����

	struct Human
	{
		double height = 160;
		float weight = 50;
		int age = 100;
	};
	Human me{162,50,26}; // ������ �� �Ҵ��� ������ �ʱ�ȭ��.

	struct Employee 
	{
		short id;	//2byte  (+2)
		int age;	//4byte
		double wage;//8byte
	};
	cout << sizeof(Employee) << endl; // �޸𸮴� 4�� �Ҵ��ؼ� size 16
	// short 2 + (2) + int 4 + double 8 (4 + 4)

	return 0;
}

//const int g_x; �ʱ�ȭ �������!! �ٵ� const �������? 
//extern const int g_z; ��𼱰��� �ʱ�ȭ �������
//static int g_y(10); �ٸ� ���Ͽ��� ��� �Ұ����� ��������
// const int g_y(10); ���� ����.
//extern int g_w(10); �ٸ��������� �ʱ�ȭ �Ұ���
//extern const int g_q(10); ��ŷ�� �� cpp ���� ���� �����ֱ� ������ ��ó�� ������� ���� ��� ������ �޶����°�
