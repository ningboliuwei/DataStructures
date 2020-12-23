#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define Int_max 999999
using namespace std;

#define MAXLEN 10
typedef struct {
    char vexs[MAXLEN];
    int edges[MAXLEN][MAXLEN];
    int n, e;
} mgraph;
int visitedu[MAXLEN];
int visitedv[MAXLEN];
void createmgraph(mgraph &g) {
    int i, j, k, a;
    char ch1, ch2;
    cin >> g.n >> g.e;

    for (i = 0; i < g.n; i++) {
        getchar();
        cin >> g.vexs[i];
    }
    for (i = 0; i < g.n; i++) {
        for (j = 0; j < g.n; j++) {
            g.edges[i][j] = Int_max;
        }
    }
    for (k = 0; k < g.e; k++) {
        getchar();
        cin >> ch1 >> ch2 >> a;
        for (i = 0; i < g.n; i++) {
            if (ch1 == g.vexs[i]) {
                for (j = 0; j < g.n; j++) {
                    if (ch2 == g.vexs[j]) {
                        g.edges[i][j] = a;
                        g.edges[j][i] = a;
                    }
                }
            }
        }
    }
}
void MiniSpanTree_PRIM(mgraph G) {
    int i, j, k;
    int count = 0;
    int u[MAXLEN], v[MAXLEN];
    int front, rear;
    int min;
    for (i = 0; i < G.n; i++) {
        u[i] = 0;
        v[i] = i;
        visitedu[i] = 0;
        visitedv[i] = 0;
    }
    printf("最小生成树\n");
    
    while (count < G.n - 1) {
        min = Int_max;
        for (i = 0; i <= count; i++)
            for (j = 0; j < G.n; j++)
                if (!visitedu[i] || !visitedv[j])
                    if (min > G.edges[u[i]][v[j]]) {
                        min = G.edges[u[i]][v[j]];
                        front = u[i];
                        rear = v[j];
                    }
        printf("%c %c %d\n", G.vexs[front], G.vexs[rear], min);
        visitedu[front] = 1;
        visitedv[rear] = 1;
        visitedv[front] = 1;
        count++;
        u[count] = rear;
        visitedu[count] = 1;
    }
}

int main() {
    mgraph g;
    createmgraph(g);
    MiniSpanTree_PRIM(g);
    return 0;
}