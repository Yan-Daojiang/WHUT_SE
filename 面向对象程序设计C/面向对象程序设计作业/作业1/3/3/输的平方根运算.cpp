/*������ĳһ������ƽ�������������ú������طֱ��������͡�ʵ�ͺ�˫����������*/
#include<iostream>
using namespace std;
#include<math.h>
int sq(int i)
{
	return sqrt(i);
}
float sq(float j)
{
	return sqrt(j);
}
double sq(double k)
{
	return sqrt(k);
}
int main()
{
	int i=16;
	float j=2.25;
	double k=1.123456789101112;
	cout<<"i��ƽ������" << sq(i) << endl;
	cout<< "jƽ������" << sq(j) << endl;
	cout<< "kƽ������" << sq(k) << endl;
}