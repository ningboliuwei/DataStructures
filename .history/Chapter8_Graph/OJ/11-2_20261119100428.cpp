//
// Created by Liu Wei on 2018/11/26.
// 问题 B: 【数据结构8-2】图的存储——邻接表

#include <stdio.h>
#include <stdlib.h>

typedef char VertexType;
#define MAX_NODE_COUNT 10

typedef struct EdgeNodeStruct {
    int adjvex;
    struct EdgeNodeStruct *next;
} EdgeNode;

typedef struct {
    VertexType vertex;
    EdgeNode *firstEdge;
} VertexNode;

typedef struct {
    VertexNode adjList[MAX_NODE_COUNT];
    int n;
    int e;
} ALGraph;

void CreateGraph(ALGraph *g) {
    char vex1;
    char vex2;
    int pos1;
    int pos2;

    scanf("%d %d\n", &(g->n), &(g->e));

    for (int i = 0; i < g->n; i++) {
        VertexType c;

        scanf("\n%c", &c);
        g->adjList[i].vertex = c;
        g->adjList[i].firstEdge = NULL;
    }

    for (int i = 0; i < g->e; i++) {
        scanf("\n%c %c", &vex1, &vex2);

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

        EdgeNode *newEdgeNode = (EdgeNode *)malloc((sizeof(EdgeNode)));
        newEdgeNode->adjvex = pos2;
        newEdgeNode->next = NULL;

        EdgeNode *tail = g->adjList[pos1].firstEdge;

        if (tail != NULL) {
            while (tail->next != NULL) {
                tail = tail->next;
            }
            tail->next = newEdgeNode;
        } else {
            g->adjList[pos1].firstEdge = newEdgeNode;
        }
    }
}
// 输出邻接表
void DisplayGraph(ALGraph *g) {
    for (int i = 0; i < g->n; i++) {
        printf("%d %c", i, g->adjList[i].vertex);
        EdgeNode *node = g->adjList[i].firstEdge;

        while (node) {
            printf("->%d", node->adjvex);
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