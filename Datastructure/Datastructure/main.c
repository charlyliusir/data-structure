//
//  main.c
//  Datastructure
//
//  Created by apple on 17/2/23.
//  Copyright © 2017年 Charly. All rights reserved.
//

#include <stdio.h>
#include "ArrayList.h"
#include "ArrayStack.h"
#include "ArrayQueue.h"
#include "LinkList.h"
#include "LinkStack.h"
#include "LinkQueue.h"

// 数组测试
void test_arr();
// 链表测试
void test_link();
// 数组栈测试
void test_arrstack();
// 链表栈测试
void test_linkstack();
// 数组队列测试
void test_arrqueue();
// 栈队列测试
void test_linkqueue();

int main(int argc, const char * argv[]) {
    
    //    test_arr();
    //    test_link();
    //    test_arrstack();
    //    test_linkstack();
    //    test_arrqueue();
    test_linkqueue();
    
    return 0;
}

void test_arr()
{
    ARRAYLIST arr;
    // 1. 创建数组
    init_arr(&arr, 5);
    // 2. 拼接数据
    append_arr(&arr, 1);
    append_arr(&arr, 2);
    append_arr(&arr, 3);
    append_arr(&arr, 4);
    append_arr(&arr, 5);
    // 3. 拼接完毕, 打印
    printf("拼接操作完毕!\n");
    show_arr(&arr);
    // 4. 测试超限拼接
    append_arr(&arr, 6);
    // 5. 超限拼接完毕, 打印
    printf("超限拼接操作完毕!\n");
    show_arr(&arr);
    // 6. 执行删除操作
    int val ;
    if (delete_arr(&arr, 5, &val)) {
        printf("删除操作成功, 删除值为:%d\n", val);
        show_arr(&arr);
    }else{
        printf("删除操作失败\n");
    }
    if (delete_arr(&arr, 4, &val)) {
        printf("删除操作成功, 删除值为:%d\n", val);
        show_arr(&arr);
    }else{
        printf("删除操作失败\n");
    }
    if (delete_arr(&arr, 3, &val)) {
        printf("删除操作成功, 删除值为:%d\n", val);
        show_arr(&arr);
    }else{
        printf("删除操作失败\n");
    }
    // 7. 执行错误删除操作
    if (delete_arr(&arr, 5, &val)) {
        printf("删除操作成功, 删除值为:%d\n", val);
        show_arr(&arr);
    }else{
        printf("删除操作失败, 错误操作:5\n");
    }
    if (delete_arr(&arr, 0, &val)) {
        printf("删除操作成功, 删除值为:%d\n", val);
        show_arr(&arr);
    }else{
        printf("删除操作失败, 错误操作:0\n");
    }
    // 8. 插入操作
    insert_arr(&arr, 3, 10);
    insert_arr(&arr, 1, 20);
    // 9. 插入操作结束, 打印结果
    printf("插入操作成功!\n");
    show_arr(&arr);
    // 9. 测试排序
    sort_arr(&arr);
    printf("排序操作结束!\n");
    show_arr(&arr);
    // 9. 测试插入操作错误
    delete_arr(&arr, 2, &val);
    insert_arr(&arr, 5, 8);
    insert_arr(&arr, -1, 3);
    
}

