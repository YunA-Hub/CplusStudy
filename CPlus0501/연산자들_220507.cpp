#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;


int add(int _a, int _b);
int getPrice(bool bSale);
void invokeEvent();
int main()
{
// 3.1 연산자 우선순위와 결합법칙  precedence

	int x = 4 + 2 * 3; //  ==  4 + (2 * 3); 


	//결합법칙
	int y = 4 * 3 / 2;  // L to R  자료형이 섞인 연산에서는 * / 순서에 따라 결과가 달라지는 경우가 있음

	int z = (1 - 2) + (-3); // 2-3 == 2 + (-3) 내부적으로는 우측처럼 연산이 이루어진다나 뭐라나

	// ^ == XOR  제곱이 아님
	std::pow(2, 3); // 이게 코딩으로 제곱하는 라이브러리 함수    #include <cmath>


// 3.2 산술 연산자 arithmetic operators

	int a = 1;
	int b = -a; // - a 컴파일러는 공백을 무시해서 문제는 없는데 보기 숭하다 
	int c = x - -z; // x- (-z);

	//나머지 연산자
	int w = x % y;

	cout << x / y << endl; // 정수끼리 연산의 결과는 정수

	cout << float(x) / y << endl;
	cout << x / float(y) << endl;
	cout << float(x) / float(y) << endl; // 연산에 실수가 있으면 결과는 실수로 나옴


	cout << -5 / 2<< endl; // 결과 :-2   버림으로 결과를 내주는걸로 c++11부터 정해짐

	a += b; // a = a + b;


//3.3 증감연산자

	int g = 5; 
	int t = ++g;//1 증가
	int h = g--;

	int xx = 6, yy = 6;

	cout << xx << " 여기임 " << yy << endl;//	6 6
	cout << ++xx << " " << --yy << endl; // 	7 5
	cout << xx << " " << yy << endl;	//		7 5
	cout << xx++ << " " << yy-- << endl;//		7 5
	cout << xx << " " << yy << endl;	//		8 4

	int l = 10, u = 10;
	cout << l << " " << u << endl;		// 10 10
	cout << ++l << " " << u++ << endl;  // 11 10
	cout << l << " " << u << endl;		// 11 11

	//증감연산자의 위치에 따라 연산되는 방법? 이 다르다

	add(xx ,++xx);//이런식으로 쓰지 말아라
	add(xx, ++yy);//이건 ㄱㅊ

	int xxx = 1;
	xxx = ++xxx; //이것도 쓰지 말아라


// 3.4 sizeof, 쉼표 연산자, 조건부 연산자

	float fa;

	sizeof(float); // 4byte 32bit
	sizeof(fa);		//변수, 변수형 모두 사용 가능하고 사용자 자료형(클래스)도 사용가능
	//sizeof 는 연산자. 함수가 아니여
	cout<< sizeof fa << endl; ; //신기함

	 // ,연산자
	int aa = 3;
	int bb = 10;
	int cc = (++aa, ++bb); 
	//++aa;
	//++bb;
	//int cc =bb;
	cout << aa << " " << bb << " " << cc << endl; //4 11 11 


	int n = 1, m = 2; //이건 구분을 위한 , 기호 ,operator가 아니여
	int ll;
	ll = n, m; //우선순위가 =보다 낮음 대입을 먼저 해버려서 ll =n 으로 끝남

	//conditional operator | 조건부 연산자 | 삼항 연산자
	// 조건에 따라 ~~해라

	bool onSale = true;

	const int price = (onSale == true) ? 10 : 100;
	/*
	if(onSale)
		price = 10;
	else
		price = 100;
	*/
	cout << price << endl; // 10
	cout << getPrice(onSale) << endl;
	// 삼항 연산자가 복잡해지면 사용 비추

	// cout << ((onSale == true) ? "ooo" : 100) << endl; 강의에서는 문제없었는데 막힌듯하다  ** 물어보기


// 3.5 관계연산자
	
	int inputx=0, inputy=0;
	cin >> inputx >> inputy;

	cout << "Your input: " << inputx << " " << inputy << endl;
	//while(true)
	//{
	if (inputx == inputy)
		cout << "equal" << endl;
	if(inputx != inputy)
		cout << "N equal" << endl;
	if (inputx > inputy)
		cout << "inputx > inputy" << endl;
	if (inputx < inputy)
		cout << "inputx < inputy" << endl;
	if (inputx >= inputy)
		cout << "inputx >= inputy" << endl;
	if (inputx <= inputy)
		cout << "inputx <= inputy" << endl;
	//}


	double d1(100 - 99.99); // 0.001
	double d2(10 - 9.99); // 0.001

	if (d1 == d2)
		cout << "==" << endl;
	else
	{
		cout << "!=" << endl;  //요기

		if (d1 > d2)
			cout << "d1 > d2" << endl; //요기
		else
			cout << "d1 < d2" << endl;
	}
	//부동소수점 차이 맞춰주는 함수? 사용

	cout << abs(d1 - d2) << endl;   // 5.32907e-15
	//오차의 한계 추가해주기

	const double epsilon = 1e-10; //1e-16  epsilon을 정하는건 분야. 사람마다 다름^0^
	if (abs(d1 - d2) < epsilon)
		cout << "Approximately equal" << endl;
	else
		cout << "N equal" << endl;


// 3.6 논리연산자

	//logical AND
	bool bx = true;
	bool by = false;
	cout << (bx && by) << endl;

	bool bHit = true;
	int health = 10;

	if (bHit == true && health < 20)
	{
		cout << "die" << endl;
	}
	else
		--health;

	//logical OR ||
	cout << (bx || by) << endl;


	int tt = 5;
	int hh = 5;
	//if ((!tt) == hh)  // 뭐야이건
	//{
	//
	//}

	int v = 1;
	if (v == 0 || v == 1)
		cout << "v if 0 or 1" << endl;

	//short circuit evaluation
	int o = 1, p = 2;

	if (o == 1 && p++ == 2)
	{
		// do something
	}
	cout << p << endl; // 강사가 보여준거랑 결과가 다르다!

	bool bxx = true;
	bool byy = false;

	!(bxx && byy);  /* != */  !bxx && !byy;
	//분배법칙이 적용되지 않음!

	//XOR 
	//false false		false
	//false true		true
	//true	false		true
	//true	true		false

	bool v1 = true, v2 = false, v3 = false;

	bool r1 = v1 || v2 && v3;

	bool r2 = (v1 || v2) && v3;

	//&& 가 ||보다 연산자 우선순위가 높음!!
	//걍 괄호를 적극 사용하자


// 3.7 이진수 binary numbers

	/*
	이진수가 이진수지...ㅠ	

				1
	 11			11
	+ 1	  ->   + 1
	---		   ---
			   100

	7654  3210
	0101  1110
	2*2*2*2*2*2 + 2*2*2*2 + 2*2*2* + 2*2* + 2 = 94
	//제곱 표시, 0승 생략^^

	148 to binary

	148 / 2 = 74 ...0
	74/ 2	= 37 ...0
	37 / 2	= 18 ...1
	18 / 2	= 9  ...0
	9 / 2	= 4  ...1
	4 / 2	= 2  ...0
	2 / 2	= 1  ...0     

	10010100

	2 제곱수들로 구하는 방법

	2 4 8 16 32 64 128 256 612 1024 2048...

	148 to binary
										   승+1				
	148 >= 128					128 =2^7	1
	148 - 128 = 20 , 20 >= 64	65 = 2^6	0
					 20 >= 32	32 = 2^5	0
					 20 >= 16	16 = 2^4	1
	20 - 16 = 4,	 4 >= 8		8 = 2^3		0
					 4 >= 4		4 = 2^2		1
	4 - 4 =0

	10010100

	음수


	0000 0101	== 5
	ㄴ이건 음수 양수 표시용임 양의정수는 0
	보수
	1111 1010
	+1
	1111 1011	== -5

	0000 0000
	1111 1111
	+1
	0000 0000
	0은 어케해도 0!
	*/


// 3.8 비트단위 연산자
	
	// << left shift
	// >> right shift
	// cout cin 에서 사용하는거랑은 다른거
	// ~, &, |, ^
	//#include <bitset>
	unsigned int ua = 1;
	cout << bitset<4>(ua) << endl;	// 0001
	ua = 3;
	cout << bitset<4>(ua) << endl;	// 0011									3
	
	unsigned int ub = ua << 1;
	cout << bitset<4>(ub) << endl;	/// 0011을 left(<<)로 옮김 ==  0110		6	3 * 2  = 3 * 2^1
	
	ub = ua << 3;
	cout << bitset<4>(ub) << endl;	//  0110을 left로 두 번 옮김 == 1000
	cout << bitset<8>(ub) << endl;	//  00011000							24	3 * 8  = 3 * 2^3	

	unsigned int uc = 1024;
	cout << bitset<16>(uc) << " " << uc << endl;		//1024
	cout << bitset<16>(uc>>1) << " "<< uc<<endl;		//512
	cout << bitset<16>(uc>>2) << " " << uc << endl;		//251
	cout << bitset<16>(uc>>3) << " " << uc << endl;		//128
	cout << bitset<16>(uc>>4) << " " << uc << endl;		//64

	//~ 는 not   0001 -> 1110
	cout << bitset<16>(~uc) << " " << ~uc << endl;		//4294966271
	

	unsigned int ux = 0b1100;
	unsigned int uy = 0b0110;
	cout << ux << " " << uy <<endl;	//12 6

	cout << bitset<4>(ux & uy) << endl;	//bitwise AND 0100
	cout << bitset<4>(ux | uy) << endl;	//bitwise OR  1110
	cout << bitset<4>(ux ^ uy) << endl; //bitwise XOR 1010

	ux &= uy; /* == */ ux = ux & uy;

	0110 >> 2;	// 0001
	5 | 12;		// 0101 | 1100  0100
	5 & 12;		// 0101 & 1100	1101
	5 ^ 12;		// 0101 ^ 1100	1001


// 3.9 비트플래그 비트마스트
	//패킷 저렇게 넘기면 일많아져서 시름



	/*
	*비트플래그를 안쓰면...
	bool item1_flat = false;
	bool item2_flat = false;
	bool item3_flat = false;
	bool item4_flat = false;

	//event
	item1_flat = true;

	//die! item2 los
	item2_flat = false;

	if (item3_flat == true) //예)아이템이 있으면!
	{
	//뭐시기~ 기능
	}
	*/

	unsigned char items_flag = 0;

	cout <<"No item " << bitset<8>(items_flag) << endl;  //00000000   비트 하나하나를 bool 값으로 쓰는것임

	const unsigned char opt0 = 1 << 0;
	const unsigned char opt1 = 1 << 1;
	const unsigned char opt2 = 1 << 2;
	const unsigned char opt3 = 1 << 3;
	cout << bitset<8>(opt0) << endl;		// 0000 0001
	cout << bitset<8>(opt1) << endl;		// 0000 0010
	cout << bitset<8>(opt2) << endl;		// 0000 0100
	cout << bitset<8>(opt3) << endl;		// 0000 1000

	//item0 on
	items_flag |= opt0;
	cout << "get item0 " << bitset<8>(items_flag) << endl;		/// 0000 0001

	items_flag |= opt3;
	cout << "get item3 " << bitset<8>(items_flag) << endl;		/// 0000 1001

	items_flag &= ~opt3;  // ~ 주의!!
	cout << "lost item3 " << bitset<8>(items_flag) << endl;		/// 0000 0001


	cout << bitset<8>(items_flag) << endl; // 0000 0001

	//has item?
	if (items_flag & opt1) // 0000 0010
		cout << "Has Item1" << endl;
	else
		cout << "No Item1" << endl;	//*


	//has item?
	if (items_flag & opt0) // 0000 0001
		cout << "Has opt0" << endl;	//*
	else
		cout << "No opt0" << endl;


	//obtain item 2,3
	items_flag |= (opt2 | opt3);

	cout << bitset<8>(opt2 | opt3) << endl; //0000 1100  or 해주면 합치는거죵
	cout << bitset<8>(items_flag) << endl;	//0000 1101

	//아이템 많으면 for 써서...

	if ((items_flag & opt2) && !(items_flag & opt1))
	{
		//items_flag ^= opt2; // 0000 0010
		//items_flag ^= opt1;	// 0000 0100

		// == 	
		items_flag ^= (opt2 | opt1); // 두 값이 같으면 0 다르면 1
	}

	cout << bitset<8>(items_flag) << endl; //0000 1011


	//glClear(GL_COLOR_BUFFER_BIT); 255 255 255   #FFFFFF   255 FF 255 FF 255 FF   알파는 앞 뒤 붙는 종류 구분하면서 써야함...
	
	//RGB
	const unsigned int red_mask = 0xFF0000; //mask는 여러개 뭐라했는데 뭔뜻일까
	const unsigned int green_mask = 0x00FF00; //mask는 여러개 뭐라했는데 뭔뜻일까
	const unsigned int blue_mask = 0x0000FF; //mask는 여러개 뭐라했는데 뭔뜻일까
	cout << bitset<32>(red_mask) << endl;
	cout << bitset<32>(green_mask) << endl;
	cout << bitset<32>(blue_mask) << endl;


	unsigned int pixel_color = 0xDAA520;
	cout << bitset<32>(pixel_color) << endl;		//00000000110110101010010100100000


	cout << "red : " << bitset<24>(pixel_color & red_mask) << " "<< (int)((pixel_color & red_mask) >> 16) <<endl;
	cout << "green : " << bitset<16>(pixel_color & green_mask) << " " << (int)((pixel_color & green_mask) >> 8) << endl;
	cout << "blue : " << bitset<8>(pixel_color & blue_mask) << " " << (int)(pixel_color & blue_mask) << endl;





	return 0;
}


int getPrice(bool bSale)
{
	if (bSale)
		return 10;
	else
		return 100;
}

int add(int _a, int _b)
{
	return _a + _b;
}