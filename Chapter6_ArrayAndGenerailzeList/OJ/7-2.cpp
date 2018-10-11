//
// Created by Liu Wei on 2018/10/11.
// 问题 B: 【数据结构6-2】稀疏矩阵三元组顺序表非零元素求列和

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
    int k, m, n, t;
    n = 0;

    scanf("%d%d", &a.rows, &a.cols);    //    @#1
    for (k = 0; k < a.rows; k++)
        for (m = 0; m < a.cols; m++) {
            cin >> t;
            if (t != 0) {
//                @@1
                a.data[n].i = k;
                a.data[n].j = m;
                a.data[n].v = t;
                // 非零元个数增加 1
                n++;
//                @@1
            }
        }
    a.terms = n;
    return 1;
}

int f2(sparmatrix a, int col) {
    int k, sum = 0;

    if (col > a.cols) //    @#2
        return -1;

    for (k = 0; k < a.terms; k++)
        if (a.data[k].j == col)
            sum = sum + a.data[k].v; //    @#3
    return sum;
}

int main() {
    sparmatrix a;
    int col, sum;
    CreatSparMatrix(a);
    cin >> col;
    sum = f2(a, col - 1);
    if (sum == -1) cout << "列错";
    else cout << sum;
}