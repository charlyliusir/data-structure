//
//  LinkStack.c
//  ArrayList
//
//  Created by apple on 17/2/22.
//  Copyright © 2017年 Charly. All rights reserved.
//

#include "LinkStack.h"

/**
 开辟栈空间

 @param pStack 操作栈
 */
void init_stack(PSTACK pStack)
{
    pStack = (PSTACK)malloc(sizeof(STACK));
    if (NULL == pStack) {
        printf("内存分配失败!\n");
        exit(-1);
    }
    pStack->pTop = (PNODE)malloc(sizeof(NODE));
    if (NULL == pStack->pTop) {
        printf("内存分配失败!\n");
        exit(-1);
    }
    pStack->pBottom = pStack->pTop;
    pStack->pTop->pNext = NULL;
    
    return;
}

/**
 获取栈长度

 @param pStack 操作栈
 @return 返回栈长度
 */
int len_stack(PSTACK pStack)
{
    int len = 0;
    
    PNODE p = pStack->pTop;
    
    while (pStack->pBottom != p) {
        ++ len;
        p = p->pNext;
    }
    
    return len;
}

/**
 判断是否是空栈

 @param pStack 操作栈
 @return 返回是否是空栈
 */
bool isempty_stack(PSTACK pStack)
{
    return pStack->pTop == pStack->pBottom;
}

/**
 入栈操作

 @param pStack 操作栈
 @param val 入栈数据值
 */
void push_stack(PSTACK pStack, int val)
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if (NULL == pNew) {
        printf("内存分配失败!\n");
        exit(-1);
    }
    pNew->data = val;
    pNew->pNext = pStack->pTop;
    pStack->pTop = pNew;
    
    return ;
}

/**
 出栈操作

 @param pStack 操作栈
 @param pVal 出栈数据值
 @return 出栈是否成功
 */
bool pop_stack(PSTACK pStack, int * pVal)
{
    if (isempty_stack(pStack)) {
        return false;
    }
    PNODE pNode = pStack->pTop;
    
    pStack->pTop = pNode->pNext;
    *pVal = pNode->data;
    free(pNode);
    pNode = NULL;
    
    return true;
}

/**
 清空栈

 @param pStack 操作栈
 */
void clear_stack(PSTACK pStack)
{
    printf("清空栈操作:");
    while(!isempty_stack(pStack)) {
        int val;
        pop_stack(pStack, &val);
        printf("%d ", val);
    }
    printf("\n");
}

/**
 栈排序

 @param pStack 操作栈
 */
void sort_stack(PSTACK pStack)
{
    int i, j, t;
    PNODE p, q;
    int len = len_stack(pStack);
    
    for (i = 0, p = pStack->pTop; i < len - 1; ++ i, p = p->pNext) {
        for (j = i, q = p; j < len; ++ j, q = q->pNext) {
            if (p->data > q->data) {
                t = q->data;
                q->data = p->data;
                p->data = t;
            }
        }
    }
}

/**
 打印显示栈数据

 @param pStack 操作栈
 */
void show_stack(PSTACK pStack)
{
    PNODE pNode = pStack->pTop;
    while (pStack->pBottom != pNode) {
        printf("%d ", pNode->data);
        pNode = pNode->pNext;
    }
    printf("\n");
}
