/******��д���������������<<���͡�>>����ʹ�û���ֱ�����������̶��绰�ĺ��롣
�绰������������ʽ���������� (027)xxxxxxxx ********************************/
#include<iostream>
#include<string>
using namespace std;
class Tel_num {
public:
	// <<��>>ֻ������Ϊ��Ԫ����
	friend istream &operator >> (istream &in, Tel_num &a) {
		cout << "������绰����:";
		in >> a.number;
		cout << "���������ڳ��е�����:";
		in >> a.area_code;
		return in;
	}
	friend ostream &operator <<(ostream &out,Tel_num &a){
		cout << "�����׼�绰��������:" << endl;
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