#define _CRT_SECURE_NO_WARNINGS   // ����VS���������У�ʹ��scanf()���������ľ���
                                  // Disable the scanf() function warning in VS

#include <stdio.h>    // �����������ͷ�ļ�  // Include stdio.h header file

#include "menu.h"     // ����menu.h�ļ�  // Include menu.h header file

int main()
{
	int nSelection = -1;   // ����˵�����  // Input menu item number

	//���ϵͳ���ơ���ӭ����Ʒѹ���ϵͳ��
	// ��ʾ�û�������Ϣ
	printf("----------��ӭ����Ʒѹ���ϵͳ-----------\n\n");
	printf("����������������������������������\n");
	printf("˵����������������Ϊÿ��0.5Ԫ\n�����о�̫���뵽��������������,ͬʱף����ÿ���\n");
	printf("\n");

	do
	{
		//���ϵͳ�˵�
		outputMenu();
		
		// ��ʼ��ѡ��Ĳ˵�����Ϊ-1
		nSelection = -1; 

		// ����˵�����
		scanf("%d",&nSelection);

		// �������������
		fflush(stdin);

		//���ѡ��Ĳ˵����
		switch(nSelection)
		{

		case 1:  // ��ӿ�
			{
				add();
				break;
			}
		case 2:  // ��ѯ��
			{
				query();
				break;
			}
		case 3:  // �ϻ�
			{
				logon();
				break;
			}
		case 4:  // �»�
			{
				settle();
				break;
			}
		case 5:  // ��ֵ
			{
				addMoney();
				break;
			}
		case 6:  // �˷�
			{
				refundMoney();
				break;
			}
		case 7:  // ��ѯͳ��
			{
				printf("��ѯͳ��\n");
				break;
			}
		case 8:  // ע����
			{
				annul();
				break;
			}
		case 0:   // �˳�
			{
				exitApp();
				break;
			}
		default:
			{
				printf("����Ĳ˵���Ŵ���\n");
				break;
			}
		}
		printf("\n");
	}
	while(nSelection != 0);

	return 0;
}