/***
** @author: Yan_Daojiang
** @date: 2018/10/16
**@description:模拟计算器功能的程序，它读入一个表达式，
**如果是一个正确的表达式则求出该表达式的值；否则给出某种错误信息
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
{//构造一个空战
	S.base = (SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}
Status StackEmpty(SqStack S)
{//判断是否为一个空栈
	if (S.base == S.top)return TRUE;
	else return FALSE;
}
Status GetTop(SqStack S, SElemType &e)
{//用元素e返回栈顶元素，并返回OK，否则返回ERROR 
	if (StackEmpty(S) == TRUE)return ERROR;
	else
		e = *(S.top - 1);
	return OK;
}
Status Push(SqStack &S, SElemType e)
{ // 插入元素e为新的栈顶元素
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
Status Pop(SqStack &S, SElemType &e)
{ // 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
	if (S.top == S.base)
		return ERROR;
	e = *--S.top;
	return OK;
}

/********求值过程具体实现********/
SElemType Precede(SElemType t1, SElemType t2)
{ //判断两符号的优先关系
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
{ // 判断c是否为运算符
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
	//进行二元运算的函数实现
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
	//算术表达式的算符优先算法
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
			case'<'://栈顶元素的优先级低
				Push(OPTR, c);
				c = getchar();
				break;
			case'='://脱括号并接受下一个字符
				Pop(OPTR, x);
				c = getchar();
				break;
			case'>'://退栈进行运算
				Pop(OPTR, theta);
				Pop(OPND, a);
				Pop(OPND, b);
				Push(OPND, Operate(a, theta, b));//将中间结果再次压入到栈顶
				break;
			}
			GetTop(OPTR, x);
		}
	}
	GetTop(OPND, x);
	return x;
}
int main(){
	printf("输入算术表达式以#结束\n");
	printf("%c\n", EvaluateExpression());
}
