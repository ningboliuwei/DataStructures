#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
typedef int datatype;
#define MAXLEN 100

typedef struct {
    datatype data[MAXLEN];
    int last;
} SeqList;

SeqList *CreatList_Seq();
int DelList(SeqList *L, int pos, int len);
void ShowList_Seq(SeqList *L);

SeqList *CreatList_Seq() {
    SeqList *head = (SeqList *)malloc(sizeof(SeqList));
    head->last = 0;
    datatype n;
    while (1) {
        scanf("%d", &n);
        if (n == -1) {
            break;
        }
        head->data[head->last] = n;
        head->last++;
    }

    return head;
}

int DelList(SeqList *L, int pos, int len) {
    if (pos < 1 || pos > L->last + 1)
        return 0;
    if (pos + len > L->last)
        return 0;
    for (int i = pos - 1; i < L->last - 2; i += len) {
        L->data[i] = L->data[i + 2];
        L->data[i + 1] = L->data[i + 3];
    }
    L->last -= len;
    return 1;
}

void ShowList_Seq(SeqList *L) {
    for (int i = 0; i < L->last; i++) {
        printf("%d ", L->data[i]);
    }
}

int main() {
    SeqList *L;
    int pos, len;
    L = CreatList_Seq();
    scanf("%d %d", &pos, &len);
    if (DelList(L, pos, len) == 0)
        printf("删除失败\n");
    ShowList_Seq(L);
    system("pause");
    return 0;
}