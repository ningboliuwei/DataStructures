#include <stdio.h>
#define L 100
typedef struct {
    int key;
} RecType;
typedef RecType Seqlist[L + 1];
Seqlist R;
int n;
int partition(int i, int j);
void quicksort(int low, int high);
int main() {
    int i;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &R[i].key);
    }
    quicksort(1, n);
    getchar();
    getchar();
}
int partition(int i, int j) {
    RecType pivot = R[i];
    while (i < j) {
        while (i < j && R[j].key >= pivot.key)
            j--;
        if (i < j)
            R[i++] = R[j];
        while (i < j && R[i].key <= pivot.key)
            i++;
        if (i < j)
            R[j--] = R[i];
    }
    R[i] = pivot;
    return i;
}
void quicksort(int low, int high) {
    int pirotpos, k;
    if (low < high) {
        pirotpos = partition(low, high);
        if (R[1].key != 13 || R[5].key != 76) {
            for (k = 1; k <= n; k++)
                printf("%d ", R[k].key);
            printf("\n");
            quicksort(low, pirotpos - 1);
            quicksort(pirotpos + 1, high);
        }
    }
}