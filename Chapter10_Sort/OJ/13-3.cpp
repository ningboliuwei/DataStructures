// Created by 慰 on 2018/12/13.
// 问题 C: 【数据结构10-3】希尔排序
// 输入数据：10 49 38 65 97 76 13 27 48 55 4
// 姑且可以，但是和 PPT 上 5 -- 3 -- 1 的步长变化不太符合

#include <stdio.h>

// 显示数组中所有元素
void ShowArray(int array[], int count) {
  for (int k = 0; k < count; k++) {
    printf("%d ", array[k]);
  }
  printf("\n");
}

int main() {
  int count = 0;

  scanf("%d", &count);
  int array[count];
  // 输入数组元素
  for (int i = 0; i < count; i++) {
    scanf("%d", &array[i]);
  }

  for (int gap = count / 2; gap >= 1; gap = gap / 2) {
    for (int i = 0; i < count; i++) {
      int j;
      int number = array[i];
      for (j = i; j > gap - 1; j = j - gap) {
        if (array[j - gap] > number) {
          array[j] = array[j - gap];
        } else {
          break;
        }
      }
      array[j] = number;
    }
    ShowArray(array, count);
  }

  getchar();
  getchar();
}
