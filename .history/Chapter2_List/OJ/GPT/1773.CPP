#include <stdio.h>
#include <iostream>
using namespace std;

#define MAXLEN 100

typedef int datatype;
typedef struct {
    datatype data[MAXLEN];
    int last;
} SeqList;

SeqList *CreatList_Seq() {
    // @@1 开始
    // 初始化顺序表
    SeqList *Lq = (SeqList *)malloc(sizeof(SeqList));
    if (Lq == NULL) {
        printf("内存分配失败。\n");
        exit(1);
    }
    Lq->last = -1; // 空表，last初始化为-1
    return Lq;
    // @@1 结束
}
int InsList_Seq(SeqList *Lq, int i, datatype x) {
    // @@2 开始
    // 检查插入位置是否合法
    if (i < 0 || i > Lq->last + 1 || Lq->last + 1 >= MAXLEN) {
        printf("插入位置不合法或顺序表已满。\n");
        return 0; // 插入失败
    }
    // 元素后移，为新元素腾出空间
    for (int j = Lq->last; j >= i; j--) {
        Lq->data[j + 1] = Lq->data[j];
    }
    Lq->data[i] = x; // 插入新元素
    Lq->last++;      // 更新最后一个元素的索引
    return 1;        // 插入成功
    // @@2 结束
}
int SearchList_Seq(SeqList *Lq, datatype x) {
    // @@3 开始
    for (int i = 0; i <= Lq->last; i++) {
        if (Lq->data[i] == x) {
            return i; // 找到元素，返回位置
        }
    }
    return -1; // 未找到
    // @@3 结束
}

void ShowList_Seq(SeqList *Lq) {
    // @@4 开始
    for (int i = 0; i <= Lq->last; i++) {
        printf("%d ", Lq->data[i]);
    }
    printf("\n");
    // @@4 结束
}
datatype Getdata(SeqList *h, int i) {
    if (i < 0 || i > h->last) {
        printf("索引越界。\n");
        exit(1);
    }
    return h->data[i];
}

void Union(SeqList *a, SeqList *b, SeqList *c) {
    int i = 0, j = 0, k = 0;
    // 合并两个有序顺序表
    while (i <= a->last && j <= b->last) {
        if (a->data[i] <= b->data[j]) {
            if (k >= MAXLEN) {
                printf("顺序表C已满，无法插入更多元素。\n");
                break;
            }
            c->data[k++] = a->data[i++];
        } else {
            if (k >= MAXLEN) {
                printf("顺序表C已满，无法插入更多元素。\n");
                break;
            }
            c->data[k++] = b->data[j++];
        }
    }
    // 将剩余元素加入到C中
    while (i <= a->last) {
        if (k >= MAXLEN) {
            printf("顺序表C已满，无法插入更多元素。\n");
            break;
        }
        c->data[k++] = a->data[i++];
    }
    while (j <= b->last) {
        if (k >= MAXLEN) {
            printf("顺序表C已满，无法插入更多元素。\n");
            break;
        }
        c->data[k++] = b->data[j++];
    }
    c->last = k - 1; // 更新C的最后一个元素索引
    // @@5 结束
}

int main() {
    SeqList *a, *b, *c;
    datatype x;

    a = CreatList_Seq();
    b = CreatList_Seq();
    c = CreatList_Seq();

    // 读取顺序表A的元素，直到遇到-1
    while (1) {
        scanf("%d", &x);
        if (x == -1)
            break;
        InsList_Seq(a, a->last + 1, x);
    }
    // 读取顺序表B的元素，直到遇到-1
    while (1) {
        scanf("%d", &x);
        if (x == -1)
            break;
        InsList_Seq(b, b->last + 1, x);
    }

    Union(a, b, c);
    ShowList_Seq(c);
}
