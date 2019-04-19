#include<stdio.h>
#include <string.h> // 包含字符处理头文件
#include <stdlib.h> // 包含动态内存分配头文件
#include <time.h>   // 包含时间处理头文件

#include "model.h"  // 包含数据定义头文件
#include "global.h" // 包含全局定义头文件
#include "card_file.h" // 包含文件处理头文件
#include "model.h"
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
/***********************************
【函数名称】上机
【功能】检查卡号密码进行上机，并对上机的卡进行消费计时
【参数】const char* pName,const char *pPwd
************************************/

Card* doLogon(const char* pName,const char *pPwd)
{
	lpCardNode cardNode=NULL;
	int nIndex=0;   //定义索引号
	//获取文件中的卡信息
	if(FALSE==getCard())
	{
		return NULL;//表示获取失败
	}
	cardNode=cardList->next;
	//遍历链表，根据卡号密码匹配判断能否进行上机
	while(cardNode!=NULL)
	{
		if(strcmp(cardNode->data.aName,pName)==0&&strcmp(cardNode->data.aPwd,pPwd)==0)
		{
			//如果找到了就要更新链表中的信息
			cardNode->data.nStatus=1;    //更新状态
			cardNode->data.nUseCount++;    //更新使用的次数
			cardNode->data.tLast=time(NULL);   //更新最后使用的时间为当前时间
			//如果能够进行上机，更新文件信息
			if(updateCard(&cardNode->data,CARDPATH,nIndex))
			{
				//返回卡信息
			    return &cardNode->data;
			}	
		}
		cardNode=cardNode->next;
		nIndex++;
	}
	return NULL;
}
/***************
[函数名称]下机
[功能]对已上机的卡进行下机，并对卡余额进行结算
[参数]const char* pName,const char* pPwd
****************/
int dosettle(const char* pName,const char* pPwd)
{
	lpCardNode cardNode = NULL;
	int nIndex = 0;
	//存储时间差
	float cost;
	time_t nowTime = 0;
	time_t aTime = 0;
	//获取文件中的卡信息
	if(FALSE == getCard())
	{
		return FALSE; 
	}

	cardNode = cardList->next;
	//遍历链表，判断能否进行下机
	while(cardNode != NULL)
	{
		if(strcmp(cardNode->data.aName,pName) == 0 && strcmp(cardNode->data.aPwd,pPwd) == 0)
		{
			//只有状态为正在使用的卡才能下机
			if(cardNode->data.nStatus != 1)
			{
				return FALSE;
			}			
			//计算消费额度（时间差）
			
			nowTime = time(NULL);
			cost = difftime(nowTime,cardNode->data.tLast);
			
			cost = cost*CHARGE;
			printf("您本次上机消费%.1f\n",cost);
			//更新链表中的信息

			cardNode->data.nStatus = 0;
			cardNode->data.tLast = time(NULL);
			cardNode->data.fBalance = cardNode->data.fBalance - cost;
			//如果可以下机，更新文件卡信息
			if(updateCard(&cardNode->data,CARDPATH,nIndex) == TRUE)
			{
				return TRUE;
			}                             
			
		}
		cardNode = cardNode->next;
		nIndex++;
	}
	return FALSE;
}

/****************************
[函数名称]充值
[功能]对指定的账户进行充值
[参数]const char* pName,const char* pPwd
******************************/
int Recharge(const char* pName,const char* pPwd)
{
	lpCardNode cardNode = NULL;
	float charge = 0;

	int nIndex = 0;
	//获取文件中的卡信息
	if(FALSE == getCard())
	{
		return FALSE; 
	}

	cardNode = cardList->next;
	//遍历链表，判断能否进行充值
	while(cardNode != NULL)
	{
		if(cardNode->data.nStatus == 2)	;

		if(strcmp(cardNode->data.aName,pName) == 0 && strcmp(cardNode->data.aPwd,pPwd) == 0)
		{
			printf("！！！！！！！！！！！！！！优惠！！！！！！！！！！！！！！\n");
			printf("一次充值大于100元可以获赠10元\n");
			printf("请输入充值的金额：");
			scanf("%f",&charge);
			if(charge>=100){
				charge=charge+10;
			}
			//更新链表中的信息
			cardNode->data.fBalance += charge;
			//如果可以充值，更新文件卡信息

			if(updateCard(&cardNode->data,CARDPATH,nIndex) == TRUE)
			{
				return TRUE;
			}                             
			
		}
		cardNode = cardNode->next;
		nIndex++;
	}
	return FALSE;
}
/*********************
[函数名称]退费
[功能]检查账户余额。若余额大于0则可以进行退费
[参数]const char* pName,const char* pPwd
**********************/
int Refund(const char* pName,const char* pPwd)
{
	lpCardNode cardNode = NULL;
	float charge = 0;

	int nIndex = 0;
	//获取文件中的卡信息
	if(FALSE == getCard())
	{
		return FALSE; 
	}

	cardNode = cardList->next;
	//遍历链表，判断能否进行退费
	while(cardNode != NULL)
	{
		if(strcmp(cardNode->data.aName,pName) == 0 && strcmp(cardNode->data.aPwd,pPwd) == 0)
		{
			printf("退费金额：%.1f\n",cardNode->data.fBalance);
			
			//更新链表中的信息
			cardNode->data.fBalance = 0.0;
			//如果可以退费，更新文件卡信息

			if(updateCard(&cardNode->data,CARDPATH,nIndex) == TRUE)
			{
				return TRUE;
			}                             
			
		}
		cardNode = cardNode->next;
		nIndex++;
	}
	return FALSE;
}

/********************
[函数名称]注销卡
[功能]改变卡的状态，使查询不到这张卡
[参数]const char* pName,const char* pPwd
**********************/
int move(const char* pName,const char* pPwd)
{
	lpCardNode cardNode = NULL;
	int nIndex = 0;
	//获取文件中的卡信息
	if(FALSE == getCard())
	{
		return FALSE; 
	}

	cardNode = cardList->next;
	//遍历链表，判断能否进行注销
	while(cardNode != NULL)
	{
		if(strcmp(cardNode->data.aName,pName) == 0 && strcmp(cardNode->data.aPwd,pPwd) == 0)
		{
			//只有状态为未使用的卡才能注销，注销卡余额应大于0
			if(cardNode->data.nStatus != 0)
			{
				return FALSE;
			}
			if(cardNode->data.fBalance < 0)
			{
				return FALSE;
			}
			//更新链表中的信息
			printf("卡号：\t退费金额\n");
			printf("%s\t%.1f\n",cardNode->data.aName,cardNode->data.fBalance);

			
			cardNode->data.nStatus = 2;
			printf("卡状态：%d\n",cardNode->data.nStatus);
			cardNode->data.fBalance = 0.0;
			//如果可以注销，更新文件卡信息

			if(updateCard(&cardNode->data,CARDPATH,nIndex) == TRUE)
			{
				return TRUE;
			}                             
			
		}
		cardNode = cardNode->next;
		nIndex++;
	}
	return FALSE;
}

/**************************
[函数名称]valu
[功能]找出余额较多的用户作为星级用户
[参数] pIndex
****************************/
Card* stars( int* pIndex)
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
		if(node->data.fBalance>500)
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
