//
//  ArrayStack.h
//  ArrayList
//
//  Created by apple on 17/2/21.
//  Copyright © 2017年 Charly. All rights reserved.
//

#ifndef ArrayStack_h
#define ArrayStack_h

#include <stdio.h>
#include <mm_malloc.h>
#include <stdbool.h>

// 数据结构：自定义实现数组版栈
typedef struct ArrayStack {
    int * pbase;    // 保存数据的第一个指针
    int len;        // 数组长度
    int cnt;        // 数组有效长度
    int increment;  // 自增变量
}ARRAYSTACK, *PARRAYSTACK;

// MAKE- 方法
// 1. 创建数组
void init_arrstack(PARRAYSTACK pStack, int increment);
// 2. 获取数组长度
int  len_arrstack(PARRAYSTACK pStack);
// 3. 判断数组是否为空
bool isempty_arrstack(PARRAYSTACK pStack);
// 4. 入栈
bool push_arrstack(PARRAYSTACK pStack, int val);
// 5. 出栈
bool pop_arrstack(PARRAYSTACK pStack, int * pVal);
// 6. 数组排序
void sort_arrstack(PARRAYSTACK pStack);
// 7. 打印显示
void show_arrstack(PARRAYSTACK pStack);



#endif /* ArrayStack_h */
