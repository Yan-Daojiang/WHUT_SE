#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "menu.h"


//菜单选项函数
void outmenu()
{
	printf("--------------菜单------------\n");
	printf("1.新建并输出\n");
	printf("2.查找\n");
	printf("0.退出\n");
	printf("请输入菜单编号(0~8):");
}
int n;

struct Student *creat(void) 
{ 
	struct Student *head,*p1,*p2;  n=0;
	p1=p2=( struct Student*) malloc(sizeof(struct Student)); 
	printf("请依次输入学号和成绩:\n");
	scanf_s("%ld%f",&p1->num,&p1->score); 
	head=NULL;
	while(p1->num!=0)
	{
		n=n+1;
		if(n==1) 
			head=p1;
		else  
			p2->next=p1;
		p2=p1;
		p1=(struct Student*)malloc(sizeof(struct Student)); 
		scanf_s("%ld%f",&p1->num,&p1->score);
	}
	p2->next=NULL;    
	return(head);
}
void print(struct Student *p)  
{   
	printf("\nThese %d records are:\n", n);
	if(p!=NULL)
	{ 
      do
      {

		  
		  printf("%ld %5.1f\n",p->num,p->score);
		 p=p->next;
      }while(p!=NULL);
 	} 
}
void find(struct Student *pt,long num)
{
	if(pt==NULL)
 	printf("\n没有记录存在！\n"); 
 	else{
	struct Student *p1;
	int flag=0;
	p1=pt;
	while(p1!=NULL){
	if(p1->num==num)
	{printf("该同学的学号为%ld成绩为%f\n",p1->num,p1->score);
	flag=1;
	break;}
	p1=p1->next;
	}
	if(flag==0)
	printf("很抱歉，没有找到您所需要的同学！\n"); 
	}	
}