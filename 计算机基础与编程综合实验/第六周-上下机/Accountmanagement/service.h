
#ifndef SERVICE_H    // 防止重复编译
#define SERVICE_H

int addCardInfo(Card card);    // 声明addCardInfo()函数
Card* queryCardInfo(const char* pName, int* pIndex);  // 声明queryCardInfo()函数
void releaseList();   // 声明releaseList()函数

#endif