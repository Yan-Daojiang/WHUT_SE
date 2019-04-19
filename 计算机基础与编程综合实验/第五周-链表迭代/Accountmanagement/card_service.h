#ifndef CARD_SERVICE_H
#define CARD_SERVICE_H
#include "model.h"
int addCard(Card card);              // ����addCard()����
Card* queryCards(const char* pName, int* pIndex);  // ����queryCards()����
void releaseCardList();              // ����releaseCardList()����
Card* checkCard(const char* pName, const char* pPwd, int* pIndex);  // ����checkCard()����
int updateCardInfo(const Card* pCard, int nIndex);   // ����updateCardInfo()����

#endif