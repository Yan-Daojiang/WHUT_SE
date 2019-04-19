/**
* @author: Yan_Daojiang
* @date: 2018/10/13
* @description:��ʽ�洢ʵ�ֹ鲢
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
{ // ������pָ���ֵΪe�Ľ�㣬������OK��������ʧ�ܡ��򷵻�ERROR
	p = (Link)malloc(sizeof(LNode));
	if (!p)
		return ERROR;
	p->data = e;
	return OK;
}
void FreeNode(Link &p)
{ // �ͷ�p��ָ���
	free(p);
	p = NULL;
}
Status InitList(LinkList &L)
{ // ����һ���յ���������
	Link p;
	p = (Link)malloc(sizeof(LNode)); // ����ͷ���
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
	if (q) // ����ǿ�
	{
		h->next = q->next;
		if (!h->next) // ɾ��β���
			L.tail = h; // �޸�βָ��
		L.len--;
		return OK;
	}
	else
		return FALSE; 
}
Status Append(LinkList &L, Link s)
{ // ��ָ��s(s->dataΪ��һ������Ԫ��)��ָ(�˴���ָ������,��NULL��β)��
  // һ�������������������L�����һ�����֮��,���ı�����L��βָ��ָ���µ�β���
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
	// ��֪pָ�����������е�һ����㣬����p��ָ���������Ԫ�ص�ֵ
	return p->data;
}
Status ListEmpty(LinkList L)
{ // ����������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE
	if (L.len)
		return FALSE;
	else
		return TRUE;
}
int ListLength(LinkList L)
{ // ������������L��Ԫ�ظ���
	return L.len;
}
Position GetHead(LinkList L)
{ // ������������L��ͷ����λ��
	return L.head;
}
Position NextPos(Link p)
{ // ��֪pָ����������L�е�һ����㣬����p��ָ����ֱ�Ӻ�̵�λ��
  // ���޺�̣��򷵻�NULL
	return p->next;
}
Status LocatePos(LinkList L, int i, Link &p)
{ // ����pָʾ��������L�е�i������λ�ã�������OK��iֵ���Ϸ�ʱ����ERROR
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
{ // �ڴ�ͷ���ĵ������Ա�L�ĵ�i��Ԫ��֮ǰ����Ԫ��e
	Link h, s;
	if (!LocatePos(L, i - 1, h))
		return ERROR; // iֵ���Ϸ�
	if (!MakeNode(s, e))return ERROR; // ������ʧ��
	InsFirst(L, h, s); //���ڴӵ�i����㿪ʼ������,��i-1�����������ͷ���
	return OK;
}
Status MergeList_L(LinkList La, LinkList Lb, LinkList &Lc, int(*compare)(ElemType, ElemType))
{ // ��֪�������Ա�La��Lb��Ԫ�ذ�ֵ�ǵݼ����С��鲢La��Lb�õ��µĵ���
	Link ha, hb, pa, pb, q;
	ElemType a, b;
	if (!InitList(Lc))return ERROR; // �洢�ռ����ʧ��
	ha = GetHead(La); // ha��hb�ֱ�ָ��La��Lb��ͷ���
	hb = GetHead(Lb);
	pa = NextPos(ha); // pa��pb�ֱ�ָ��La��Lb�ĵ�һ�����
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