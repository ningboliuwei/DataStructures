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
    // 得到顶点个数和边的个数
    scanf("%d %d\n", &(g->n), &(g->e));
    // 得到所有的顶点
    for (int i = 0; i < g->n; i++) {
        char c;
        scanf("\n%c", &c);
        g->vexs[i].vertext = c;
        g->vexs[i].firstEdge = NULL;
    }
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