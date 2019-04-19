#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

//函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;

//线性表的动态分配存储结构
#define LIST_INIT_SIZE 100//存储空间的初始分配量
#define LISTINCREMENT 10//存储空间的增加量
typedef struct{
	ElemType *elem;//存储空间的基地址
	int length;//当前的长度
	int listsize;//当前的空间分配的存储容量
}Sqlist;

/***********************顺序存储的线性表的基本操作函数声明*****************/
//操作结果：构造一个空的线性表
Status InitList_Sq(Sqlist &L);	

//初始条件：线性表已经存在
//操作结果：摧毁线性表
Status DestoryList(Sqlist &L);

//初始条件：线性表已经存在
//操作结果：将线性表置空
Status ClearList(Sqlist &L);

//初始条件：线性表已经存在
//操作结果：如果是空表就返回TRUE 否则返回FALSE
Status ListEmpty(Sqlist L);

//初始条件：线性表已经存在
//操作结果：返回线性表中的元素的个数
int ListLenth(Sqlist L);

//初始条件：线性表已经存在，1<=i<=Listgth(L)
//操作结果：用e返回线性表L中的第i个元素
Status GetElem(Sqlist L,int i,ElemType &e);

//初始条件：线性表已经存在，compare()是元素判定函数
//操作结果：返回线性表中第一个满足判定函数的元素的位序，如果这样的元素不存在就返回0
Status LocateElem(Sqlist L,ElemType e,Status(*compare)(ElemType,ElemType));

//初始条件：线性表已经存在
//操作结果：若cur_r是线性表的数据元素，并且不是线性表的第一个元素，那么就用pre_e返回他的前驱，否则操作失败，pre_e没有意义
Status PriorElem(Sqlist L,ElemType cur_e,ElemType &pre_e);

//初始条件：线性表已经存在
//操作结果：若cur_r 是线性表的元素，并且不是最后一个元素，那么就用next_e 返回他的后继，否则操作失败，next_e 没有意义
Status NextElem(Sqlist L,ElemType cur_e,ElemType &next_e);

//初始条件：线性表已经存在，1<=i<=ListLenth(L)+1
//操作结果：在L 的第i 位之前插入新的元素e，L的长度加1
Status ListInsert(Sqlist &L,int i,ElemType e);

//初始条件：线性表已经存在并且线性表是非空的，同时需要参数的满足条件
//操作结果：删除线性表的第i个元素，并返回他的值
Status ListDelete(Sqlist &L,int i,ElemType &e);

//初始条件：线性表已经存在
//操作结果：依次对L中的每一个元素调用函数visit(),如果visit()失败那么操作失败，同时如果需要可以通过visit()改变元素的值
Status ListTraverse(Sqlist L,void(*visit)(ElemType&));

//操作结果：访问线性表中的元素
void visit(ElemType &c);
