#include "menu.h"
#define _CRT_SECURE_NO_WARNINGS
int main()
{
	int nSection = -1;    //����˵�����
	printf("��ӭ����Ʒѹ���ϵͳ");
	printf("\n");
	do
	{
		//���ϵͳ�˵�
		outputMenu();
		nSection = -1;
		scanf_s("%d", &nSection);
		//���ѡ��˵��ı��
		switch (nSection)
		{
		case 1://��ӿ�
		{
			add();
			
			break;
		}
		case 2://��ѯ��
		{
			query();
			break;
		}
		case 3://�ϻ�
		{
			logon();
			break;
		}
		case 4://�»�
		{
			settle();
			break;
		}
		case 5://��ֵ
		{
			addMoney();
			break;
		}
		case 6://�˷�
		{
			refunMoney();
			break;
		}
		case 7://��ѯͳ��
		{
			count();
			break;
		}
		case 8://ע����
		{
			annul();
			break;
		}
		case 0://�˳�Ӧ�ó���
		{
			exitApp();
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

	return 0;
}