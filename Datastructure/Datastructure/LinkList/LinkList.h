//
//  LinkList.h
//  ArrayList
//
//  Created by apple on 17/2/21.
//  Copyright © 2017年 Charly. All rights reserved.
//

#ifndef LinkList_h
#define LinkList_h

// 数据机构: 实现链表

#include <stdio.h>
#include <mm_malloc.h>
#include <stdbool.h>

typedef struct LinkList {
    int data;// 数据域
    struct LinkList * pNext; // 指针域
}LINKLIST, *PLINKLIST;

// MAKE- 方法
// 1. 创建链表
void init_list(PLINKLIST pHead);
// 2. 获取链表长度
int  len_list(PLINKLIST pHead);
// 3. 判断链表是否为空
bool isempty_list(PLINKLIST pHead);
// 5. 拼接链表
bool append_list(PLINKLIST pHead, int val);
// 6. 插入数据
bool insert_list(PLINKLIST pHead, int pos, int val);
// 7. 删除数据
bool delete_list(PLINKLIST pHead, int pos, int * pVal);
// 8. 数组排序
void sort_list(PLINKLIST pHead);
// 9. 打印显示
void show_list(PLINKLIST pHead);

#endif /* LinkList_h */
