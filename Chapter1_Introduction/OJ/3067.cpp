#include "stdlib.h"  // 引入标准库头文件
#include <iostream>  // 引入输入输出流头文件
using namespace std; // 使用命名空间 std

typedef int datatype; // 定义数据类型为 int
#define MAXLEN 100    // 定义最大长度为 100

typedef struct linknode {  // 定义链表结构体
    datatype data;         // 数据域
    struct linknode *next; // 指向下一个节点的指针
} LinkNode, *LinkList;

LinkList CreatLinkList() {     // 定义一个函数，用于创建链表
    LinkList L = new LinkNode; // 创建一个新的链表节点
    L->next = NULL;            // 将新节点的 next 指针设置为 NULL
    return L;                  // 返回新创建的链表
} // 函数结束

int SearchLinkList(LinkList L, datatype x) { // 定义一个函数，用于查找链表中的元素
    LinkList p = L->next;                    // 将 p 指向链表的第一个节点
    int i = 1;                               // 定义一个变量 i，表示当前节点的位置

    while (p && p->data != x) { // 遍历链表，查找元素
        p = p->next;            // 将 p 指向下一个节点
        i++;                    // 将 i 加 1
    }

    if (!p) {     // 如果 p 为 NULL，表示链表中没有找到元素 x
        return 0; // 返回 0
    }

    return i; // 返回元素 x 在链表中的位置
} // 函数结束

int InsLinkList(LinkList L, int i, datatype x) { // 定义一个函数，用于在链表中插入元素
    LinkList p = L;                              // 将 p 指向链表的头节点
    int j = 0;                                   // 定义一个变量 j，表示当前节点的位置

    while (p && j < i - 1) { // 遍历链表，查找插入位置
        p = p->next;         // 将 p 指向下一个节点
        j++;                 // 将 j 加 1
    }

    if (!p || j > i - 1) { // 如果 p 为 NULL 或 j 大于 i - 1，表示插入位置不合法
        return 0;          // 返回插入失败
    }

    LinkList s = new LinkNode; // 创建一个新的链表节点
    s->data = x;               // 将新节点的数据域设置为 x
    s->next = p->next;         // 将新节点的 next 指针指向 p 的下一个节点
    p->next = s;               // 将 p 的 next 指针指向新节点

    return 1; // 返回插入成功
} // 函数结束

void ShowLinkList(LinkList L) { // 定义一个函数，用于输出链表中的元素
    LinkList p = L->next;       // 将 p 指向链表的第一个节点

    while (p) {                 // 遍历链表
        cout << p->data << " "; // 输出当前节点的数据域
        p = p->next;            // 将 p 指向下一个节点
    }

    cout << endl; // 输出换行符
} // 函数结束

int main() {     // 主函数
    LinkList L;  // 定义一个链表
    datatype x;  // 定义一个数据类型为 datatype 的变量 x
    int pos = 0; // 定义一个变量 pos，表示插入位置

    L = CreatLinkList();        // 创建链表
    cin >> x;                   // 输入要插入的元素
    pos = SearchLinkList(L, x); // 查找要插入的位置
    InsLinkList(L, pos, x);     // 在链表中插入元素
    ShowLinkList(L);            // 输出链表中的元素
    return 0;                   // 返回 0，表示程序正常结束
} // 函数结束