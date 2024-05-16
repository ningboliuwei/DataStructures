#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 100 /* 声明：MAXVEX 用于定义图中最大的顶点数 */

/* 定义链表节点，表示图的边 */
typedef struct EdgeNode {
    int adjvex;            // 声明：adjvex 存储邻接点的索引
    struct EdgeNode *next; // 声明：next 指针指向下一个邻接点
} EdgeNode;

/* 定义顶点表节点 */
typedef struct VertexNode {
    char vertex;         // 声明：vertex 存储顶点信息
    EdgeNode *firstEdge; // 声明：firstEdge 指向该顶点的第一个邻接点
} VertexNode, AdjList[MAXVEX];

/* 定义图结构 */
typedef struct {
    AdjList adjList; // 声明：adjList 邻接表数组
    int numVertexes; // 声明：numVertexes 图中当前的顶点数
    int numEdges;    // 声明：numEdges 图中当前的边数
} GraphAdjList;

/* 创建图的函数 */
void CreateALGraph(GraphAdjList *G) {
    int i, j;                                      // 声明：i 和 j 用作循环计数
    char c1, c2;                                   // 声明：c1 和 c2 用于临时存储输入的顶点信息
    scanf("%d %d", &G->numVertexes, &G->numEdges); // 读取顶点数和边数
    for (i = 0; i < G->numVertexes; i++) {         // 初始化顶点表
        scanf(" %c", &G->adjList[i].vertex);       // 读取顶点信息
        G->adjList[i].firstEdge = NULL;            // 初始化边表头指针为NULL
    }
    for (i = 0; i < G->numEdges; i++) { // 读取边信息
        scanf(" %c %c", &c1, &c2);      // 读取一条边的两个顶点
        int position1 = c1 - 'a';       // 计算顶点索引
        int position2 = c2 - 'a';       // 计算顶点索引

        EdgeNode *newEdge = (EdgeNode *)malloc(sizeof(EdgeNode)); // 创建新的边节点
        newEdge->adjvex = position2;                              // 设置邻接点索引
        newEdge->next = NULL;                                     // 设置next指针为NULL

        if (G->adjList[position1].firstEdge == NULL) { // 边表为空时直接插入
            G->adjList[position1].firstEdge = newEdge;
        } else { // 否则遍历到边表末尾,尾插法插入新节点
            EdgeNode *lastEdge = G->adjList[position1].firstEdge;
            while (lastEdge->next != NULL) {
                lastEdge = lastEdge->next;
            }
            lastEdge->next = newEdge;
        }
    }
}

/* 打印图的邻接表 */
void PrintGraph(GraphAdjList *G) {
    for (int i = 0; i < G->numVertexes; i++) {
        EdgeNode *e = G->adjList[i].firstEdge;
        printf("%d %c", i, G->adjList[i].vertex); // 打印顶点索引和顶点信息
        while (e) {                               // 遍历该顶点的所有邻接点
            printf("->%d", e->adjvex);            // 打印邻接点索引
            e = e->next;                          // 移到下一个邻接点
        }
        printf("\n"); // 一个顶点的邻接点打印完毕，换行
    }
}

/* 主函数 */
int main() {
    GraphAdjList GL;    // 声明：GL 图的邻接表结构变量
    CreateALGraph(&GL); // 调用函数创建图
    PrintGraph(&GL);    // 调用函数打印图的邻接表
    return 0;           // 程序结束
}