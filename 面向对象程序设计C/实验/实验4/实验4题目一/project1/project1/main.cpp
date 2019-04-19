/******编写程序，重载运算符“<<”和“>>”，使用户能直接输入和输出固定电话的号码。
电话号码以如下形式输入和输出： (027)xxxxxxxx ********************************/
#include<iostream>
#include<string>
using namespace std;
class Tel_num {
public:
	// <<和>>只能重载为友元函数
	friend istream &operator >> (istream &in, Tel_num &a) {
		cout << "请输入电话号码:";
		in >> a.number;
		cout << "请输入所在城市的区号:";
		in >> a.area_code;
		return in;
	}
	friend ostream &operator <<(ostream &out,Tel_num &a){
		cout << "输出标准电话号码如下:" << endl;
		out << "(" << a.area_code << ")" << a.number<<endl;
		return out;
	}
private:
	string area_code;
	string number;
};
int main() {
	Tel_num a;
	cin >> a;
	cout << a;
	return 0;
}