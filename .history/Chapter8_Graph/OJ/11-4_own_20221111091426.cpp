#include <stdio.h>
#include <stdlib.h>

/*
���룺
6,10
1
2
3
4
5
6
1,2,6
1,3,1
1,4,5
2,3,5
2,5,3
3,4,5
3,5,6
3,6,4
4,6,2
5,6,6

1����ʼ�㣩

��������
1->3,1
3->6,4
6->4,2
3->2,5
2->5,3
*/
//��󶥵���
#define MAX_VERTEX_COUNT 10
//��ʾ�����������ʾ ��
#define MAX_INTEGER 32767

//ÿ��������������Ϊ�ַ���
typedef char VertexType;
//�ڽӾ���ṹ��
typedef struct {
    // ��Ŷ���Ԫ�ص�һά����
    VertexType vexs[MAX_VERTEX_COUNT];
    // �ڽӾ����ά����
    int edges[MAX_VERTEX_COUNT][MAX_VERTEX_COUNT];
    // ������
    int n;
    // ����
    int e;
} MGraph;

//��������ṹ��(��ѡ��̱�)
typedef struct {
    //��ѡ��̱ߵ��ڽӵ�
    VertexType adjvex;
    //��ѡ��̱ߵ�Ȩֵ
    int minWeight;
} ShortEdge;

// ����Ԫ��v��һά���� Vertex[] �е��±꣬�������±�
int LocateVex(MGraph *G, VertexType v) {
    int i;

    for (i = 0; i < G->n; i++) {
        if (v == G->vexs[i]) {
            return i;
        }
    }

    printf("�Ҳ����ö���!\n");
    return -1;
}
// ������������Undirected Network��
void CreateGraph(MGraph *G) {
    int i = 0;
    int j = 0;
    scanf("%d %d", &G->n, &G->e);

    for (i = 0; i < G->n; i++) {
        scanf("%c", &(G->vexs[i]));
    }

    // �����ʼ��
    for (i = 0; i < G->n; i++)
        for (j = 0; j < G->n; j++) {
            G->edges[i][j] = MAX_INTEGER;
        }

    // �����ڽӾ���
    int n = 0;
    int m = 0;
    VertexType v1;
    VertexType v2;
    int weight; // v1->v2��Ȩֵ

    for (i = 0; i < G->e; i++) {
        scanf("%c %c %d", &v1, &v2, &weight);
        // ��ȡ v1 ����Ӧ����Vertex�����е�д�±�
        n = LocateVex(G, v1);
        // ��ȡv2����Ӧ����Vertex�����е��±�
        m = LocateVex(G, v2);

        G->edges[n][m] = weight;
        // ��������Ҫ��һ�д���
        G->edges[m][n] = weight;
    }
}

int GetMinimalWeightVertex(MGraph *G, ShortEdge *shortEdge) {
    int i = 0;
    int j = 0;
    int min = 0;
    int location = 0;

    min = MAX_INTEGER;
    for (i = 1; i < G->n; i++) {
        if (min > shortEdge[i].minWeight && shortEdge[i].minWeight != 0) {
            min = shortEdge[i].minWeight;
            location = i;
        }
    }
    return location;
}

void MiniSpanTree_Prim(MGraph *G, VertexType start) {
    int i = 0;
    int j = 0;
    int k = 0;

    ShortEdge shortedge[MAX_VERTEX_COUNT];

    // 1.������ʼ��start
    k = LocateVex(G, start);

    for (i = 0; i < G->n; i++) {
        shortedge[i].adjvex = start; // ��ѡ��̱��ڽӵ�������
        shortedge[i].minWeight = G->edges[k][i];
    }

    shortedge[k].minWeight = 0; // minWeightΪ0��ʾ�ö�������U����

    // 2.����������
    for (i = 0; i < G->n - 1; i++) //�Լ���U��ȥ�����·���Ķ���
    {
        k = GetMinimalWeightVertex(G, shortedge); //�����·���Ķ���

        printf("%c->%c,%d\n", shortedge[k].adjvex, G->vexs[k],
               shortedge[k].minWeight); //����ҵ������·��������·��Ȩֵ
        shortedge[k].minWeight = 0;     //���ҵ������·��������뼯��U��

        for (j = 0; j < G->n; j++) // U�м������½ڵ㣬���ܳ����µ����·�����ʸ���shortedge����
        {
            if (G->edges[k][j] < shortedge[j].minWeight) //�и���·������ʱ�������滻��shortedge����
            {
                shortedge[j].minWeight = G->edges[k][j];
                shortedge[j].adjvex = G->vexs[k];
            }
        }
    }
}

int main() {
    VertexType start;

    MGraph G;
    CreateGraph(&G);
    PrintGraph(G);

    printf("��������ʼ�㣺");
    scanf(" %c", &start); //%cǰ���пո�
    MiniSpanTree_Prim(&G, start);

    return 0;
}