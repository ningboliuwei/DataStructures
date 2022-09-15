//
// Created by Liu Wei on 2018/11/25.

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 10

typedef int VertexType;

/*
8,9
1
2
3
4
5
6
7
8
9
1,2
1,3
2,4
2,5
3,6
3,7
4,8
5,8
6,7
DFS: 1 2 4 8 5 3 6 7

*/
typedef struct {
    VertexType vertex[MAXLEN];
    int edges[MAXLEN][MAXLEN];
    // ������
    int n;
    // ����
    int e;
} MGraph;

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

    printf("�����붥�����������\n");
    scanf("%d,%d", &(g->n), &(g->e));

    printf("����������㣺\n");
    for (int i = 0; i < g->n; i++) {
        VertexType c;
        scanf("\n%d", &c);
        g->vertex[i] = c;
    }

    printf("������ÿ���߶�Ӧ���������㣺\n");
    for (int i = 0; i < g->e; i++) {
        printf("�������%d���ߵĶ��㣺", i + 1);
        scanf("\n%d,%d", &vex1, &vex2);

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
        // ����ͼ�ڽӾ���Գ�
        g->edges[pos2][pos1] = 1;
    }
}

void DFSM(MGraph *g, int nodeIndex, int *visited) {
    printf("%d ", g->vertex[nodeIndex]);
    visited[nodeIndex] = 1;

    for (int i = 0; i < g->n; i++) {
        if (g->edges[nodeIndex][i] == 1 && !visited[i]) {
            DFSM(g, i, visited);
        }
    }
}

void DFSTraverseM(MGraph *g) {
    int visited[MAXLEN];

    for (int i = 0; i < g->n; i++) {
        visited[i] = 0;
    }

    printf("DFS ");
    for (int i = 0; i < g->n; i++) {
        if (!visited[i]) {
            DFSM(g, i, visited);
        }
    }
}

int main() {
    MGraph *g = (MGraph *)malloc(sizeof(MGraph));

    CreateGraph(g);
    DFSTraverseM(g);

    int i = 0;
    scanf("%d", &i);
}
