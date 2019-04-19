/***
** @author: Yan_Daojiang
** @date: 2018/10/22
**@description:魔王语言解释
**@测试数据:B(einxgz)B
**@标准结果:天上一个鹅地上一个鹅鹅追鹅赶鹅下鹅蛋鹅恨鹅天上一个鹅地上一个鹅
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
   QueuePtr front,rear; // 队头、队尾指针
 };
Status InitStack(SqStack &S){//构造一个空战
	S.base = (SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}
Status Push(SqStack &S, SElemType e){ // 插入元素e为新的栈顶元素
	if (S.top - S.base >= S.stacksize) // 栈满，追加存储空间
	{
		S.base = (SElemType *)realloc(S.base, (S.stacksize + STACKINCREMENT)*sizeof(SElemType));
		if (!S.base)
			exit(OVERFLOW); // 存储分配失败
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*(S.top)++ = e;
	return OK;
}
Status Pop(SqStack &S, SElemType &e){ // 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
	if (S.top == S.base)
		return ERROR;
	e = *--S.top;
	return OK;
}
Status InitQueue(LinkQueue &Q){ // 构造一个空队列Q
	if (!(Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode))))
		exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}
Status EnQueue(LinkQueue &Q, QElemType e){ // 插入元素e为Q的新的队尾元素
	QueuePtr p;
	if (!(p = (QueuePtr)malloc(sizeof(QNode)))) // 存储分配失败
		exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}
Status DeQueue(LinkQueue &Q, QElemType &e){ // 若队列不空,删除Q的队头元素,用e返回其值,并返回OK,否则返回ERROR
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
	printf("请输入魔王语言:\n");
	gets_s(str);
	SqStack S;
	InitStack(S);
	char k[20];
	for (int i = strlen(str) - 1; i >= 0; i--) {//将魔王语言逆序入栈,并在入栈的时候转换大写字母
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
		Pop(S, e);//没有匹配到括号时直接出栈入队
		if (e == '(')
			break;
		else
			EnQueue(Q, e);
	}
	char temp;
	Pop(S, temp);
	//将括号之间的元素读入到一个字符串中(除去括号的第一个字符）
	char t[100];
	int l = 0;
	while (e != ')'&&S.base!=S.top) {
		if (e == ')')
			break;
		Pop(S, e);
		t[l] = e;
		l++;
	}
	//在让这个字符串按照规则入队
	for (int i = l - 2; i >= 0; i--) {
		EnQueue(Q, temp);
		EnQueue(Q, t[i]);
	}
	EnQueue(Q, temp);
	//然后再将剩余的元素入队
	while (S.base != S.top) {
		Pop(S, e);
		EnQueue(Q, e);
	}
	printf("魔王说的是:\n");
	//所有的元素出队进行匹配
	while (Q.front != Q.rear) {//当队列中的元素部位空时间进行翻译
		DeQueue(Q, e);
		switch (e){
		case 't': printf("天");   break;
		case 'd': printf("地");   break;
		case 's': printf("上");   break;
		case 'a': printf("一个"); break;
		case 'e': printf("鹅");   break;
		case 'z': printf("追");   break;
		case 'g': printf("赶");   break;
		case 'x': printf("下");   break;
		case 'n': printf("蛋");   break;
		case 'i': printf("恨");   break;
		default:                  break;
		}
	}
	printf("\n");
	return 0;
}