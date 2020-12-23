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

��������
1->3,1
3->6,4
6->4,2
3->2,5
2->5,3
*/
#define MAX_VERTEX_COUNT 20 //��󶥵���Ϊ100
#define MAX_INTEGER 32767   //��ʾ�����������ʾ ��

typedef char VertexType; //ÿ��������������Ϊ�ַ���

typedef struct //�ڽӾ���ṹ��
{
    VertexType vexs[MAX_VERTEX_COUNT]; //��Ŷ���Ԫ�ص�һά����
    int edges[MAX_VERTEX_COUNT][MAX_VERTEX_COUNT]; //�ڽӾ����ά����
    int n; // ������                                         //ͼ�Ķ������ͱ���
    int e; // ����
} MGraph;

typedef struct //��������ṹ��(��ѡ��̱�)
{
    VertexType adjvex; //��ѡ��̱ߵ��ڽӵ�
    int minWeight;     //��ѡ��̱ߵ�Ȩֵ
} ShortEdge;

int LocateVex(MGraph *G,
              VertexType v) //����Ԫ��v��һά���� Vertex[] �е��±꣬�������±�
{
    int i;

    for (i = 0; i < G->n; i++) {
        if (v == G->vexs[i]) {
            return i;
        }
    }

    printf("�Ҳ����ö���!\n");
    return -1;
}

void CreateGraph(MGraph *G) //������������Undirected Network��
{
    int i, j;
    // ���붥�����ͱ���
    printf("���붥������ͱ�����\n");
    scanf("%d,%d", &G->n, &G->e);

    // ���붥��Ԫ��
    printf("�����붥�㣺\n");

    for (i = 0; i < G->n; i++) {
        getchar();
        scanf("%c", &(G->vexs[i]));
    }

    // �����ʼ��
    for (i = 0; i < G->n; i++)
        for (j = 0; j < G->n; j++) {
            G->edges[i][j] = MAX_INTEGER;
        }

    // �����ڽӾ���
    int n, m;
    VertexType v1, v2;
    int w; // v1->v2��Ȩֵ

    printf("������ߵ���Ϣ��Ȩֵ(����a,b,15)��\n");
    for (i = 0; i < G->e; i++) {
        printf("�����%d������Ϣ��Ȩֵ��", i + 1);
        scanf(" %c,%c,%d", &v1, &v2, &w);
        n = LocateVex(G, v1); //��ȡv1����Ӧ����Vertex�����е�����
        m = LocateVex(G, v2); //��ȡv2����Ӧ����Vertex�����е�����

        if (n == -1 || m == -1) {
            printf("û�иö���\n");
            return;
        }

        G->edges[n][m] = w;
        G->edges[m][n] = w; //���������˴���ͬ
    }
}

void PrintGraph(MGraph G) {
    int i = 0;
    int j = 0;

    printf("\n-------------------------------");
    printf("\n �ڽӾ���\n\n");

    printf("\t ");

    for (i = 0; i < G.n; i++) {
        printf("\t%c", G.vexs[i]);
    }

    printf("\n");

    for (i = 0; i < G.n; i++) {
        printf("\t%c", G.vexs[i]);

        for (j = 0; j < G.n; j++) {

            if (G.edges[i][j] == MAX_INTEGER)
                printf("\t��");
            else
                printf("\t%d", G.edges[i][j]);
        }
        printf("\n");
    }
}

int GetMinimalWeightVertex(MGraph *G, ShortEdge *shortedge) {
    int i = 0;
    int j = 0;
    int min = 0;
    int loc = 0;

    min = MAX_INTEGER;
    for (i = 1; i < G->n; i++) {
        if (min > shortedge[i].minWeight && shortedge[i].minWeight != 0) {
            min = shortedge[i].minWeight;
            loc = i;
        }
    }
    return loc;
}

void MiniSpanTree_Prim(MGraph *G, VertexType start) {
    int i = 0;
    int j = 0;
    int k = 0;

    ShortEdge shortedge[MAX_VERTEX_COUNT];

    // 1.������ʼ��start
    k = LocateVex(G, start);

    for (i = 0; i < G->n; i++) {
        shortedge[i].adjvex = start;
        shortedge[i].minWeight = G->edges[k][i];
    }

    shortedge[k].minWeight = 0; // minWeightΪ0��ʾ�ö�������U����

    // 2.����������
    for (i = 0; i < G->n - 1; i++) //�Լ���U��ȥ�����·���Ķ���
    {
        k = GetMinimalWeightVertex(G, shortedge); //�����·���Ķ���

        printf("%c->%c,%d\n", shortedge[k].adjvex, G->vexs[k],
               shortedge[k].minWeight); //����ҵ������·��������·��Ȩֵ
        shortedge[k].minWeight = 0; //���ҵ������·��������뼯��U��

        for (j = 0; j < G->n;
             j++) // U�м������½ڵ㣬���ܳ����µ����·�����ʸ���shortedge����
        {
            if (G->edges[k][j] <
                shortedge[j]
                    .minWeight) //�и���·������ʱ�������滻��shortedge����
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