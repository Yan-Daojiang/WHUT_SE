#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>    // 包含文件结构体头文件
#include <string.h>   // 包含字符处理头文件
#include <stdlib.h>   // 包含standard library标准库头文件

#include "model.h"    // 包含数据类型定义头文件
#include "global.h"   // 包含全局定义头文件
#include "tool.h"     // 包含工具头文件

/*************************************************
[函数名] saveCard
[功能]  将卡信息保存到文件中
[参数]  pCard：需要保存到卡信息中的卡结构体指针
        pPath：保存卡信息的文件路径
[返回值] int型，TRUE表示成功，FALSE表示失败
*************************************************/
int saveCard(const Card* pCard, const char* pPath)
{
	FILE* fp = NULL;   // 文件结构体指针

	// 以追加的模式打开文件，如果打开失败，则以只写的模式打开文件
	if((fp = fopen(pPath,"ab")) == NULL)
	{
		if((fp = fopen(pPath,"wb")) == NULL)
		{
			return FALSE;
		}
	}

	fwrite(pCard, sizeof(Card), 1, fp);

	// 关闭文件
	fclose(fp);
	return TRUE;
}

/*************************************************
[函数名] readCard
[功能]  从文件中读取卡信息
[参数]  pCard：从文件读取的卡信息结构体指针
        pPath：读取的文件路径
[返回值] int型，TRUE表示成功，FALSE表示失败
*************************************************/
int readCard(Card* pCard, const char* pPath)
{
	FILE* fp = NULL;  // 文件结构体指针
	int nIndex = 0;   // 卡信息数量

	// 以只读的方式打开文件
	if((fp = fopen(pPath, "rb")) == NULL)
	{
		return FALSE;
	}

	// 从文件中逐行读取文件
	while(!feof(fp))
	{
		if(fread(&pCard[nIndex], sizeof(Card), 1, fp) != 0)
		{
			nIndex++;
		}
	}

	// 关闭文件
	fclose(fp);

	return TRUE;
}

/*************************************************
[函数名] getCardCount
[功能]  获取卡信息文件中，卡信息数量
[参数]  pPath：卡信息文件的路径
[返回值] int:卡信息文件中的卡信息数量
*************************************************/
int getCardCount(const char* pPath)
{
	FILE* fp = NULL;  // 文件指针
	int nIndex = 0;   // 卡信息数量
	Card* pCard = (Card*)malloc(sizeof(Card));

	// 以只读模式打开文件
	if((fp = fopen(pPath, "rb")) == NULL)
	{
		return 0;
	}

	// 逐行读取文件内容，获取的文件行数就是卡信息数
	while(!feof(fp))
	{
		if(fread(pCard, sizeof(Card), 1, fp) != 0)
		{
			nIndex++;
		}
	}

	// 关闭文件
	fclose(fp);
	free(pCard);
	return nIndex;
}

/*************************************************
[函数名] updateCard
[功能]  更新卡信息文件中的一条卡信息
[参数]  pCard:更新后的卡内容
       pPath:卡信息文件的路径
	   nIndex:需要更新的卡信息在文件中的卡数
[返回值] int: TRUE 更新成功，FALSE 更新失败
*************************************************/
int updateCard(const Card* pCard, const char* pPath, int nIndex)
{
	FILE* fp = NULL;    // 文件指针
	int nLine = 0;      // 文件卡信息数
	long lPosition = 0; // 文件位置标记
	Card bBuf;

	// 以读写模式打开文件，如果失败，返回FALSE
	if((fp = fopen(pPath, "rb+")) == NULL)
	{
		return FALSE;
	}

	// 遍历文件
	while((!feof(fp)) && (nLine < nIndex))
	{
		// 逐行读取文件内容
		if(fread(&bBuf, sizeof(Card), 1, fp) != 0)
		{
			// 获取文件标识位置
			lPosition = ftell(fp);
			nLine++;
		}
	}
	// 移到文件标识位置
	fseek(fp, lPosition, 0);

	fwrite(pCard, sizeof(Card), 1, fp);	

	// 关闭文件
	fclose(fp);

	return TRUE;
}

/*************************************************
[函数名] isExsit
[功能]  根据卡号判断卡是否存在
[参数]  pNum:卡号
		pPath:卡信息文件的路径
[返回值] int: TRUE 表示卡存在，FALSE 表示卡不存在
*************************************************/
int isExsit(const char* pNum, const char* pPath)
{
	FILE* fp = NULL;  // 文件结构体指针
	char aName[18];   // 存放读取出的卡号

	// 以只读的方式打开文件
	if((fp = fopen(pPath, "rb")) == NULL)
	{
		return FALSE;
	}

	// 循环读取文件，当读取到文件结尾时结束
	while(!feof(fp))
	{
		// 读取卡号，并比较卡号是否为当前查找的卡号
		if(fread(aName, sizeof(aName), 1, fp) != 0)
		{
			if(strcmp(aName, pNum) == 0)
			{
				fclose(fp);
				return TRUE;
			}
			else
			{
				// 移到下一条记录
				fseek(fp, sizeof(Card) - sizeof(aName), SEEK_CUR);
			}
		}
	}

	// 关闭文件
	fclose(fp);

	return FALSE;
}