void test_link()
{
    LINKLIST pHead;
    // 1. 创建数组
    init_list(&pHead);
    // 2. 拼接数据
    append_list(&pHead, 1);
    append_list(&pHead, 1);
    append_list(&pHead, 2);
    append_list(&pHead, 3);
    append_list(&pHead, 4);
    append_list(&pHead, 5);
    // 3. 拼接完毕, 打印
    printf("拼接操作完毕!\n");
    show_list(&pHead);
    // 6. 执行删除操作
    int val ;
    if (delete_list(&pHead, 5, &val)) {
        printf("删除操作成功, 删除值为:%d\n", val);
        show_list(&pHead);
    }else{
        printf("删除操作失败\n");
    }
    if (delete_list(&pHead, 4, &val)) {
        printf("删除操作成功, 删除值为:%d\n", val);
        show_list(&pHead);
    }else{
        printf("删除操作失败\n");
    }
    if (delete_list(&pHead, 3, &val)) {
        printf("删除操作成功, 删除值为:%d\n", val);
        show_list(&pHead);
    }else{
        printf("删除操作失败\n");
    }
    // 7. 执行错误删除操作
    if (delete_list(&pHead, 5, &val)) {
        printf("删除操作成功, 删除值为:%d\n", val);
        show_list(&pHead);
    }else{
        printf("删除操作失败, 错误操作:5\n");
    }
    if (delete_list(&pHead, 0, &val)) {
        printf("删除操作成功, 删除值为:%d\n", val);
        show_list(&pHead);
    }else{
        printf("删除操作失败, 错误操作:0\n");
    }
    // 8. 插入操作
    insert_list(&pHead, 4, 10);
    insert_list(&pHead, 3, 20);
    insert_list(&pHead, 1, 20);
    // 9. 插入操作结束, 打印结果
    printf("插入操作成功!\n");
    show_list(&pHead);
    // 9. 测试排序
    sort_list(&pHead);
    printf("排序操作结束!\n");
    show_list(&pHead);
    // 9. 测试插入操作错误
    delete_list(&pHead, 2, &val);
    insert_list(&pHead, 5, 8);
    insert_list(&pHead, -1, 3);
    show_list(&pHead);
}

void test_arrstack()
{
    ARRAYSTACK arrStack;
    // 1. 创建栈
    init_arrstack(&arrStack, 5);
    // 2. 入栈操作
    push_arrstack(&arrStack, 1);
    push_arrstack(&arrStack, 8);
    push_arrstack(&arrStack, 3);
    push_arrstack(&arrStack, 14);
    push_arrstack(&arrStack, 5);
    // 3. 打印
    printf("入栈操作完毕!\n");
    show_arrstack(&arrStack);
    // 4. 自动扩容
    push_arrstack(&arrStack, 2);
    // 6. 自动扩容后
    printf("自动扩容操作完毕!\n");
    show_arrstack(&arrStack);
    // 8. 排序
    sort_arrstack(&arrStack);
    // 9. 排序后打印
    printf("排序操作成功!\n");
    show_arrstack(&arrStack);
    // 7. 出栈操作
    int val;
    if (pop_arrstack(&arrStack, &val)) {
        printf("出栈操作成功, 出栈值:%d\n", val);
        show_arrstack(&arrStack);
    }else{
        printf("出栈失败\n");
    }
    if (pop_arrstack(&arrStack, &val)) {
        printf("出栈操作成功, 出栈值:%d\n", val);
        show_arrstack(&arrStack);
    }else{
        printf("出栈失败\n");
    }
    if (pop_arrstack(&arrStack, &val)) {
        printf("出栈操作成功, 出栈值:%d\n", val);
        show_arrstack(&arrStack);
    }else{
        printf("出栈失败\n");
    }
    if (pop_arrstack(&arrStack, &val)) {
        printf("出栈操作成功, 出栈值:%d\n", val);
        show_arrstack(&arrStack);
    }else{
        printf("出栈失败\n");
    }
    if (pop_arrstack(&arrStack, &val)) {
        printf("出栈操作成功, 出栈值:%d\n", val);
        show_arrstack(&arrStack);
    }else{
        printf("出栈失败\n");
    }
    if (pop_arrstack(&arrStack, &val)) {
        printf("出栈操作成功, 出栈值:%d\n", val);
        show_arrstack(&arrStack);
    }else{
        printf("出栈失败\n");
    }
    if (pop_arrstack(&arrStack, &val)) {
        printf("出栈操作成功, 出栈值:%d\n", val);
        show_arrstack(&arrStack);
    }else{
        printf("出栈失败\n");
    }
    if (pop_arrstack(&arrStack, &val)) {
        printf("出栈操作成功, 出栈值:%d\n", val);
        show_arrstack(&arrStack);
    }else{
        printf("出栈失败\n");
    }
    
}

