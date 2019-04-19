/*�޸������ĳ�����ṹ�캯������������*/
#include<iostream>  
using namespace std;
class IntArray {
public:
	IntArray(int sz);           // �����ʼ��Ϊsz��Ԫ�أ���ֵȫΪ0
	IntArray(int *array, int sz);  // �þ�̬����array��ǰsz��Ԫ�س�ʼ��������
	IntArray(const IntArray &rhs); // �������캯��

	/*��ӵ�������������*/
	~IntArray();    //��������������
	void common(int *array,int sz);    //�γɶ����ĺ��������ظ�
	void printAll();
private:
	int *ia;
	int size;
};
IntArray::IntArray(int sz) {
	int *array = NULL;
	size = sz;         // �������ݳ�Ա 
	common(array,size);    //�������õĶ�������
}
IntArray::IntArray(int *array, int sz) {
	size = sz;         // �������ݳ�Ա 
	common(array, size);    //�������õĶ�������
}
IntArray::IntArray(const IntArray &rhs)
{
	int *array = rhs.ia;
	size = rhs.size;
	common(array, size);    //�������õĶ�������
}
//���в��ִ��룬���������ظ���
void  IntArray::common(int *array,int size)
{
	if (array == NULL)
	{
		ia = new int[size];
		for (int ix = 0; ix < size; ++ix)
			ia[ix] = 0;    // ��ʼ������Ԫ��
	}
	else
	{
		ia = new int[size];
		for (int ix = 0; ix < size; ++ix)
			ia[ix] = array[ix];    // �������ݳ�Ա
	}

}
//��������������ɾ�����飬���ڳɹ���������������ӡ��Ϣ����Ļ��
IntArray::~IntArray()    //���������Ķ��岿��
{
	cout << "Destructor called" << endl;
	delete ia;
}

void IntArray::printAll()
{
	for (int ix = 0; ix < size; ++ix)
		cout << ia[ix] << "  ";
	cout << endl;
}
int main()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	IntArray arr1(10), arr2(a, 5), arr3(arr2);
	arr1.printAll();
	arr2.printAll();
	arr3.printAll();
	return 0;
}
