// 快速排序
// 输入数据 1： 8 49 38 65 97 76 13 27 50
// 输入数据 2： 9 49 38 65 97 76 65 13 27 50
// 输入数据 3： 10 82 42 33 67 82 53 24 35 84 8

#include <stdio.h>

// 显示数组中所有元素
void ShowArray(int array[], int count) {
    for (int k = 0; k < count; k++) {
        printf("%d ", array[k]);
    }

    printf("\n");
}

int Partition(int array[], int lowerIndex, int upperIndex) {
    int pivot = array[lowerIndex]; //取基准值
    int mark = lowerIndex;         // Mark初始化为起始下标

    for (int i = lowerIndex + 1; i <= upperIndex; i++) {
        if (array[i] <= pivot) {
            //小于基准值 则mark+1，并交换位置。
            mark++;
            int temp = array[mark];
            array[mark] = array[i];
            array[i] = temp;
        }
    }
    //基准值与mark对应元素调换位置
    array[lowerIndex] = array[mark];
    array[mark] = pivot;

    return mark;
}

void QuickSort(int array[], int lowerIndex, int upperIndex, int count) {
    if (upperIndex <= lowerIndex) {
        return;
    }
   
    ShowArray(array, count);
    //切分
    int pivotIndex = Partition(array, lowerIndex, upperIndex);
    QuickSort(array, lowerIndex, pivotIndex - 1, count);
    QuickSort(array, pivotIndex + 1, upperIndex, count);
}

int main() {
    int count = 0;
    scanf("%d", &count);

    int array[count];
    // 输入数组元素
    for (int i = 0; i < count; i++) {
        scanf("%d", &array[i]);
    }

    int lower = 0;
    int upper = count - 1;

    QuickSort(array, lower, upper, count);
    printf("-------------end-------------");

    getchar();
    getchar();
}
