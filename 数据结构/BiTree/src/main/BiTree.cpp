//
// Created by yan_daojiang on 18-10-31.
//
#include"main.h"
#include"BiTree.h"
Status CreatBiTree(BiTree &T)
{
    char a;
    scanf("%c",&a);
    if(a==' ')T=NULL;
    else{
        if(!(T=(BiTNode*)malloc(sizeof(BiTNode))))exit(OVERFLOW);
        T->data=a;
        CreatBiTree(T->lchild);
        CreatBiTree(T->rchild);
    }
    return OK;
}

Status PreOrderTraverse(BiTree T,Status(*visit)(TElemType e))
{
    if(T){
        if(visit(T->data))
            if(PreOrderTraverse(T->lchild,visit))
                if(PreOrderTraverse(T->rchild,visit))
                    return OK;
                return ERROR;
    }
    else
        return OK;
}

Status visit(TElemType e)
{
    printf("%c",e);
    return OK;
}