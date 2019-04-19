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
	
	// �ر��ļ�
	fclose(fp);
	return TRUE;
}

int isExsit(const char* pNum, Card *pCard,const char* pPath)
{
  FILE* fp = NULL;  // �ļ��ṹ��ָ��
  char aName[18]={0};   // ��Ŷ�ȡ���Ŀ���


  // ��ֻ���ķ�ʽ���ļ�
  if((fp = fopen(pPath, "rb")) == NULL)

	  {
		return FALSE;
	}
  // ѭ����ȡ�ļ�������ȡ���ļ���βʱ����
  while(!feof(fp))
  {
    // ��ȡ���ţ����ȽϿ����Ƿ�Ϊ��ǰ���ҵĿ���
	  
	
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
        // �Ƶ���һ����¼
        fseek(fp, sizeof(Card) - sizeof(aName), SEEK_CUR);
      }
    }
  }
  fclose(fp);
  return FALSE;
}