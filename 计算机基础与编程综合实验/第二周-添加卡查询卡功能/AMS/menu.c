#include <stdio.h>//�����������ͷ�ļ�
#include <time.h>//����ʱ��ͷ�ļ�
#include <string.h> //�����ַ���������
#include <stdlib.h>//������̬�ڴ����ͷ�ļ�

#include "model.h"//�������ݶ���ͷ�ļ�
#include "service.h"//����ҵ����ͷ�ļ�
#include "global.h"//����ȫ�ֶ���ͷ�ļ�
#include "tool.h"//��������ͷ�ļ�

#define _CRT_SECURE_NO_WARINGS
void cardService(Card card);
/************************
����������outputMenu
�����ܡ����ϵͳ�˵�
��������void
������ֵ��void
*************************/
void outputMenu()
{
	printf("--------------�˵�------------\n");
	printf("1.��ӿ�\n");
	printf("2.��ѯ��\n");
	printf("3.�ϻ�\n");
	printf("4.�»�\n");
	printf("5.��ֵ\n");
	printf("6.�˷�\n");
	printf("7.��ѯͳ��\n");
	printf("8.ע����\n");
	printf("0.�˳�\n");
	printf("������˵����(0~8):");
}
/************************
����������add
�����ܡ���ӿ�
��������void
������ֵ��void
*************************/
void add( )
{    
	/*������Ϣ��ӵ��ṹ����*/
	Card card;
	printf("--------��ӿ�--------\n");
	printf("�����뿨��<����1~18>:");
	scanf("%s",card.aName);
	printf("����������<����1~8>:");
	scanf("%s",card.aPwd);
	printf("�����뿪�����<RMB>:");
	scanf("%f",&card.fBalance);
	card.fTotalUse=card.fBalance;
	card.nDel=0;//ɾ����ʶ
	card.nUseCount=0;//ʹ�ô���
	card.nStaus=0;//��״̬
	card.tStart=card.tEnd=card.tLastTime=time(NULL);/*������ʱ�䣬��ֹʱ�䣬���ʹ��ʱ����ΪϵͳĬ��ʱ��*/
	printf("----------------��ӿ���Ϣ����-------------------\n");
	printf("����\t����\t״̬\t�������\n");
	printf("%s\t%s\t%d\t%0.1f\n",card.aName,card.aPwd,card.nStaus,card.fBalance);
	cardService(card);
}
int i=0;
Card aCard[50];
void cardService(Card card)
{
    aCard[i]=card;
	i=i+1;
}


/************************
����������query
�����ܡ���ѯ��
��������void
������ֵ��void
*************************/
void query()
{    
	int index=0;
	int a;
	char numCard[8];/*����Ҫ��ѯ�Ŀ���*/
	printf("�������ѯ�����ţ�");
	scanf("%s",numCard);/*�Ӽ��̽���Ҫ��ѯ�Ŀ���*/
	for(index=0;index<i;index++)/*����ѭ���Խṹ���������ѭ������*/
	{
	    if(strcmp(numCard,aCard[index].aName)==0)
		{
			a=1;
			break;
		}
		else
		{
			a=0;
		}
	}
	if(a==1)
	{
	    char time[24];
	    timeToString( aCard[index].tLastTime,time);
	    printf("--------------------����ѯ�Ŀ��������µ���Ϣ-------------------------\n");/*��ˮƽ������ʽ�Բ�ѯ����Ϣ�������*/
		printf("����\t״̬\t���\t�ۼ�ʹ��\tʹ�ô���\t�ϴ�ʹ��ʱ��\n");
		printf("%s\t%d\t%.2f\t%.2f\t\t%d\t\t%s\n",aCard[index].aName,aCard[index].nStaus,aCard[index].fBalance,aCard[index].fTotalUse-aCard[index].fBalance,aCard[index].nUseCount,time);
	}
	else
	{
		printf("û�иÿ�����Ϣ��");
	}
}
/************************
����������exitApp
�����ܡ��˳�ϵͳ
��������void
������ֵ��void
*************************/
void exitApp()
{
	printf("��ȷ���˳�ϵͳ�𣿣���<��ѡ��1����2>\n");
	printf("1.ȷ�� 2.ȡ��");
}
/************************
����������logon
�����ܡ��ϻ�
��������void
������ֵ��void
*************************/
void logon()
{
	printf("�ϻ�ʱ�䣺");
}
/************************
����������settle
�����ܡ��»�
��������void
������ֵ��void
*************************/
void settle()
{
	printf("�»�ʱ�䣺");
}
/************************
����������annul
�����ܡ�ע����
��������void
������ֵ��void
*************************/
void annul()
{
	printf("��ȷ��ע�����𣿣���<��ѡ��1����2>\n");
	printf("1.ȷ�� 2.ȡ��");
}
/************************
����������addMoney
�����ܡ���ֵ
��������void
������ֵ��void
*************************/
void addMoney()
{
	printf("�������ֵ���:<RMB>:");
}
/************************
����������refunMoney
�����ܡ��˷�
��������void
������ֵ��void
*************************/
void refunMoney()
{
	printf("�˷ѽ��<RMB>:");
}
/************************
����������count
�����ܡ���ѯͳ��
��������void
������ֵ��void
*************************/
void count()
{}
