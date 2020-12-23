//
// Created by Liu Wei on 2018/11/26.
// ���� B: �����ݽṹ8-2��ͼ�Ĵ洢�����ڽӱ�

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 10
typedef char VertexType;

// �߽��
typedef struct EdgeNodeStruct {
    VertexType adjVex;
    struct EdgeNodeStruct *next;
} EdgeNode;

// ������
typedef struct {
    VertexType vertex;
    EdgeNode *firstEdge;
} VertexNode;

typedef struct {
    VertexNode adjList[MAXLEN];
    int n;
    int e;
} ALGraph;

void CreateGraph(ALGraph *g) {
    char vex1;
    char vex2;
    int pos1;
    int pos2;

    printf("���붥�����������");
    scanf("%d %d\n", &(g->n), &(g->e));
printf("��������㣺");
    for (int i = 0; i < g->n; i++) {
        char c;
        scanf("\n%c", &c);
        g->adjList[i].vertex = c;
    }

    for (int i = 0; i < g->e; i++) {
        printf("����ߵ�������յ㣺");
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
}