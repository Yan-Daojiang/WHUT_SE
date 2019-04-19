/*********************对文件中的样本字符创进行匹配**************/
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main() {
    fstream in;//创建文件对象，采用C++中流的方式对文件进行读取
    in.open("../data/data.txt");//读取文件中的内容到文件对象中,文件路径为相对路径
    char s[1000];
    int i = 0;
    while (in) {
        in.get(s[i]);//获取文件中的字符保存到一个字符数组中
        i++;
    }
    string str(s, i-1);//将文件中的字符串按照一定的顺序存到一个字符串中
    string str1 = "Chinese";
    cout << "文件中的文本内容是：" << str << endl;
    cout << "要进行匹配的字符串是:" << str1 << endl;
    int position = str.find(str1);
    if (position != str.npos) {
        //利用C++中的特别标志npos进行判断是否成功进行了匹配
        cout << "能够成功匹配,首个匹配的位置是：" << position << endl;//能成功的匹配就输出首字母的位置
    }
    else
        cout << "不能够成功匹配" << endl;
}