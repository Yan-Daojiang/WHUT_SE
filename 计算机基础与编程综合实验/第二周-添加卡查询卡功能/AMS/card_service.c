#include <stdio.h>//�����������ͷ�ļ�
#include <time.h>//����ʱ��ͷ�ļ�
#include <string.h> //�����ַ���������
#include <stdlib.h>//������̬�ڴ����ͷ�ļ�

#include "model.h"//�������ݶ���ͷ�ļ�
#include "service.h"//����ҵ����ͷ�ļ�
#include "global.h"//����ȫ�ֶ���ͷ�ļ�
#include "tool.h"//��������ͷ�ļ�
#define _CRT_SECURE_NO_WARINGS     
void addCard(Card card)
{
	Card aCard[50];//����Ϣ�ṹ������
	int nCount=0;//����Ϣ��
	aCard[0]=card;
	printf("%s",aCard[0]);

}