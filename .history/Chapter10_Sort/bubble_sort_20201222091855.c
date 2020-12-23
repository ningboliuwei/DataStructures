#include <stdio.h>
#define NUMBER_COUNT 8
//交换 a 和 b 的位置的函数
void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void print_array(int array[], int i) {
    printf("%d: ", i);
    for (int i = 0; i < NUMBER_COUNT; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[NUMBER_COUNT] = {49, 38, 65, 97, 76, 13, 27, 30};
    int i, j;
    int key;
    //有多少记录，就需要多少次冒泡，当比较过程，所有记录都按照升序排列时，排序结束
    for (i = 0; i < NUMBER_COUNT; i++) {
        //每次开始冒泡前，初始化 key 值为 0
        key = 0;
        //每次起泡从下标为 0 开始，到 8-i 结束
        for (j = 0; j + 1 < NUMBER_COUNT - i; j++) {
            if (array[j] > array[j + 1]) {
                key = 1;
                swap(&array[j], &array[j + 1]);
            }
        }
        //如果 key 值为 0，表明表中记录排序完成
        if (key == 0) {
            break;
        }
        print_array(array, i);
    }

    int x = 0;
    scanf("%d", &x);

    return 0;
}
