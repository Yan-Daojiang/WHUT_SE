/**
* @author: Yan_Daojiang
* @date: 2018/10/7
* @description:有两个指数递减的一元多项式，写一程序先求这两个多项式的和，再求它们的积。
**/
#include<stdio.h> 
#include<stdlib.h> 
// 函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1

typedef int Status; 

typedef struct {
	float coef; // 系数
	int expn; // 指数
}term, ElemType;
typedef struct LNode { 
	ElemType data;
	LNode *next;
}*Link, *Position;

struct LinkList { 
	Link head, tail; 
	int len; 
};

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
	p = (Link)malloc(sizeof(LNode)); 
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

Status ClearList(LinkList &L)
{ // 将线性链表L重置为空表，并释放原链表的结点空间
	Link p, q;
	if (L.head != L.tail)// 不是空表
	{
		p = q = L.head->next;
		L.head->next = NULL;
		while (p != L.tail)
		{
			p = q->next;
			free(q);
			q = p;
		}
		free(q);
		L.tail = L.head;
		L.len = 0;
	}
	return OK;
}

Status DestroyList(LinkList &L)
{ // 销毁线性链表L，L不再存在
	ClearList(L); // 清空链表
	FreeNode(L.head);
	L.tail = NULL;
	L.len = 0;
	return OK;
}

Status InsFirst(LinkList &L, Link h, Link s) 
{ // h指向L的一个结点，把h当做头结点，将s所指结点插入在第一个结点之前
	s->next = h->next;
	h->next = s;
	if (h == L.tail) // h指向尾结点
		L.tail = h->next; // 修改尾指针
	L.len++;
	return OK;
}

Status DelFirst(LinkList &L, Link h, Link &q) 
{ // h指向L的一个结点，把h当做头结点，删除链表中的第一个结点并以q返回。
  // 若链表为空(h指向尾结点)，q=NULL，返回FALSE
	q = h->next;
	if (q) // 链表非空
	{
		h->next = q->next;
		if (!h->next) 
			L.tail = h; 
		L.len--;
		return OK;
	}
	else
		return FALSE; // 链表空
}

