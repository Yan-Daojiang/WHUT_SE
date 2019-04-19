/**
* @author: Yan_Daojiang
* @date: 2018/10/13
* @description:将两个值非递减排列的线性表进行归并
**/
#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
#define OK 1
#define OVERFLOW -2
typedef int Status;

typedef int Elemtype;
//--------------线性表的动态分配顺序存储结构--------
#define LIST_INIT_SIZE 100//线性表存储空间的初始分配量
#define LISTINCREMENT 10//线性表的存储空间增量
typedef struct {
	int *elem;//存储空间的基地址
	int length;//当前的长度
			   //线性表的长度是指线性表中元素的个数
	int listsize;//分配空间的存储容量
}Sqlist;

Status InitList_Sq(Sqlist &L) {
	//构造一个空的线性表
	L.elem = (Elemtype*)malloc(LIST_INIT_SIZE*sizeof(int));
	if (!L.elem)//存储空间分配失败
		exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}//initlist_sq

Status ListInsert_Sq(Sqlist &L, int i, Elemtype e) {
	//在顺序表的第i个位置之前插入元素e
	//注意i 的合法取值为1<=i<=ListLength_Sq(L)+1
	if (i<1 || i>L.length + 1)
		return ERROR;//如果i的值不合法就返回ERROR
	if (L.length >= L.listsize) {//如果当前的空间已经满了，就追加分配
		Elemtype * newbase = (Elemtype *)realloc(L.elem, (L.listsize + LISTINCREMENT)*sizeof(Elemtype));
		if (!newbase)
			exit(OVERFLOW);//存储分配失败
		L.elem = newbase;//新的基地址
		L.listsize += LISTINCREMENT;
	}
	int *q = &(L.elem[i - 1]);//q为元素的插入位置
	for (int *p = &L.length - 1; p >= q; --p)
		*(p + 1) = *p;//从插入位置开始后面的元素都要后移
	*q = e;
	++L.length;//插入一个元素之后表长度要+1
	return OK;
}// ListInsert_Sq

int ListLength(Sqlist L) {
	//返回线性表中元素的个数	
	return L.length;
}
Elemtype Getelem(Sqlist L, int i, Elemtype &e) {
	//用e返回第i个数据元素的值
	e = L.elem[i - 1];
	return e;
}

void MergeList(Sqlist La, Sqlist Lb, Sqlist &Lc) {
	//已知两个线性表的数据元素按照非递减排列，将两个线性表进行归并
	Elemtype ai, bj;
	InitList_Sq(Lc);
	int i, j, k;
	i = j = 1;
	k = 0;
	La.length = ListLength(La);
	Lb.length = ListLength(Lb);
	while ((i <= La.length) && j <= Lb.length) {//确定两个线性表都是非空表
		Getelem(La, i, ai);
		Getelem(Lb, j, bj);
		if (ai < bj) {
			ListInsert_Sq(Lc, ++k, ai);
			i++;
		}
		else {
			ListInsert_Sq(Lc, ++k, bj);
			j++;
		}
	}
	while (i <= La.length) {
		Getelem(La, i++, ai);
		ListInsert_Sq(Lc, ++k, ai);
	}
	while (j <= Lb.length) {
		Getelem(Lb, j++, bj);
		ListInsert_Sq(Lc, ++k, bj);
	}
}
int main() {
	Sqlist La, Lb, Lc;
	//分别创建空表La，Lb,并对相关的参数进行初始化
	InitList_Sq(La);
	InitList_Sq(Lb);
	//将需要归并的两个表的元素分别插入到La和Lb中去
	int i, j, a[4] = { 3,5,8,11 }, b[7] = { 2,6,8,9,11,15,20 };
	printf("需要进行操作的两个线性表如下\n");
	for (i = 1; i <= 4; i++) {// 在表La中插入4个元素
		ListInsert_Sq(La, i, a[i - 1]);
		printf("%d ", a[i - 1]);
	}
	printf("\n");
	for (j = 1; j <= 7; j++) {//在线性表Lb中插入7个元素
		ListInsert_Sq(Lb, j, b[j - 1]);
		printf("%d ", b[j - 1]);
	}
	printf("\n");
	//对两个表进行归并
	MergeList(La, Lb, Lc);
	//输出归并结果
	Elemtype result;
	printf("归并结果:\n");
	for (int k = 1; k <= Lc.length; k++) {
		printf("%d ", Getelem(Lc, k, result));
	}
	printf("\n");
	return OK;
}