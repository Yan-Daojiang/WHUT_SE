/**
* @author: Yan_Daojiang
* @date: 2018/10/7
* @description:������ָ���ݼ���һԪ����ʽ��дһ������������������ʽ�ĺͣ��������ǵĻ���
**/
#include<stdio.h> 
#include<stdlib.h> 
// �������״̬����
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1

typedef int Status; 

typedef struct {
	float coef; // ϵ��
	int expn; // ָ��
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
{ // ����������L����Ϊ�ձ����ͷ�ԭ����Ľ��ռ�
	Link p, q;
	if (L.head != L.tail)// ���ǿձ�
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
{ // ������������L��L���ٴ���
	ClearList(L); // �������
	FreeNode(L.head);
	L.tail = NULL;
	L.len = 0;
	return OK;
}

Status InsFirst(LinkList &L, Link h, Link s) 
{ // hָ��L��һ����㣬��h����ͷ��㣬��s��ָ�������ڵ�һ�����֮ǰ
	s->next = h->next;
	h->next = s;
	if (h == L.tail) // hָ��β���
		L.tail = h->next; // �޸�βָ��
	L.len++;
	return OK;
}

Status DelFirst(LinkList &L, Link h, Link &q) 
{ // hָ��L��һ����㣬��h����ͷ��㣬ɾ�������еĵ�һ����㲢��q���ء�
  // ������Ϊ��(hָ��β���)��q=NULL������FALSE
	q = h->next;
	if (q) // ����ǿ�
	{
		h->next = q->next;
		if (!h->next) 
			L.tail = h; 
		L.len--;
		return OK;
	}
	else
		return FALSE; // �����
}

Status Append(LinkList &L, Link s)
{ // ��ָ��s(s->dataΪ��һ������Ԫ��)��ָ(�˴���ָ������,��NULL��β)�� 
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
{ // ��֪pָ����������L�е�һ����㣬����p��ָ����ֱ��ǰ����λ��
	Link q;
	q = L.head->next;
	if (q == p) // ��ǰ��
		return NULL;
	else
	{
		while (q->next != p) // q����p��ֱ��ǰ��
			q = q->next;
		return q;
	}
}

Status Remove(LinkList &L, Link &q)
{ // ɾ����������L�е�β��㲢��q���أ��ı�����L��βָ��ָ���µ�β���
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
{ // ��֪pָ����������L�е�һ����㣬��s��ָ��������p��ָ���֮ǰ��
  // ���޸�ָ��pָ���²���Ľ��
	Link q;
	q = PriorPos(L, p); // q��p��ǰ��
	if (!q) // p��ǰ��
		q = L.head;
	s->next = p;
	q->next = s;
	p = s;
	L.len++;
	return OK;
}

Status InsAfter(LinkList &L, Link &p, Link s)
{ // ��֪pָ����������L�е�һ����㣬��s��ָ��������p��ָ���֮��
	if (p == L.tail) // �޸�βָ��
		L.tail = s;
	s->next = p->next;
	p->next = s;
	p = s;
	L.len++;
	return OK;
}

Status SetCurElem(Link p, ElemType e)
{ // ��֪pָ�����������е�һ����㣬��e����p��ָ���������Ԫ�ص�ֵ
	p->data = e;
	return OK;
}

ElemType GetCurElem(Link p)
{ // ��֪pָ�����������е�һ����㣬����p��ָ���������Ԫ�ص�ֵ
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

Position GetLast(LinkList L)
{ // ������������L�����һ������λ��
	return L.tail;
}
Position NextPos(Link p)
{ // ��֪pָ����������L�е�һ����㣬����p��ָ����ֱ�Ӻ�̵�λ��
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

Position LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType))
{ // ������������L�е�1����e���㺯��compare()�ж���ϵ��Ԫ�ص�λ�ã�
	Link p = L.head;
	do
		p = p->next;
	while (p&&!(compare(p->data, e))); // û����β��û�ҵ������ϵ��Ԫ��
	return p;
}

Status ListTraverse(LinkList L, void(*visit)(ElemType))
{ // ���ζ�L��ÿ������Ԫ�ص��ú���visit()��һ��visit()ʧ�ܣ������ʧ��
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
{ // ��֪LΪ��������������Ԫ��e���ǽ��������L��
	Link o, p, q;
	q = L.head;
	p = q->next;
	while (p != NULL&&comp(p->data, e)<0) // p���Ǳ�β��Ԫ��ֵС��e
	{
		q = p;
		p = p->next;
	}
	o = (Link)malloc(sizeof(LNode)); // ���ɽ��
	o->data = e; 
	q->next = o; 
	o->next = p;
	L.len++; 
	if (!p) 
		L.tail = o; 
	return OK;
}

Status LocateElem(LinkList L, ElemType e, Position &q, int(*compare)(ElemType, ElemType))
{ // ����������L�д�����e�����ж�����compare()ȡֵΪ0��Ԫ�أ���qָʾL�е�һ��
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
{ // �������ж�����compare()��Լ������ֵΪe�Ľ������ϲ�����������L���ʵ�λ��
	Position q, s;
	if (LocateElem(L, e, q, compare)) // L�д��ڸ�ָ����
	{
		q->data.coef += e.coef; // �ı䵱ǰ���ϵ����ֵ
		if (!q->data.coef) // ϵ��Ϊ0
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
		else // ���ɽ��ʧ��
			return ERROR;
}

int cmp(term a, term b) 
{ // ��a��ָ��ֵ<��=��>b��ָ��ֵ���ֱ𷵻�-1��0��+1
	if (a.expn == b.expn)
		return 0;
	else
		return (a.expn - b.expn) / abs(a.expn - b.expn);
}

void CreatPolyn(polynomial &P, int m) 
{ // ����m���ϵ����ָ����������ʾһԪ����ʽ����������P
	Position q, s;
	term e;
	int i;
	InitList(P);
	printf("����������%d��ϵ����ָ����\n", m);
	for (i = 1; i <= m; ++i)
	{ 
		scanf("%f,%d", &e.coef, &e.expn);
		if (!LocateElem(P, e, q, cmp))
			if (MakeNode(s, e)) 
				InsFirst(P, q, s);
	}
}

void PrintPolyn(polynomial P)
{ // ��ӡ���һԪ����ʽP
	Link q;
	q = P.head->next; // qָ���һ�����
	printf("  ϵ��    ָ��\n");
	while (q)
	{
		printf("%f  %d\n", q->data.coef, q->data.expn);
		q = q->next;
	}
}

void AddPolyn(polynomial &Pa, polynomial &Pb) 
{ // ����ʽ�ӷ�:Pa=Pa+Pb
	Position ha, hb, qa, qb;
	term a, b;
	ha = GetHead(Pa);
	hb = GetHead(Pb); // ha��hb�ֱ�ָ��Pa��Pb��ͷ���
	qa = NextPos(ha);
	qb = NextPos(hb); // qa��qb�ֱ�ָ��Pa��Pb�е�ǰ��㣨��Ϊ��һ����㣩
	while (!ListEmpty(Pa) && !ListEmpty(Pb) && qa)
	{ // Pa��Pb���ǿ���haûָ��β���(qa!=0)
		a = GetCurElem(qa);
		b = GetCurElem(qb); // a��bΪ�����е�ǰ�Ƚ�Ԫ��
		switch (cmp(a, b))
		{
		case -1:ha = qa; // ����ʽPa�е�ǰ����ָ��ֵС
			qa = NextPos(ha); // ha��qa�������һ�����
			break;
		case 0: qa->data.coef += qb->data.coef;
			// ���ߵ�ָ��ֵ���,�޸�Pa��ǰ����ϵ��ֵ
			if (qa->data.coef == 0) // ɾ������ʽPa�е�ǰ���
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
		case 1: DelFirst(Pb, hb, qb); // ����ʽPb�е�ǰ����ָ��ֵС
			InsFirst(Pa, ha, qb);
			ha = ha->next;
			qb = NextPos(hb);
		}
	}
	if (!ListEmpty(Pb))
	{
		Pb.tail = hb;
		Append(Pa, qb); // ����Pb��ʣ����
	}
	DestroyList(Pb); // ����Pb
}

void MultiplyPolyn(polynomial &Pa, polynomial &Pb)
{ // ����ʽ�˷�
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
	DestroyList(Pb); // ����Pb
	ClearList(Pa); // ��Pa����Ϊ�ձ�
	Pa.head = Pc.head;
	Pa.tail = Pc.tail;
	Pa.len = Pc.len;
}

int main()
{
	polynomial p, q;
	int m;
	printf("--------------˵��---------------\n");
	printf("����ʱ���������ʽ��������Ȼ��ɰ�����˳������ϵ����ָ��\n");
	printf("ע�⣺ÿһ���ϵ����ָ��֮����Ӣ�Ķ��Ÿ���\n");
	printf("---------------------------------------\n");
	printf("�����һ������ʽ������m:\n");
	scanf("%d", &m);
	CreatPolyn(p, m);
	printf("����ڶ�������ʽ������m:\n");
	scanf("%d", &m);
	CreatPolyn(q, m);
	AddPolyn(p, q);
	printf("-----------------ִ��������������ʽ��ӵĽ��---------------------\n");
	PrintPolyn(p);
	printf("-----------------------------------------------------\n");
	//���ж���ʽ�ĳ˷�����
	printf("�������������ʽ������m:\n");
	scanf("%d", &m);
	CreatPolyn(p, m);
	printf("������ĸ�����ʽ������m:\n");
	scanf("%d", &m);
	CreatPolyn(q, m);
	MultiplyPolyn(p, q);
	printf("--------------ִ��������������ʽ��˵Ľ��--------------------\n");
	PrintPolyn(p);
	DestroyList(p);
}
