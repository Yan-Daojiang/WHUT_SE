#include <stdio.h>//包含输入输出头文件
#include <time.h>//包含时间头文件
#include <string.h> //包含字符串处理函数
#include <stdlib.h>//包含动态内存分配头文件

#include "model.h"//包含数据定义头文件
#include "service.h"//包含业务处理头文件
#include "global.h"//包含全局定义头文件
#include "tool.h"//包含工具头文件
#define _CRT_SECURE_NO_WARINGS     
void addCard(Card card)
{
	Card aCard[50];//卡信息结构体数组
	int nCount=0;//卡信息数
	aCard[0]=card;
	printf("%s",aCard[0]);

}