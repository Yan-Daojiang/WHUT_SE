#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	//�����������ͷ�ļ�
#include<time.h>	//����ʱ��ͷ�ļ�
#include<string.h>	//�����ַ���������
#include<stdlib.h>	//������̬�ڴ�����ͷ�ļ�
#include"model.h"	//�������ݶ���ͷ�ļ�
#include"card_service.h" //����ҵ����ͷ�ļ�
#include"global.h"  //����ȫ�ֶ���ͷ�ļ�
#include"tool.h"    //��������ͷ�ļ�
#include"card_file.h"
void outputMenu(){	printf("-------------�˵�-------------\n");		//����˵�����
	printf("1:��ӿ�\n2:��ѯ��\n3:�ϻ�\n4:�»�\n5:��ֵ\n6:�˷�\n7:��ѯͳ��\n8:ע��\n0���˳�ϵͳ\n��ѡ��˵�����(0-8)��");}

int getSize(const char* pInfo)//ȡ����
{
	int nSize = 0;
	while(*(pInfo+nSize)!='\0')
	{
		nSize++;
	}
	return nSize;
}
void add()								 //��ӿ�
{
char atime[100]={0};					//��ʼ��״̬
Card card;
char aName[32]={0};
char aPwd[20]={0};
int aNamesize=0;
int aPwdsize=0;

int flag=0;

printf("�����뿨��<����Ϊ1-18>:");		//���п��ź����������
scanf("%s",aName);
aNamesize=getSize(aName);
printf("����������<����Ϊ1-8>:");
scanf("%s",aPwd);
aPwdsize=getSize(aPwd);

if(aNamesize > 18 || aPwdsize > 8)		//�ж������Ƿ����Ҫ��
	{
		printf("���Ż����볬���涨���ȣ�\n");
		return;
	}
strcpy(card.aName,aName);
strcpy(card.aPwd,aPwd);
printf("�����뿪�����<RMB>:");
scanf("%f",&card.fBalance);
card.fTotalUse=card.fBalance;			//��ʼ��״̬
card.nDel=card.nUseCount=card.nStatus=0;
card.tStart=card.tEnd=card.tLastTime = time(NULL);
flag=addcard(card);
if(flag==1)
{
printf("-----��ӵĿ���Ϣ����-------\n");
printf("����\t����\t��״̬\t�������\n");
printf("%s\t%s\t%d\t%.1f\t",card.aName,card.aPwd,card.nStatus,card.fBalance);}
else
	printf("��ӿ�ʧ��!");

}

void query()			  //��ѯ��
{
	int i=0;
	int flag=0;
	char bname[50]={0};
	char atime[100]={0};
	Card* pcard = (Card*)malloc(sizeof(Card));
	printf("�������ѯ�Ŀ���<����Ϊ1-18>:");
	scanf("%s",bname);
	flag=querycard(bname,pcard);
	if(flag==0)printf( "�ܱ�Ǹ��û���ҵ�������Ϣ!\n");
	else{timeToString(pcard->tLastTime,atime);
	printf("����\t״̬\t���\t�ۼ�ʹ��\tʹ�ô���\t�ϴ�ʹ��ʱ��\n");
	printf("%s\t%d\t%0.1f\t%0.1f\t\t%d\t\t%s\n",pcard->aName,pcard->nStatus,pcard->fBalance,
		pcard->fTotalUse,pcard->nUseCount,atime);}

		
}
void loggon(){}           //�ϻ�
void settle(){};          //�»�
void addMoney(){};        //��ֵ
void refundMoney(){};     //�˷�
void statistics(){};      //��ѯͳ��
void annul(){};           //ע��
void exitApp(){};         //�˳�Ӧ�ó���