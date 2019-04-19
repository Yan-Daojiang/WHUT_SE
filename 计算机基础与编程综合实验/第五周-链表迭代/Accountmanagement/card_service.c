#include <string.h> // �����ַ�����ͷ�ļ�
#include <stdlib.h> // ������̬�ڴ����ͷ�ļ�
#include <time.h>   // ����ʱ�䴦��ͷ�ļ�

#include "model.h"  // �������ݶ���ͷ�ļ�
#include "global.h" // ����ȫ�ֶ���ͷ�ļ�
#include "card_file.h" // �����ļ�����ͷ�ļ�

lpCardNode cardList = NULL;    // ����Ϣ����
int getCard();                 // ����getCard()����

/*************************************************
[������] initCardList
[����]  ��ʼ������Ϣ����
[����]  void
[����ֵ] int�ͣ�TRUE��ʾ�ɹ���FALSE��ʾʧ��
*************************************************/
int initCardList()
{
	lpCardNode head = NULL;
	if(cardList == NULL)
	{
		// Ϊ����ͷ�������ڴ�
		head = (lpCardNode)malloc(sizeof(CardNode));

		// �������ɹ���������ָ��
		if(head != NULL)
		{
			head->next = NULL;
			cardList = head;
			return TRUE;
		}

	}
	return FALSE;
}

/*************************************************
[������] releaseCardList
[����]  �ͷſ���Ϣ����
[����]  void
[����ֵ] void
*************************************************/
void releaseCardList()
{
	lpCardNode cur = cardList;   
	lpCardNode next = NULL;

	while(cur != NULL)
	{
		next = cur->next;  // �ͷ�cur���ǰ����next�������ĺ�̽��
		free(cur);         // �ͷ�cur���
		cur = next;
	}
	cardList = NULL;
}


/*************************************************
[������] queryCards
[����]  �ڿ���Ϣ�����У���ѯ������ͬ�Ŀ���Ϣ
[����]  pName:Ҫ��ѯ�Ŀ��Ŀ���
       pIndex:��ѯ���Ŀ���Ϣ������ָ��
[����ֵ] Card*:��ѯ���Ŀ���Ϣ��ָ��
*************************************************/
Card* queryCards(const char* pName, int* pIndex)
{
	lpCardNode node = NULL;
	Card* pCard = NULL;

	// ���ļ��У���ȡ����Ϣ
	if(getCard() == FALSE)
	{
		return NULL;
	}

	// ���ȷ���һ��Card��С�ڴ�ռ�
	pCard = (Card*)malloc(sizeof(Card));
	if(pCard == NULL)
	{
		return NULL;
	}

	// �������ͷ���ָ�����һ����㿪ʼ����
	node = cardList->next;

	// �����������Ϊ�ձ�ʾ��������β��
	while(node != NULL)
	{
		// �ж��ڱ������Ľ��Ŀ����У������Ƿ����pName�ַ���
		if(strstr(node->data.aName, pName) != NULL)
		{
			// ����У��򱣴����е�����
			pCard[*pIndex] = node->data;
			(*pIndex)++;

			// ����Ϊָ������ڴ�
			pCard = (Card*)realloc(pCard, ((*pIndex)+1)*sizeof(Card));
		}

		// �Ƶ��������һ�����
		node = node->next;
	}

	return pCard;
}

/*************************************************
[������] getCard
[����]  �ӿ���Ϣ�ļ��У���ȡ����Ϣ�����浽������
[����]  void
[����ֵ] int: FALSE ��ȡʧ�ܣ�TRUE����ȡ�ɹ�
*************************************************/
int getCard()
{
	int nCount = 0;      // ����Ϣ��
	int i = 0;
	Card* pCard = NULL;  //  ����Ϣ
	lpCardNode node = NULL;  // �����Ϣ
	lpCardNode cur = NULL;   // ��ӵ������еĽ��

	// ����������Ѿ����ڵ�����
	if(cardList != NULL)
	{
		releaseCardList();
	}

	// ��ʼ������
	initCardList();

	// ��ȡ����Ϣ����
	nCount = getCardCount(CARDPATH);

	if(nCount == 0)
	{
		return FALSE;
	}

	// ��̬�����ڴ汣�濨��Ϣ
	pCard = (Card*)malloc(sizeof(Card)*nCount);
	if(pCard != NULL)
	{
		// �������FALSE����ʾ��ȡ����Ϣʧ��
		if(0 == readCard(pCard, CARDPATH))
		{
			free(pCard);
			return FALSE;
		}

		// ����ȡ�Ŀ���Ϣ�����浽������
		for(i = 0, node = cardList; i < nCount; i++)
		{
			// Ϊ�������ڴ�
			cur = (lpCardNode)malloc(sizeof(CardNode));

			// ��������ڴ�ʧ�ܣ��򷵻�
			if(cur == NULL)
			{
				free(pCard);
				return FALSE;
			}
			// ��ʼ���µĿռ䣬ȫ����ֵΪ0
			memset(cur, 0, sizeof(CardNode));

			// ������Ϣ���浽�����
			cur->data = pCard[i];
			cur->next = NULL;

			// �������ӵ�����β��
			node->next = cur;
			node = cur;
		}
		// �ͷ��ڴ�
		free(pCard);
		return TRUE;
	}
	return FALSE;
}

/*************************************************
[������] checkCard
[����]  ���ݿ��ź����룬�������в�ѯ����Ϣ������ȡ��ѯ���Ŀ���Ϣ�������е�λ��
[����]  pName:�ϻ����Ŀ���
       pPwd: �ϻ�������
	   pIndex: �ϻ����ڿ���Ϣ�����е�������ָ��
[����ֵ] Card*: �����ϻ��Ŀ���Ϣ�ṹ��ָ��
*************************************************/
Card* checkCard(const char* pName, const char* pPwd, int* pIndex)
{
	lpCardNode cardNode = NULL; 
	int nIndex = 0;             // �ϻ����ڿ���Ϣ�����е�������

	// ������ļ��л�ȡ����Ϣʧ�ܣ����ϻ�ʧ��
	if(FALSE == getCard())
	{
		return FALSE;
	}

	// ��ȡ����ĵ�һ�����
	cardNode = cardList->next;

	// ��������
	while(cardNode != NULL)
	{
		// �жϿ��ź������Ƿ���ȷ
		if((strcmp(cardNode->data.aName, pName) == 0 ) && (strcmp(cardNode->data.aPwd, pPwd) == 0 ))
		{
			// ���ؿ���Ϣ������ݵĵ�ַ
			*pIndex = nIndex;
			return &cardNode->data;
		}
		cardNode = cardNode->next;
		nIndex++;

	}

	return NULL;
}