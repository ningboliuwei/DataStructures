#include <stdio.h>
#include <malloc.h>
#define MAXLEN 100
typedef struct xznode {
    int m; // m为指数
    int n; // n为系数
} datatype;

typedef struct {
    datatype data[MAXLEN];
    int last;
} SeqList;

SeqList *InitSeqList() {
    // @@1
    SeqList *head;
    head = new SeqList;
    head->last = -1;
    return head;
    // @@1
}

int InsSeqList(SeqList *L, int i, datatype x) {
    // @@2
    return 1;
    // @@2
}

int CreatSeqList(SeqList *L) {
    // @@3
    while (1) {
        int m, n;
        scanf("%d %d", &n, &m);
        if (m == 0 && n == 0)
            break;
        L->data[L->last + 1].n = n;
        L->data[L->last + 1].m = m;
        L->last++;
    }
    return 1;
    // @@3
}

int LenSeqList(SeqList *L) {
    // @@4
    int i;
    i = L->last + 1;
    return i;
    // @@4
}

int Add_Seq(SeqList *A, SeqList *B, SeqList *C) {
    // @@5
    int a = 0;
    int b = 0;
    if (A->last + 1 >= B->last + 1) {
        for (int i = 0; i < A->last + 1; ++i) {
            for (int j = 0; j < B->last + 1; ++j) {
                if (A->data[i].m == B->data[j].m) {
                    C->data[C->last + 1].n = A->data[i].n + B->data[j].n;
                    C->data[C->last + 1].m = A->data[i].m;
                    C->last++;
                    break;
                } else if (j == B->last && B->data[j].m != A->data[i].m) {
                    C->data[C->last + 1].n = A->data[i].n;
                    C->data[C->last + 1].m = A->data[i].m;
                    C->last++;
                }
            }
        }
    } else if (A->last + 1 < B->last + 1) {
        for (int i = 0; i < B->last + 1; ++i) {
            for (int j = 0; j < A->last + 1; ++j) {
                if (B->data[i].m == A->data[j].m) {
                    C->data[C->last + 1].n = B->data[i].n + A->data[j].n;
                    C->data[C->last + 1].m = B->data[i].m;
                    C->last++;
                    break;
                } else if (j == B->last && B->data[j].m != A->data[i].m) {
                    C->data[C->last + 1].n = B->data[i].n;
                    C->data[C->last + 1].m = B->data[i].m;
                    C->last++;
                }
            }
        }
    }
    return 1;
    // @@5
}

int ShowSeqList(SeqList *L) {
    //  @@6
    int i = 0;
    int len = L->last + 2;
    for (i = 0; i < len; i++) {
        printf("%d %d \n", L->data[i].n, L->data[i].m);
    }
    return 1;
    // @@6
}

int main() {
    SeqList *L1, *L2, *L3;

    L1 = InitSeqList();
    L2 = InitSeqList();
    L3 = InitSeqList();

    CreatSeqList(L1); //创建两个顺序表
    CreatSeqList(L2);

    Add_Seq(L1, L2, L3); // L1 L2相加之后结果放入L3
    ShowSeqList(L3);
    return 1;
}