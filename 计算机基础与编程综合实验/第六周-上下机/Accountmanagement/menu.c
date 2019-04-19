#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>   // �����������ͷ�ļ�
#include <time.h>    // ����ʱ��ͷ�ļ�
#include <string.h>  // �����ַ���������
#include <stdlib.h>  // ������̬�ڴ����ͷ�ļ�
#include <time.h>    //����ʱ�䴦��ͷ�ļ�
#include "model.h"   // �������ݶ���ͷ�ļ�
#include "service.h"     // ����ҵ����ͷ�ļ�
#include "global.h"      // ����ȫ�ֶ���ͷ�ļ�
#include "tool.h"        // ��������ͷ�ļ�
#include "card_service.h"
#include "card_file.h"

int getSize(const char* pInput);                          // ����getSize()����
/*****************************************************
[������] outputMenu
[����] ���ϵͳ�˵�
[����] void
[����ֵ] void
*****************************************************/
void outputMenu()
{
	printf("----------�˵�----------\n");
	printf("1.��ӿ�\n");
	printf("2.��ѯ��\n");
	printf("3.�ϻ�\n");
	printf("4.�»�\n");
	printf("5.��ֵ\n");
	printf("6.�˷�\n");
	printf("7.��ѯͳ��\n");
	printf("8.ע����\n");
	printf("0.�˳�\n\n");
	
	//��ʾѡ��˵����
	printf("������˵����ţ�0~8����");
}

/*************************************************
[������] add
[����]  ��ӿ�
[����]  void
[����ֵ] void
*************************************************/
void add()
{
	char aName[32] = {0};   // ����Ŀ���
	char aPwd[20] = {0};    // ���������
	Card card;              // ����Ϣ
	struct tm* endTime;     // ��ֹʱ��
	struct tm* startTime;   // ����ʱ��
	
	printf("----------��ӿ�----------\n");

	// ��ʾ����������Ŀ���
	printf("�����뿨��(����Ϊ1~18)��");
	scanf("%s", aName);

	// �ж�����Ŀ����Ƿ����Ҫ��
	if(getSize(aName) >= 18)
	{
		printf("����Ŀ��ų��ȳ������ֵ��\n");
		return;
	}

	// ������Ŀ��ű��浽���ṹ����
	strcpy(card.aName, aName);

	// ��ʾ��������������
	printf("����������(����Ϊ1~8)��");
	scanf("%s", aPwd);

	// �ж�����������Ƿ����Ҫ��
	if(getSize(aPwd) >= 8)
	{
		printf("��������볤�ȳ������ֵ��\n");
		return;
	}

	// ����������뱣�浽���ṹ����
	strcpy(card.aPwd, aPwd);

	printf("�����뿪�����(RMB)��");
	scanf("%f", &card.fBalance);

	card.fTotalUse = card.fBalance;    // ��ӿ�ʱ���ۼƽ����ڿ������
	card.nDel = 0;                     // ɾ����ʶ
	card.nStatus = 0;                  // ��״̬
	card.nUseCount = 0;                // ʹ�ô���
	card.tStart = card.tEnd = card.tLast = time(NULL);  // ����ʱ�䣬��ֹʱ�䣬���ʹ��ʱ�䶼Ĭ��Ϊ��ǰʱ�䡣

	// ���ݿ���ʱ�䣬�����ֹʱ�䣬ÿ�ſ�����Ч��Ϊһ��
	startTime = localtime(&card.tStart);
	endTime = localtime(&card.tEnd);
	endTime->tm_year = startTime->tm_year + 1;
	card.tEnd = mktime(endTime);

	if(FALSE == addCardInfo(card))
	{
		printf("��ӿ���Ϣʧ�ܣ�\n");
	}
	else
	{
		printf("��ӿ���Ϣ�ɹ���\n");
	}

}

/*************************************************
[������] getSize
[����]  ��ȡpInput��ָ����ַ������ַ�����
[����]  pInput:��Ҫ���ַ������ַ���
[����ֵ] int: �ַ������ַ��ĸ���
*************************************************/
int getSize(const char* pInput)
{
	int nSize = 0;

	// �����ַ������ַ�����
	while(*(pInput + nSize) != '\0')
	{
		nSize++;
	}

	// �����ַ�����
	return nSize;
}

