#include <iostream>
using namespace std;

extern int TestA =1; // �ʱ�ȭ�� ����� ��ü��(�޸��Ҵ���) �Ǵ°���
void DoSometingTest()
{
	cout << "Hello " << endl;
}


#include "���.h"

void DoHeaderExternalTest()
{
	cout << "externalTest.cpp pipi" << &Constants::Pipi << endl;
}