//
//  ArrayQueue.c
//  ArrayList
//
//  Created by apple on 17/2/21.
//  Copyright © 2017年 Charly. All rights reserved.
//

#include "ArrayQueue.h"

/**
 创建队列

 @param pQueue 操作队列
 @param len 队列长度
 */
void init_arrqueue(PARRAYQUEUE pQueue, int len)
{
    pQueue->pbase = (int *)malloc(sizeof(int)*len);
    if (NULL == pQueue->pbase) {
        printf("内存分配失败!\n");
        exit(-1);
    }
    
    pQueue->len = len;
    pQueue->cnt = 0;
    pQueue->front = 1;
    pQueue->rear  = 1;
    
    return;
}

/**
 获取队列长度

 @param pQueue 操作队列
 @return 队列长度
 */
int len_arrqueue(PARRAYQUEUE pQueue)
{
    return pQueue->cnt;
}

/**
 判断队列是否为空

 @param pQueue 操作队列
 @return 队列是否为空
 */
bool isempty_arrqueue(PARRAYQUEUE pQueue)
{
    return pQueue->front == pQueue->rear;
}

/**
 判断队列是否已满

 @param pQueue 操作队列
 @return 队列是否已满
 */
bool isfull_arrqueue(PARRAYQUEUE pQueue)
{
    return (pQueue->front == 1 && pQueue->rear == 5) || (pQueue->front - pQueue->rear == 1);
}

/**
 入队操作

 @param pQueue 操作队列
 @param val 入队值
 @return 入队操作是否成功
 */
bool enter_arrqueue(PARRAYQUEUE pQueue, int val)
{
    if (isfull_arrqueue(pQueue)) {
        printf("队列已满!\n");
        return false;
    }
    
    pQueue->pbase[pQueue->rear] = val;
    pQueue->rear = pQueue->rear % pQueue->len + 1;
    pQueue->cnt ++;
    
    return true;
}

/**
 出队操作

 @param pQueue 操作队列
 @param pVal 出队值
 @return 出队操作是否成功
 */
bool delete_arrqueue(PARRAYQUEUE pQueue, int * pVal)
{
    if (isempty_arrqueue(pQueue)) {
        printf("队列已空!\n");
        return false;
    }
    
    *pVal = pQueue->pbase[pQueue->front - 1];
    pQueue->front = pQueue->front % pQueue->len + 1;
    pQueue->cnt --;
    
    return true;
}

/**
 排序操作

 @param pQueue 操作队列
 */
void sort_arrqueue(PARRAYQUEUE pQueue)
{
    int i, j, t;
    
    for (i = 0; i < pQueue->cnt - 1; ++ i) {
        for (j = i; j < pQueue->cnt; ++ j) {
            if (pQueue->pbase[i]> pQueue->pbase[j]) {
                t = pQueue->pbase[j];
                pQueue->pbase[j] = pQueue->pbase[i];
                pQueue->pbase[i] = t;
            }
        }
    }
    
    return;
}

/**
 打印操作

 @param pQueue 操作队列
 */
void show_arrqueue(PARRAYQUEUE pQueue)
{
    int i, j;
    
    for (i = pQueue->front, j = 0; j < pQueue->cnt; ++ j, i = i % pQueue->len + 1) {
        printf("%d ", pQueue->pbase[i]);
    }
    
    printf("\n");
    return;
}
