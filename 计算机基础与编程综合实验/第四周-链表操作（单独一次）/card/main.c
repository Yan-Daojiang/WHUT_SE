#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "menu.h"
long num;
struct Student *pt;
int main(void)
{
	struct Student *head=NULL;
	int nSection = -1;    //����˵�����
	printf("\n��ӭ����ѧ������ϵͳ");
	printf("\n");
	do
	{
		//���ϵͳ�˵�
		outmenu();
		nSection = -1;
		scanf_s("%d", &nSection);
		//���ѡ��˵��ı��
		switch (nSection)
		{
		case 1://�½�ѧ����Ϣ������ҽ��в���
		{
			
			pt=creat();
			print(pt);
			break;
		}
		case 2:
		{
			printf("��������Ҫ���ҵ�ѧ�����:");
			scanf_s("%ld",&num);
			find(pt,num);
			break;
		}
		default:
		{
			printf("����˵���Ŵ���\n");
			break;
		}
		}
		printf("\n");
	} while (nSection != 0);

	
}









