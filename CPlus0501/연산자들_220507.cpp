#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;


int add(int _a, int _b);
int getPrice(bool bSale);
void invokeEvent();
int main()
{
// 3.1 ������ �켱������ ���չ�Ģ  precedence

	int x = 4 + 2 * 3; //  ==  4 + (2 * 3); 


	//���չ�Ģ
	int y = 4 * 3 / 2;  // L to R  �ڷ����� ���� ���꿡���� * / ������ ���� ����� �޶����� ��찡 ����

	int z = (1 - 2) + (-3); // 2-3 == 2 + (-3) ���������δ� ����ó�� ������ �̷�����ٳ� ����

	// ^ == XOR  ������ �ƴ�
	std::pow(2, 3); // �̰� �ڵ����� �����ϴ� ���̺귯�� �Լ�    #include <cmath>


// 3.2 ��� ������ arithmetic operators

	int a = 1;
	int b = -a; // - a �����Ϸ��� ������ �����ؼ� ������ ���µ� ���� ���ϴ� 
	int c = x - -z; // x- (-z);

	//������ ������
	int w = x % y;

	cout << x / y << endl; // �������� ������ ����� ����

	cout << float(x) / y << endl;
	cout << x / float(y) << endl;
	cout << float(x) / float(y) << endl; // ���꿡 �Ǽ��� ������ ����� �Ǽ��� ����


	cout << -5 / 2<< endl; // ��� :-2   �������� ����� ���ִ°ɷ� c++11���� ������

	a += b; // a = a + b;


//3.3 ����������

	int g = 5; 
	int t = ++g;//1 ����
	int h = g--;

	int xx = 6, yy = 6;

	cout << xx << " ������ " << yy << endl;//	6 6
	cout << ++xx << " " << --yy << endl; // 	7 5
	cout << xx << " " << yy << endl;	//		7 5
	cout << xx++ << " " << yy-- << endl;//		7 5
	cout << xx << " " << yy << endl;	//		8 4

	int l = 10, u = 10;
	cout << l << " " << u << endl;		// 10 10
	cout << ++l << " " << u++ << endl;  // 11 10
	cout << l << " " << u << endl;		// 11 11

	//������������ ��ġ�� ���� ����Ǵ� ���? �� �ٸ���

	add(xx ,++xx);//�̷������� ���� ���ƶ�
	add(xx, ++yy);//�̰� ����

	int xxx = 1;
	xxx = ++xxx; //�̰͵� ���� ���ƶ�


// 3.4 sizeof, ��ǥ ������, ���Ǻ� ������

	float fa;

	sizeof(float); // 4byte 32bit
	sizeof(fa);		//����, ������ ��� ��� �����ϰ� ����� �ڷ���(Ŭ����)�� ��밡��
	//sizeof �� ������. �Լ��� �ƴϿ�
	cout<< sizeof fa << endl; ; //�ű���

	 // ,������
	int aa = 3;
	int bb = 10;
	int cc = (++aa, ++bb); 
	//++aa;
	//++bb;
	//int cc =bb;
	cout << aa << " " << bb << " " << cc << endl; //4 11 11 


	int n = 1, m = 2; //�̰� ������ ���� , ��ȣ ,operator�� �ƴϿ�
	int ll;
	ll = n, m; //�켱������ =���� ���� ������ ���� �ع����� ll =n ���� ����

	//conditional operator | ���Ǻ� ������ | ���� ������
	// ���ǿ� ���� ~~�ض�

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
	// ���� �����ڰ� ���������� ��� ����

	// cout << ((onSale == true) ? "ooo" : 100) << endl; ���ǿ����� ���������µ� �������ϴ�  ** �����


// 3.5 ���迬����
	
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
		cout << "!=" << endl;  //���

		if (d1 > d2)
			cout << "d1 > d2" << endl; //���
		else
			cout << "d1 < d2" << endl;
	}
	//�ε��Ҽ��� ���� �����ִ� �Լ�? ���

	cout << abs(d1 - d2) << endl;   // 5.32907e-15
	//������ �Ѱ� �߰����ֱ�

	const double epsilon = 1e-10; //1e-16  epsilon�� ���ϴ°� �о�. ������� �ٸ�^0^
	if (abs(d1 - d2) < epsilon)
		cout << "Approximately equal" << endl;
	else
		cout << "N equal" << endl;


// 3.6 ��������

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
	//if ((!tt) == hh)  // �����̰�
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
	cout << p << endl; // ���簡 �����ذŶ� ����� �ٸ���!

	bool bxx = true;
	bool byy = false;

	!(bxx && byy);  /* != */  !bxx && !byy;
	//�й��Ģ�� ������� ����!

	//XOR 
	//false false		false
	//false true		true
	//true	false		true
	//true	true		false

	bool v1 = true, v2 = false, v3 = false;

	bool r1 = v1 || v2 && v3;

	bool r2 = (v1 || v2) && v3;

	//&& �� ||���� ������ �켱������ ����!!
	//�� ��ȣ�� ���� �������


