#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "menu.h"
long num;
struct Student *pt;
int main(void)
{
	struct Student *head=NULL;
	int nSection = -1;    //输入菜单项编号
	printf("\n欢迎进入学生管理系统");
	printf("\n");
	do
	{
		//输出系统菜单
		outmenu();
		nSection = -1;
		scanf_s("%d", &nSection);
		//输出选择菜单的编号
		switch (nSection)
		{
		case 1://新建学生信息输出并且进行查找
		{
			
			pt=creat();
			print(pt);
			break;
		}
		case 2:
		{
			printf("请输入您要查找的学生编号:");
			scanf_s("%ld",&num);
			find(pt,num);
			break;
		}
		default:
		{
			printf("输入菜单编号错误\n");
			break;
		}
		}
		printf("\n");
	} while (nSection != 0);

	
}









