//
// Created by 慰 on 2018/12/13.
// 归并排序
// 输入数据：8 6 3 2 7 1 5 4 8


#include <stdio.h>

void ShowArray(int array[], int length) {
  // 显示当前趟排序所有元素
  for (int k = 0; k < length; k++) {
    printf("%d ", array[k]);
  }
  printf("\n");
}

int main() {
  int count = 0;

  scanf("%d", &count);
  int array[count];

  for (int i = 0; i < count; i++) {
    int number;
    scanf("%d", &number);

    array[i] = number;
  }

  getchar();
  getchar();
}
