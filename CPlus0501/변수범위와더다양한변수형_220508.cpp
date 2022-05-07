#include <iostream>
#include <string>
#include <cstdint>
#include <vector>
using namespace std;

// 4.1
namespace Work1 //Work1::Work1_1 컴파일러 최신(?)버전에서는 사용 가능
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
	static int a = 1; // 다른곳에서 접근하기 힘들다. 할 필요도 없고
	++a;
	cout << a << endl;
}

// 4.2
/*생략된 키워드 extern */void DoSometingTest(); //전방선언
extern int TestA; //전방선언 여기서는 초기화를 해주면 안됨! 초기화 하면 충돌이 생겨버린다 이것도 전역변수 사용을 비추천하는 요소중 하나

#include "헤더.h"
// using namespace Constants;

void DoHeaderExternalTest();

// 4.3
int add(int a_, int b_) // return은 auto 사용 가능. but 매개변수는 auto 사용 불가. 변수를 선언 할 때에 타입이 정해지는 형태이기 때문에!
{						//Template으로 유사 기능 사용 가능
	return a_+ b_;
}

auto add2(int a_, int b_) ->int;
auto add2(int a_, int b_) ->int //위랑 동일한 기능... 코드 정리할 때 좋다함
{						
	return a_ + b_;
}

// 4.7
enum Color //사용자 정의 자료형중 하나
{
	COLOR_BLACK,
	COLOR_RED,
	COLOR_BLUE = 3,
	COLOR_GREEN = 3, // 동일하게 할 수도 있음  권장하지 X
	COLOR_END /* ,는 있어도 없어도 상관 없음*/
};//세미콜론 빼먹지 말기
// 보통 대문자로 사용
enum Feeling
{
	HAPPY =-1,
	SAD = 3,
	JOY,
	//BLUE //같은걸 쓰면 안좋다 enum class를 쓰던가
};

int computeDamage(int weapon_id)
{
	if (weapon_id == 0)
	{
		return 1;
	}
	if (weapon_id == COLOR_RED) // 1-> COLOR_RED   enum으로 관리해주면 직관성good
	{
		return 2;
	}
}



