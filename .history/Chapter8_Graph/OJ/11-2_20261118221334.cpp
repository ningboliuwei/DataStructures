//
// Created by Liu Wei on 2018/11/26.
// 问题 B: 【数据结构8-2】图的存储——邻接表

#include <stdio.h>
#include <stdlib.h>

typedef char VertexType;

// 邻接表中的边表结点结构
typedef struct EdgeNodeStruct {
    int adjVex;
    struct EdgeNodeStruct *next;
} EdgeNode;

// 邻接表中的顶点表结点结构
typedef struct {
    VertexType vertex;
    EdgeNode *firstEdge;
} VertexNode;

typedef struct {
    // 邻接表
    VertexNode *adjList;
    // 顶点数
    int n;
    // 边数
    int e;
} ALGraph;

void CreateGraph(ALGraph *g) {
    char vex1;
    char vex2;
    int pos1;
    int pos2;

    if (scanf("%d %d", &(g->n), &(g->e)) != 2 || g->n < 0 || g->e < 0) {
        exit(EXIT_FAILURE);
    }
    g->adjList = (VertexNode *)malloc(g->n * sizeof(VertexNode));
    if (g->n > 0 && g->adjList == NULL) {
        exit(EXIT_FAILURE);
    }
    // 循环 g->n 次，输入每个顶点
    for (int i = 0; i < g->n; i++) {
        char c;
        if (scanf(" %c", &c) != 1) {
            exit(EXIT_FAILURE);
        }
        g->adjList[i].vertex = c;
        // 如果下面这句不加会有什么结果？
        g->adjList[i].firstEdge = NULL;
    }

    // 循环 g->e 次，输入每条边的起点与终点
    for (int i = 0; i < g->e; i++) {
        if (scanf(" %c %c", &vex1, &vex2) != 2) {
            exit(EXIT_FAILURE);
        }
        // 找到边的起点在顶点表中的位置
        for (pos1 = 0; pos1 < g->n; pos1++) {
            if (g->adjList[pos1].vertex == vex1) {
                break;
            }
        }
        // 找到边的终点在顶点表中的位置
        for (pos2 = 0; pos2 < g->n; pos2++) {
            if (g->adjList[pos2].vertex == vex2) {
                break;
            }
        }
        if (pos1 == g->n || pos2 == g->n) {
            exit(EXIT_FAILURE);
        }
        // 将边的终点在顶点表中的位置赋值给邻接表中的边表结点
        EdgeNode *newEdgeNode = (EdgeNode *)malloc(sizeof(EdgeNode));
        if (newEdgeNode == NULL) {
            exit(EXIT_FAILURE);
        }
        newEdgeNode->adjVex = pos2;
        newEdgeNode->next = NULL;
        // 将边表结点插入到作为起点的顶点的边表中
        EdgeNode *tail = g->adjList[pos1].firstEdge;
        // 如果该顶点的边表不为空
        if (tail != NULL) {
            // 找到该顶点的边表的最后一个结点
            while (tail->next) {
                tail = tail->next;
            }
            // 将新的边表结点插入到最后一个结点的后面
            tail->next = newEdgeNode;
        } else {
            // 如果该顶点的边表为空，则将新的边表结点插入到该顶点的边表中
            g->adjList[pos1].firstEdge = newEdgeNode;
        }

        // 以下部分加了为无向图
        // newEdgeNode = (EdgeNode *)malloc(sizeof(EdgeNode));
        // newEdgeNode->adjVex = pos1;
        // newEdgeNode->next = NULL;

        // tail = g->adjList[pos2].firstEdge;

        // if (tail != NULL) {
        //     while (tail->next) {
        //         tail = tail->next;
        //     }
        //     tail->next = newEdgeNode;
        // } else {
        //     g->adjList[pos2].firstEdge = newEdgeNode;
        // }
        // 以上部分加了为无向图
    }
}
// 输出邻接表
void DisplayGraph(ALGraph *g) {
    for (int i = 0; i < g->n; i++) {
        printf("%d %c", i, g->adjList[i].vertex);
        EdgeNode *node = g->adjList[i].firstEdge;

        while (node) {
            printf("->%d", node->adjVex);
            node = node->next;
        }

        printf("\n");
    }
}

int main() {
    ALGraph *g = (ALGraph *)malloc(sizeof(ALGraph));
    if (g == NULL) {
        return EXIT_FAILURE;
    }

    CreateGraph(g);
    DisplayGraph(g);

    for (int i = 0; i < g->n; i++) {
        EdgeNode *node = g->adjList[i].firstEdge;
        while (node != NULL) {
            EdgeNode *next = node->next;
            free(node);
            node = next;
        }
    }
    free(g->adjList);
    free(g);
    return 0;
}