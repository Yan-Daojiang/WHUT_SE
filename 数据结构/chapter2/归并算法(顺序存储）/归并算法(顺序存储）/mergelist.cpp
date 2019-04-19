/**
* @author: Yan_Daojiang
* @date: 2018/10/13
* @description:������ֵ�ǵݼ����е����Ա���й鲢
**/
#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
#define OK 1
#define OVERFLOW -2
typedef int Status;

typedef int Elemtype;
//--------------���Ա�Ķ�̬����˳��洢�ṹ--------
#define LIST_INIT_SIZE 100//���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 10//���Ա�Ĵ洢�ռ�����
typedef struct {
	int *elem;//�洢�ռ�Ļ���ַ
	int length;//��ǰ�ĳ���
			   //���Ա�ĳ�����ָ���Ա���Ԫ�صĸ���
	int listsize;//����ռ�Ĵ洢����
}Sqlist;

Status InitList_Sq(Sqlist &L) {
	//����һ���յ����Ա�
	L.elem = (Elemtype*)malloc(LIST_INIT_SIZE*sizeof(int));
	if (!L.elem)//�洢�ռ����ʧ��
		exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}//initlist_sq

Status ListInsert_Sq(Sqlist &L, int i, Elemtype e) {
	//��˳���ĵ�i��λ��֮ǰ����Ԫ��e
	//ע��i �ĺϷ�ȡֵΪ1<=i<=ListLength_Sq(L)+1
	if (i<1 || i>L.length + 1)
		return ERROR;//���i��ֵ���Ϸ��ͷ���ERROR
	if (L.length >= L.listsize) {//�����ǰ�Ŀռ��Ѿ����ˣ���׷�ӷ���
		Elemtype * newbase = (Elemtype *)realloc(L.elem, (L.listsize + LISTINCREMENT)*sizeof(Elemtype));
		if (!newbase)
			exit(OVERFLOW);//�洢����ʧ��
		L.elem = newbase;//�µĻ���ַ
		L.listsize += LISTINCREMENT;
	}
	int *q = &(L.elem[i - 1]);//qΪԪ�صĲ���λ��
	for (int *p = &L.length - 1; p >= q; --p)
		*(p + 1) = *p;//�Ӳ���λ�ÿ�ʼ�����Ԫ�ض�Ҫ����
	*q = e;
	++L.length;//����һ��Ԫ��֮�����Ҫ+1
	return OK;
}// ListInsert_Sq

int ListLength(Sqlist L) {
	//�������Ա���Ԫ�صĸ���	
	return L.length;
}
Elemtype Getelem(Sqlist L, int i, Elemtype &e) {
	//��e���ص�i������Ԫ�ص�ֵ
	e = L.elem[i - 1];
	return e;
}

void MergeList(Sqlist La, Sqlist Lb, Sqlist &Lc) {
	//��֪�������Ա������Ԫ�ذ��շǵݼ����У����������Ա���й鲢
	Elemtype ai, bj;
	InitList_Sq(Lc);
	int i, j, k;
	i = j = 1;
	k = 0;
	La.length = ListLength(La);
	Lb.length = ListLength(Lb);
	while ((i <= La.length) && j <= Lb.length) {//ȷ���������Ա��Ƿǿձ�
		Getelem(La, i, ai);
		Getelem(Lb, j, bj);
		if (ai < bj) {
			ListInsert_Sq(Lc, ++k, ai);
			i++;
		}
		else {
			ListInsert_Sq(Lc, ++k, bj);
			j++;
		}
	}
	while (i <= La.length) {
		Getelem(La, i++, ai);
		ListInsert_Sq(Lc, ++k, ai);
	}
	while (j <= Lb.length) {
		Getelem(Lb, j++, bj);
		ListInsert_Sq(Lc, ++k, bj);
	}
}
int main() {
	Sqlist La, Lb, Lc;
	//�ֱ𴴽��ձ�La��Lb,������صĲ������г�ʼ��
	InitList_Sq(La);
	InitList_Sq(Lb);
	//����Ҫ�鲢���������Ԫ�طֱ���뵽La��Lb��ȥ
	int i, j, a[4] = { 3,5,8,11 }, b[7] = { 2,6,8,9,11,15,20 };
	printf("��Ҫ���в������������Ա�����\n");
	for (i = 1; i <= 4; i++) {// �ڱ�La�в���4��Ԫ��
		ListInsert_Sq(La, i, a[i - 1]);
		printf("%d ", a[i - 1]);
	}
	printf("\n");
	for (j = 1; j <= 7; j++) {//�����Ա�Lb�в���7��Ԫ��
		ListInsert_Sq(Lb, j, b[j - 1]);
		printf("%d ", b[j - 1]);
	}
	printf("\n");
	//����������й鲢
	MergeList(La, Lb, Lc);
	//����鲢���
	Elemtype result;
	printf("�鲢���:\n");
	for (int k = 1; k <= Lc.length; k++) {
		printf("%d ", Getelem(Lc, k, result));
	}
	printf("\n");
	return OK;
}