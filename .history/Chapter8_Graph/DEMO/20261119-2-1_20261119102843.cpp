#include <stdio.h>
#include <stdlib.h>

#define MAX_NODE_COUNT 10

typedef struct {
    char vexs[MAX_NODE_COUNT];
    int edges[MAX_NODE_COUNT][MAX_NODE_COUNT];
    // 顶点个数
    int n;
    // 边个数
    int e;
} MGraph;

void CreateGraph(MGraph *g) {
    for (int i = 0; i < MAX_NODE_COUNT; i++) {
        for (int j = 0; j < MAX_NODE_COUNT; j++) {
            g->edges[i][j] = 0;
        }
    }
}

void DisplayGraph(MGraph *g) {
}

int main() {
    MGraph *g = (MGraph *)malloc(sizeof(MGraph));
}