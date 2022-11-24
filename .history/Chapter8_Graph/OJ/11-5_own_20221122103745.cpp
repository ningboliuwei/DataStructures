#include <stdio.h>
#include <stdlib.h>

// ���� D: �����ݽṹ8-7�����·������Dijkstra�㷨
// ID��1649
// ���룺
// 7 10
// 0
// 1
// 2
// 3
// 4
// 5
// 6
// 0 2 8
// 2 3 5
// 3 4 6
// 0 4 30
// 0 1 13
// 4 5 2
// 1 5 9
// 1 6 7
// 5 6 17
// 0 6 30
// 0 // Դ��
// 1<-0 13
// 2<-0 8
// 3<-2<-0 13
// 4<-3<-2<-0 21
// 6<-1<-0 20

#define MAX_VEX_COUNT 10
#define INFINITY 99999
typedef struct {
    char vexs[MAX_VEX_COUNT];
    int edges[MAX_VEX_COUNT][MAX_VEX_COUNT];
    // ������
    int n;
    // ����
    int e;
} MGraph;

void MiniSpanTree_PRIM(MGraph G, int n, int v) {
    // lowcost �������ڴ�� U �����е����� i���±꣩Ȩֵ��С��·����̣����Ǹ�����ıߵ�Ȩֵ
    int lowcost[MAX_VEX_COUNT];
    // closest �������ڴ�� U �����е����� i���±꣩Ȩֵ��С��·����̣����Ǹ�������±�
    int closest[MAX_VEX_COUNT];
    int i;
    int j;
    int k;
    int min;

    for (i = 0; i < n; i++) {
        // lowcost ��ʼֵΪ��㵽�������Ȩֵ
        lowcost[i] = G.edges[v][i];
        // close ��ʼֵΪ�����±꣨�β� v��
        closest[i] = v;
    }
    // ��һ����ѡ���� U ������Ψһ�ĵ㣨����㣩������ V-U �����У�Ȩֵ��С���Ǹ���

    for (i = 0; i < n - 1; i++) {
        min = INFINITY;
        // �� lowcost �������ҳ�Ȩֵ��С���Ǹ���U ���ϵ� V-U ������Ȩֵ��С���Ǹ��ߣ�
        for (j = 0; j < n; j++) {
            if (lowcost[j] < min && lowcost[j] != 0) {
                min = lowcost[j];
                // ��¼��ĿǰΪֹ�ҵ�����СȨֵ���±굽 k
                k = j;
            }
        }
        // �����С�ߣ���ѡ���� U �� U-V ��Ȩֵ��С���Ǹ��ߣ�k �����±� 0 ������ �±� n-1��k �� V-U
        // �е���һ�ˣ������յ���±꣬closest[j] ���� U ����� j ���������������Ǹ��㣬closest[k] ���� U ����� k
        // ���������������Ǹ�����±꣨˼�����ÿ����һ���µĶ��㣬�ȿ���������㵽������������ľ���᲻���֮ǰ���������е��и����ıߣ����仰˵���Ǳ�֤
        // closest �� lowcost �����������б���Ķ��� U ��ÿ�� V-U �����е������̵��Ǹ��㣨�ͱߣ���
        printf("%d %d %d\n", closest[k] + 1, k + 1, min);
        // ��Ϊ 0����ʾ������ڼ��� U ����
        lowcost[k] = 0;

        // �������飬�жϼ��� U �Ķ��㵽���յ�֮��ı��Ƿ�Ȩֵ��С�������С���� lowcost
        // ��������ĳ��������ص�Ԫ�ظ�Ϊ�µ�Ȩֵ�� �� closest
        // ��������ĳ��������ص�Ԫ�ظ�Ϊ�µ��±꣨��������¼���Ķ�����±꣩
        for (j = 0; j < n; j++) {
            if (G.edges[k][j] < lowcost[j]) {
                lowcost[j] = G.edges[k][j];
                closest[j] = k;
            }
        }
    }

} // Min

void CreateGraph(MGraph *g) {
    char vex1;
    char vex2;
    int weight;
    int pos1;
    int pos2;

    for (int i = 0; i < MAX_VEX_COUNT; i++) {
        for (int j = 0; j < MAX_VEX_COUNT; j++) {
            if (i == j) {
                g->edges[i][j] = 0;
            } else {
                g->edges[i][j] = INFINITY;
            }
        }
    }

    scanf("%d %d\n", &(g->n), &(g->e));

    for (int i = 0; i < g->n; i++) {
        char c;
        scanf("\n%c", &c);
        g->vexs[i] = c;
    }

    for (int i = 0; i < g->e; i++) {
        scanf("\n%c %c %d", &vex1, &vex2, &weight);

        for (pos1 = 0; pos1 < g->n; pos1++) {
            if (g->vexs[pos1] == vex1) {
                break;
            }
        }

        for (pos2 = 0; pos2 < g->n; pos2++) {
            if (g->vexs[pos2] == vex2) {
                break;
            }
        }

        g->edges[pos1][pos2] = weight;
        // ������Ҫ������һ�У����ڶԽ��߶Գƣ�
        g->edges[pos2][pos1] = weight;
    }
}

int main() {
    MGraph *g = (MGraph *)malloc(sizeof(MGraph));

    CreateGraph(g);
    printf("��С������\n");
    MiniSpanTree_PRIM(*g, g->n, 0);

    getchar();
    getchar();
}