Status Append(LinkList &L, Link s)
{ // 将指针s(s->data为第一个数据元素)所指(彼此以指针相链,以NULL结尾)的 
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

Position PriorPos(LinkList L, Link p)
{ // 已知p指向线性链表L中的一个结点，返回p所指结点的直接前驱的位置
	Link q;
	q = L.head->next;
	if (q == p) // 无前驱
		return NULL;
	else
	{
		while (q->next != p) // q不是p的直接前驱
			q = q->next;
		return q;
	}
}

Status Remove(LinkList &L, Link &q)
{ // 删除线性链表L中的尾结点并以q返回，改变链表L的尾指针指向新的尾结点
	Link p = L.head;
	if (L.len == 0) 
	{
		q = NULL;
		return FALSE;
	}
	while (p->next != L.tail)
		p = p->next;
	q = L.tail;
	p->next = NULL;
	L.tail = p;
	L.len--;
	return OK;
}

Status InsBefore(LinkList &L, Link &p, Link s)
{ // 已知p指向线性链表L中的一个结点，将s所指结点插入在p所指结点之前，
  // 并修改指针p指向新插入的结点
	Link q;
	q = PriorPos(L, p); // q是p的前驱
	if (!q) // p无前驱
		q = L.head;
	s->next = p;
	q->next = s;
	p = s;
	L.len++;
	return OK;
}

Status InsAfter(LinkList &L, Link &p, Link s)
{ // 已知p指向线性链表L中的一个结点，将s所指结点插入在p所指结点之后，
	if (p == L.tail) // 修改尾指针
		L.tail = s;
	s->next = p->next;
	p->next = s;
	p = s;
	L.len++;
	return OK;
}

Status SetCurElem(Link p, ElemType e)
{ // 已知p指向线性链表中的一个结点，用e更新p所指结点中数据元素的值
	p->data = e;
	return OK;
}

ElemType GetCurElem(Link p)
{ // 已知p指向线性链表中的一个结点，返回p所指结点中数据元素的值
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

Position GetLast(LinkList L)
{ // 返回线性链表L中最后一个结点的位置
	return L.tail;
}
Position NextPos(Link p)
{ // 已知p指向线性链表L中的一个结点，返回p所指结点的直接后继的位置
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

Position LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType))
{ // 返回线性链表L中第1个与e满足函数compare()判定关系的元素的位置，
	Link p = L.head;
	do
		p = p->next;
	while (p&&!(compare(p->data, e))); // 没到表尾且没找到满足关系的元素
	return p;
}

Status ListTraverse(LinkList L, void(*visit)(ElemType))
{ // 依次对L的每个数据元素调用函数visit()。一旦visit()失败，则操作失败
	Link p = L.head->next;
	int j;
	for (j = 1; j <= L.len; j++)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}
Status OrderInsert(LinkList &L, ElemType e, int(*comp)(ElemType, ElemType))
{ // 已知L为有序线性链表，将元素e按非降序插入在L中
	Link o, p, q;
	q = L.head;
	p = q->next;
	while (p != NULL&&comp(p->data, e)<0) // p不是表尾且元素值小于e
	{
		q = p;
		p = p->next;
	}
	o = (Link)malloc(sizeof(LNode)); // 生成结点
	o->data = e; 
	q->next = o; 
	o->next = p;
	L.len++; 
	if (!p) 
		L.tail = o; 
	return OK;
}

Status LocateElem(LinkList L, ElemType e, Position &q, int(*compare)(ElemType, ElemType))
{ // 若升序链表L中存在与e满足判定函数compare()取值为0的元素，则q指示L中第一个
	Link p = L.head, pp;
	do
	{
		pp = p;
		p = p->next;
	} while (p && (compare(p->data, e)<0)); 
	if (!p || compare(p->data, e)>0)
	{
		q = pp;
		return FALSE;
	}
	else 
	{
		q = p;
		return TRUE;
	}
}
typedef LinkList polynomial;
Status OrderInsertMerge(LinkList &L, ElemType e, int(*compare)(term, term))
{ // 按有序判定函数compare()的约定，将值为e的结点插入或合并到升序链表L的适当位置
	Position q, s;
	if (LocateElem(L, e, q, compare)) // L中存在该指数项
	{
		q->data.coef += e.coef; // 改变当前结点系数的值
		if (!q->data.coef) // 系数为0
		{ 
			s = PriorPos(L, q); 
			if (!s) 
				s = L.head;
			DelFirst(L, s, q);
			FreeNode(q);
		}
		return OK;
	}
	else 
		if (MakeNode(s, e)) 
		{
			InsFirst(L, q, s);
			return OK;
		}
		else // 生成结点失败
			return ERROR;
}

int cmp(term a, term b) 
{ // 依a的指数值<、=或>b的指数值，分别返回-1、0或+1
	if (a.expn == b.expn)
		return 0;
	else
		return (a.expn - b.expn) / abs(a.expn - b.expn);
}

void CreatPolyn(polynomial &P, int m) 
{ // 输入m项的系数和指数，建立表示一元多项式的有序链表P
	Position q, s;
	term e;
	int i;
	InitList(P);
	printf("请依次输入%d个系数，指数：\n", m);
	for (i = 1; i <= m; ++i)
	{ 
		scanf("%f,%d", &e.coef, &e.expn);
		if (!LocateElem(P, e, q, cmp))
			if (MakeNode(s, e)) 
				InsFirst(P, q, s);
	}
}

void PrintPolyn(polynomial P)
{ // 打印输出一元多项式P
	Link q;
	q = P.head->next; // q指向第一个结点
	printf("  系数    指数\n");
	while (q)
	{
		printf("%f  %d\n", q->data.coef, q->data.expn);
		q = q->next;
	}
}

void AddPolyn(polynomial &Pa, polynomial &Pb) 
{ // 多项式加法:Pa=Pa+Pb
	Position ha, hb, qa, qb;
	term a, b;
	ha = GetHead(Pa);
	hb = GetHead(Pb); // ha和hb分别指向Pa和Pb的头结点
	qa = NextPos(ha);
	qb = NextPos(hb); // qa和qb分别指向Pa和Pb中当前结点（现为第一个结点）
	while (!ListEmpty(Pa) && !ListEmpty(Pb) && qa)
	{ // Pa和Pb均非空且ha没指向尾结点(qa!=0)
		a = GetCurElem(qa);
		b = GetCurElem(qb); // a和b为两表中当前比较元素
		switch (cmp(a, b))
		{
		case -1:ha = qa; // 多项式Pa中当前结点的指数值小
			qa = NextPos(ha); // ha和qa均向后移一个结点
			break;
		case 0: qa->data.coef += qb->data.coef;
			// 两者的指数值相等,修改Pa当前结点的系数值
			if (qa->data.coef == 0) // 删除多项式Pa中当前结点
			{
				DelFirst(Pa, ha, qa);
				FreeNode(qa);
			}
			else
				ha = qa;
			DelFirst(Pb, hb, qb);
			FreeNode(qb);
			qb = NextPos(hb);
			qa = NextPos(ha);
			break;
		case 1: DelFirst(Pb, hb, qb); // 多项式Pb中当前结点的指数值小
			InsFirst(Pa, ha, qb);
			ha = ha->next;
			qb = NextPos(hb);
		}
	}
	if (!ListEmpty(Pb))
	{
		Pb.tail = hb;
		Append(Pa, qb); // 链接Pb中剩余结点
	}
	DestroyList(Pb); // 销毁Pb
}

void MultiplyPolyn(polynomial &Pa, polynomial &Pb)
{ // 多项式乘法
	polynomial Pc;
	Position qa, qb;
	term a, b, c;
	InitList(Pc);
	qa = GetHead(Pa);
	qa = qa->next;
	while (qa)
	{
		a = GetCurElem(qa);
		qb = GetHead(Pb);
		qb = qb->next;
		while (qb)
		{
			b = GetCurElem(qb);
			c.coef = a.coef*b.coef;
			c.expn = a.expn + b.expn;
			OrderInsertMerge(Pc, c, cmp);
			qb = qb->next;
		}
		qa = qa->next;
	}
	DestroyList(Pb); // 销毁Pb
	ClearList(Pa); // 将Pa重置为空表
	Pa.head = Pc.head;
	Pa.tail = Pc.tail;
	Pa.len = Pc.len;
}

int main()
{
	polynomial p, q;
	int m;
	printf("--------------说明---------------\n");
	printf("计算时先输入多项式的项数，然后可按任意顺序输入系数和指数\n");
	printf("注意：每一项的系数和指数之间用英文逗号隔开\n");
	printf("---------------------------------------\n");
	printf("输入第一个多项式的项数m:\n");
	scanf("%d", &m);
	CreatPolyn(p, m);
	printf("输入第二个多项式的项数m:\n");
	scanf("%d", &m);
	CreatPolyn(q, m);
	AddPolyn(p, q);
	printf("-----------------执行以上两个多项式相加的结果---------------------\n");
	PrintPolyn(p);
	printf("-----------------------------------------------------\n");
	//进行多项式的乘法运算
	printf("输入第三个多项式的项数m:\n");
	scanf("%d", &m);
	CreatPolyn(p, m);
	printf("输入第四个多项式的项数m:\n");
	scanf("%d", &m);
	CreatPolyn(q, m);
	MultiplyPolyn(p, q);
	printf("--------------执行以上两个多项式相乘的结果--------------------\n");
	PrintPolyn(p);
	DestroyList(p);
}
