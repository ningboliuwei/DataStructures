#include <stdio.h>
#include <stdlib.h>

// 双向链表节点结构体定义
typedef struct DoubleLinkNode {
    int data;                        // 数据域
    struct DoubleLinkNode *previous; // 前驱指针
    struct DoubleLinkNode *next;     // 后继指针
} DoubleNode, *DoubleLinkList;

/**
 * 在双向链表的第i个位置插入元素x
 * @param L 链表头指针的引用（允许修改头指针）
 * @param x 要插入的数据值
 * @param i 插入位置（从1开始计数）
 * @return int 成功返回1，失败返回0
 */
int InsElem_Dul(DoubleLinkList &L, int x, int i) {
    if (i < 1) {
        printf("错误：插入位置i必须大于等于1。\n");
        return 0; // 位置非法
    }

    // 创建新节点
    DoubleLinkList s = (DoubleLinkList)malloc(sizeof(DoubleNode));
    if (s == NULL) {
        printf("错误：内存分配失败。\n");
        return 0;
    }
    s->data = x;
    s->previous = NULL;
    s->next = NULL;

    // 情况1：空链表插入
    if (L == NULL) {
        if (i != 1) {
            printf("错误：空链表只能插入到第1个位置。\n");
            free(s);
            return 0;
        }
        L = s; // 头指针指向新节点
        printf("成功在空链表插入元素%d作为头节点。\n", x);
        return 1;
    }

    // 情况2：头插法（插入到第1个位置）
    if (i == 1) {
        s->next = L;
        L->previous = s;
        L = s; // 更新头指针
        printf("成功在头部插入元素%d。\n", x);
        return 1;
    }

    // 寻找第i-1个节点
    DoubleLinkList p = L;
    int j = 1;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }

    if (p == NULL) {
        printf("错误：插入位置%d超出链表长度。\n", i);
        free(s);
        return 0;
    }

    // 情况3：尾插法（插入到最后一个节点之后）
    if (p->next == NULL) {
        p->next = s;
        s->previous = p;
        printf("成功在尾部插入元素%d。\n", x);
        return 1;
    }

    // 情况4：中间插入
    s->next = p->next;
    s->previous = p;
    p->next->previous = s;
    p->next = s;
    printf("成功在第%d个位置插入元素%d。\n", i, x);
    return 1;
}

/**
 * 删除双向链表中第i个位置的元素
 * @param L 链表头指针的引用（允许修改头指针）
 * @param i 删除位置（从1开始计数）
 * @return int 成功返回1，失败返回0
 */
int DelElem_Dul(DoubleLinkList &L, int i) {
    if (L == NULL) {
        printf("错误：链表为空，无法删除。\n");
        return 0;
    }

    if (i < 1) {
        printf("错误：删除位置i必须大于等于1。\n");
        return 0;
    }

    DoubleLinkList p = L;
    int j = 1;

    // 寻找第i个节点
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }

    if (p == NULL) {
        printf("错误：删除位置%d超出链表长度。\n", i);
        return 0;
    }

    // 情况1：删除头节点
    if (i == 1) {
        L = p->next; // 头指针指向下一个节点
        if (L != NULL) {
            L->previous = NULL; // 新头节点的前驱置空
        }
        printf("成功删除头节点（元素值：%d）。\n", p->data);
        free(p);
        return 1;
    }

    // 情况2：删除尾节点
    if (p->next == NULL) {
        p->previous->next = NULL;
        printf("成功删除尾节点（元素值：%d）。\n", p->data);
        free(p);
        return 1;
    }

    // 情况3：删除中间节点
    p->previous->next = p->next;
    p->next->previous = p->previous;
    printf("成功删除第%d个节点（元素值：%d）。\n", i, p->data);
    free(p);
    return 1;
}

/**
 * 打印双向链表的所有元素（从头到尾）
 * @param L 链表头指针
 */
void PrintList(DoubleLinkList L) {
    if (L == NULL) {
        printf("链表为空。\n");
        return;
    }
    DoubleLinkList p = L;
    printf("链表元素（从头到尾）：");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

/**
 * 主函数：演示插入和删除操作
 */
int main() {
    DoubleLinkList L = NULL; // 初始化空链表

    // 示例操作
    InsElem_Dul(L, 10, 1); // 插入到空链表
    InsElem_Dul(L, 20, 2); // 尾部插入
    InsElem_Dul(L, 5, 1);  // 头部插入
    InsElem_Dul(L, 15, 3); // 中间插入

    PrintList(L); // 打印链表：5 10 15 20

    DelElem_Dul(L, 2); // 删除第2个节点（值10）
    DelElem_Dul(L, 1); // 删除头节点（值5）

    PrintList(L); // 打印链表：15 20

    // 清理内存（删除剩余节点）
    while (L != NULL) {
        DelElem_Dul(L, 1);
    }

    return 0;
}