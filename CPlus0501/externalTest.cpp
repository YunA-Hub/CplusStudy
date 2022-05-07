#include <iostream>
using namespace std;

extern int TestA =1; // 초기화를 해줘야 몸체가(메모리할당이) 되는거쥬
void DoSometingTest()
{
	cout << "Hello " << endl;
}


#include "헤더.h"

void DoHeaderExternalTest()
{
	cout << "externalTest.cpp pipi" << &Constants::Pipi << endl;
}