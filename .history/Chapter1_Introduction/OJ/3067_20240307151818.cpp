// OJ PASSED
// OJ 3067

#include "stdlib.h"  // 引入标准库头文件
#include <iostream>  // 引入输入输出流头文件
using namespace std; // 使用命名空间 std

typedef int datatype; // 定义数据类型为 int
#define MAXLEN 100    // 定义最大长度为 100

typedef struct linknode {  // 定义链表结构体
    datatype data;         // 数据域
    struct linknode *next; // 指向下一个节点的指针
} LinkNode, *LinkList;

// @@1

LinkList CreatLinkList() {
    datatype x;
    LinkList p, head = NULL, tail;
    while (1) {
        cin >> x;
        if (x == -1)
            break;
        p = new LinkNode;
        p->data = x;
        p->next = NULL;
        if (head == NULL)
            head = p;
        else
            tail->next = p;
        tail = p;
    }
    return head;
}
int SearchLinkList(LinkList L, datatype x) {
    LinkList p = L, q = NULL;
    int i = 1;
    while (p) {
        if (p->data < x) {
            i++;
            p = p->next;
        } else
            break;
    }
    return i;
}
void InsLinkList(LinkList &L, int pos, datatype x) {
    LinkList p = L, s, q;
    int i = 1;
    while (i < pos) {
        q = p;
        p = p->next;
        i++;
    }
    s = new LinkNode;
    s->data = x;
    s->next = NULL;
    if (pos == 1) {
        s->next = L;
        L = s;
    } else {
        q->next = s;
        s->next = p;
    }
}
void ShowLinkList(LinkList L) {
    LinkList p = L;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
}

// @@1

int main() {     // 主函数
    LinkList L;  // 定义一个链表
    datatype x;  // 定义一个数据类型为 datatype 的变量 x
    int pos = 0; // 定义一个变量 pos，表示插入位置

    L = CreatLinkList();        // 创建链表
    cin >> x;                   // 输入要插入的元素
    pos = SearchLinkList(L, x); // 查找要插入的位置
    InsLinkList(L, pos, x);     // 在链表中插入元素
    ShowLinkList(L);
    // 输出链表中的元素
    return 0; // 返回 0，表示程序正常结束
} // 函数结束