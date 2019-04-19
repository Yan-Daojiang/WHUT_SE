#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"time.h"
#include"model.h"
#include"global.h"
#include"card_file.h"


int saveCard(const Card*pCard,const char*pPath)
{
	FILE* fp=NULL;
	if((fp=fopen(pPath,"ab"))==NULL)
	{
		if((fp=fopen(pPath,"wb"))==NULL)
			{
			return FALSE;
		}
	}
	
	fwrite(pCard, sizeof(Card), 1, fp);
	
	// 关闭文件
	fclose(fp);
	return TRUE;
}

int isExsit(const char* pNum, Card *pCard,const char* pPath)
{
  FILE* fp = NULL;  // 文件结构体指针
  char aName[18]={0};   // 存放读取出的卡号


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
        fseek(fp,  - sizeof(aName), SEEK_CUR);
		fread(pCard,sizeof(Card),1,fp);
       fclose(fp); return TRUE;
      }
      else
      {
        // 移到下一条记录
        fseek(fp, sizeof(Card) - sizeof(aName), SEEK_CUR);
      }
    }
  }
  fclose(fp);
  return FALSE;
}