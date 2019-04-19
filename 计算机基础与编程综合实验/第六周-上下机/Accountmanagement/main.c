#define _CRT_SECURE_NO_WARNINGS   // 消除VS开发环境中，使用scanf()函数引发的警告
                                  // Disable the scanf() function warning in VS

#include <stdio.h>    // 包含输入输出头文件  // Include stdio.h header file

#include "menu.h"     // 包含menu.h文件  // Include menu.h header file

int main()
{
	int nSelection = -1;   // 输入菜单项编号  // Input menu item number

	//输出系统名称“欢迎进入计费管理系统”
	// 提示用户消费信息
	printf("----------欢迎进入计费管理系统-----------\n\n");
	printf("！！！！！！！！！！！！！！！！！\n");
	printf("说明：本店上网费用为每秒0.5元\n如果你感觉太贵，请到隔壁老王家消费,同时祝您玩得开心\n");
	printf("\n");

	do
	{
		//输出系统菜单
		outputMenu();
		
		// 初始化选择的菜单项编号为-1
		nSelection = -1; 

		// 输入菜单项编号
		scanf("%d",&nSelection);

		// 清除输入流缓存
		fflush(stdin);

		//输出选择的菜单编号
		switch(nSelection)
		{

		case 1:  // 添加卡
			{
				add();
				break;
			}
		case 2:  // 查询卡
			{
				query();
				break;
			}
		case 3:  // 上机
			{
				logon();
				break;
			}
		case 4:  // 下机
			{
				settle();
				break;
			}
		case 5:  // 充值
			{
				addMoney();
				break;
			}
		case 6:  // 退费
			{
				refundMoney();
				break;
			}
		case 7:  // 查询统计
			{
				printf("查询统计\n");
				break;
			}
		case 8:  // 注销卡
			{
				annul();
				break;
			}
		case 0:   // 退出
			{
				exitApp();
				break;
			}
		default:
			{
				printf("输入的菜单编号错误！\n");
				break;
			}
		}
		printf("\n");
	}
	while(nSelection != 0);

	return 0;
}