void test_linkstack()
{
    STACK pStack;
    // 1. 创建栈
    init_stack(&pStack);
    // 2. 入栈操作
    push_stack(&pStack, 1);
    push_stack(&pStack, 8);
    push_stack(&pStack, 3);
    push_stack(&pStack, 14);
    push_stack(&pStack, 5);
    // 3. 打印
    printf("入栈操作完毕!\n");
    show_stack(&pStack);
    // 4. 自动扩容
    push_stack(&pStack, 2);
    // 6. 自动扩容后
    printf("自动扩容操作完毕!\n");
    show_stack(&pStack);
    // 8. 排序
    sort_stack(&pStack);
    // 9. 排序后打印
    printf("排序操作成功!\n");
    show_stack(&pStack);
    // 7. 出栈操作
    int val;
    if (pop_stack(&pStack, &val)) {
        printf("出栈操作成功, 出栈值:%d\n", val);
        show_stack(&pStack);
    }else{
        printf("出栈失败\n");
    }
    if (pop_stack(&pStack, &val)) {
        printf("出栈操作成功, 出栈值:%d\n", val);
        show_stack(&pStack);
    }else{
        printf("出栈失败\n");
    }
    if (pop_stack(&pStack, &val)) {
        printf("出栈操作成功, 出栈值:%d\n", val);
        show_stack(&pStack);
    }else{
        printf("出栈失败\n");
    }
    if (pop_stack(&pStack, &val)) {
        printf("出栈操作成功, 出栈值:%d\n", val);
        show_stack(&pStack);
    }else{
        printf("出栈失败\n");
    }
    if (pop_stack(&pStack, &val)) {
        printf("出栈操作成功, 出栈值:%d\n", val);
        show_stack(&pStack);
    }else{
        printf("出栈失败\n");
    }
    if (pop_stack(&pStack, &val)) {
        printf("出栈操作成功, 出栈值:%d\n", val);
        show_stack(&pStack);
    }else{
        printf("出栈失败\n");
    }
    if (pop_stack(&pStack, &val)) {
        printf("出栈操作成功, 出栈值:%d\n", val);
        show_stack(&pStack);
    }else{
        printf("出栈失败\n");
    }
    if (pop_stack(&pStack, &val)) {
        printf("出栈操作成功, 出栈值:%d\n", val);
        show_stack(&pStack);
    }else{
        printf("出栈失败\n");
    }
}

