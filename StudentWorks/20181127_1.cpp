//
// Created by Liu Wei on 2018/11/27.
//

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXLEN
// MAXLEN 后少了数值，结果会有 g.n 被神奇修改的 bug

typedef struct edgenode
{
    int adjvex;   //临界顶点下标
    struct edgenode * next;
}Edgenode;

typedef struct
{
    char vertex;
    Edgenode *firstedge;
}vertexnode;

typedef struct
{
    vertexnode adjlist[MAXLEN];
    int n,e;
}alg;
void create(alg &g)
{
    int i,j,k,pos1,pos2;
    Edgenode *s;
    char ch1,ch2,ch;
    scanf("%d%d",&(g.n),&(g.e));
    printf("%d %d\n",g.n,g.e);
    //getchar();
    for(i=0;i<g.n;i++)
    {
        scanf("\n%c",&ch);
        g.adjlist[i].vertex=ch;
        printf("%c",g.adjlist[i].vertex);
        printf("%d %d\n",(g.n),g.e);
        g.adjlist[i].firstedge=NULL;
        getchar();
    }

    for(i=0;i<g.e;i++)
    {
        scanf("%c %c",&ch1,&ch2);
        for(j=0;j<g.n;j++)
        {
            if(g.adjlist[j].vertex==ch1)
                pos1=j;

            if(g.adjlist[j].vertex==ch2)
                pos2=j;
        }

        s=new edgenode;
        s->adjvex=pos2;
        s->next=NULL;
        g.adjlist[pos1].firstedge=s;


    }
    Edgenode *p;
    for(i=0;i<g.n;i++)
    {
        printf("%d %c",i,g.adjlist[i].vertex);
        p=g.adjlist[i].firstedge;
        while(p)
        {
            printf("->%d",p->adjvex);
            p=p->next;
        }
        printf("\n");

    }



}
int main()
{
    alg g;

    create(g);


}