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
}

void DisplayGraph(MGraph *g) {
}

int main() {
    MGraph *g = (MGraph *)malloc(sizeof(MGraph));
}