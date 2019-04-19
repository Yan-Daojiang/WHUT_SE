#include"LinearTable_1.h"

/*顺序存储的线性表的具体操作的实现*/
Status InitList_Sq(Sqlist &L)
{
	//操作结果：构造一个空的线性表
	L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L.elem)exit(OVERFLOW);
	L.length=0;
	L.listsize=LIST_INIT_SIZE;
	return OK;
}

Status DestoryList(Sqlist &L)
{
	//初始条件：线性表已经存在
	//操作结果：销毁已经存在的一个线性表
	if(!L.elem)
		return INFEASIBLE;
	else{
		free(L.elem);
		L.length=0;
		L.listsize=0;
		}
	return OK;
}

 Status ClearList(Sqlist &L)
 { 
	 // 初始条件：顺序线性表L已存在
	 // 操作结果：将L重置为空表
   	L.length=0;
   	return OK;
 }


Status ListEmpty(Sqlist L)
{
	//初始条件：线性表已经存在
	//操作结果：如果是空表就返回TRUE 否则返回FALSE
	if(!L.elem)return OVERFLOW;//线性表并不存在
	if(L.length==0)return TRUE;
	if(L.elem!=0)return FALSE;
}

int ListLenth(Sqlist L)
{
	//初始条件：线性表已经存在
	//操作结果：返回线性表中的元素的个数
	if(!L.elem)return OVERFLOW;
	return L.length;
}

Status GetElem(Sqlist L,int i,ElemType &e)
{
	//初始条件：线性表已经存在，1<=i<=Listgth(L)
	//操作结果：用e返回线性表L中的第i个元素
	if(i<=0||i>L.length)exit(ERROR);//参数错误
	e=*(L.elem+i-1);
	return OK;
}

Status LocateElem(Sqlist L,ElemType e,Status(*compare)(ElemType,ElemType))
{
	//初始条件：线性表已经存在，compare()是元素判定函数
	//操作结果：返回线性表中第一个满足判定函数的元素的位序，如果这样的元素不存在就返回0
	if(!L.elem) exit(ERROR);
	ElemType *p;
	int i=1;
	p=L.elem;
	while(i<=L.length&&!compare(*p++,e))
		++i;
	if(i<=L.length)
		return i;
	else return 0;
}

Status PriorElem(Sqlist L,ElemType cur_e,ElemType &pre_e)
{
	//初始条件：线性表已经存在
	//操作结果：若cur_r是线性表的数据元素，并且不是线性表的第一个元素，那么就用pre_e返回他的前驱，否则操作失败，pre_e没有意义
	if(!L.elem)exit(ERROR);
	ElemType *p=L.elem+1;
	int i=2;
	while(i<=L.length&&*p!=cur_e){
		++i;
		++p;
	}
	if(i<=L.length){
		return pre_e=*--p;
		return OK;
	}
	else return INFEASIBLE;
}


Status NextElem(Sqlist L,ElemType cur_e,ElemType &next_e)
{
	//初始条件：线性表已经存在
	//操作结果：若cur_r 是线性表的元素，并且不是最后一个元素，那么就用next_e 返回他的后继，否则操作失败，next_e 没有意义
	if(!L.elem)exit(ERROR);
	int i=1;
	ElemType *p=L.elem;
	while(i<=L.length&&*p!=cur_e){
		++i;
		++p;
	}
	if(i<=L.length-1){
		return next_e=*++p;
		return OK;
	}
	else return INFEASIBLE;
}

Status ListInsert(Sqlist &L,int i,ElemType e)
{
	//初始条件：线性表已经存在，1<=i<=ListLenth(L)+1
	//操作结果：在L 的第i 位之前插入新的元素e，L的长度加1
	if(!L.elem)exit(ERROR);
	if(i<1||i>L.length+1)exit(ERROR);//参数不合法
	//插入操作的具体实现  对应教材的算法2.4
	if(L.length>=L.listsize){//当前的存储空间以将满了，需要增加空间进行存储
		ElemType *newbase=(ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
	if(!newbase)exit(OVERFLOW);//存储空间分配失败
	L.elem=newbase;
	L.listsize+=LISTINCREMENT;
	}
	ElemType *p,*q;
	q=L.elem+i-1;
	for(p=L.elem+L.length-1;p>=q;--p)//插入位置之后的元素向后移动
		*(p+1)=*p;
	*q=e;
	++L.length;
	return OK;
}

Status ListDelete(Sqlist &L,int i,ElemType &e)
{
	//初始条件：线性表已经存在并且线性表是非空的，同时需要参数的满足条件
	//操作结果：删除线性表的第i个元素，并返回他的值
	if(!L.elem)exit(ERROR);
	if(i<1||i>L.length)exit(ERROR);
	ElemType *p;
	p=L.elem+i-1;//用指针p指向要删除的那个元素
	e=*p;
	for(p=p+1;p<=L.elem+L.length-1;p++)
		*(p-1)=*p;
	L.length--;
	return OK;
}

Status ListTraverse(Sqlist L,void(*visit)(ElemType&))
{
	//初始条件：线性表已经存在
	//操作结果：依次对L中的每一个元素调用函数visit(),如果visit()失败那么操作失败，同时如果需要可以通过visit()改变元素的值
	ElemType *p;
	int i;
	p=L.elem;
	for(i=1;i<=L.length;i++)
		visit(*p++);
	printf("\n");
	return OK;
}
void visit(ElemType &c) // ListTraverse()调用的函数(类型要一致)
 {
   cout<<c<<' ';
 }
