#ifndef CARD_SERVICE_H
#define CARD_SERVICE_H
#include "model.h"
int addCard(Card card);              // ����addCard()����
Card* queryCards(const char* pName, int* pIndex);  // ����queryCards()����
void releaseCardList();              // ����releaseCardList()����
Card* checkCard(const char* pName, const char* pPwd, int* pIndex);  // ����checkCard()����
int updateCardInfo(const Card* pCard, int nIndex);   // ����updateCardInfo()����
Card* doLogon(const char* pName,const char *pPwd);   //�����ϻ�����
int dosettle(const char* pName,const char* pPwd);    //�����»�����
int Recharge(const char* pName,const char* pPwd);    //������ֵ����
int Recharge(const char* pName,const char* pPwd);    //�����˷Ѻ���
int move(const char* pName,const char* pPwd);    //����ע��������
Card* stars(int* pIndex);
#endif