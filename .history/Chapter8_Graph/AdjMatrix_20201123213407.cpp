#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 10

typedef struct {
    char vexs[MAXLEN];
    int edges[MAXLEN][MAXLEN];
    int n, e;
} MGraph;

MGraph G;

void CreateMGraph(MGraph &G) {
    int i = 0;
    int j = 0;
    int k = 0;
    char ch1;
    char ch2;

    printf("请输入顶点数和边数：\n");
    scanf("%d,%d", &(G.n), &(G.e));
    printf("请输入顶点：\n");

    for (i = 0; i < G.n; i++) {
        getchar();
        scanf("%c", &(G.vexs[i]));
    }

    for (i = 0; i < G.n; i++) {
        for (j = 0; j < G.n; j++) {
            G.edges[i][j] = 0;
        }
    }

    printf("请输入每条边对应的两个顶点：\n");

    for (k = 0; k < G.e; k++) {
        getchar();
        printf("请输入第%d条边的顶点：", k + 1);
        scanf("%c,%c", &ch1, &ch2);

        for (i = 0; ch1 != G.vexs[i]; i++) {
        }

        for (j = 0; ch2 != G.vexs[j]; j++) {
        }
        G.edges[i][j] = 1;
        // 下面这行不写会出现什么结果？
        G.edges[j][i] = 1;
    }
}

void DisplayGraph(MGraph g) {
    for (int i = 0; i < g.n; i++) {
        for (int j = 0; j < g.n; j++) {
            printf("%d", g.edges[i][j]);
        }
        printf("\n");
    }
}

int main() {
    MGraph g;
    CreateMGraph(g);
    DisplayGraph(g);
    int i = 0;

    scanf("%d", &i);
}