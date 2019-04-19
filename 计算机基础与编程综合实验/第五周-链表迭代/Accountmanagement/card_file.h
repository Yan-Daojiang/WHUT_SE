#ifndef CARD_FILE_H
#define CARD_FILE_H

int saveCard(const Card* pCard, const char* pPath);  // ����saveCard()����
int getCardCount(const char* pPath);                 // ����getCardCount()����
int readCard(Card* pCard, const char* pPath);        // ����readCard()����
int updateCard(const Card* pCard, const char* pPath, int nIndex);  // ����updateCard()����
int isExsit(const char* pNum, const char* pPath); // ���ݿ��Ų�Ŀ�

#endif