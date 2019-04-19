#include <string.h> // 包含字符处理头文件
#include <stdlib.h> // 包含动态内存分配头文件
#include <time.h>   // 包含时间处理头文件

#include "model.h"  // 包含数据定义头文件
#include "global.h" // 包含全局定义头文件
#include "card_file.h" // 包含文件处理头文件

lpCardNode cardList = NULL;    // 卡信息链表
int getCard();                 // 声明getCard()函数

/*************************************************
[函数名] initCardList
[功能]  初始化卡信息链表
[参数]  void
[返回值] int型，TRUE表示成功，FALSE表示失败
*************************************************/
int initCardList()
{
	lpCardNode head = NULL;
	if(cardList == NULL)
	{
		// 为链表头结点分配内存
		head = (lpCardNode)malloc(sizeof(CardNode));

		// 如果分配成功，则将链表指向
		if(head != NULL)
		{
			head->next = NULL;
			cardList = head;
			return TRUE;
		}

	}
	return FALSE;
}

/*************************************************
[函数名] releaseCardList
[功能]  释放卡信息链表
[参数]  void
[返回值] void
*************************************************/
void releaseCardList()
{
	lpCardNode cur = cardList;   
	lpCardNode next = NULL;

	while(cur != NULL)
	{
		next = cur->next;  // 释放cur结点前，用next保存它的后继结点
		free(cur);         // 释放cur结点
		cur = next;
	}
	cardList = NULL;
}


/*************************************************
[函数名] queryCards
[功能]  在卡信息链表中，查询卡号相同的卡信息
[参数]  pName:要查询的卡的卡号
       pIndex:查询到的卡信息数量的指针
[返回值] Card*:查询到的卡信息的指针
*************************************************/
Card* queryCards(const char* pName, int* pIndex)
{
	lpCardNode node = NULL;
	Card* pCard = NULL;

	// 从文件中，获取卡信息
	if(getCard() == FALSE)
	{
		return NULL;
	}

	// 首先分配一个Card大小内存空间
	pCard = (Card*)malloc(sizeof(Card));
	if(pCard == NULL)
	{
		return NULL;
	}

	// 从链表的头结点指向的下一个结点开始遍历
	node = cardList->next;

	// 遍历链表，结点为空表示到达链表尾部
	while(node != NULL)
	{
		// 判断在遍历到的结点的卡号中，查找是否包含pName字符串
		if(strstr(node->data.aName, pName) != NULL)
		{
			// 如果有，则保存结点中的数据
			pCard[*pIndex] = node->data;
			(*pIndex)++;

			// 重新为指针分配内存
			pCard = (Card*)realloc(pCard, ((*pIndex)+1)*sizeof(Card));
		}

		// 移到链表的下一个结点
		node = node->next;
	}

	return pCard;
}

/*************************************************
[函数名] getCard
[功能]  从卡信息文件中，获取卡信息，保存到链表中
[参数]  void
[返回值] int: FALSE 获取失败，TRUE，获取成功
*************************************************/
int getCard()
{
	int nCount = 0;      // 卡信息数
	int i = 0;
	Card* pCard = NULL;  //  卡信息
	lpCardNode node = NULL;  // 结点信息
	lpCardNode cur = NULL;   // 添加到链表中的结点

	// 清除链表中已经存在的数据
	if(cardList != NULL)
	{
		releaseCardList();
	}

	// 初始化链表
	initCardList();

	// 获取卡信息个数
	nCount = getCardCount(CARDPATH);

	if(nCount == 0)
	{
		return FALSE;
	}

	// 动态分配内存保存卡信息
	pCard = (Card*)malloc(sizeof(Card)*nCount);
	if(pCard != NULL)
	{
		// 如果返回FALSE，表示读取卡信息失败
		if(0 == readCard(pCard, CARDPATH))
		{
			free(pCard);
			return FALSE;
		}

		// 将读取的卡信息，保存到链表中
		for(i = 0, node = cardList; i < nCount; i++)
		{
			// 为结点分配内存
			cur = (lpCardNode)malloc(sizeof(CardNode));

			// 如果分配内存失败，则返回
			if(cur == NULL)
			{
				free(pCard);
				return FALSE;
			}
			// 初始化新的空间，全部赋值为0
			memset(cur, 0, sizeof(CardNode));

			// 将卡信息保存到结点中
			cur->data = pCard[i];
			cur->next = NULL;

			// 将结点添加到链表尾部
			node->next = cur;
			node = cur;
		}
		// 释放内存
		free(pCard);
		return TRUE;
	}
	return FALSE;
}

/*************************************************
[函数名] checkCard
[功能]  根据卡号和密码，在链表中查询卡信息，并获取查询到的卡信息在链表中的位置
[参数]  pName:上机卡的卡号
       pPwd: 上机卡密码
	   pIndex: 上机卡在卡信息链表中的索引的指针
[返回值] Card*: 符合上机的卡信息结构体指针
*************************************************/
Card* checkCard(const char* pName, const char* pPwd, int* pIndex)
{
	lpCardNode cardNode = NULL; 
	int nIndex = 0;             // 上机卡在卡信息链表中的索引号

	// 如果从文件中获取卡信息失败，则上机失败
	if(FALSE == getCard())
	{
		return FALSE;
	}

	// 获取链表的第一个结点
	cardNode = cardList->next;

	// 遍历链表
	while(cardNode != NULL)
	{
		// 判断卡号和密码是否正确
		if((strcmp(cardNode->data.aName, pName) == 0 ) && (strcmp(cardNode->data.aPwd, pPwd) == 0 ))
		{
			// 返回卡信息结点数据的地址
			*pIndex = nIndex;
			return &cardNode->data;
		}
		cardNode = cardNode->next;
		nIndex++;

	}

	return NULL;
}