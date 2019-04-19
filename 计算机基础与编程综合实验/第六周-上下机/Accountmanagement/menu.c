#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>   // 包含输入输出头文件
#include <time.h>    // 包含时间头文件
#include <string.h>  // 导入字符串处理函数
#include <stdlib.h>  // 包含动态内存分配头文件
#include <time.h>    //包含时间处理头文件
#include "model.h"   // 包含数据定义头文件
#include "service.h"     // 包含业务处理头文件
#include "global.h"      // 包含全局定义头文件
#include "tool.h"        // 包含工具头文件
#include "card_service.h"
#include "card_file.h"

int getSize(const char* pInput);                          // 声明getSize()函数
/*****************************************************
[函数名] outputMenu
[功能] 输出系统菜单
[参数] void
[返回值] void
*****************************************************/
void outputMenu()
{
	printf("----------菜单----------\n");
	printf("1.添加卡\n");
	printf("2.查询卡\n");
	printf("3.上机\n");
	printf("4.下机\n");
	printf("5.充值\n");
	printf("6.退费\n");
	printf("7.查询统计\n");
	printf("8.注销卡\n");
	printf("0.退出\n\n");
	
	//提示选择菜单编号
	printf("请输入菜单项编号（0~8）：");
}

/*************************************************
[函数名] add
[功能]  添加卡
[参数]  void
[返回值] void
*************************************************/
void add()
{
	char aName[32] = {0};   // 输入的卡号
	char aPwd[20] = {0};    // 输入的密码
	Card card;              // 卡信息
	struct tm* endTime;     // 截止时间
	struct tm* startTime;   // 开卡时间
	
	printf("----------添加卡----------\n");

	// 提示并接收输入的卡号
	printf("请输入卡号(长度为1~18)：");
	scanf("%s", aName);

	// 判断输入的卡号是否符合要求
	if(getSize(aName) >= 18)
	{
		printf("输入的卡号长度超过最大值！\n");
		return;
	}

	// 将输入的卡号保存到卡结构体中
	strcpy(card.aName, aName);

	// 提示并接收输入密码
	printf("请输入密码(长度为1~8)：");
	scanf("%s", aPwd);

	// 判断输入的密码是否符合要求
	if(getSize(aPwd) >= 8)
	{
		printf("输入的密码长度超过最大值！\n");
		return;
	}

	// 将输入的密码保存到卡结构体中
	strcpy(card.aPwd, aPwd);

	printf("请输入开卡金额(RMB)：");
	scanf("%f", &card.fBalance);

	card.fTotalUse = card.fBalance;    // 添加卡时，累计金额等于开卡金额
	card.nDel = 0;                     // 删除标识
	card.nStatus = 0;                  // 卡状态
	card.nUseCount = 0;                // 使用次数
	card.tStart = card.tEnd = card.tLast = time(NULL);  // 开卡时间，截止时间，最后使用时间都默认为当前时间。

	// 根据开卡时间，计算截止时间，每张卡的有效期为一年
	startTime = localtime(&card.tStart);
	endTime = localtime(&card.tEnd);
	endTime->tm_year = startTime->tm_year + 1;
	card.tEnd = mktime(endTime);

	if(FALSE == addCardInfo(card))
	{
		printf("添加卡信息失败！\n");
	}
	else
	{
		printf("添加卡信息成功！\n");
	}

}

/*************************************************
[函数名] getSize
[功能]  获取pInput所指向的字符串的字符数量
[参数]  pInput:需要求字符数的字符串
[返回值] int: 字符串中字符的个数
*************************************************/
int getSize(const char* pInput)
{
	int nSize = 0;

	// 计算字符串的字符个数
	while(*(pInput + nSize) != '\0')
	{
		nSize++;
	}

	// 返回字符个数
	return nSize;
}

/*************************************************
[函数名] query
[功能]  查询卡
[参数]  void
[返回值] void
*************************************************/
void query()
{
	char aName[18] = {0};  // 保存输入的卡号
	Card* pCard = NULL;    // 保存查询到的卡信息
	char aLastTime[TIMELENGTH] = {0};
	int nIndex = 0;         // 卡查询到的信息数量
	int i = 0;

	printf("----------查询卡----------\n");

	// 提示并接收输入的卡信息
	printf("请输入查询的卡号(长度为1~18):");
	scanf("%s", aName);

	// 查询卡
	pCard = queryCardInfo(aName, &nIndex);

	// 如果pCard为NULL，表示没有该卡的信息
	if(pCard == NULL )
	{
		printf("没有该卡的信息！\n");
	}
	else
	{
		// 输出表格的表头
		printf("卡号\t状态\t余额\t累计使用\t使用次数\t上次使用时间\n");
		for(i = 0; i < nIndex; i++)
		{
			timeToString(pCard[i].tLast, aLastTime);
			printf("%s\t%d\t%0.1f\t%0.1f\t\t%d\t\t%s\n", pCard[i].aName, pCard[i].nStatus, pCard[i].fBalance, 
				pCard[i].fTotalUse, pCard[i].nUseCount, aLastTime);
		}
		// 释放动态分配的内存
		free(pCard);
		pCard = NULL;
	}
}

/*************************************************
[函数名] logon
[功能]  上机
[参数]  void
[返回值] void
*************************************************/
void logon()
{
	char aName[20]={0};
	char aPwd[8]={0};
	Card* pCard=NULL;
	//接收用户输入的信息
	printf("您好，请输入您要上机的卡号:");
	scanf("%s",aName);
	printf("请输入您卡号对应的密码:");
	scanf("%s",aPwd);
	printf("----------上机----------\n");
	pCard=doLogon(aName,aPwd);
	//进行上机
	if(pCard!=NULL)
	{
		// 输出表格的表头
		printf("上机成功\n");
		printf("卡号\t状态\t余额\t累计使用\t使用次数\t\n");
		printf("%s\t%d\t%0.1f\t%0.1f\t\t%d\t\n", pCard->aName, pCard->nStatus, pCard->fBalance, 
			pCard->fTotalUse, pCard->nUseCount);
		// 释放动态分配的内存
			    
	}
	else
	{
		printf("上机失败，请检查你输入的账号密码");
	}

	
}

/*************************************************
[函数名] settle
[功能]  下机
[参数]  void
[返回值] void
*************************************************/
void settle()
{ 
	
	char aName[20]={0};
	char aPwd[8]={0};
	
	//接收用户输入的信息
	printf("--------------------下机----------------------\n");
	printf("您好，请输入您要下机的卡号:");
	scanf("%s",aName);
	printf("请输入您卡号对应的密码:");
	scanf("%s",aPwd);
	if(TRUE == dosettle(aName,aPwd))
	{
		printf("下机成功\n");
	}
	else
	{
		printf("下机失败，请检查您输入的账号密码\n");
	}
	return;
}

/*************************************************
[函数名] annul
[功能]  注销卡
[参数]  void
[返回值] void
*************************************************/
void annul()
{
	printf("----------注销卡---------\n");
}

/*************************************************
[函数名] addMoney
[功能]  充值
[参数]  void
[返回值] void
*************************************************/
void addMoney()
{
	printf("----------充值----------\n");
}

	
/*************************************************
[函数名] refundMoney
[功能]  退费
[参数]  void
[返回值] void
*************************************************/
void refundMoney()
{
	printf("----------退费----------\n");
}

/*************************************************
[函数名] exitApp
[功能]  退出应用程序
[参数]  void
[返回值] void
*************************************************/
void exitApp()
{

}