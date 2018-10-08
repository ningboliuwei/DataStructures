//
// Created by 慰 on 2018/10/8.
// 本 C 文件中所有函数都针对于不带头结点的链表
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} Node, *LinkList;

// 头插法创建不带头结点的链表
LinkList CreateLinkListByHeadInsertion(LinkList linkList) {
    int data;

    while (scanf("%d", &data) && data != -1) {
        Node *newNode = (Node *) malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;

        // 如果 linkList 为空（即当前没有任何结点）
        if (linkList == NULL) {
            // linkList 指向新节点
            linkList = newNode;
        } else {
            newNode->next = linkList;
            linkList = newNode;
        }
    }

    return linkList;
}

//显示不带头结点的链表元素
void ShowLinkList(LinkList linkList) {
    // 声明一个 Node 指针指向链表中第一个结点
    Node *p = linkList;
    // 输出链表中每一个节点的 data 域的值
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
}

// 尾插法创建带头结点的链表
LinkList CreateLinkListByTailInsertion(LinkList linkList) {
    int data;
    Node *tail = NULL;

    printf("Input the numbers, -1 to exit.\n");
    while (scanf("%d", &data) && data != -1) {
        Node *newNode = (Node *) malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;

        // 如果 linkList 为空（即当前没有任何结点）
        if (linkList == NULL) {
            // linkList 指向新节点
            linkList = newNode;
        } else {
            // 尾结点的 next 域指向新节点
            tail->next = newNode;
        }
        // 尾结点指针指向新的结点（即新结点作为尾结点）
        tail = newNode;
    }

    return linkList;
}

//
//
// 求不带头结点的链表长度
int LengthOfLinkList(LinkList linkList) {
    Node *p = linkList;

    int n = 0;
    while (p != NULL) {
        n++;
        p = p->next;
    }
    return n;
}


// 根据位置（从 0 开始的下标）搜索链表中的元素
Node *GetNodeByPosition(LinkList linkList, int pos) {
    Node *p = linkList;
    int i = 0;

    // 在 p 没有移动到链表最后一个结点，及当前下标小于指定下标前，不断将 p 后移一个结点
    while (p->next != NULL && i < pos) {
        p = p->next;
        i++;
    }
    // 若 i 刚好是指定下标（即 pos 没有比链表中最后一个结点的下标还大）
    if (i == pos) {
        return p;
    } else {
        return NULL;
    }
}

// 根据某个值搜索第一个结点拥有该值的结点在链表中的位置
int GetPositionByValue(LinkList linkList, int value) {
    Node *p = linkList;
    int i = 0;

    while (p != NULL && p->data != value) {
        p = p->next;
        i++;
    }

    if (p->data == value) {
        return i;
    } else {
        return -1;
    }
}

int Insert(LinkList linkList, int pos, int value) {
    Node *p = linkList;
    int i = 0;

    while (p->next != NULL && i < pos - 1) {
        p = p->next;
        i++;
    }

    if (p == NULL || i >= pos) {
        return 0;
    } else {
        Node *s = (Node *) malloc(sizeof(Node));
        s->data = value;
        s->next = p->next;
        p->next = s;

        return 1;
    }
}
//
//// 删除链表中指定位置的元素
//int DelList_L(LinkList linkList, int pos) {
//    Node *p = linkList;
//    int index = 0;
//
//    while (p->next != NULL && index < pos - 1) {
//        p = p->next;
//        index++;
//    }
//
//    if (p || index > pos - 1) {
//        return 0;
//    } else {
//        Node *q = p->next;
//        p->next = q->next;
//        free(q);
//
//        return 1;
//    }
//}
//
//// 我自己的写法
//int DelList_L2(LinkList linkList, int pos) {
//    Node *p = linkList;
//    int index = 0;
//
//    if (pos <= 0 || pos > LengthList_L(linkList)) {
//        return -1;
//    }
//
//    // 这里的 p->next == NULL 判定可以精简吗？
//    while (index < pos - 1) {
//        p = p->next;
//        index++;
//    }
//
//    Node *q = p->next;
//    p->next = q->next;
//    free(q);
//
//    return 1;
//}


int main() {
    LinkList linkList = NULL;

    printf("Input the numbers, -1 to exit\n");
    // 使用头插法创建列表，使用下一行
    linkList = CreateLinkListByHeadInsertion(linkList);
    // 使用尾插法创建列表，使用下一行
    // linkList = CreateLinkListByTailInsertion(linkList);
    // 显示列表中的元素
    ShowLinkList(linkList);
    // 输出链表中所有元素
    int length = LengthOfLinkList(linkList);
    printf("Length: %d\n", length);
    printf("Input the position:\n");
    int position;
    scanf("%d", &position);
    // 输出下标为 position 的结点中的数据
    Node *node = GetNodeByPosition(linkList, position);
    if (node != NULL) {
        printf("The element is %d.\n", node->data);
    } else {
        printf("Invalid position");
    }
    // 输出值为 value 的结点在链表中的位置
    printf("Input the value:\n");
    int value;
    scanf("%d", &value);
    position = GetPositionByValue(linkList, value);
    if (position != -1) {
        printf("The position of %d is %d.\n", value, position);
    } else {
        printf("Can't find");
    }

    // 在链表中的指定位置 pos 插入一个值为 value 的结点
    printf("\n");
    printf("Input a new number:\n");
    scanf("%d", &value);
    printf("Input the position you want to insert:");
    scanf("%d", &position);
    int result = Insert(linkList, position, value);
    // 插入成功
    if (result == 1) {
        printf("The elements of the link list after insertion:");
        ShowLinkList(linkList);
        printf("\n");
    } else {
        //插入失败
        printf("Insertion failed.");
    }

//    printf("\n");
//    printf("The elements of the linklist:");
//    ShowList_L(linkList);
//    printf("\n");
//
//    int length = LengthList_L(linkList);
//    printf("\n");
//    printf("The length of the linklist is %d.", length);
//    printf("\n");

//    printf("\n");
//    printf("Input a index you want to search.");
//    printf("\n");
//
//    int index = 0;
//    scanf("%d", &index);
//    Node *result = SearchListByPos_L(linkList, index);
//    printf("The found element is %d", result->data);
//
//    printf("\n");
//    printf("Input a element you want to search.");
//    printf("\n");
//
//    int element = 0;
//    scanf("%d", &element);
//    int pos = SearchListByElement_L(linkList, element);
//
//    printf("\n");
//    printf("The found position is %d", pos);

//    int pos;
//    printf("\n");
//    printf("Input the position of element you want to delete");
//    scanf("%d", &pos);
//    int q = DelList_L2(linkList, pos);
//
//    printf("%d\n", q);
//    printf("The elements of the linklist after deletion:");
//    ShowList_L(linkList);
//    printf("\n");


//
//    printf("%d\n", q);
//    printf("The elements of the linklist after insertion:");
//    ShowList_L(linkList);
//    printf("\n");
//
//    getchar();
}
