/*修改所给的程序，体会构造函数与析构函数*/
#include<iostream>  
using namespace std;
class IntArray {
public:
	IntArray(int sz);           // 数组初始化为sz个元素，初值全为0
	IntArray(int *array, int sz);  // 用静态数组array的前sz个元素初始化新数组
	IntArray(const IntArray &rhs); // 拷贝构造函数

	/*添加的析构函数部分*/
	~IntArray();    //析构函数的声明
	void common(int *array,int sz);    //形成独立的函数避免重复
	void printAll();
private:
	int *ia;
	int size;
};
IntArray::IntArray(int sz) {
	int *array = NULL;
	size = sz;         // 设置数据成员 
	common(array,size);    //调用设置的独立函数
}
IntArray::IntArray(int *array, int sz) {
	size = sz;         // 设置数据成员 
	common(array, size);    //调用设置的独立函数
}
IntArray::IntArray(const IntArray &rhs)
{
	int *array = rhs.ia;
	size = rhs.size;
	common(array, size);    //调用设置的独立函数
}
//公有部分代码，避免代码的重复性
void  IntArray::common(int *array,int size)
{
	if (array == NULL)
	{
		ia = new int[size];
		for (int ix = 0; ix < size; ++ix)
			ia[ix] = 0;    // 初始化数组元素
	}
	else
	{
		ia = new int[size];
		for (int ix = 0; ix < size; ++ix)
			ia[ix] = array[ix];    // 拷贝数据成员
	}

}
//设置析构函数，删除数组，并在成功调用析构函数打印信息到屏幕上
IntArray::~IntArray()    //析构函数的定义部分
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
