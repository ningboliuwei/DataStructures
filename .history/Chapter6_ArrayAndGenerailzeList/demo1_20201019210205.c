//
// Created by Liu Wei on 2018/10/11.
// 问题 A: 【数据结构6-1】数组存储——多维数组顺序存储

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

void CreateMatrix(int *array, int lineCount, int columnCount) {
    for (int i = 0; i < lineCount; i++) {
        for (int j = 0; j < columnCount; j++) {
            scanf("%d", &array[i * columnCount + j]);
        }
    }
}

void ShowMatrix(int *array, int lineCount, int columnCount) {
    for (int i = 0; i < lineCount; i++) {
        for (int j = 0; j < columnCount; j++) {
            printf("%d ", array[i * columnCount + j]);
        }
        printf("\n");
    }
}

int GetLocation(int lineNumber, int columnNumber, int columnCount) {
    return lineNumber * columnCount + columnNumber;
}

int main() {
    int columnCount;
    int lineCount;
    int array[MAX_LENGTH];

    int columnNumber;
    int lineNumber;

    scanf("%d%d", &lineCount, &columnCount);
    CreateMatrix(array, lineCount, columnCount);
//    ShowMatrix(array, lineCount, columnCount);

    scanf("%d%d", &lineNumber, &columnNumber);
    printf("%d", GetLocation(lineNumber, columnNumber, columnCount));
}

