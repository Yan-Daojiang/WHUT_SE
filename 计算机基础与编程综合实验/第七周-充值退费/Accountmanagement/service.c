#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>          // 
#include <time.h>           // 包含时间处理头文件
#include <string.h>         // 包含字符串处理头文件

#include "card_service.h"   // 包含卡业务逻辑处理头文件
#include "model.h"          // 包含数据类型定义头文件
#include "global.h"         // 包含全局定义头文件
#include "card_file.h"      // 包含卡文件处理头文件
#include "service.h"

/*************************************************
[函数名] addCardInfo
[功能]  添加卡信息
[参数]  card:添加的卡信息结构体
[返回值] int型，TRUE表示添加成功，FALSE表示添加失败
*************************************************/
int addCardInfo(Card card)
{
	// 判断卡号是否已经存在
	if (isExsit(card.aName, CARDPATH) == TRUE)
	{
		return FALSE;
	}

	// 将卡信息保存到文件中
	if(TRUE == saveCard(&card, CARDPATH))
	{
		return TRUE;
	}

	return FALSE;
}

/*************************************************
[函数名] queryCardInfo
[功能]  查询卡信息
[参数]  pName:需要查询的卡号
	   pIndex:查询到的卡信息数量的指针
[返回值] Card*: 查询到的卡信息指针
*************************************************/
Card* queryCardInfo(const char* pName, int* pIndex)
{
	Card* pCard = NULL;
	pCard = queryCards(pName, pIndex);

	return pCard;
}
/*************************************************
[函数名] queryCardInfo
[功能]  星级用户信息
[参数]    pIndex:查询到的卡信息数量的指针
[返回值] Card*: 查询到的卡信息指针
*************************************************/

Card* CardInfo( int* pIndex)
{
	Card* pCard = NULL;
	pCard = stars(pIndex);

	return pCard;
}

/*************************************************
[函数名] releaseList
[功能]  退出应用程序时，释放链表内存
[参数]  void
[返回值] void
*************************************************/
void releaseList()
{
	releaseCardList();      // 释放卡信息链表内存
//	releaseBillingList();   // 释放计费信息链表内存
}