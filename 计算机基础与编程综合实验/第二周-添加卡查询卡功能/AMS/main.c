#include "menu.h"
#define _CRT_SECURE_NO_WARNINGS
int main()
{
	int nSection = -1;    //输入菜单项编号
	printf("欢迎进入计费管理系统");
	printf("\n");
	do
	{
		//输出系统菜单
		outputMenu();
		nSection = -1;
		scanf_s("%d", &nSection);
		//输出选择菜单的编号
		switch (nSection)
		{
		case 1://添加卡
		{
			add();
			
			break;
		}
		case 2://查询卡
		{
			query();
			break;
		}
		case 3://上机
		{
			logon();
			break;
		}
		case 4://下机
		{
			settle();
			break;
		}
		case 5://充值
		{
			addMoney();
			break;
		}
		case 6://退费
		{
			refunMoney();
			break;
		}
		case 7://查询统计
		{
			count();
			break;
		}
		case 8://注销卡
		{
			annul();
			break;
		}
		case 0://退出应用程序
		{
			exitApp();
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

	return 0;
}