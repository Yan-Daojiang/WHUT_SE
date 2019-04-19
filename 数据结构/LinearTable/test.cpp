//编写主函数对线性表的基本操作进行测试

#include<stdio.h>
#include"LinearTable_1.h"
int main(){
	Sqlist L1;
	InitList_Sq(L1);//初始化表
	int a[7]={1,3,5,7,9,11,13};
	int i;
	for(i=1;i<=7;i++)
		ListInsert(L1,i,a[i-1]);
	printf("用七个奇数初始化一个空的线性表:\n");
	ListTraverse(L1,visit);
	printf("在第三个数之前插入数：100\n");//增
	ListInsert(L1,3,100);
	ListTraverse(L1,visit);
	printf("删除第5个数字：\n");//删
	ElemType e;
	ListDelete(L1,5,e);
	ListTraverse(L1,visit);
	printf("依次返回第四个数以及其前驱和后继\n");//查
	ElemType e1,e2,e3;
	GetElem(L1,4,e1);
	PriorElem(L1,e1,e2);
	NextElem(L1,e1,e3);
	printf("%d\t%d\t%d\n",e1,e2,e3);
	printf("将第六个位置上的元素修改为99：\n");//改
	ListDelete(L1,6,e);
	ListInsert(L1,6,99);
	ListTraverse(L1,visit);
	return 0;
}
