#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 10000
typedef struct student //学生结构体类型
{
    char no[10];
    char name[10];
    int grade;
} stu;

typedef struct student DataType;

typedef struct //顺序表类型
{
    DataType data[MAXLEN];
    int last;
} SeqList;

SeqList *InitSeqList() //创建一个空的顺序表
{
    SeqList *L;
    L = (SeqList *)malloc(sizeof(SeqList));
    L->last = 0;
    return L;
}

int InsertSeqList(SeqList *L, int i, DataType x) {
    int j;
    if (L->last == MAXLEN)
        return 0;
    if (i < 1 || i > L->last)
        return 0;
    if (i == 0) {
        L->data[0] = x;
        L->last++;
    } else {
        if (L->data[i - 1] == NULL) {
            return 0;
        } else {
            L->data[0] = x;
            L->last++;
        }
    }
    return 1;
}

void ShowSeqList(SeqList *L) {
    int i;
    for (i = 0; i < L->last; i++) {
        printf("%d", L->data[i]);
    }
}

int main() {
    SeqList *Lq;
    struct student x;
    int flag; // flag用来记录操作是否成功
    int i;

    Lq = InitSeqList();

    while (i != -1) {
        scanf("%s %s %d %d", x.no, x.name, &x.grade, &i);
        if (i == -1)
            break;
        if (InsertSeqList(Lq, i, x)) {
            printf("插入成功");
        } else {
            printf("位置错误");
        }
        ShowSeqList(Lq);
    }
}