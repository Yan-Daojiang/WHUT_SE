#include<stdio.h>
#include"menu.h"
#include"global.h"
#include"model.h"
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{int nSelection;                                     //����˵����� //Input menu item number
	printf("\n��ӭ����Ʒѹ���ϵͳ��\n");
	printf("\n");
	do{
		outputMenu();                               //���ϵͳ�˵�
		nSelection=-1;
		scanf("%d",&nSelection);		           //����ѡ��Ĳ˵����                              
		
		switch(nSelection)
		{
		case 1:{printf("��ӿ�\n");add();break;}           //��ӿ�
		case 2:{printf("��ѯ��\n");query();break;}         //��ѯ��   
		case 3:{printf("�ϻ�\n");loggon();break;}          //�ϻ�    
		case 4:{printf("�»�\n");settle();break;}          //�»� 
		case 5:{printf("��ֵ\n");addMoney();break;}        //��ֵ
		case 6:{printf("�˷�\n");refundMoney();break;}     //�˷�
		case 7:{printf("��ѯͳ��\n");statistics();break;}  //��ѯͳ��
		case 8:{printf("\nע��\n");annul();break;}         //ע��	   
		case 0:{exitApp();break;}                          //�˳�	
		default:{printf("\n����Ĳ˵���Ŵ�������������\n");break;}
		}
		printf("\n");
	}
		while(nSelection!=0);
		
	return 0;
}

