#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define ElemType int
#define KeyType int
#define MAX_COUNT 10
/* �����������Ľڵ�ṹ���� */
typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
//���������������㷨
int SearchBST(BiTree T, KeyType key, BiTree f, BiTree *p) {
    //��� T ָ��Ϊ�գ�˵������ʧ�ܣ��� p
    //ָ��ָ����ҹ��������һ��Ҷ�ӽ�㣬�����ز���ʧ�ܵ���Ϣ
    if (!T) {
        *p = f;
        return FALSE;
    }
    //�����ȣ��� p ָ��ָ��ùؼ��֣������ز��ҳɹ���Ϣ
    else if (key == T->data) {
        *p = T;
        return TRUE;
    }
    //��� key ֵ�� T ������ֵС�������������������֮��������������
    else if (key < T->data) {
        return SearchBST(T->lchild, key, T, p);
    } else {
        return SearchBST(T->rchild, key, T, p);
    }
}

int InsertBST(BiTree *T, ElemType e) {
    BiTree p = NULL;
    //������Ҳ��ɹ��������������
    if (!SearchBST((*T), e, NULL, &p)) {
        //��ʼ��������
        BiTree s = (BiTree)malloc(sizeof(BiTNode));
        s->data = e;
        s->lchild = s->rchild = NULL;
        //��� p ΪNULL��˵���ö���������Ϊ��������ʱ����Ľ��Ϊ�������ĸ����
        if (!p) {
            *T = s;
        }
        //��� p ��Ϊ NULL���� p
        //ָ���Ϊ����ʧ�ܵ����һ��Ҷ�ӽ�㣬ֻ��Ҫͨ���Ƚ� p �� e ��ֵȷ�� s
        //������ p �����ӻ����Һ���
        else if (e < p->data) {
            p->lchild = s;
        } else {
            p->rchild = s;
        }
        return TRUE;
    }
    //������ҳɹ�������Ҫ���������������ʧ��
    return FALSE;
}

//ɾ������
int Delete(BiTree *p) {
    BiTree q, s;
    //��� 1����� p ����ΪҶ�ӽ�㣬ֱ��ɾ������
    if (!(*p)->lchild && !(*p)->rchild) {
        *p = NULL;
    } else if (!(*p)->lchild) { //������Ϊ�գ�ֻ���ý�� p
                                //������������������ p ���ɣ�
        q = *p;
        *p = (*p)->rchild;
        free(q);
    } else if (!(*p)->rchild) { //������Ϊ�գ�ֻ���ý�� p
                                //������������������ p ���ɣ�
        q = *p;
        *p =
            (*p)->lchild; //���ﲻ��ָ�� *p
                          //ָ�������������ǽ��������洢�Ľ��ĵ�ַ��ֵ��ָ�����
                          // p
        free(q);
    } else { //������������Ϊ�գ����õ� 2 �ַ�ʽ
        q = *p;
        s = (*p)->lchild;
        //�������ҵ���� p ��ֱ��ǰ��
        while (s->rchild) {
            q = s;
            s = s->rchild;
        }
        //ֱ�Ӹı��� p ��ֵ
        (*p)->data = s->data;
        //�жϽ�� p �������� s �Ƿ�������������Ϊ�����������
        if (q != *p) {
            q->rchild =
                s->lchild; //���У�����ɾ��ֱ��ǰ������ͬʱ����ǰ�������ӽ���Ϊ
                           // q ָ����ĺ��ӽ��
        } else {
            q->lchild = s->lchild; //����ֱ�ӽ����������Ƽ���
        }
        free(s);
    }
    return TRUE;
}

int DeleteBST(BiTree *T, int key) {
    if (!(*T)) { //�����ڹؼ��ֵ���key������Ԫ��
        return FALSE;
    } else {
        if (key == (*T)->data) {
            Delete(T);
            return TRUE;
        } else if (key < (*T)->data) {
            //ʹ�õݹ�ķ�ʽ
            return DeleteBST(&(*T)->lchild, key);
        } else {
            return DeleteBST(&(*T)->rchild, key);
        }
    }
}

void PrintBST(BiTree t) //�������
{
    if (t == NULL) {
        return;
    }
    PrintBST(t->lchild);
    printf("%d ", t->data);
    PrintBST(t->rchild);
}

int main() {
    int i;
    int a[MAX_COUNT];
    int elementCount;

    BiTree T = NULL;
    printf("������Ҫ����ĸ�����");
    scanf("%d", &elementCount);
    printf("�������������");

    for (i = 0; i < elementCount; i++) {
        scanf("%d ", &a[i]);
        InsertBST(&T, a[i]);
    }

    printf("�������������������\n");
    PrintBST(T);
    printf("\n");
    // printf("ɾ��3���������������������\n");
    // DeleteBST(&T, 3);
    // PrintBST(T);
    getchar();
}

// 45 12 65 4 23 87 20 72 80

// �������������������
// 2 3 4 5 9
// ɾ�� 3 ���������������������
// 2 4 5 9