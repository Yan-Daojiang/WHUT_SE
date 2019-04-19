#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>    // �����ļ��ṹ��ͷ�ļ�
#include <string.h>   // �����ַ�����ͷ�ļ�
#include <stdlib.h>   // ����standard library��׼��ͷ�ļ�

#include "model.h"    // �����������Ͷ���ͷ�ļ�
#include "global.h"   // ����ȫ�ֶ���ͷ�ļ�
#include "tool.h"     // ��������ͷ�ļ�

/*************************************************
[������] saveCard
[����]  ������Ϣ���浽�ļ���
[����]  pCard����Ҫ���浽����Ϣ�еĿ��ṹ��ָ��
        pPath�����濨��Ϣ���ļ�·��
[����ֵ] int�ͣ�TRUE��ʾ�ɹ���FALSE��ʾʧ��
*************************************************/
int saveCard(const Card* pCard, const char* pPath)
{
	FILE* fp = NULL;   // �ļ��ṹ��ָ��

	// ��׷�ӵ�ģʽ���ļ��������ʧ�ܣ�����ֻд��ģʽ���ļ�
	if((fp = fopen(pPath,"ab")) == NULL)
	{
		if((fp = fopen(pPath,"wb")) == NULL)
		{
			return FALSE;
		}
	}

	fwrite(pCard, sizeof(Card), 1, fp);

	// �ر��ļ�
	fclose(fp);
	return TRUE;
}

/*************************************************
[������] readCard
[����]  ���ļ��ж�ȡ����Ϣ
[����]  pCard�����ļ���ȡ�Ŀ���Ϣ�ṹ��ָ��
        pPath����ȡ���ļ�·��
[����ֵ] int�ͣ�TRUE��ʾ�ɹ���FALSE��ʾʧ��
*************************************************/
int readCard(Card* pCard, const char* pPath)
{
	FILE* fp = NULL;  // �ļ��ṹ��ָ��
	int nIndex = 0;   // ����Ϣ����

	// ��ֻ���ķ�ʽ���ļ�
	if((fp = fopen(pPath, "rb")) == NULL)
	{
		return FALSE;
	}

	// ���ļ������ж�ȡ�ļ�
	while(!feof(fp))
	{
		if(fread(&pCard[nIndex], sizeof(Card), 1, fp) != 0)
		{
			nIndex++;
		}
	}

	// �ر��ļ�
	fclose(fp);

	return TRUE;
}

/*************************************************
[������] getCardCount
[����]  ��ȡ����Ϣ�ļ��У�����Ϣ����
[����]  pPath������Ϣ�ļ���·��
[����ֵ] int:����Ϣ�ļ��еĿ���Ϣ����
*************************************************/
int getCardCount(const char* pPath)
{
	FILE* fp = NULL;  // �ļ�ָ��
	int nIndex = 0;   // ����Ϣ����
	Card* pCard = (Card*)malloc(sizeof(Card));

	// ��ֻ��ģʽ���ļ�
	if((fp = fopen(pPath, "rb")) == NULL)
	{
		return 0;
	}

	// ���ж�ȡ�ļ����ݣ���ȡ���ļ��������ǿ���Ϣ��
	while(!feof(fp))
	{
		if(fread(pCard, sizeof(Card), 1, fp) != 0)
		{
			nIndex++;
		}
	}

	// �ر��ļ�
	fclose(fp);
	free(pCard);
	return nIndex;
}

/*************************************************
[������] updateCard
[����]  ���¿���Ϣ�ļ��е�һ������Ϣ
[����]  pCard:���º�Ŀ�����
       pPath:����Ϣ�ļ���·��
	   nIndex:��Ҫ���µĿ���Ϣ���ļ��еĿ���
[����ֵ] int: TRUE ���³ɹ���FALSE ����ʧ��
*************************************************/
int updateCard(const Card* pCard, const char* pPath, int nIndex)
{
	FILE* fp = NULL;    // �ļ�ָ��
	int nLine = 0;      // �ļ�����Ϣ��
	long lPosition = 0; // �ļ�λ�ñ��
	Card bBuf;

	// �Զ�дģʽ���ļ������ʧ�ܣ�����FALSE
	if((fp = fopen(pPath, "rb+")) == NULL)
	{
		return FALSE;
	}

	// �����ļ�
	while((!feof(fp)) && (nLine < nIndex))
	{
		// ���ж�ȡ�ļ�����
		if(fread(&bBuf, sizeof(Card), 1, fp) != 0)
		{
			// ��ȡ�ļ���ʶλ��
			lPosition = ftell(fp);
			nLine++;
		}
	}
	// �Ƶ��ļ���ʶλ��
	fseek(fp, lPosition, 0);

	fwrite(pCard, sizeof(Card), 1, fp);	

	// �ر��ļ�
	fclose(fp);

	return TRUE;
}

/*************************************************
[������] isExsit
[����]  ���ݿ����жϿ��Ƿ����
[����]  pNum:����
		pPath:����Ϣ�ļ���·��
[����ֵ] int: TRUE ��ʾ�����ڣ�FALSE ��ʾ��������
*************************************************/
int isExsit(const char* pNum, const char* pPath)
{
	FILE* fp = NULL;  // �ļ��ṹ��ָ��
	char aName[18];   // ��Ŷ�ȡ���Ŀ���

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
				fclose(fp);
				return TRUE;
			}
			else
			{
				// �Ƶ���һ����¼
				fseek(fp, sizeof(Card) - sizeof(aName), SEEK_CUR);
			}
		}
	}

	// �ر��ļ�
	fclose(fp);

	return FALSE;
}