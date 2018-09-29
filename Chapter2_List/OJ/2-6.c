//
// Created by Liu Wei on 2018/9/29.
// 多项式求和——顺序表实现
#include<stdio.h>
#include<malloc.h>


#define MAXLEN  100
typedef struct xznode {
    int m;       // 系数
    int n;       // 指数
} datatype;

typedef struct {
    datatype data[MAXLEN];
    int last;
} SeqList;

SeqList *InitSeqList() {
//    @@1
    SeqList *list = (SeqList *) malloc(sizeof(SeqList));
    list->last = -1;

    return list;
//    @@1
}

int InsSeqList(SeqList *L, int i, datatype x) {
//    @@2
    int index = 0;

    if (L->last == MAXLEN - 1) {
        return 0;
    }

    if (i < 0 || i > L->last + 1) {
        return 0;
    }

    for (index = L->last + 1; index >= i; index--) {
        L->data[index] = L->data[index - 1];
    }

    L->data[i] = x;
    L->last++;

    return 1;
//    @@2
}

int CreatSeqList(SeqList *L) {
//    @@3
    // 系数
    int m = -1;
    // 指数
    int n = -1;

    while (scanf("%d%d", &m, &n) && !(m == 0 && n == 0)) {
        struct xznode node;
        node.m = m;
        node.n = n;

        InsSeqList(L, L->last + 1, node);
    }

    return 1;
//    @@3
}

int LenSeqList(SeqList *L) {
//    @@4
    return L->last + 1;
//    @@4
}

int Add_Seq(SeqList *A, SeqList *B, SeqList *C) {
//    @@5
    int maxn = -1;

    // 找到 A 与 B 中的最大指数
    for (int i = 0; i <= A->last; i++) {
        if (A->data[i].n > maxn) {
            maxn = A->data[i].n;
        }
    }

    for (int i = 0; i <= B->last; i++) {
        if (B->data[i].n > maxn) {
            maxn = B->data[i].n;
        }
    }

    for (int i = 0; i <= maxn; i++) {
        int mSum = 0;

        for (int j = 0; j <= A->last; j++) {
            if (A->data[j].n == i) {
                mSum = mSum + A->data[j].m;
            }
        }

        for (int j = 0; j <= B->last; j++) {
            if (B->data[j].n == i) {
                mSum = mSum + B->data[j].m;
            }
        }

        struct xznode node;
        node.n = i;
        node.m = mSum;
        InsSeqList(C, C->last + 1, node);
    }
//    @@5
}

int ShowSeqList(SeqList *L) {
//    @@6
    for (int i = L->last; i >= 0; i--) {
        if (L->data[i].m != 0) {
            printf("%d %d\n", L->data[i].m, L->data[i].n);
        }
    }
//    @@6
}

int main() {
    SeqList *L1, *L2, *L3;

    L1 = InitSeqList();    //初始化三个空表
    L2 = InitSeqList();
    L3 = InitSeqList();

    CreatSeqList(L1);    //创建两个顺序表
    CreatSeqList(L2);

    Add_Seq(L1, L2, L3);   //L1 L2相加之后结果放入L3
    ShowSeqList(L3);
    return 1;
}
