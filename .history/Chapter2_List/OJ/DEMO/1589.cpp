#include <stdio.h>
#include <stdlib.h>

// 填写 @#1 和 @#2
typedef int datatype; // @#1: 定义顺序表中存储的数据类型为整型
#define MAXLEN 100    // @#2: 定义顺序表的最大长度为 100

typedef struct {
    datatype data[MAXLEN]; // 存储数据的数组
    int last;              // 当前顺序表的最后一个元素的索引
} SeqList;

// 创建顺序表的函数
SeqList *CreatSeqList() {
    // @@1
    // 分配内存给顺序表
    SeqList *L = (SeqList *)malloc(sizeof(SeqList));
    L->last = -1; // -1 表示顺序表为空

    int input;

    // 逐个输入元素并存入顺序表，直到输入 -1 或达到最大长度
    while (1) {
        if (input == -1) { // 输入 -1 表示结束
            break;
        }

        if (L->last >= MAXLEN - 1) { // 检查是否超过最大容量
            break;
        }

        // 插入新元素
        L->data[++(L->last)] = input;
    }

    return L;
    // @@1
}

// 遍历顺序表并输出的函数
void ShowSeqList(SeqList *L) {
    // @@2
    for (int i = 0; i <= L->last; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
    // @@2
}

int main() {
    SeqList *L = CreatSeqList();
    ShowSeqList(L);
    free(L); // 释放顺序表的内存
    return 0;
}