int main()
{
// 4.1 지역변수의 범위와 지속기간
	//동적할당 전까지는 범위-지속기간은 같이가는거

	//apple =3 ; ->undefined
	int apple = 5;
/*
	return;
}
apple =4; // 중괄호 밖이라 할당 끝난 상태
*/
	{
		apple = 11; // 바깥apple과 동일한 apple
		int apple = 33;
		cout << apple << endl;  //얘는 블록 안에서 선언된 apple 
		//중괄호 안에서 동일한 변수가 선언되면 기존 변수의 이름이 숨겨진다.
		//이름은 다르게 짓자^^
	}
	cout << apple << endl; //처음 선언된 apple

	//선언은 여기저기 나와도 ㄱㅊ지만
	//정의는 반드시 한 곳에만 존재

	Work2::doSometing();
	//namespace는 구조체. 클래스와 연결된다
	Work1::Work1_1::doSometing();
	//namespace 안에 namespace 사용 가능
	//실제로패킷 이렇게 많이옴


	
// 4.2 전역변수, 정적변수 |  내부연결, 외부연결
	//global	 static	   internal  external(extern)

	//전역변수는 가급적 사용하지 않아야 한다
	//명확한 답은 아니다

	//obj 링킹과 비슷한 개념

	//파일단위로 사용하는걸 정의해주는? 뭐시기?

	cout << value << endl;

	int value = 1;
	//전역변수로 선언한 value는 위 value가 선언한 후에는 숨김상태로 된다

	cout << value << endl;

	cout << ::value << endl; //전역을 불러오는 방법 ::


	doSomethings(); //2
	doSomethings(); //2
	doSomethingstatic(); //2
	doSomethingstatic(); //3

	//static == 할당받은 메모리가 static 
	//doSomethings 의 a 는 1회용 최적화 잘되면 동일한 메모리를 주겠지만...
	//doSomethingstatic 의 a 는 초기화를 한 번만 한다 

	// os에 메모리를 할당 받아
	// 다시 들어오면 어딘가에 할당받았었다는 기록이 남아있어
	// static int a =1; 줄을 거치지 않고 실행된다.

	// 전역변수는 퇴근이 늦어진다. 쓰게되는 일도 물론 있음
	// g_a 전역변수 변수명짓는법

	// 링커가 링킹을 해줄 때 local valuable
	// 링킹 링키지...?
	// 링킹 - obj 파일 링킹 단계에서 local valuable 끼리 연결은 필요 없는 작업(뭔말이지) #이해안됨
	// local valuable 링키지가 없다.
	// 
	// internal link 개별 cpp 안에서만 사용가능
	// static 전역변수는 다른 cpp 파일에서 사용 할 수 없도록 막아줌  but static의 기능 !=영역 제한
	// external link

	// include"" 로 불러올 수 있지만 그러지 않는편...? 실화?

	DoSometingTest();
	cout << TestA << endl;

	cout <<"메인함수" << &Constants::Pipi << endl;
	DoHeaderExternalTest();//두 주소값(Constants::pi)이 다르게 나온다. 

	
// 4.3 using 문과 모호성

	// using namespace std; -><iostream> namespace를 사용한다는것
	using std::endl; //이런식으로 사용 가능

	// 다른 namespace에 동일한 함수나 변수가 있을 때  ex)doSometing();
	// using namespace ~~; 를 쓰게되면

	Work2::doSometing();
	//or
	{
		using namespace Work2; // 밖에서 using namespace Work1::Work1_1;을 하면 X
		doSometing();
	}
	//전 영역에서는 using namespace 사용은 삼가하기
	//그때그때 현명하게 잘 쓰기^^


// 4.4 Auto 키워드와 자료형 추론

	int b = 123; // 123==정수 int==정수
	auto b1 = 123; // 초기화 할 때 auto의 변수형이 정해지는것
	auto b2 = 1.23;
	auto b3 = 1+2.0; // 연산의 결과(형변환)이 되는 경우
	auto result2 = add(1, 2);


// 4.5 형변환

	cout << typeid(b).name() << endl; //변수 형 알려줌

	int x = 123.0; //정수로 암시적 형변환. numeric conversion
	double y = x;	//numeric promotion 큰 변수형으로 들어가는건 큰 문제가 없다
	short s = 2;	//numeric conversion
	int i = 1000;
	char c = i; //절삭해서 저장.
	cout << static_cast<int>(c) << endl; //48 명시적 형변환

	double dd = 0.123456789;
	float nopp = dd;	//double 정밀도 높은 숫자를 float에 강제 형변환 시키면 정밀도가 떨어짐.

	float fpi = 3.14;
	int _i = fpi; //소수점 잘라버림;

	cout << 5u - 10 << endl; // u == unsigned  형변환도 우선순위가 있음

	//우선순위
	//int,	unsigned int, long, unsigned long,
	//long long, unsigned long long, float, double ,long double

	int t1 = int(4.0);	// c++ 스타일
	int t2 = (int)4.0;	// c 스타일
	int t3 = static_cast<int>(4.0); // 추천스타일


// 4.6 문자열 소개  std::string 
	
	cout << "Hello World" << endl; // 문자열 마지막 표시가 숨겨져있음

	//#include <string>
	const string my_hello = "Hello, World";
	cout << my_hello << endl;
	//string 은 사용자 정의 자료형
	
	
	const char my_hello_arr[] = "Hello, World";
	cout << my_hello_arr << endl;

	const string my_hello_init1{ "Hello, World" };
	string ID = "123";  // 123 정수로 대입 안됨!

	string Name;
	cout << "Your Name? ";
	//cin >> Name;

	//jack jack 버퍼에 저장했다가 뒤에까지 넘겨준다??  #이해안됨

	std::getline(std::cin, Name); //string 입력에 사용


	string Age;
	cout << "Your Age? ";
	cin >> Age;


	cout << "Your ID? ";
	std::getline(std::cin, ID);	// 안함;; 	cin >> Age;에서 첫 번째 입력 받았던걸 넘겨버려서 std::cin.ignore(32767, '\n'); 를 위에서(입력받기 전에) 선언해주면 됨


	cout << Name << " " << Age << " " << ID << endl;


	std::cin.ignore(32767, '\n'); //  32767magic number는 코드에 없는게 좋으므로 std::numeric_limits<std::streamsize> 이런걸 쓰는게 좋긴한데... 라이브러리로 만들어서 쓰는 법이 젤 좋을것같다~~

	string str_a("Hello, ");
	string str_b("World");
	string str_c = str_a + str_b;
	str_c += " Hell";
	cout << str_c << endl;
	//+ 연산자가 string 클래스 내부에 정의되어있음

	cout << str_c.length() << endl; // 17  문자열 길이 반환함수 \n 빼고!  .~() 내부 함수 호출 


// 4.7 열거형 enumerated

	Color paint = COLOR_BLACK;
	Color house(COLOR_BLUE);
	Color car{COLOR_GREEN};
	int colortest = COLOR_BLACK; // 는 가능
	Color int_test; /* = 3  불가능*/

	//cin으로 직접 사용 불가
	//다른 변수 사용해서 조건문으로 우회하는 식으로 사용
	//문명 6의 문자열 오타로 인공지능 성능이 낮아졌다고 함
	//보통 헤더에 넣어서 include 사용


// 4.8 영역 제한 열거형 (열거형 클래스 Enum Class) c++11
	//Enum Struct도 있는데 class를 많이 쓰는 편
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
	//if (Testenum::ONE == Fruit::BANANA) 	//Testenum 와 Fruit을 비교 할 수 없게 막아줌
	{
		//static_cast<int> 로 강제 비교는 가능
	}

	Fruit fruit1 = Fruit::BANANA;
	Fruit fruit2 = Fruit::APPLE;
	//namespace와 비슷함.


// 4.9 자료형에게 가명 붙여주기 Type aliases

	//Typedef 
	typedef double distance_t;
	typedef unsigned int u_int;

	//고정너비소수 <cstdint>
	double my_distance;
	distance_t homework;
	//코딩 편의를 위한것

	//변수형을 통으로 수정하기 편함
	vector<pair<string, int>> pairtest;
	
	typedef vector<pair<string, int>> str_intVec; 
	
	using pairlist_t = vector<pair<string, int>>; //컴파일러한테 이름 명시해주는것 변수선언과는 메모리적으로 다름!


// 4.10 구조체 struct

	//많은 요소들을 묶어주는거
	/*
	double height1;
	float weight;
	int age;
	string name;
	*/
	// 함수(double height1, float weight, int age, string name);
	struct MyStruct
	{
		double height1; //멤버
		float weight;
		int age;
		string name;

		void print()
		{
			cout << height1 << weight << age << name << endl;
		}
	};
	MyStruct info{2.2, 2.2, 2 ,"name"};
	// 함수(MyStruct myinfo);
	info.age; //멤버 선택 오퍼레이터
	
	//데이터와 기능을 묶음
	info.print();

	MyStruct info2{ 23.0, 1.2, 5 ,"namee" };
	info = info2; // 동작은 하지만 후에는 문제가 생길 수 있음 의도대로 동작하지 않을 수 있음.

	struct InMyStruct
	{
		MyStruct inMy_info;
	};
	// 함수 return, 매개변수로 사용 가능

	struct Human
	{
		double height = 160;
		float weight = 50;
		int age = 100;
	};
	Human me{162,50,26}; // 선언할 때 할당한 값으로 초기화됨.

	struct Employee 
	{
		short id;	//2byte  (+2)
		int age;	//4byte
		double wage;//8byte
	};
	cout << sizeof(Employee) << endl; // 메모리는 4씩 할당해서 size 16
	// short 2 + (2) + int 4 + double 8 (4 + 4)

	return 0;
}

//const int g_x; 초기화 해줘야함!! 근데 const 언제배움? 
//extern const int g_z; 어디선가는 초기화 해줘야함
//static int g_y(10); 다른 파일에서 사용 불가능한 전역변수
// const int g_y(10); 위랑 동일.
//extern int g_w(10); 다른곳에서는 초기화 불가능
//extern const int g_q(10); 링킹할 때 cpp 파일 별로 엮어주기 때문에 위처럼 선언법에 따라 사용 범위가 달라지는것
