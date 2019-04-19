//
// Created by yan_daojiang on 18-10-31.
//

#ifndef BITREE_BITREE_H
#define BITREE_BITREE_H
#include"Status.h"
typedef char TElemType;
typedef struct BiTNode{
    TElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
Status CreatBiTree(BiTree &T);
Status PreOrderTraverse(BiTree T,Status(*visit)(TElemType e));

Status visit(TElemType e);
#endif //BITREE_BITREE_H
