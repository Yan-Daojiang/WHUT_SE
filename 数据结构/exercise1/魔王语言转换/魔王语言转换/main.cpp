/***
** @author: Yan_Daojiang
** @date: 2018/10/22
**@description:ħ�����Խ���
**@��������:B(einxgz)B
**@��׼���:����һ�������һ�����׷��϶��¶쵰��޶�����һ�������һ����
***/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef char SElemType;
typedef char QElemType;
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 2
typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;
 typedef struct QNode{
   QElemType data;
   QNode *next;
 }*QueuePtr;
 struct LinkQueue {
   QueuePtr front,rear; // ��ͷ����βָ��
 };
Status InitStack(SqStack &S){//����һ����ս
	S.base = (SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}
Status Push(SqStack &S, SElemType e){ // ����Ԫ��eΪ�µ�ջ��Ԫ��
	if (S.top - S.base >= S.stacksize) // ջ����׷�Ӵ洢�ռ�
	{
		S.base = (SElemType *)realloc(S.base, (S.stacksize + STACKINCREMENT)*sizeof(SElemType));
		if (!S.base)
			exit(OVERFLOW); // �洢����ʧ��
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*(S.top)++ = e;
	return OK;
}
Status Pop(SqStack &S, SElemType &e){ // ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
	if (S.top == S.base)
		return ERROR;
	e = *--S.top;
	return OK;
}
Status InitQueue(LinkQueue &Q){ // ����һ���ն���Q
	if (!(Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode))))
		exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}
Status EnQueue(LinkQueue &Q, QElemType e){ // ����Ԫ��eΪQ���µĶ�βԪ��
	QueuePtr p;
	if (!(p = (QueuePtr)malloc(sizeof(QNode)))) // �洢����ʧ��
		exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}
Status DeQueue(LinkQueue &Q, QElemType &e){ // �����в���,ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������OK,���򷵻�ERROR
	QueuePtr p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return OK;
}
int main() {
	char str[100];
	printf("������ħ������:\n");
	gets_s(str);
	SqStack S;
	InitStack(S);
	char k[20];
	for (int i = strlen(str) - 1; i >= 0; i--) {//��ħ������������ջ,������ջ��ʱ��ת����д��ĸ
		if (str[i] == 'A') {
			strcpy(k, "sae");
			for (int j = strlen(k) - 1; j >= 0; j--)
				Push(S, k[j]);
		}
		else if (str[i] == 'B') {
			strcpy(k, "tsaedsae");
			for (int j = strlen(k) - 1; j >= 0; j--)
				Push(S, k[j]);
		}
		else
			Push(S, str[i]);
	}
	char e = 0, c;
	LinkQueue Q;
	InitQueue(Q);
	while (e != '('&S.base != S.top) {
		Pop(S, e);//û��ƥ�䵽����ʱֱ�ӳ�ջ���
		if (e == '(')
			break;
		else
			EnQueue(Q, e);
	}
	char temp;
	Pop(S, temp);
	//������֮���Ԫ�ض��뵽һ���ַ�����(��ȥ���ŵĵ�һ���ַ���
	char t[100];
	int l = 0;
	while (e != ')'&&S.base!=S.top) {
		if (e == ')')
			break;
		Pop(S, e);
		t[l] = e;
		l++;
	}
	//��������ַ������չ������
	for (int i = l - 2; i >= 0; i--) {
		EnQueue(Q, temp);
		EnQueue(Q, t[i]);
	}
	EnQueue(Q, temp);
	//Ȼ���ٽ�ʣ���Ԫ�����
	while (S.base != S.top) {
		Pop(S, e);
		EnQueue(Q, e);
	}
	printf("ħ��˵����:\n");
	//���е�Ԫ�س��ӽ���ƥ��
	while (Q.front != Q.rear) {//�������е�Ԫ�ز�λ��ʱ����з���
		DeQueue(Q, e);
		switch (e){
		case 't': printf("��");   break;
		case 'd': printf("��");   break;
		case 's': printf("��");   break;
		case 'a': printf("һ��"); break;
		case 'e': printf("��");   break;
		case 'z': printf("׷");   break;
		case 'g': printf("��");   break;
		case 'x': printf("��");   break;
		case 'n': printf("��");   break;
		case 'i': printf("��");   break;
		default:                  break;
		}
	}
	printf("\n");
	return 0;
}