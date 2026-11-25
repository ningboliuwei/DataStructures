#include <stdio.h>
#include <stdlib.h>

#define MAX_NODE_COUNT 10

typedef struct EdgeNodeStruct {
    int adjVex;
    struct EdgeNodeStruct *next;
} EdgeNode;

typedef struct {
    char vertext;
    EdgeNode *firstEdge;
} VertexNode;

typedef struct {
    VertexNode vexs[MAX_NODE_COUNT];
    int n;
    int e;
} ALGraph;

void CreateGraph(ALGraph *g) {
}
void DisplayGraph(ALGraph *g) {
}

int main() {
    ALGraph *g = (ALGraph *)malloc(sizeof(ALGraph));
    CreateGraph(g);
    DisplayGraph(g);

    getchar();
    getchar();
}