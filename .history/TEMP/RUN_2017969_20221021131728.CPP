#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define MAXLEN 5

typedef int datatype;
typedef struct {
    datatype data[MAXLEN];
    int front; // 头指针
    int count; //元素个数
} SeqQueue;

int InitQueue(SeqQueue *&Q) {
    Q->front = 0;
    Q->count = 0;
    return 1;
}
int QueueEmpty(SeqQueue *Q) {
    if (Q->count == 0) {
        printf("该诊室尚无人排队\n");
    } else {
        printf("该诊室排队人数%d：\n", Q->count);
        for (int i = Q->count; i != 0; i--) {
            printf("%d\n", Q->data[Q->front]);
            Q->front++;
        }
    }
}

int InQueue(SeqQueue *Q, datatype x) {
    if (Q->count == 5)
        return 0;
    Q->data[(Q->front + Q->count) % 5] = x;
    Q->count++;
    printf("挂号成功请等候，您前面排队人数%d\n", Q->count - 1);
    return 1;
}

int OutQueue(SeqQueue *Q, datatype &x) {
    if (Q->count == 0) {
        x = 0;
        return 0;
    }
    x = Q->data[Q->front];
    Q->front = (Q->front + 1) % 5;
    Q->count--;
    return 1;
}
int ShowMenu()

{
    printf("*****     排队系统     *****\n");

    printf("1 排队\n");

    printf("2 就诊\n");

    printf("3 查看排队\n");

    printf("4 下班\n");

    printf("*****     排队系统     *****\n");

    return 1;
}

int ShowMenu1()

{
    printf("请选择诊室：\n");

    printf("1 内科 2 外科 3 五官科 4 口腔科\n");

    return 1;
}
int main() {
    SeqQueue *nei, *wai, *wu, *kou;
    nei = new SeqQueue;
    wai = new SeqQueue;
    wu = new SeqQueue;
    kou = new SeqQueue;
    InitQueue(nei);
    InitQueue(wai);
    InitQueue(wu);
    InitQueue(kou);
    int n, ks, blh, x = 0; // ks是科室，blh是病历号。
    ShowMenu();
    int n;
    scanf("%d", &n);
    while (n != 4) {
        if (n == 1) {
            ShowMenu1();
            scanf("%d", &ks);
            printf("请输入病历号：\n");
            if (ks == 1) {
                scanf("%d", &blh);
                InQueue(nei, blh);
            }
            if (ks == 2) {
                scanf("%d", &blh);
                InQueue(wai, blh);
            }
            if (ks == 3) {
                scanf("%d", &blh);
                InQueue(wu, blh);
            }
            if (ks == 4) {
                scanf("%d", &blh);
                InQueue(kou, blh);
            }
        }
        if (n == 2) {
            ShowMenu1();
            scanf("%d", &ks);
            if (ks == 1) {
                OutQueue(nei, x);
                if (x == 0)
                    printf("该诊室尚无人排队\n");
                else
                    printf("请%d病人到内科看病\n", x);
            }
            if (ks == 2) {
                OutQueue(wai, x);
                if (x == 0)
                    printf("该诊室尚无人排队\n");
                else
                    printf("请%d病人到内科看病\n", x);
            }
            if (ks == 3) {
                OutQueue(wu, x);
                if (x == 0)
                    printf("该诊室尚无人排队\n");
                else
                    printf("请%d病人到内科看病\n", x);
            }
            if (ks == 4) {
                OutQueue(kou, x);
                if (x == 0)
                    printf("该诊室尚无人排队\n");
                else
                    printf("请%d病人到内科看病\n", x);
            }
        }
        if (n == 3) {
            ShowMenu1();
            scanf("%d", &ks);
            if (ks == 1) {
                QueueEmpty(nei);
            }
            if (ks == 2) {
                QueueEmpty(wai);
            }
            if (ks == 3) {
                QueueEmpty(wu);
            }
            if (ks == 4) {
                QueueEmpty(kou);
            }
        }
        if (n == 4)
            return 0;
        ShowMenu();
        scanf("%d", &n);
    }
}