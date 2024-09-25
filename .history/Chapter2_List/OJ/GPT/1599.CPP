#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct Node {
    int data;          // 数据域
    struct Node *next; // 指针域，指向下一个节点
} Node;

// 创建链表函数
Node *createLinkedList() {
    Node *head = NULL; // 链表的头指针，初始化为NULL
    Node *tail = NULL; // 链表的尾指针，便于快速插入新节点
    int num;

    // 读取输入，直到遇到-1
    while (scanf("%d", &num) == 1 && num != -1) {
        // 创建一个新节点
        Node *newNode = (Node *)malloc(sizeof(Node));
        if (!newNode) {
            // 内存分配失败，释放已分配的节点并退出
            Node *current = head;
            while (current != NULL) {
                Node *temp = current;
                current = current->next;
                free(temp);
            }
            printf("Memory allocation failed.\n");
            exit(1);
        }
        newNode->data = num;
        newNode->next = NULL;

        // 插入新节点到链表末尾
        if (head == NULL) {
            head = newNode; // 第一个节点
            tail = newNode;
        } else {
            tail->next = newNode; // 将新节点连接到链表末尾
            tail = newNode;       // 更新尾指针
        }
    }

    return head;
}

// 查找并计数函数
int countOccurrences(Node *head, int x) {
    int count = 0;        // 初始化计数器
    Node *current = head; // 从头节点开始遍历

    while (current != NULL) {
        if (current->data == x) {
            count++; // 找到一个匹配的节点，计数加1
        }
        current = current->next; // 移动到下一个节点
    }

    return count; // 返回总计数
}

int main() {
    // 创建链表
    Node *head = createLinkedList();

    // 读取要查找的值x
    int x;
    if (scanf("%d", &x) != 1) {
        printf("Invalid input for x.\n");
        // 释放链表内存
        Node *current = head;
        while (current != NULL) {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
        return 1;
    }

    // 查找x在链表中出现的次数
    int count = countOccurrences(head, x);

    // 输出结果
    if (count > 0) {
        printf("%d %d\n", count, x);
    } else {
        printf("NO\n");
    }

    // 释放链表内存
    Node *current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
