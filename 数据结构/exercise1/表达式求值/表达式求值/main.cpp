/***
** @author: Yan_Daojiang
** @date: 2018/10/16
**@description:ģ����������ܵĳ���������һ�����ʽ��
**�����һ����ȷ�ı��ʽ������ñ��ʽ��ֵ���������ĳ�ִ�����Ϣ
***/
#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef char SElemType;
#define STACK_INIT_SIZE 10
#define STACKINCREMENT 2
typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

Status InitStack(SqStack &S)
{//����һ����ս
	S.base = (SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}
Status StackEmpty(SqStack S)
{//�ж��Ƿ�Ϊһ����ջ
	if (S.base == S.top)return TRUE;
	else return FALSE;
}
Status GetTop(SqStack S, SElemType &e)
{//��Ԫ��e����ջ��Ԫ�أ�������OK�����򷵻�ERROR 
	if (StackEmpty(S) == TRUE)return ERROR;
	else
		e = *(S.top - 1);
	return OK;
}
Status Push(SqStack &S, SElemType e)
{ // ����Ԫ��eΪ�µ�ջ��Ԫ��
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
Status Pop(SqStack &S, SElemType &e)
{ // ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
	if (S.top == S.base)
		return ERROR;
	e = *--S.top;
	return OK;
}

/********��ֵ���̾���ʵ��********/
SElemType Precede(SElemType t1, SElemType t2)
{ //�ж������ŵ����ȹ�ϵ
	SElemType f;
	switch (t2){
	case '+':
	case '-':
		if (t1 == '(' || t1 == '#')
		f = '<';
		else
			f = '>';
		break;
	case '*':
	case '/':
		if (t1 == '*' || t1 == '/' || t1 == ')')
		f = '>';
		else
			f = '<';
		break;
	case '(':
		if (t1 == ')')
		exit(ERROR);
		else
			f = '<';
		break;
	case ')':
		switch (t1){
		case '(':f = '=';
			break;
		case '#':
			printf("ERROR2\n");
			exit(ERROR);
		default: f = '>';
		}
		 break;
	case '#':
		switch (t1){
			case '#':f = '=';
			break;
			case '(':
			exit(ERROR);
		default: 
			f = '>';
		}
	}
	return f;
}

Status In(SElemType c)
{ // �ж�c�Ƿ�Ϊ�����
	switch (c)
	{
	case'+':
	case'-':
	case'*':
	case'/':
	case'(':
	case')':
	case'#':return TRUE;
	default:return FALSE;
	}
}
SElemType Operate(SElemType a, SElemType theta, SElemType b) {
	//���ж�Ԫ����ĺ���ʵ��
	SElemType c = 0;
	a = a - 48;
	b = b - 48;
	switch (theta)
	{
	case'+':
		c = a + b + 48;
		break;
	case'-':
		c = a - b + 48;
		break;
	case'*':
		c = a*b + 48;
		break;
	case'/':
		c = a / b + 48;
	}
	return c;
}
SElemType EvaluateExpression() {
	//�������ʽ����������㷨
	SqStack OPTR, OPND;
	SElemType a, b, c, x , theta;
	InitStack(OPTR);
	Push(OPTR, '#');
	InitStack(OPND);
	c = getchar();
	GetTop(OPTR, x);
	printf("%c", x);
	while (c != '#' || x != '#') {
		if (!In(c)) {
			Push(OPND, c);
			c = getchar();
		}
		else {
			switch (Precede(x, c) ){
			case'<'://ջ��Ԫ�ص����ȼ���
				Push(OPTR, c);
				c = getchar();
				break;
			case'='://�����Ų�������һ���ַ�
				Pop(OPTR, x);
				c = getchar();
				break;
			case'>'://��ջ��������
				Pop(OPTR, theta);
				Pop(OPND, a);
				Pop(OPND, b);
				Push(OPND, Operate(a, theta, b));//���м����ٴ�ѹ�뵽ջ��
				break;
			}
			GetTop(OPTR, x);
		}
	}
	GetTop(OPND, x);
	return x;
}
int main(){
	printf("�����������ʽ��#����\n");
	printf("%c\n", EvaluateExpression());
}
