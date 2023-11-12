//
// Created by Liu Wei on 2018/11/26.
// 问题 B: 【数据结构8-2】图的存储——邻接表

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 10
typedef char VertexType;

// 邻接表中的边结构
typedef struct EdgeNodeStruct {
    VertexType adjVex;
    struct EdgeNodeStruct *next;
} EdgeNode;

// 邻接表中的顶点结点
typedef struct {
    VertexType vertex;
    EdgeNode *firstEdge;
} VertexNode;

typedef struct {
    // 顶点向量
    VertexNode adjList[MAXLEN];
    int n;
    int e;
} ALGraph;

void CreateGraph(ALGraph *g) {
    char vex1;
    char vex2;
    int pos1;
    int pos2;

    printf("输入顶点数与边数：\n");
    scanf("%d,%d", &(g->n), &(g->e));
    printf("输入各顶点：\n");

    for (int i = 0; i < g->n; i++) {
        char c;
        getchar();
        scanf("%c", &c);
        g->adjList[i].vertex = c;
        // 如果下面这句不加会有什么结果？
        g->adjList[i].firstEdge = NULL;
    }

    printf("请输入每条边对应的两个顶点：\n");

    for (int i = 0; i < g->e; i++) {
        getchar();
        printf("请输入第%d条边的顶点：", i + 1);
        scanf("\n%c,%c", &vex1, &vex2);
        // 找到边的起点在顶点集合中的位置
        for (pos1 = 0; pos1 < g->n; pos1++) {
            if (g->adjList[pos1].vertex == vex1) {
                break;
            }
        }

        for (pos2 = 0; pos2 < g->n; pos2++) {
            if (g->adjList[pos2].vertex == vex2) {
                break;
            }
        }

        EdgeNode *newEdgeNode = (EdgeNode *)malloc(sizeof(EdgeNode));
        newEdgeNode->adjVex = pos2;
        newEdgeNode->next = NULL;

        EdgeNode *tail = g->adjList[pos1].firstEdge;

        if (tail != NULL) {
            while (tail->next) {
                tail = tail->next;
            }
            tail->next = newEdgeNode;
        } else {
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

    CreateGraph(g);
    DisplayGraph(g);

    int i = 0;
    scanf("%d", &i);
}