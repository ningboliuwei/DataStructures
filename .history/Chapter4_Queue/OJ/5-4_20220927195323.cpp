//
// Created by Liu Wei on 2018/10/9.
// 1613 问题 D: 【数据结构4-4】队列应用——医院排队

#include <stdio.h>
#include <stdlib.h>

#define QUEUE_COUNT 4

typedef int dataType;
typedef struct QNode {
    dataType data;
    struct QNode *next;
} QNode;

typedef struct qptr {
    QNode *front; //队头指针
    QNode *rear;  //队尾指针
} LinkQueue;

int InitQueue(LinkQueue *&Q) {
    //@@1
    Q = new LinkQueue;
    Q->front = NULL;
    Q->rear = NULL;

    return 1;
    //@@1
}

int QueueEmpty(LinkQueue *Q) {
    //    @@2
    if (Q->front == NULL && Q->rear == NULL) {
        return 1;
    }
    return 0;
    //    @@2
}

int InQueue(LinkQueue *Q, dataType x) {
    //    @@3
    QNode *newNode = new QNode;
    newNode->data = x;
    newNode->next = NULL;

    if (Q->rear == NULL) {
        Q->front = newNode;
        Q->rear = newNode;
    } else {
        Q->rear->next = newNode;
        Q->rear = newNode;
    }

    return 1;
    //    @@3
}

int OutQueue(LinkQueue *Q, dataType &x) {
    //@@4
    if (QueueEmpty(Q)) {
        return 0;
    }

    QNode *p = Q->front;
    x = Q->front->data;
    Q->front = Q->front->next;
    // 表示队列中只有一个元素
    if (Q->rear == p) {
        Q->rear = NULL;
    }

    free(p);

    return 1;
    //@@4
}

int QueueLength(LinkQueue *Q) {
    if (QueueEmpty(Q)) {
        return 0;
    };

    QNode *node = Q->front;
    int count = 0;
    while (node) {
        count++;
        node = node->next;
    }
    return count;
}

void ShowMainMenu() {
    printf("*****     排队系统     *****\n");
    printf("1 排队\n");
    printf("2 就诊\n");
    printf("3 查看排队\n");
    printf("4 下班\n");
    printf("*****     排队系统     *****\n");
}

void ShowDepartmentChooseMenu() {
    printf("请选择诊室：\n");
    printf("1 内科 2 外科 3 五官科 4 口腔科\n");
}

void ShowQueueElements(LinkQueue *Q) {
    if (QueueEmpty(Q)) {
        return;
    };

    QNode *node = Q->front;
    while (node) {
        printf("%d\n", node->data);
        node = node->next;
    }
}

void ShowQueueInfo(LinkQueue *Q) {
    int length = QueueLength(Q);
    if (length == 0) {
        printf("该诊室尚无人排队\n");
    } else {
        printf("该诊室排队人数%d：\n", length);
        ShowQueueElements(Q);
    }
}

int main() {
    int choice = 0;
    int department = 0;
    int registerNumber = 0;

    LinkQueue *queues[QUEUE_COUNT];

    // 初始化所有队列
    for (int i = 0; i < QUEUE_COUNT; i++) {
        queues[i] = (LinkQueue *)malloc(sizeof(LinkQueue));
        InitQueue(queues[i]);
    }

    ShowMainMenu();
    scanf("%d", &choice);

    while (choice != 4) {
        if (choice == 1) {
            ShowDepartmentChooseMenu();
            scanf("%d", &department);
            printf("请输入病历号：");
            scanf("%d", &registerNumber);

            int result = InQueue(queues[department], registerNumber);

            if (result == 1) {
                printf("挂号成功请等候，您前面排队人数%d\n", QueueLength(queues[department]) - 1);
            }
        } // 排队
        else if (choice == 2) {
            ShowDepartmentChooseMenu();
            scanf("%d", &department);

            if (QueueEmpty(queues[department])) {
                printf("该诊室尚无人排队\n");
            } else {
                int result = OutQueue(queues[department], registerNumber);

                if (result == 1) {
                    printf("请%d病人到内科看病\n", registerNumber);
                }
            }
        } // 就诊
        else if (choice == 3) {
            ShowDepartmentChooseMenu();
            scanf("%d", &department);
            ShowQueueInfo(queues[department]);
        } // 查看排队
        else {}
        ShowMainMenu();
        scanf("%d", &choice);
    }
}