// 3.7 ������ binary numbers

	/*
	�������� ��������...��	

				1
	 11			11
	+ 1	  ->   + 1
	---		   ---
			   100

	7654  3210
	0101  1110
	2*2*2*2*2*2 + 2*2*2*2 + 2*2*2* + 2*2* + 2 = 94
	//���� ǥ��, 0�� ����^^

	148 to binary

	148 / 2 = 74 ...0
	74/ 2	= 37 ...0
	37 / 2	= 18 ...1
	18 / 2	= 9  ...0
	9 / 2	= 4  ...1
	4 / 2	= 2  ...0
	2 / 2	= 1  ...0     

	10010100

	2 ��������� ���ϴ� ���

	2 4 8 16 32 64 128 256 612 1024 2048...

	148 to binary
										   ��+1				
	148 >= 128					128 =2^7	1
	148 - 128 = 20 , 20 >= 64	65 = 2^6	0
					 20 >= 32	32 = 2^5	0
					 20 >= 16	16 = 2^4	1
	20 - 16 = 4,	 4 >= 8		8 = 2^3		0
					 4 >= 4		4 = 2^2		1
	4 - 4 =0

	10010100

	����


	0000 0101	== 5
	���̰� ���� ��� ǥ�ÿ��� ���������� 0
	����
	1111 1010
	+1
	1111 1011	== -5

	0000 0000
	1111 1111
	+1
	0000 0000
	0�� �����ص� 0!
	*/


// 3.8 ��Ʈ���� ������
	
	// << left shift
	// >> right shift
	// cout cin ���� ����ϴ°Ŷ��� �ٸ���
	// ~, &, |, ^
	//#include <bitset>
	unsigned int ua = 1;
	cout << bitset<4>(ua) << endl;	// 0001
	ua = 3;
	cout << bitset<4>(ua) << endl;	// 0011									3
	
	unsigned int ub = ua << 1;
	cout << bitset<4>(ub) << endl;	/// 0011�� left(<<)�� �ű� ==  0110		6	3 * 2  = 3 * 2^1
	
	ub = ua << 3;
	cout << bitset<4>(ub) << endl;	//  0110�� left�� �� �� �ű� == 1000
	cout << bitset<8>(ub) << endl;	//  00011000							24	3 * 8  = 3 * 2^3	

	unsigned int uc = 1024;
	cout << bitset<16>(uc) << " " << uc << endl;		//1024
	cout << bitset<16>(uc>>1) << " "<< uc<<endl;		//512
	cout << bitset<16>(uc>>2) << " " << uc << endl;		//251
	cout << bitset<16>(uc>>3) << " " << uc << endl;		//128
	cout << bitset<16>(uc>>4) << " " << uc << endl;		//64

	//~ �� not   0001 -> 1110
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


// 3.9 ��Ʈ�÷��� ��Ʈ����Ʈ
	//��Ŷ ������ �ѱ�� �ϸ������� �ø�



	/*
	*��Ʈ�÷��׸� �Ⱦ���...
	bool item1_flat = false;
	bool item2_flat = false;
	bool item3_flat = false;
	bool item4_flat = false;

	//event
	item1_flat = true;

	//die! item2 los
	item2_flat = false;

	if (item3_flat == true) //��)�������� ������!
	{
	//���ñ�~ ���
	}
	*/

	unsigned char items_flag = 0;

	cout <<"No item " << bitset<8>(items_flag) << endl;  //00000000   ��Ʈ �ϳ��ϳ��� bool ������ ���°���

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

	items_flag &= ~opt3;  // ~ ����!!
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

	cout << bitset<8>(opt2 | opt3) << endl; //0000 1100  or ���ָ� ��ġ�°���
	cout << bitset<8>(items_flag) << endl;	//0000 1101

	//������ ������ for �Ἥ...

	if ((items_flag & opt2) && !(items_flag & opt1))
	{
		//items_flag ^= opt2; // 0000 0010
		//items_flag ^= opt1;	// 0000 0100

		// == 	
		items_flag ^= (opt2 | opt1); // �� ���� ������ 0 �ٸ��� 1
	}

	cout << bitset<8>(items_flag) << endl; //0000 1011


	//glClear(GL_COLOR_BUFFER_BIT); 255 255 255   #FFFFFF   255 FF 255 FF 255 FF   ���Ĵ� �� �� �ٴ� ���� �����ϸ鼭 �����...
	
	//RGB
	const unsigned int red_mask = 0xFF0000; //mask�� ������ �����ߴµ� �����ϱ�
	const unsigned int green_mask = 0x00FF00; //mask�� ������ �����ߴµ� �����ϱ�
	const unsigned int blue_mask = 0x0000FF; //mask�� ������ �����ߴµ� �����ϱ�
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