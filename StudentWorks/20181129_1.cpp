#include<stdio.h>

#define MAXLEN 100
typedef struct {
    int vexs[MAXLEN];
    int edges[MAXLEN][MAXLEN];
    int n, e;
} MGraph;

void CreateMGraph(MGraph &G) {
    int i, j, k;
    int ch1, ch2;
    for (i = 0; i < G.n; i++)
        scanf("\n%d", &(G.vexs[i]));
    for (i = 0; i < G.n; i++)
        for (j = 0; j < G.n; j++)
            G.edges[i][j] = 0;
    for (k = 0; k < G.e; k++) {
        scanf("%d %d", &ch1, &ch2);
        for (i = 0; ch1 != G.vexs[i]; i++);
        for (j = 0; ch2 != G.vexs[j]; j++);
        G.edges[i][j] = 1;
        G.edges[j][i] = 1;
    }
}

void DFSM(MGraph &G, int i, int *visited) {
    int j;
    printf("%d ", i + 1);
    visited[i] = 1;
    for (j = 0; j < G.n; j++)
        if (G.edges[i][j] == 1 && !visited[j])DFSM(G, j, visited);
}

void DFSTraverseM(MGraph &G, int *visited) {
    int i;
    printf("DFS ");
    for (i = 0; i < G.n; i++)
        visited[i] = 0;
    for (i = 0; i < G.n; i++)
        if (!visited[i])DFSM(G, i, visited);
}

int main() {
    MGraph G;
    scanf("%d%d", &(G.n), &(G.e));
    int visited[G.n];
    CreateMGraph(G);
    DFSTraverseM(G, visited);
} 