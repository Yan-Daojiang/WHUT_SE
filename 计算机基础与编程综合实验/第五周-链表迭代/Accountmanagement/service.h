
#ifndef SERVICE_H    // ��ֹ�ظ�����
#define SERVICE_H

int addCardInfo(Card card);    // ����addCardInfo()����
Card* queryCardInfo(const char* pName, int* pIndex);  // ����queryCardInfo()����
void releaseList();   // ����releaseList()����

#endif