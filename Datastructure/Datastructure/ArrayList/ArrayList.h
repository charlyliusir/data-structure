//
//  ArrayList.h
//  ArrayList
//
//  Created by apple on 17/2/21.
//  Copyright © 2017年 Charly. All rights reserved.
//

#ifndef ArrayList_h
#define ArrayList_h

#include <stdio.h>
#include <stdbool.h>
#include <mm_malloc.h>

// 数据结构：数组实现
typedef struct ArrayList {
    int * pbase;    // 保存数据的第一个指针
    int len;        // 数组长度
    int cnt;        // 数组有效长度
}ARRAYLIST, *PARRAYLIST;

// MAKE- 方法
// 1. 创建数组
void init_arr(PARRAYLIST pArray, int len);
// 2. 获取数组长度
int  len_arr(PARRAYLIST pArray);
// 3. 判断数组是否为空
bool isempty_arr(PARRAYLIST pArray);
// 4. 判断数组是否已满
bool isfull_arr(PARRAYLIST pArray);
// 5. 拼接数据
bool append_arr(PARRAYLIST pArray, int val);
// 6. 插入数据
bool insert_arr(PARRAYLIST pArray, int pos, int val);
// 7. 删除数据
bool delete_arr(PARRAYLIST pArray, int pos, int * pVal);
// 8. 数组排序
void sort_arr(PARRAYLIST pArray);
// 9. 打印显示
void show_arr(PARRAYLIST pArray);

#endif /* ArrayList_h */
