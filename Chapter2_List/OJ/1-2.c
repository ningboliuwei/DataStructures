//
// Created by 慰 on 2018/9/24.
// 链表练习——问题 B: 【结构体】【应用】成绩管理

/*File: list17.4_struct array.c
==============================================================================
已知：一个班级，人数不超过60名，每个学生的记录为：
学号，姓名，性别，英语，数学，程序设计，总分，平均分。
要求：编程实现以下功能：
（1）、输入每位学生的各项信息。
（2）、计算每位学生的总分和平均分。
（3）、计算每门课程的平均分。
==============================================================================*/
#include <stdio.h>
#include <string.h>
struct stdType
{
    int id;
    char name[10];
    char sex;
    float English;
    float Maths;
    float Program;
    float sum;
    float average;
};
int N;//学生人数
void getaverage(struct stdType *pstu,float *E,float *M,float *P);
main()
{
    int i;
    struct stdType std[60];
    float aveE=0,aveM=0,aveP=0;
    scanf("%d",&N);//输入学生人数
    for (i=0;i<N;i++)
    {
        scanf("%d%s %c%f%f%f",&(std+i)->id,std[i].name,&std[i].sex,&std[i].English,&std[i].Maths,&std[i].Program); //读取学生信息，依次为学号、姓名(不含空格)、性别、英语分数、数学分数、程序设计分数
        (std + i)->sum = (std + i)->English + (std + i)->Maths + (std + i)->Program;    //算出每个学生的总分，并保存到结构体的成员sum中
        (std + i)->average = (std + i)->sum / 3;     //算出每个学生的平均分，并保存到结构体的成员average中
    }
    /*获取各门课的平均分*/
    getaverage(std,&aveE,&aveM,&aveP);

    /*输出数据*/
    printf("No.     name    sex     English Maths   Program  sum      average\n");
    for (i=0;i<N;i++)
    {
        printf("%d    %-8s%c   %8.1f%8.1f%8.1f  %8.1f%8.1f\n",std[i].id,std[i].name, std[i].sex, std[i].English, std[i].Maths,std[i].Program, std[i].sum, std[i].average);
    }
    printf("Average mark of English is %.2f\n",aveE);
    printf("Average mark of Maths is %.2f\n",aveM);
    printf("Average mark of Program is %.2f\n",aveP);
}
void getaverage(struct stdType *pstu,float *E,float *M,float *P)
{
    float sumE = 0;
    float sumM = 0;
    float sumP = 0;
    int i = 0;

    for (i = 0; i < N; i++) {
        sumE = sumE + (pstu + i)->English;
        sumM = sumM + (pstu + i)->Maths;
        sumP = sumP + (pstu + i)->Program;
    }

    *E = sumE / i;
    *M = sumM / i;
    *P = sumP / i;

}