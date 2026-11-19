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

    scanf("%d %d\n", &(g->n), &(g->e));

    for (int i = 0; i < g->n; i++) {
        VertexType c;

        scanf("\n%c", &c);
        g->adjList[i].vertex = c;
        g->adjList[i].firstEdge = NULL;
    }

    for (int i = 0; i < g->e; i++) {
        scanf("\n%c %c", &vex1, &vex2);
    }
}

void DisplayGraph(ALGraph *g) {
}

int main() {
    ALGraph *g = (ALGraph *)malloc(sizeof(ALGraph));
    CreateGraph(g);
    DisplayGraph(g);
}