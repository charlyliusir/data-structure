//
//  LinkQueue.h
//  ArrayList
//
//  Created by apple on 17/2/22.
//  Copyright © 2017年 Charly. All rights reserved.
//

#ifndef LinkQueue_h
#define LinkQueue_h

#include <stdio.h>
#include <mm_malloc.h>
#include <stdbool.h>
// 数据结构: 实现栈队列【队列实现先入先出,入队从队尾操作,出队从队首操作】
typedef struct LNode{
    int data;               // 数据域
    struct LNode * pNext;    // 指针域
}LNODE, *PLNODE;

typedef struct Queue{
    PLNODE front;    // 队首
    PLNODE rear;     // 队尾
}QUEUE, *PQUEUE;

// MAKE:队列方法
// 1. 创建队列
void init_queue(PQUEUE pQueue);
// 2. 计算队列长度
int len_queue(PQUEUE pQueue);
// 3. 判断队列是否为空
bool isempty_queue(PQUEUE pQueue);
// 4. 入队操作
void enter_queue(PQUEUE pQueue, int val);
// 5. 出队操作
bool delete_queue(PQUEUE pQueue, int * pVal);
// 6. 清空操作
void clear_queue(PQUEUE pQueue);
// 7. 排序
void sort_queue(PQUEUE pQueue);
// 8. 打印显示
void show_queue(PQUEUE pQueue);

#endif /* LinkQueue_h */
