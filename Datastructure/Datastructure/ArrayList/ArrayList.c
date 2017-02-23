//
//  ArrayList.c
//  ArrayList
//
//  Created by apple on 17/2/21.
//  Copyright © 2017年 Charly. All rights reserved.
//

#include "ArrayList.h"

/**
 创建数组

 @param pArray 操作数组
 @param len 创建数组长度
 */
void init_arr(PARRAYLIST pArray, int len)
{
    // 1. 为指针域分配空间
    pArray->pbase = (int *)malloc(sizeof(int)*len);
    
    if (NULL == pArray->pbase) {
        printf("内存分配失败!\n");
        exit(-1);
    }
    
    // 初始化数组其他参数
    pArray->len = len;
    pArray->cnt = 0;
    
    return;
}

/**
 获取数组长度

 @param pArray 操作数组
 @return 数组长度
 */
int  len_arr(PARRAYLIST pArray)
{
    return pArray->cnt;
}

/**
 判断数组是否为空

 @param pArray 操作数组
 @return 是否为空
 */
bool isempty_arr(PARRAYLIST pArray)
{
    return pArray->cnt == 0;
}

/**
 判断数组是否已满

 @param pArray 操作数组
 @return 数组是否已满
 */
bool isfull_arr(PARRAYLIST pArray)
{
    return pArray->cnt == pArray->len;
}

/**
 拼接数据

 @param pArray 操作数组
 @param val    拼接数据
 @return 拼接是否成功
 */
bool append_arr(PARRAYLIST pArray, int val)
{
    if (isfull_arr(pArray)) {
        printf("数组已满, 拼接操作失败\n");
        return false;
    }
    
    pArray->pbase[pArray->cnt] = val;
    pArray->cnt ++;
    
    return true;
}

/**
 插入数据

 @param pArray 操作数组
 @param pos 插入位置
 @param val 插入值
 @return 插入是否成功
 */
bool insert_arr(PARRAYLIST pArray, int pos, int val)
{
    if (isfull_arr(pArray)) {
        printf("数组已满, 拼接操作失败\n");
        return false;
    }
    if (0 > pos - 1 || pos > pArray->cnt + 1) {
        printf("插入位置不合法!\n");
        return false;
    }
    
    if (pos == pArray->cnt + 1) {
        
        pArray->pbase[pos - 1] = val;
        pArray->cnt ++;
        
        return true;
    }
    
    int i ;
    
    for (i = pArray->cnt; i >= pos - 1; -- i) {
        pArray->pbase[i] = pArray->pbase[i - 1];
    }
    
    pArray->pbase[pos - 1] = val;
    pArray->cnt ++;
    
    return true;
}

/**
 删除数据

 @param pArray 操作数组
 @param pos 删除位置
 @param pVal 删除值
 @return 是否删除成功
 */
bool delete_arr(PARRAYLIST pArray, int pos, int * pVal)
{
    if (isempty_arr(pArray)) {
        printf("数组为空,不能执行删除操作!\n");
        exit(-1);
    }
    if (0 > pos - 1 || pos > pArray->cnt) {
        printf("删除位置不合法!\n");
        return false;
    }
    
    *pVal = pArray->pbase[pos - 1];
    
    if (pos == pArray->cnt + 1) {
        
        pArray->cnt --;
        
        return true;
    }
    
    int i ;
    
    for (i = pos - 1; i < pArray->cnt; ++ i) {
        pArray->pbase[i] = pArray->pbase[i + 1];
    }
    
    pArray->cnt --;
    
    return true;
    
}

/**
 数组排序

 @param pArray 操作数组
 */
void sort_arr(PARRAYLIST pArray)
{
    int i, j, t;
    
    for (i = 0; i < pArray->cnt - 1; ++ i) {
        for (j = i; j < pArray->cnt; ++ j) {
            
            if (pArray->pbase[i] > pArray->pbase[j]) {
                t = pArray->pbase[j];
                pArray->pbase[j] = pArray->pbase[i];
                pArray->pbase[i] = t;
            }
            
        }
    }
}
// 9.

/**
 打印显示

 @param pArray 操作数组
 */
void show_arr(PARRAYLIST pArray)
{
    int i ;
    
    for (i = 0; i < pArray->cnt; ++ i) {
        printf("%d ", pArray->pbase[i]);
    }
    printf("\n");
    
    return;
}
