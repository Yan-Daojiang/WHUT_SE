/**
* @author: Yan_Daojiang
* @date: 2018/10/13
* @description:链式存储实现归并
**/
#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode *next;
}*Link, *Position;
typedef struct {
	Link head, tail;
	int len;
}LinkList;

Status MakeNode(Link &p, ElemType e)
{ // 分配由p指向的值为e的结点，并返回OK；若分配失败。则返回ERROR
	p = (Link)malloc(sizeof(LNode));
	if (!p)
		return ERROR;
	p->data = e;
	return OK;
}
void FreeNode(Link &p)
{ // 释放p所指结点
	free(p);
	p = NULL;
}
Status InitList(LinkList &L)
{ // 构造一个空的线性链表
	Link p;
	p = (Link)malloc(sizeof(LNode)); // 生成头结点
	if (p)
	{
		p->next = NULL;
		L.head = L.tail = p;
		L.len = 0;
		return OK;
	}
	else
		return ERROR;
}
Status InsFirst(LinkList &L, Link h, Link s) 
{
	s->next = h->next;
	h->next = s;
	if (h == L.tail) 
		L.tail = h->next;
	L.len++;
	return OK;
}
Status DelFirst(LinkList &L, Link h, Link &q) 
{
	q = h->next;
	if (q) // 链表非空
	{
		h->next = q->next;
		if (!h->next) // 删除尾结点
			L.tail = h; // 修改尾指针
		L.len--;
		return OK;
	}
	else
		return FALSE; 
}
Status Append(LinkList &L, Link s)
{ // 将指针s(s->data为第一个数据元素)所指(彼此以指针相链,以NULL结尾)的
  // 一串结点链接在线性链表L的最后一个结点之后,并改变链表L的尾指针指向新的尾结点
	int i = 1;
	L.tail->next = s;
	while (s->next)
	{
		s = s->next;
		i++;
	}
	L.tail = s;
	L.len += i;
	return OK;
}
Status SetCurElem(Link p, ElemType e){
	p->data = e;
	return OK;
}
ElemType GetCurElem(Link p){
	// 已知p指向线性链表中的一个结点，返回p所指结点中数据元素的值
	return p->data;
}
Status ListEmpty(LinkList L)
{ // 若线性链表L为空表，则返回TRUE，否则返回FALSE
	if (L.len)
		return FALSE;
	else
		return TRUE;
}
int ListLength(LinkList L)
{ // 返回线性链表L中元素个数
	return L.len;
}
Position GetHead(LinkList L)
{ // 返回线性链表L中头结点的位置
	return L.head;
}
Position NextPos(Link p)
{ // 已知p指向线性链表L中的一个结点，返回p所指结点的直接后继的位置
  // 若无后继，则返回NULL
	return p->next;
}
Status LocatePos(LinkList L, int i, Link &p)
{ // 返回p指示线性链表L中第i个结点的位置，并返回OK，i值不合法时返回ERROR
	int j;
	if (i<0 || i>L.len)
		return ERROR;
	else
	{
		p = L.head;
		for (j = 1; j <= i; j++)
			p = p->next;
		return OK;
	}
}
Status ListTraverse(LinkList L, void(*print)(ElemType))
{
	Link p = L.head->next;
	int j;
	for (j = 1; j <= L.len; j++)
	{
		print(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

Status ListInsert_L(LinkList &L, int i, ElemType e) 
{ // 在带头结点的单链线性表L的第i个元素之前插入元素e
	Link h, s;
	if (!LocatePos(L, i - 1, h))
		return ERROR; // i值不合法
	if (!MakeNode(s, e))return ERROR; // 结点分配失败
	InsFirst(L, h, s); //对于从第i个结点开始的链表,第i-1个结点是它的头结点
	return OK;
}
Status MergeList_L(LinkList La, LinkList Lb, LinkList &Lc, int(*compare)(ElemType, ElemType))
{ // 已知单链线性表La和Lb的元素按值非递减排列。归并La和Lb得到新的单链
	Link ha, hb, pa, pb, q;
	ElemType a, b;
	if (!InitList(Lc))return ERROR; // 存储空间分配失败
	ha = GetHead(La); // ha和hb分别指向La和Lb的头结点
	hb = GetHead(Lb);
	pa = NextPos(ha); // pa和pb分别指向La和Lb的第一个结点
	pb = NextPos(hb);
	while (!ListEmpty(La) && !ListEmpty(Lb)) 
	{
		a = GetCurElem(pa); 
		b = GetCurElem(pb);
		if (compare(a, b) <= 0)
		{
			DelFirst(La, ha, q);
			InsFirst(Lc, Lc.tail, q);
			pa = NextPos(ha);
		}
		else 
		{
			DelFirst(Lb, hb, q);
			InsFirst(Lc, Lc.tail, q);
			pb = NextPos(hb);
		}
	}
	if (!ListEmpty(La))
		Append(Lc, pa);
	else
		Append(Lc, pb);
	FreeNode(ha);
	FreeNode(hb);
	return OK;
}
int comp(ElemType c1, ElemType c2)
{
	if (c1 > c2)return 1;
	else return -1;
}
void print(ElemType c)
{
	printf("%d ", c); 
}
int main()
{
	LinkList La, Lb, Lc;
	int j;
	InitList(La);
	for (j = 1; j <= 5; j++)
		ListInsert_L(La, j, j); 
	ListTraverse(La, print);
	InitList(Lb);
	for (j = 1; j <= 5; j++)
		ListInsert_L(Lb, j, 2 * j); 
	ListTraverse(Lb, print);
	InitList(Lc);
	MergeList_L(La, Lb, Lc, comp); 
	ListTraverse(Lc, print);
}