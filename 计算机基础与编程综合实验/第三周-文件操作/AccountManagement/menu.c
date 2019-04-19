#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	//包含输入输出头文件
#include<time.h>	//包含时间头文件
#include<string.h>	//导入字符串处理函数
#include<stdlib.h>	//包含动态内存分配的头文件
#include"model.h"	//包含数据定义头文件
#include"card_service.h" //包含业务处理头文件
#include"global.h"  //包含全局定义头文件
#include"tool.h"    //包含工具头文件
#include"card_file.h"
void outputMenu(){	printf("-------------菜单-------------\n");		//输出菜单函数
	printf("1:添加卡\n2:查询卡\n3:上机\n4:下机\n5:充值\n6:退费\n7:查询统计\n8:注销\n0：退出系统\n请选择菜单项编号(0-8)：");}

int getSize(const char* pInfo)//取长度
{
	int nSize = 0;
	while(*(pInfo+nSize)!='\0')
	{
		nSize++;
	}
	return nSize;
}
void add()								 //添加卡
{
char atime[100]={0};					//初始化状态
Card card;
char aName[32]={0};
char aPwd[20]={0};
int aNamesize=0;
int aPwdsize=0;

int flag=0;

printf("请输入卡号<长度为1-18>:");		//进行卡号和密码的输入
scanf("%s",aName);
aNamesize=getSize(aName);
printf("请输入密码<长度为1-8>:");
scanf("%s",aPwd);
aPwdsize=getSize(aPwd);

if(aNamesize > 18 || aPwdsize > 8)		//判断输入是否符合要求
	{
		printf("卡号或密码超过规定长度！\n");
		return;
	}
strcpy(card.aName,aName);
strcpy(card.aPwd,aPwd);
printf("请输入开卡金额<RMB>:");
scanf("%f",&card.fBalance);
card.fTotalUse=card.fBalance;			//初始化状态
card.nDel=card.nUseCount=card.nStatus=0;
card.tStart=card.tEnd=card.tLastTime = time(NULL);
flag=addcard(card);
if(flag==1)
{
printf("-----添加的卡信息如下-------\n");
printf("卡号\t密码\t卡状态\t开卡金额\n");
printf("%s\t%s\t%d\t%.1f\t",card.aName,card.aPwd,card.nStatus,card.fBalance);}
else
	printf("添加卡失败!");

}

void query()			  //查询卡
{
	int i=0;
	int flag=0;
	char bname[50]={0};
	char atime[100]={0};
	Card* pcard = (Card*)malloc(sizeof(Card));
	printf("请输入查询的卡号<长度为1-18>:");
	scanf("%s",bname);
	flag=querycard(bname,pcard);
	if(flag==0)printf( "很抱歉，没有找到您的信息!\n");
	else{timeToString(pcard->tLastTime,atime);
	printf("卡号\t状态\t余额\t累计使用\t使用次数\t上次使用时间\n");
	printf("%s\t%d\t%0.1f\t%0.1f\t\t%d\t\t%s\n",pcard->aName,pcard->nStatus,pcard->fBalance,
		pcard->fTotalUse,pcard->nUseCount,atime);}

		
}
void loggon(){}           //上机
void settle(){};          //下机
void addMoney(){};        //充值
void refundMoney(){};     //退费
void statistics(){};      //查询统计
void annul(){};           //注销
void exitApp(){};         //退出应用程序