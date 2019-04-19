#include<stdio.h>
#include"menu.h"
#include"global.h"
#include"model.h"
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{int nSelection;                                     //输入菜单项编号 //Input menu item number
	printf("\n欢迎进入计费管理系统！\n");
	printf("\n");
	do{
		outputMenu();                               //输出系统菜单
		nSelection=-1;
		scanf("%d",&nSelection);		           //输入选择的菜单编号                              
		
		switch(nSelection)
		{
		case 1:{printf("添加卡\n");add();break;}           //添加卡
		case 2:{printf("查询卡\n");query();break;}         //查询卡   
		case 3:{printf("上机\n");loggon();break;}          //上机    
		case 4:{printf("下机\n");settle();break;}          //下机 
		case 5:{printf("充值\n");addMoney();break;}        //充值
		case 6:{printf("退费\n");refundMoney();break;}     //退费
		case 7:{printf("查询统计\n");statistics();break;}  //查询统计
		case 8:{printf("\n注销\n");annul();break;}         //注销	   
		case 0:{exitApp();break;}                          //退出	
		default:{printf("\n输入的菜单编号错误！请重新输入\n");break;}
		}
		printf("\n");
	}
		while(nSelection!=0);
		
	return 0;
}

