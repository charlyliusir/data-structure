//
//  LinkQueue.c
//  ArrayList
//
//  Created by apple on 17/2/22.
//  Copyright © 2017年 Charly. All rights reserved.
//

#include "LinkQueue.h"

/**
 创建队列

 @param pQueue 操作队列
 */
void init_queue(PQUEUE pQueue)
{
    pQueue->front = (PLNODE)malloc(sizeof(LNODE));
    if (NULL == pQueue->front) {
        printf("内存分配失败!\n");
        exit(-1);
    }
    
    pQueue->rear = pQueue->front;
    pQueue->front->pNext = NULL;
    
    return;
}

/**
 计算队列长度

 @param pQueue 操作队列
 @return 返回队列长度
 */
int len_queue(PQUEUE pQueue)
{
    int len = 0;
    PLNODE pNode = pQueue->front;
    while (pQueue->rear != pNode) {
        ++ len;
        pNode = pNode->pNext;
    }
    
    return len;
}

/**
 判断队列是否为空

 @param pQueue 操作队列
 @return 返回队列是否为空
 */
bool isempty_queue(PQUEUE pQueue)
{
    return pQueue->front == pQueue->rear;
}

/**
 入队操作

 @param pQueue 操作队列
 @param val 入队数据值
 */
void enter_queue(PQUEUE pQueue, int val)
{
    PLNODE pNew = (PLNODE)malloc(sizeof(LNODE));
    if (NULL == pNew) {
        printf("内存分配失败!\n");
        exit(-1);
    }
    pNew->data = val;
    
    PLNODE pNode = pQueue->rear;
    
    pNode->pNext = pNew;
    pQueue->rear = pNew;
    
    return;
}

/**
 出队操作

 @param pQueue 操作队列
 @param pVal 出队数据值
 @return 出队操作是否成功
 */
bool delete_queue(PQUEUE pQueue, int * pVal)
{
    
    if (isempty_queue(pQueue)) {
        return false;
    }
    
    PLNODE pNode = pQueue->front->pNext;
    *pVal = pNode->data;
    pQueue->front->pNext = pNode->pNext;
    free(pNode);
    pNode = NULL;
    
    if (NULL == pQueue->front->pNext) {
        pQueue->rear = pQueue->front;
    }
    
    return true;
}

/**
 清空操作

 @param pQueue 操作队列
 */
void clear_queue(PQUEUE pQueue)
{
     printf("清空队列操作:");
    if (!isempty_queue(pQueue)) {
        int val;
        delete_queue(pQueue, &val);
        printf("%d ", val);
    }
    printf("\n");
}

/**
 排序

 @param pQueue 操作队列
 */
void sort_queue(PQUEUE pQueue)
{
    int i, j, t;
    PLNODE p, q;
    int len = len_queue(pQueue);
    
    for (i = 0, p = pQueue->front->pNext; i < len - 1; ++ i, p = p->pNext) {
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
 打印显示

 @param pQueue 操作队列
 */
void show_queue(PQUEUE pQueue)
{
    PLNODE pNode = pQueue->front;
    while (pQueue->rear != pNode) {
        printf("%d ", pNode->pNext->data);
        pNode = pNode->pNext;
    }
    printf("\n");
}
