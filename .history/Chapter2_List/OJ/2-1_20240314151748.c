//
// Created by 慰 on 2018/9/24.
//【2-1】顺序表创建
// OJ PASSED
// #1589

#include <stdlib.h>

// 定义数据类型为 int
typedef int datatype;
// 定义顺序表的最大长度为 10
#define MAXLEN 10

// 定义顺序表结构体
typedef struct {
    datatype data[MAXLEN]; // 数据数组
    int last;              // 最后一个元素的下标
} SeqList;

// 创建顺序表函数
SeqList *CreatSeqList() {
    SeqList *list = (SeqList *)malloc(sizeof(SeqList)); // 动态分配内存
    list->last = -1;                                    // 初始化最后一个元素的下标为 -1

    int value = 0;       // 定义输入的值
    scanf("%d", &value); // 读取用户输入的整数

    // 循环读取用户输入的整数，直到输入 -1
    while (value != -1) {
        list->last++;                   // 最后一个元素的下标加 1
        list->data[list->last] = value; // 将输入的值存储到顺序表中
        scanf("%d ", &value);           // 读取下一个用户输入的整数
    }

    return list; // 返回创建好的顺序表
}

// 显示顺序表函数
void ShowSeqList(SeqList *L) {
    // 循环遍历顺序表中的元素
    for (int i = 0; i <= L->last; i++) {
        printf("%d ", L->data[i]); // 输出当前元素的值
    }
    printf("\n"); // 输出换行符
}

int main() {
    SeqList *L = CreatSeqList(); // 创建顺序表
    ShowSeqList(L);              // 显示顺序表
    free(L);                     // 释放动态分配的内存
    return 0;
}