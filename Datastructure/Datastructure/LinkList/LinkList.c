//
//  LinkList.c
//  ArrayList
//
//  Created by apple on 17/2/21.
//  Copyright © 2017年 Charly. All rights reserved.
//

#include "LinkList.h"

/**
 创建链表

 @param pHead 操作链表
 */
void init_list(PLINKLIST pHead)
{
    pHead = (PLINKLIST)malloc(sizeof(LINKLIST));
    if (NULL == pHead) {
        printf("内存分配失败!\n");
        exit(-1);
    }
    
    pHead->pNext = NULL;
    
    return;
}

/**
 获取链表长度

 @param pHead 操作链表
 @return 链表长度
 */
int  len_list(PLINKLIST pHead)
{
    int len = 0;
    PLINKLIST pNext = pHead;
    while (NULL != pNext->pNext) {
        pNext = pNext->pNext;
        len ++;
    }
    
    return len;
}

/**
 判断链表是否为空

 @param pHead 操作链表
 @return 链表长度
 */
bool isempty_list(PLINKLIST pHead)
{
    return NULL != pHead->pNext;
}

/**
 追加链表

 @param pHead 操作链表
 @param val 追加数据值
 @return 是否追加成功
 */
bool append_list(PLINKLIST pHead, int val)
{
    PLINKLIST pNext = pHead;
    
    while (NULL != pNext->pNext) {
        pNext = pNext->pNext;
    }
    
    PLINKLIST pNew = (PLINKLIST)malloc(sizeof(LINKLIST));
    if (NULL == pNew) {
        printf("内存分配失败!\n");
        exit(-1);
    }
    pNew->data   = val;
    pNext->pNext = pNew;
    pNew->pNext  = NULL;
    
    return true;
}

/**
 插入数据v

 @param pHead 操作链表
 @param pos 插入数据位置
 @param val 插入数据值
 @return 是否插入成功
 */
bool insert_list(PLINKLIST pHead, int pos, int val)
{
    int index = 0;
    PLINKLIST pNext = pHead;
    while (NULL != pNext->pNext && index < pos - 1) {
        pNext = pNext->pNext;
        index ++;
    }
    
    if (NULL == pNext || index >= pos) {
        printf("插入位置有问题\n");
        return false;
    }
    
    PLINKLIST pNew = (PLINKLIST)malloc(sizeof(LINKLIST));
    if (NULL == pNew) {
        printf("内存分配失败!\n");
        exit(-1);
    }
    pNew->data = val;
    pNew->pNext = pNext->pNext;
    pNext->pNext = pNew;
    
    return true;
}

/**
 删除数据

 @param pHead 操作链表
 @param pos 删除数据位置
 @param pVal 删除数据值
 @return 是否删除数据成功
 */
bool delete_list(PLINKLIST pHead, int pos, int * pVal)
{
    int index = 0;
    PLINKLIST pNext = pHead;
    while (NULL != pNext->pNext && index < pos - 1) {
        pNext = pNext->pNext;
        index ++;
    }
    if (NULL == pNext->pNext || index >= pos) {
        printf("删除位置有问题\n");
        return false;
    }
    
    PLINKLIST pCurrent = pNext->pNext;
    *pVal = pCurrent->data;
    pNext->pNext = pCurrent->pNext;
    free(pCurrent);
    pCurrent = NULL;
    
    return true;
}

/**
 数组排序

 @param pHead 操作链表
 */
void sort_list(PLINKLIST pHead)
{
    int i, j, t;
    PLINKLIST p, q;
    int len = len_list(pHead);
    
    for (i = 0, p = pHead->pNext; i < len - 1; ++ i, p = p->pNext) {
        for (j = i, q = p; j < len; ++ j, q = q->pNext) {
            if (p->data > q->data) {
                t = p->data;
                p->data = q->data;
                q->data = t;
            }
        }
    }
    return;
}
/**
 打印显示
 
 @param pHead 操作链表
 */
void show_list(PLINKLIST pHead)
{
    PLINKLIST pNext = pHead->pNext;
    while (NULL != pNext) {
        printf("%d ", pNext->data);
        pNext = pNext->pNext;
    }
    
    printf("\n");
    return;
}