void test_arrqueue()
{
    ARRAYQUEUE arrQueue;
    // 1. 创建栈
    init_arrqueue(&arrQueue, 5);
    // 2. 入栈操作
    enter_arrqueue(&arrQueue, 1);
    enter_arrqueue(&arrQueue, 8);
    enter_arrqueue(&arrQueue, 3);
    enter_arrqueue(&arrQueue, 14);
    enter_arrqueue(&arrQueue, 5);
    // 3. 打印
    printf("入队操作完毕!\n");
    show_arrqueue(&arrQueue);
    // 4. 自动扩容
    enter_arrqueue(&arrQueue, 2);
    // 6. 自动扩容后
    printf("自动扩容操作完毕!\n");
    show_arrqueue(&arrQueue);
    // 8. 排序
    sort_arrqueue(&arrQueue);
    // 9. 排序后打印
    printf("排序操作成功!\n");
    show_arrqueue(&arrQueue);
    // 7. 出栈操作
    int val;
    if (delete_arrqueue(&arrQueue, &val)) {
        printf("出栈操作成功, 出栈值:%d\n", val);
        show_arrqueue(&arrQueue);
    }else{
        printf("出栈失败\n");
    }
    if (delete_arrqueue(&arrQueue, &val)) {
        printf("出栈操作成功, 出栈值:%d\n", val);
        show_arrqueue(&arrQueue);
    }else{
        printf("出栈失败\n");
    }
    if (delete_arrqueue(&arrQueue, &val)) {
        printf("出栈操作成功, 出栈值:%d\n", val);
        show_arrqueue(&arrQueue);
    }else{
        printf("出栈失败\n");
    }
    if (delete_arrqueue(&arrQueue, &val)) {
        printf("出栈操作成功, 出栈值:%d\n", val);
        show_arrqueue(&arrQueue);
    }else{
        printf("出栈失败\n");
    }
    if (delete_arrqueue(&arrQueue, &val)) {
        printf("出栈操作成功, 出栈值:%d\n", val);
        show_arrqueue(&arrQueue);
    }else{
        printf("出栈失败\n");
    }
    if (delete_arrqueue(&arrQueue, &val)) {
        printf("出栈操作成功, 出栈值:%d\n", val);
        show_arrqueue(&arrQueue);
    }else{
        printf("出栈失败\n");
    }
    if (delete_arrqueue(&arrQueue, &val)) {
        printf("出栈操作成功, 出栈值:%d\n", val);
        show_arrqueue(&arrQueue);
    }else{
        printf("出栈失败\n");
    }
    if (delete_arrqueue(&arrQueue, &val)) {
        printf("出栈操作成功, 出栈值:%d\n", val);
        show_arrqueue(&arrQueue);
    }else{
        printf("出栈失败\n");
    }
}

void test_linkqueue()
{
    QUEUE pQueue;
    // 1. 创建栈
    init_queue(&pQueue);
    // 2. 入栈操作
    enter_queue(&pQueue, 1);
    enter_queue(&pQueue, 8);
    enter_queue(&pQueue, 3);
    enter_queue(&pQueue, 14);
    enter_queue(&pQueue, 5);
    // 3. 打印
    printf("入队操作完毕!\n");
    show_queue(&pQueue);
    // 4. 自动扩容
    enter_queue(&pQueue, 2);
    // 6. 自动扩容后
    printf("自动扩容操作完毕!\n");
    show_queue(&pQueue);
    // 8. 排序
    sort_queue(&pQueue);
    // 9. 排序后打印
    printf("排序操作成功!\n");
    show_queue(&pQueue);
    // 7. 出栈操作
    int val;
    if (delete_queue(&pQueue, &val)) {
        printf("出栈操作成功, 出栈值:%d\n", val);
        show_queue(&pQueue);
    }else{
        printf("出栈失败\n");
    }
    if (delete_queue(&pQueue, &val)) {
        printf("出栈操作成功, 出栈值:%d\n", val);
        show_queue(&pQueue);
    }else{
        printf("出栈失败\n");
    }
    if (delete_queue(&pQueue, &val)) {
        printf("出栈操作成功, 出栈值:%d\n", val);
        show_queue(&pQueue);
    }else{
        printf("出栈失败\n");
    }
    if (delete_queue(&pQueue, &val)) {
        printf("出栈操作成功, 出栈值:%d\n", val);
        show_queue(&pQueue);
    }else{
        printf("出栈失败\n");
    }
    if (delete_queue(&pQueue, &val)) {
        printf("出栈操作成功, 出栈值:%d\n", val);
        show_queue(&pQueue);
    }else{
        printf("出栈失败\n");
    }
    if (delete_queue(&pQueue, &val)) {
        printf("出栈操作成功, 出栈值:%d\n", val);
        show_queue(&pQueue);
    }else{
        printf("出栈失败\n");
    }
    if (delete_queue(&pQueue, &val)) {
        printf("出栈操作成功, 出栈值:%d\n", val);
        show_queue(&pQueue);
    }else{
        printf("出栈失败\n");
    }
    if (delete_queue(&pQueue, &val)) {
        printf("出栈操作成功, 出栈值:%d\n", val);
        show_queue(&pQueue);
    }else{
        printf("出栈失败\n");
    }
}

