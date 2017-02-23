//
//  ArrayQueue.h
//  ArrayList
//
//  Created by apple on 17/2/21.
//  Copyright © 2017年 Charly. All rights reserved.
//

#ifndef ArrayQueue_h
#define ArrayQueue_h

// 数据结构：用数组实现队列

#include <stdio.h>
#include <mm_malloc.h>
#include <stdbool.h>

typedef struct ArrayQueue {
    int * pbase;// 数据域
    int len;    // 长度
    int cnt;    // 实际长度
    int front;  // 队首标识
    int rear;   // 队尾标识
}ARRAYQUEUE, *PARRAYQUEUE;

// MAKE- 方法操作
// 1. 创建队列
void init_arrqueue(PARRAYQUEUE pQueue, int len);
// 2. 获取队列长度
int len_arrqueue(PARRAYQUEUE pQueue);
// 3. 判断队列是否为空
bool isempty_arrqueue(PARRAYQUEUE pQueue);
// 4. 判断队列是否已满
bool isfull_arrqueue(PARRAYQUEUE pQueue);
// 5. 入队操作
bool enter_arrqueue(PARRAYQUEUE pQueue, int val);
// 6. 出队操作
bool delete_arrqueue(PARRAYQUEUE pQueue, int * pVal);
// 7. 排序操作
void sort_arrqueue(PARRAYQUEUE pQueue);
// 8. 打印操作
void show_arrqueue(PARRAYQUEUE pQueue);

#endif /* ArrayQueue_h */
