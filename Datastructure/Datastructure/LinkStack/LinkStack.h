//
//  LinkStack.h
//  ArrayList
//
//  Created by apple on 17/2/22.
//  Copyright © 2017年 Charly. All rights reserved.
//

#ifndef LinkStack_h
#define LinkStack_h

#include <stdio.h>
#include <mm_malloc.h>
#include <stdbool.h>

/// 数据结构：实现链表栈【栈实行后入先出,出栈和入栈都是从栈顶操作】
typedef struct Node {
    int data;           // 数据域
    struct Node * pNext;// 指针域
}NODE, *PNODE;

typedef struct Stack{
    PNODE pTop;         // 栈顶
    PNODE pBottom;      // 栈底
}STACK, *PSTACK;
// MAKE- 链表栈方法
// 1. 开辟栈空间
void init_stack(PSTACK pStack);
// 2. 获取栈长度
int len_stack(PSTACK pStack);
// 3. 判断是否是空栈
bool isempty_stack(PSTACK pStack);
// 4. 入栈操作
void push_stack(PSTACK pStack, int val);
// 5. 出栈操作
bool pop_stack(PSTACK pStack, int * pVal);
// 6. 清空栈
void clear_stack(PSTACK pStack);
// 7. 栈排序
void sort_stack(PSTACK pStack);
// 8. 打印显示栈数据
void show_stack(PSTACK pStack);


#endif /* LinkStack_h */
