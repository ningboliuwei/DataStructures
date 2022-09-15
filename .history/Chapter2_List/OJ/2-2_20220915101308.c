//
// Created by Liu Wei on 2018/9/29.
// 【2-2】顺序表的插入删除

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// @#1 50
#define MAXLEN 50
typedef struct student //学生结构体类型
{

    char Sno[10];
    char Sname[20];
    int Grade;

} stu;

typedef struct student DataType;

typedef struct //顺序表类型
{
    DataType data[MAXLEN];
    int last;
} SeqList;

SeqList *InitSeqList() //创建一个空的顺序表
{

    SeqList *seqList = (SeqList *)malloc(sizeof(SeqList));
    seqList->last = -1;
    return seqList;
}

int InsertSeqList(SeqList *Lq, int i, DataType x) {

    int index;

    // 当前线性表已满，不允许插入
    if (Lq->last == MAXLEN - 1) {
        return 0;
    }
    // 判断插入位置（pos）是否合法
    if (i < 1 || i > Lq->last + 2) {
        printf("位置出错\n");
        return 0;
    }

    for (index = Lq->last; index >= i - 1; index--) {
        Lq->data[index + 1] = Lq->data[index];
    }

    Lq->data[i - 1] = x;
    Lq->last++;

    printf("插入成功\n");
    return 1;
}

int DelSeqList(SeqList *Lq, int i) {

    int index = 0;

    // 空表，不允许删除
    if (Lq->last == -1) {
        return 0;
    }
    // 判断删除位置（pos）是否合法
    if (i < 1 || i > Lq->last + 2) {
        return 0;
    }

    for (index = i - 1; index < Lq->last; index++) {
        Lq->data[index] = Lq->data[index + 1];
    }

    Lq->last--;

    return 1;
}

void ShowSeqList(SeqList *Lq) {
    for (int i = 0; i <= Lq->last; i++) {
        stu item = Lq->data[i];
        printf("%s %s %d\n", item.Sno, item.Sname, item.Grade);
    }
}

int main() {
    SeqList *Lq;
    DataType x;
    int flag; // flag用来记录操作是否成功
    int i;

    Lq = InitSeqList();

    int pos = 0;
    stu newStudent;
    ;
    while (scanf("%s%s%d%d", newStudent.Sno, newStudent.Sname,
                 &newStudent.Grade, &pos) &&
           pos != -1) {
        InsertSeqList(Lq, pos, newStudent);
        ShowSeqList(Lq);
    }
    //输入学生信息以及插入位置

    printf("请输入删除位序：\n");
    scanf("%d", &i);
    flag = DelSeqList(Lq, i); //删除顺序表中的某一个学生

    if (flag == 1) {
        printf("删除后：\n");
        ShowSeqList(Lq);
    } else {
        printf("不存在第%d个元素\n", i);
    }

    return 1;
}
