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
