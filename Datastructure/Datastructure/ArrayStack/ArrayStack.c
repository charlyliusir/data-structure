//
//  ArrayStack.c
//  ArrayList
//
//  Created by apple on 17/2/21.
//  Copyright © 2017年 Charly. All rights reserved.
//

#include "ArrayStack.h"


/**
 对栈进行扩容操作

 @param pStack 操作栈
 */
void increment_arrstack(PARRAYSTACK pStack)
{
    int len = pStack->len;
    int *pbase = pStack->pbase;
    
    pStack->len += pStack->increment;
    pStack->pbase = malloc(sizeof(int)*pStack->len);
    
    if (NULL == pStack->pbase) {
        printf("内存分配失败!\n");
        exit(-1);
    }
    
    int i ;
    
    for (i = 0; i < len; ++ i) {
        pStack->pbase[i] = pbase[i];
    }
    
    return;
}

/**
 创建数组

 @param pStack 操作栈
 @param increment 数组自增常量
 */
void init_arrstack(PARRAYSTACK pStack, int increment)
{
    
    pStack->increment = increment;
    increment_arrstack(pStack);
    pStack->cnt = 0;
    
    return;
}

/**
 获取数组长度

 @param pStack 操作栈
 @return 返回栈长度
 */
int  len_arrstack(PARRAYSTACK pStack)
{
    return pStack->cnt;
}

/**
 判断数组是否为空

 @param pStack 操作栈
 @return 栈是否为空
 */
bool isempty_arrstack(PARRAYSTACK pStack)
{
    return pStack->cnt == 0;
}

/**
 判断当前栈是否已满

 @param pStack 操作栈
 @return 栈是否已满
 */
bool isfull_arrstack(PARRAYSTACK pStack)
{
    return pStack->cnt == pStack->len;
}

/**
 入栈

 @param pStack 操作栈
 @param val 入栈数据
 @return 入栈操作是否成功
 */
bool push_arrstack(PARRAYSTACK pStack, int val)
{
    if (isfull_arrstack(pStack)) {
        printf("执行一次扩容!\n");
        increment_arrstack(pStack);
    }
    
    pStack->pbase[pStack->cnt] = val;
    pStack->cnt ++;
    
    return true;
}

/**
 出栈

 @param pStack 操作栈
 @param pVal 出栈数据
 @return 出栈操作是否成功
 */
bool pop_arrstack(PARRAYSTACK pStack, int * pVal)
{
    if (isempty_arrstack(pStack)) {
        printf("这是一个空栈!\n");
        return false;
    }
    
    *pVal = pStack->pbase[pStack->cnt - 1];
    pStack->cnt --;
    
    return true;
}

/**
 数组排序

 @param pStack 操作栈
 */
void sort_arrstack(PARRAYSTACK pStack)
{
    int i, j, t;
    
    for (i = 0; i < pStack->cnt - 1; ++ i) {
        for (j = i; j < pStack->cnt; ++ j) {
            
            if (pStack->pbase[i] > pStack->pbase[j]) {
                t = pStack->pbase[j];
                pStack->pbase[j] = pStack->pbase[i];
                pStack->pbase[i] = t;
            }
            
        }
    }
}

/**
 打印显示

 @param pStack 操作栈
 */
void show_arrstack(PARRAYSTACK pStack)
{
    int i ;
    
    for (i = 0; i < pStack->cnt; ++ i) {
        printf("%d ", pStack->pbase[i]);
    }
    printf("\n");
    
    return;
}