/*************************************************
[������] query
[����]  ��ѯ��
[����]  void
[����ֵ] void
*************************************************/
void query()
{
	char aName[18] = {0};  // ��������Ŀ���
	Card* pCard = NULL;    // �����ѯ���Ŀ���Ϣ
	char aLastTime[TIMELENGTH] = {0};
	int nIndex = 0;         // ����ѯ������Ϣ����
	int i = 0;

	printf("----------��ѯ��----------\n");

	// ��ʾ����������Ŀ���Ϣ
	printf("�������ѯ�Ŀ���(����Ϊ1~18):");
	scanf("%s", aName);

	// ��ѯ��
	pCard = queryCardInfo(aName, &nIndex);

	// ���pCardΪNULL����ʾû�иÿ�����Ϣ
	if(pCard == NULL )
	{
		printf("û�иÿ�����Ϣ��\n");
	}
	else
	{
		// ������ı�ͷ
		printf("����\t״̬\t���\t�ۼ�ʹ��\tʹ�ô���\t�ϴ�ʹ��ʱ��\n");
		for(i = 0; i < nIndex; i++)
		{
			timeToString(pCard[i].tLast, aLastTime);
			printf("%s\t%d\t%0.1f\t%0.1f\t\t%d\t\t%s\n", pCard[i].aName, pCard[i].nStatus, pCard[i].fBalance, 
				pCard[i].fTotalUse, pCard[i].nUseCount, aLastTime);
		}
		// �ͷŶ�̬������ڴ�
		free(pCard);
		pCard = NULL;
	}
}

/*************************************************
[������] logon
[����]  �ϻ�
[����]  void
[����ֵ] void
*************************************************/
void logon()
{
	char aName[20]={0};
	char aPwd[8]={0};
	Card* pCard=NULL;
	//�����û��������Ϣ
	printf("���ã���������Ҫ�ϻ��Ŀ���:");
	scanf("%s",aName);
	printf("�����������Ŷ�Ӧ������:");
	scanf("%s",aPwd);
	printf("----------�ϻ�----------\n");
	pCard=doLogon(aName,aPwd);
	//�����ϻ�
	if(pCard!=NULL)
	{
		// ������ı�ͷ
		printf("�ϻ��ɹ�\n");
		printf("����\t״̬\t���\t�ۼ�ʹ��\tʹ�ô���\t\n");
		printf("%s\t%d\t%0.1f\t%0.1f\t\t%d\t\n", pCard->aName, pCard->nStatus, pCard->fBalance, 
			pCard->fTotalUse, pCard->nUseCount);
		// �ͷŶ�̬������ڴ�
			    
	}
	else
	{
		printf("�ϻ�ʧ�ܣ�������������˺�����");
	}

	
}

/*************************************************
[������] settle
[����]  �»�
[����]  void
[����ֵ] void
*************************************************/
void settle()
{ 
	
	char aName[20]={0};
	char aPwd[8]={0};
	
	//�����û��������Ϣ
	printf("--------------------�»�----------------------\n");
	printf("���ã���������Ҫ�»��Ŀ���:");
	scanf("%s",aName);
	printf("�����������Ŷ�Ӧ������:");
	scanf("%s",aPwd);
	if(TRUE == dosettle(aName,aPwd))
	{
		printf("�»��ɹ�\n");
	}
	else
	{
		printf("�»�ʧ�ܣ�������������˺�����\n");
	}
	return;
}

/*************************************************
[������] annul
[����]  ע����
[����]  void
[����ֵ] void
*************************************************/
void annul()
{
	printf("----------ע����---------\n");
}

/*************************************************
[������] addMoney
[����]  ��ֵ
[����]  void
[����ֵ] void
*************************************************/
void addMoney()
{
	printf("----------��ֵ----------\n");
}

	
/*************************************************
[������] refundMoney
[����]  �˷�
[����]  void
[����ֵ] void
*************************************************/
void refundMoney()
{
	printf("----------�˷�----------\n");
}

/*************************************************
[������] exitApp
[����]  �˳�Ӧ�ó���
[����]  void
[����ֵ] void
*************************************************/
void exitApp()
{

}