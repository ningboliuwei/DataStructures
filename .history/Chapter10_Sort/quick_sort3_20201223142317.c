#include "stdlib.h"
#include <stdlib.h>
#define MAX 9
#define NUMBER_COUNT 8
//单个记录的结构体
typedef struct {
    int key;
} SqNode;
//记录表的结构体
typedef struct {
    SqNode r[MAX];
    int length;
} SqList;

void PrintArray(SqList *L) {
    for (int i = 1; i <= L->length; i++) {
        printf("%d ", L->r[i].key);
    }
    printf("\n");
}
//此方法中，存储记录的数组中，下标为 0
//的位置时空着的，不放任何记录，记录从下标为 1 处开始依次存放
int Partition(SqList *L, int low, int high) {
    L->r[0] = L->r[low];
    int pivotkey = L->r[low].key;
    //直到两指针相遇，程序结束
    while (low < high) {
        // high指针左移，直至遇到比pivotkey值小的记录，指针停止移动
        while (low < high && L->r[high].key >= pivotkey) {
            high--;
        }
        //直接将high指向的小于支点的记录移动到low指针的位置。
        L->r[low] = L->r[high];
        // low 指针右移，直至遇到比pivotkey值大的记录，指针停止移动
        while (low < high && L->r[low].key <= pivotkey) {
            low++;
        }
        //直接将low指向的大于支点的记录移动到high指针的位置
        L->r[high] = L->r[low];

        printf("l:%d, h:%d\t", low, high);
        PrintArray(L);
    }
    //将支点添加到准确的位置
    L->r[low] = L->r[0];
    return low;
}
void QSort(SqList *L, int low, int high) {
    //找到支点的位置
    // 以下三行放在此处，用于显示每趟（子序列）排序结束后的结果
    // int pivotloc = Partition(L, low, high);
    // printf("l:%d, h:%d, p:%d\t", low, high, L->r[pivotloc]);

    // PrintArray(L);

    if (low < high) {

        //对支点左侧的子表进行排序
        QSort(L, low, pivotloc - 1);
        //对支点右侧的子表进行排序
        QSort(L, pivotloc + 1, high);
    }
}
void QuickSort(SqList *L) { QSort(L, 1, L->length); }
int main() {
    SqList *L = (SqList *)malloc(sizeof(SqList));
    L->length = NUMBER_COUNT;
    L->r[1].key = 49;
    L->r[2].key = 38;
    L->r[3].key = 65;
    L->r[4].key = 97;
    L->r[5].key = 76;
    L->r[6].key = 13;
    L->r[7].key = 27;
    L->r[8].key = 50;
    QuickSort(L);

    int x = 0;
    scanf("%d", &x);
    return 0;
}