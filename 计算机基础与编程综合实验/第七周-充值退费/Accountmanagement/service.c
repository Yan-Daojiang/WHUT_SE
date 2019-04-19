#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>          // 
#include <time.h>           // ����ʱ�䴦��ͷ�ļ�
#include <string.h>         // �����ַ�������ͷ�ļ�

#include "card_service.h"   // ������ҵ���߼�����ͷ�ļ�
#include "model.h"          // �����������Ͷ���ͷ�ļ�
#include "global.h"         // ����ȫ�ֶ���ͷ�ļ�
#include "card_file.h"      // �������ļ�����ͷ�ļ�
#include "service.h"

/*************************************************
[������] addCardInfo
[����]  ��ӿ���Ϣ
[����]  card:��ӵĿ���Ϣ�ṹ��
[����ֵ] int�ͣ�TRUE��ʾ��ӳɹ���FALSE��ʾ���ʧ��
*************************************************/
int addCardInfo(Card card)
{
	// �жϿ����Ƿ��Ѿ�����
	if (isExsit(card.aName, CARDPATH) == TRUE)
	{
		return FALSE;
	}

	// ������Ϣ���浽�ļ���
	if(TRUE == saveCard(&card, CARDPATH))
	{
		return TRUE;
	}

	return FALSE;
}

/*************************************************
[������] queryCardInfo
[����]  ��ѯ����Ϣ
[����]  pName:��Ҫ��ѯ�Ŀ���
	   pIndex:��ѯ���Ŀ���Ϣ������ָ��
[����ֵ] Card*: ��ѯ���Ŀ���Ϣָ��
*************************************************/
Card* queryCardInfo(const char* pName, int* pIndex)
{
	Card* pCard = NULL;
	pCard = queryCards(pName, pIndex);

	return pCard;
}
/*************************************************
[������] queryCardInfo
[����]  �Ǽ��û���Ϣ
[����]    pIndex:��ѯ���Ŀ���Ϣ������ָ��
[����ֵ] Card*: ��ѯ���Ŀ���Ϣָ��
*************************************************/

Card* CardInfo( int* pIndex)
{
	Card* pCard = NULL;
	pCard = stars(pIndex);

	return pCard;
}

/*************************************************
[������] releaseList
[����]  �˳�Ӧ�ó���ʱ���ͷ������ڴ�
[����]  void
[����ֵ] void
*************************************************/
void releaseList()
{
	releaseCardList();      // �ͷſ���Ϣ�����ڴ�
//	releaseBillingList();   // �ͷżƷ���Ϣ�����ڴ�
}