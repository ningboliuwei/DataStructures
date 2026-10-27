////
//// Created by Liu Wei on 2019-10-14.
////
////
//// Created by Liu Wei on 2019-10-11.
////
#include "stdio.h"
#include "stdlib.h"
//
//#define MAXLEN 100
//
//typedef int datatype;
//
//typedef struct {
//    datatype data[MAXLEN];
//    int last;
//} SeqList;
//
//SeqList *CreateList_Seq() {
//    SeqList *L = (SeqList *) malloc(sizeof(SeqList));
//    L->last = -1;
//
//    return L;
//}
//
//int InsList_Seq(SeqList *L, int pos, datatype x) {
//    for (int i = L->last; i >= pos; i--) {
//        L->data[i + 1] = L->data[i];
//    }
//
//    L->data[pos] = x;
//    L->last++;
//
//    return 1;
//}
//
//int DelList_Seq(SeqList *L, int pos) {
//    for (int i = pos; i < L->last; i++) {
//        L->data[i] = L->data[i + 1];
//    }
//    L->last--;
//}
//
//
//int LengthList_Seq(SeqList *L) {
//    return L->last + 1;
//}
//
//void ShowList_Seq(SeqList *L) {
//    for (int i = 0; i <= L->last; i++) {
//        printf("%d ", L->data[i]);
//    }
//    printf("\n");
//}
//
//int SearchList_Seq(SeqList *L, datatype x) {
//    int i = 0;
//    while (i <= L->last && L->data[i] != x) {
//        i++;
//    }
//
//    if (i <= L->last) {
//        return i;
//    } else {
//        return -1;
//    }
//}
//
//
//int SearchList_Seq2(SeqList *L, datatype x) {
//    for (int i = 0; i <= L->last; i++) {
//        if (L->data[i] == x) {
//            return i;
//        }
//    }
//    return -1;
//}
//
//int main() {
//    SeqList *list = CreateList_Seq();
//
////    printf("%d\n", list->last);
////    printf("%d\n", LengthList_Seq(list));
//
//    InsList_Seq(list, 0, 1);
//    InsList_Seq(list, 0, 2);
//    InsList_Seq(list, 0, 3);
//
//    ShowList_Seq(list);
//    DelList_Seq(list, 0);
//    ShowList_Seq(list);
//
//    getchar();
//}
//

typedef int datatype;

typedef struct LinkNode {
    datatype data;
    struct LinkNode *next;
} Node, *LinkList;

LinkList CreateList_Link() {

//    LinkList list = (LinkList) malloc(sizeof(Node));
//
//    Node *node = (Node *) malloc(sizeof(node));
//    node->next = NULL;



//    list->next = node;
    LinkList list = (LinkList) malloc(sizeof(Node));
    list->next = NULL;

    return list;
}

void InsList_Link(LinkList list, datatype x) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = x;
    node->next = NULL;

    if (list->next == NULL) {
        list->next = node;
    } else {
        node->next = list->next;
        list->next = node;
    }
}

int LengthOfList_Link(LinkList list) {
    int length = 0;
    Node *p = list;

    while (p->next != NULL) {
        p = p->next;
        length++;
    }

    return length;
}

void ShowList_Link(LinkList list) {
    Node *p = list;

    if (LengthOfList_Link(list) == 0) {
        printf("this is an empty linklist");

        return;
    }

    while (p->next != NULL) {
        p = p->next;
        printf("%d ", p->data);
    }

    printf("\n");

}


void DeleteList_Link(LinkList list, datatype x) {
    Node *p = list;

    while (p->next->data != x && p->next != NULL) {
        p = p->next;
    }

    Node *s = p->next;
    p->next = p->next->next;
    free(s);
}

int main() {
    LinkList L = CreateList_Link();
    InsList_Link(L, 1);
    InsList_Link(L, 2);
    InsList_Link(L, 3);
    InsList_Link(L, 4);
    ShowList_Link(L);
//    int length = LengthOfList_Link(L);
//    printf("\nlength: %d", length);

    DeleteList_Link(L, 1);
    ShowList_Link(L);
    DeleteList_Link(L, 2);
    ShowList_Link(L);
    DeleteList_Link(L, 3);
    ShowList_Link(L);
    DeleteList_Link(L, 4);
    ShowList_Link(L);
    getchar();
}

