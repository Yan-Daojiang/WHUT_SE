#include <stdio.h>//包含输入输出头文件
#include <time.h>//包含时间头文件
#include <string.h> //包含字符串处理函数
#include <stdlib.h>//包含动态内存分配头文件

#include "model.h"//包含数据定义头文件
#include "service.h"//包含业务处理头文件
#include "global.h"//包含全局定义头文件
#include "tool.h"//包含工具头文件

#define _CRT_SECURE_NO_WARINGS
void cardService(Card card);
/************************
【函数名】outputMenu
【功能】输出系统菜单
【参数】void
【返回值】void
*************************/
void outputMenu()
{
	printf("--------------菜单------------\n");
	printf("1.添加卡\n");
	printf("2.查询卡\n");
	printf("3.上机\n");
	printf("4.下机\n");
	printf("5.充值\n");
	printf("6.退费\n");
	printf("7.查询统计\n");
	printf("8.注销卡\n");
	printf("0.退出\n");
	printf("请输入菜单编号(0~8):");
}
/************************
【函数名】add
【功能】添加卡
【参数】void
【返回值】void
*************************/
void add( )
{    
	/*将卡信息添加到结构体重*/
	Card card;
	printf("--------添加卡--------\n");
	printf("请输入卡号<长度1~18>:");
	scanf("%s",card.aName);
	printf("请输入密码<长度1~8>:");
	scanf("%s",card.aPwd);
	printf("请输入开卡金额<RMB>:");
	scanf("%f",&card.fBalance);
	card.fTotalUse=card.fBalance;
	card.nDel=0;//删除标识
	card.nUseCount=0;//使用次数
	card.nStaus=0;//卡状态
	card.tStart=card.tEnd=card.tLastTime=time(NULL);/*将开卡时间，截止时间，最后使用时间设为系统默认时间*/
	printf("----------------添加卡信息如下-------------------\n");
	printf("卡号\t密码\t状态\t开卡金额\n");
	printf("%s\t%s\t%d\t%0.1f\n",card.aName,card.aPwd,card.nStaus,card.fBalance);
	cardService(card);
}
int i=0;
Card aCard[50];
void cardService(Card card)
{
    aCard[i]=card;
	i=i+1;
}


/************************
【函数名】query
【功能】查询卡
【参数】void
【返回值】void
*************************/
void query()
{    
	int index=0;
	int a;
	char numCard[8];/*保存要查询的卡号*/
	printf("请输入查询卡卡号：");
	scanf("%s",numCard);/*从键盘接收要查询的卡号*/
	for(index=0;index<i;index++)/*利用循环对结构体数组进行循环查找*/
	{
	    if(strcmp(numCard,aCard[index].aName)==0)
		{
			a=1;
			break;
		}
		else
		{
			a=0;
		}
	}
	if(a==1)
	{
	    char time[24];
	    timeToString( aCard[index].tLastTime,time);
	    printf("--------------------您查询的卡包含如下的信息-------------------------\n");/*以水平表格的形式对查询的信息进行输出*/
		printf("卡号\t状态\t金额\t累计使用\t使用次数\t上次使用时间\n");
		printf("%s\t%d\t%.2f\t%.2f\t\t%d\t\t%s\n",aCard[index].aName,aCard[index].nStaus,aCard[index].fBalance,aCard[index].fTotalUse-aCard[index].fBalance,aCard[index].nUseCount,time);
	}
	else
	{
		printf("没有该卡的信息！");
	}
}
/************************
【函数名】exitApp
【功能】退出系统
【参数】void
【返回值】void
*************************/
void exitApp()
{
	printf("你确定退出系统吗？？？<请选择1或者2>\n");
	printf("1.确定 2.取消");
}
/************************
【函数名】logon
【功能】上机
【参数】void
【返回值】void
*************************/
void logon()
{
	printf("上机时间：");
}
/************************
【函数名】settle
【功能】下机
【参数】void
【返回值】void
*************************/
void settle()
{
	printf("下机时间：");
}
/************************
【函数名】annul
【功能】注销卡
【参数】void
【返回值】void
*************************/
void annul()
{
	printf("你确定注销卡吗？？？<请选择1或者2>\n");
	printf("1.确定 2.取消");
}
/************************
【函数名】addMoney
【功能】充值
【参数】void
【返回值】void
*************************/
void addMoney()
{
	printf("请输入充值金额:<RMB>:");
}
/************************
【函数名】refunMoney
【功能】退费
【参数】void
【返回值】void
*************************/
void refunMoney()
{
	printf("退费金额<RMB>:");
}
/************************
【函数名】count
【功能】查询统计
【参数】void
【返回值】void
*************************/
void count()
{}
