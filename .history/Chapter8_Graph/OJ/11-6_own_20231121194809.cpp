//
// Created by Liu Wei on 2018/11/25.
// 问题 B: 【数据结构8-4】图的遍历——BFS
// OJ: 1646 OJ PASSED
/*
8 10
1
2
3
4
5
6
7
8
1 2
1 3
2 4
2 5
3 6
3 7
4 8
5 8
6 8
7 8
BFS: 1 2 3 4 5 6 7 8
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 10

typedef int VertexType;
// 基于邻接矩阵的图结构
typedef struct {
    VertexType vertex[MAXLEN];
    int edges[MAXLEN][MAXLEN];
    // 顶点数
    int n;
    // 边数
    int e;
} MGraph;
// 定义队列结构
typedef struct SequenceQueueType {
    int data[MAXLEN];
    int front;
    int rear;
} * SequenceQueue;
// 判断队列是否是空队列
int IsEmptyQueue(SequenceQueue queue) {
    if (queue->rear - queue->front == 0) {
        return 1;
    }

    return 0;
}
// 求队列长度
int LengthOfQueue(SequenceQueue queue) {
    if (IsEmptyQueue(queue)) {
        return 0;
    }

    return queue->rear - queue->front + 1;
}
// 入队
int InQueue(SequenceQueue *queue, int item) {
    if ((*queue)->rear == MAXLEN - 1) {
        return 0;
    }

    if (IsEmptyQueue(*queue)) {
        (*queue)->front = 0;
    }

    (*queue)->rear++;
    (*queue)->data[(*queue)->rear] = item;

    return 1;
}
// 出队
int OutQueue(SequenceQueue *queue, int *item) {
    if (IsEmptyQueue(*queue)) {
        return 0;
    }

    *item = (*queue)->data[(*queue)->front];
    (*queue)->front++;

    return 1;
}
// 初始化队列
int InitQueue(SequenceQueue *queue) {
    // 此处 sizeof 的参数要注意
    *queue = (SequenceQueue)malloc(sizeof(struct SequenceQueueType));

    (*queue)->front = -1;
    (*queue)->rear = -1;

    return 1;
}
// 创建基于邻接矩阵的图
void CreateGraph(MGraph *g) {
    VertexType vex1;
    VertexType vex2;
    int pos1;
    int pos2;

    for (int i = 0; i < MAXLEN; i++) {
        for (int j = 0; j < MAXLEN; j++) {
            g->edges[i][j] = 0;
        }
    }

    // printf("请输入顶点数与边数：\n");
    scanf("%d %d\n", &(g->n), &(g->e));

    // printf("请输入各顶点：\n");
    for (int i = 0; i < g->n; i++) {
        VertexType c;
        scanf("\n%d", &c);
        g->vertex[i] = c;
    }

    // printf("请输入每条边对应的两个顶点：\n");
    for (int i = 0; i < g->e; i++) {
        // printf("请输入第%d条边的顶点：", i + 1);
        scanf("\n%d %d", &vex1, &vex2);

        for (pos1 = 0; pos1 < g->n; pos1++) {
            if (g->vertex[pos1] == vex1) {
                break;
            }
        }

        for (pos2 = 0; pos2 < g->n; pos2++) {
            if (g->vertex[pos2] == vex2) {
                break;
            }
        }

        g->edges[pos1][pos2] = 1;
        // 无向图邻接矩阵对称
        g->edges[pos2][pos1] = 1;
    }
}
// 广度遍历函数（从指定的顶点出发，以广度优先的方式遍历所有的邻接顶点）
void BFSM(MGraph *g, int nodeIndex, int *visited) {
    // 创建一个队列并初始化
    SequenceQueue *queue = (SequenceQueue *)malloc(sizeof(SequenceQueue));
    InitQueue(queue);
    // 输出当前顶点信息（可以理解为“访问”了这个顶点）
    printf("%d ", g->vertex[nodeIndex]);
    // 将当前顶点设为“已访问”
    visited[nodeIndex] = 1;
    // 将当前顶点的下标入队
    InQueue(queue, nodeIndex);
    // 只要当前队列不为空，就一直进行出队（注意，从队列中删除的永远是当前的队头元素）操作，直到队列为空为止
    while (!IsEmptyQueue(*queue)) {
        // 得到当前队头元素（在顶点数组）中的下标
        int currentIndex = (*queue)->front;
        // 为了和从以往的实验题中 copy 来的队列的代码“兼容”，需要声明 item 这个变量，实际上在本程序中用不到
        int *item = (int *)malloc(sizeof(int));
        OutQueue(queue, item);

        for (int i = 0; i < g->n; i++) {
            if (g->edges[currentIndex][i] == 1 && !visited[i]) {
                printf("%d ", g->vertex[i]);
                visited[i] = 1;
                InQueue(queue, i);
            }
        }
    }

    return;
}

void BFSTraverseM(MGraph *g) {
    // 声明 visted 数组，用于记录哪些顶点已被访问过
    int visited[g->n];
    // 初始化 visted 数组
    for (int i = 0; i < g->n; i++) {
        visited[i] = 0;
    }

    printf("BFS ");
    // 针对所有当前尚未被访问的顶点，进行广度优先遍历
    for (int i = 0; i < g->n; i++) {
        if (!visited[i]) {
            BFSM(g, i, visited);
        }
    }
}

int main() {
    MGraph *g = (MGraph *)malloc(sizeof(MGraph));

    CreateGraph(g);
    BFSTraverseM(g);
    getchar();
    getchar();
}
