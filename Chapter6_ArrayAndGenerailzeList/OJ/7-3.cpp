//
// Created by Liu Wei on 2018/10/11.
// 问题 C: 【数据结构6-3】稀疏矩阵三元组顺序表对角线元素之和

#include<stdio.h>
#include<iostream>

using namespace std;
#define   SMAX  100

typedef struct {
    int i, j, v;
} SPNode;  //三元组

typedef struct {
    int rows, cols, terms;  //行数，列数，非0元个数
    SPNode data[SMAX];
} sparmatrix;      //三元组顺序表

int CreatSparMatrix(sparmatrix &a) {
//    @@1
    int k, m, n, t;
    n = 0;

    scanf("%d%d", &a.rows, &a.cols);
    for (k = 0; k < a.rows; k++)
        for (m = 0; m < a.cols; m++) {
            cin >> t;
            if (t != 0) {
                a.data[n].i = k;
                a.data[n].j = m;
                a.data[n].v = t;
                n++;
            }
        }
    a.terms = n;
    return 1;
//    @@1
}

int sum(sparmatrix a) {
//    @@2
    int sum = 0;

    for (int k = 0; k < a.terms; k++) {
        if (a.data[k].j == a.data[k].i) {
            sum = sum + a.data[k].v;
        }
    }
    return sum;
//    @@2
}

int main() {
    sparmatrix a;
//    @@3
    CreatSparMatrix(a);
    printf("%d", sum(a));
//    @@3
}

