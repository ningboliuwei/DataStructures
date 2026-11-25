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
    char vex1;
    char vex2;
    int pos1;
    int pos2;
    // 得到顶点个数和边的个数
    scanf("%d %d\n", &(g->n), &(g->e));
    // 得到所有的顶点
    for (int i = 0; i < g->n; i++) {
        char c;
        scanf("\n%c", &c);
        g->vexs[i].vertext = c;
        g->vexs[i].firstEdge = NULL;
    }

    // 得到所有的边
    for (int i = 0; i < g->e; i++) {
        scanf("\n%c %c %d", &vex1, &vex2);

        for (int pos1 = 0; pos1 < g->n; pos1++) {
            if (g->vexs[pos1].vertext == vex1) {
                break;
            }
        }
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