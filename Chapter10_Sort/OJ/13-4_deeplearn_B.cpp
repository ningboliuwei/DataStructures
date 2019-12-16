//
// Created by 慰 on 2018/12/13.
// 问题 D: 【数据结构10-4】改进的冒泡排序
// 输入数据：6 3 45 82 36 100 12
// 输入数据2：6 40 45 82 36 100 12
// 另一种冒泡法，区别在于内层循环的循环变量取值

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

  int notSortedCount = count;
  int pos;

  for (int i = 0; i < count; i++) {
    // 判断本轮是否有交换，若没有，则提前结束循环
    bool anySwap = false;

    for (int j = 0; j < count - i; j++) {
      if (array[j] > array[j + 1]) {
        // 输出交换前的数组
        printf("before: ");
        ShowArray(array, count);
        // 输出要交换的数
        printf("swap %d %d\n", array[j], array[j + 1]);

        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
        // 输出交换后的数组
        printf("after: ");
        ShowArray(array, count);
        printf("###\n");

        anySwap = true;
      }
    }

    // 若无任何交换，提早结束循环
    if (!anySwap) {
      break;
    }

    printf("this round ends: ");
    ShowArray(array, count);
    printf("--------------------------\n");

    getchar();
  }
}
