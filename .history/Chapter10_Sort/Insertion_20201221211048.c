#include <stdio.h>
#define NUMBER_COUNT 7
//自定义的输出函数
void print(int a[], int n, int i) {
    printf("%d:", i);
    for (int j = 0; j < NUMBER_COUNT; j++) {
        printf("%d ", a[j]);
    }
    printf("\n");
}
//直接插入排序函数
void InsertSort(int array[], int n) {
    for (int i = 1; i < n; i++) {
        if (array[i] < array[i - 1]) { //若第 i 个元素大于 i-1
            //元素则直接插入；反之，需要找到适当的插入位置后在插入。
            int j = i - 1;
            int x = array[i];
            while (
                j > -1 &&
                x < array
                        [j]) { //采用顺序查找方式找到插入的位置，在查找的同时，将数组中的元素进行后移操作，给插入元素腾出空间
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = x; //插入到正确位置
        }
        print(array, n, i); //打印每次排序后的结果
    }
}
int main() {
    int a[7] = {49, 38, 65, 97, 76, 13, 27};
    InsertSort(a, 7);

    int x;
    scanf("%d", &x);
    return 0;
}