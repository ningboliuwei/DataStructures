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

    // 链表为空
    if (p == NULL) {
        return NULL;
    }

    // 若要插入的位置小于 0 或者大于链表中最后一个结点的下标，不合法
    if (pos < 0 || pos > LengthOfLinkList(linkList) - 1) {
        return NULL;
    }

    // 在 p 没有移动到链表最后一个结点，及当前下标小于指定下标前，不断将 p 后移一个结点
    while (p->next != NULL && i < pos) {
        p = p->next;
        i++;
    }

    return p;
}

// 根据某个值搜索第一个结点拥有该值的结点在链表中的位置
int GetPositionByValue(LinkList linkList, int value) {
    Node *p = linkList;
    int i = 0;

    while (p != NULL && p->data != value) {
        p = p->next;
        i++;
    }

    // 链表为空
    if (p == NULL) {
        return -1;
    } else if (p->data == value) {
        return i;
    } else {
        // 遍历所有结点仍然找不到
        return -1;
    }
}

int Insert(LinkList *linkListPointer, int pos, int value) {
    // 因为链表无头结点的话，可能需要修改 linkList 指向的地址，所以需要将其作为指针
    Node *p = *linkListPointer;
    int i = 0;

    // 若要插入的位置小于 0 或者大于链表中最后一个结点的下标 + 1（最后一个结点的下标 + 1 表示作为最后一个节点插入），不合法
    if (pos < 0 || pos > LengthOfLinkList(*linkListPointer)) {
        return 0;
    }

    // 当前链表为空时，若要插入的位置不为 0，不合法
    if (p == NULL && pos != 0) {
        return 0;
    }

    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    // 如果要将新结点作为第一个结点插入
    if (pos == 0) {
        // 链表不为空时
        if (p != NULL) {
            newNode->next = (*linkListPointer)->next;
        }
        *linkListPointer = newNode;
    } else {
        while (i < pos - 1) {
            p = p->next;
            i++;
        }

        newNode->next = p->next;
        p->next = newNode;
    }
    return 1;
}

//
//// 删除链表中指定位置的元素
int Delete(LinkList *linkListPointer, int pos, int value) {
    // 因为链表无头结点的话，可能需要修改 linkList 指向的地址，所以需要将其作为指针
    Node *p = *linkListPointer;
    int i = 0;

    // 链表为空
    if (p == NULL) {
        return 0;
    }

    // 若要删除的位置小于 0 或者大于链表中最后一个结点的下标，不合法
    if (pos < 0 || pos > LengthOfLinkList(*linkListPointer) - 1) {
        return 0;
    }

    // 如果删除的是第一个结点
    if (pos == 0) {
        *linkListPointer = p->next;
        free(p);
    } else {
        while (i < pos - 1) {
            p = p->next;
            i++;
        }

        Node *q = p->next;
        p->next = p->next->next;
        free(q);
    }
    return 1;
}


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
    int result = Insert(&linkList, position, value);
    // 插入成功
    if (result == 1) {
        printf("The elements of the link list after insertion:");
        ShowLinkList(linkList);
        printf("\n");
    } else {
        //插入失败
        printf("Insertion failed.");
    }

    printf("Input the position you want to delete:");
    scanf("%d", &position);
    result = Delete(&linkList, position, value);
    // 删除成功
    if (result == 1) {
        printf("The elements of the link list after deletion:");
        ShowLinkList(linkList);
        printf("\n");
    } else {
        //删除失败
        printf("Deletion failed.");
    }

    getchar();
}
