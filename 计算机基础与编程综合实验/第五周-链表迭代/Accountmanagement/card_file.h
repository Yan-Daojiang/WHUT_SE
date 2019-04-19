#ifndef CARD_FILE_H
#define CARD_FILE_H

int saveCard(const Card* pCard, const char* pPath);  // 声明saveCard()函数
int getCardCount(const char* pPath);                 // 声明getCardCount()函数
int readCard(Card* pCard, const char* pPath);        // 声明readCard()函数
int updateCard(const Card* pCard, const char* pPath, int nIndex);  // 声明updateCard()函数
int isExsit(const char* pNum, const char* pPath); // 根据卡号查的卡

#endif