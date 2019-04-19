#ifndef CARD_SERVICE_H
#define CARD_SERVICE_H
#include "model.h"
int addCard(Card card);              // 声明addCard()函数
Card* queryCards(const char* pName, int* pIndex);  // 声明queryCards()函数
void releaseCardList();              // 声明releaseCardList()函数
Card* checkCard(const char* pName, const char* pPwd, int* pIndex);  // 声明checkCard()函数
int updateCardInfo(const Card* pCard, int nIndex);   // 声明updateCardInfo()函数

#endif