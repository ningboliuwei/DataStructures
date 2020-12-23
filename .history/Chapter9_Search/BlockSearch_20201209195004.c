#include <stdio.h>

#define BLOCK_COUNT 4

struct index //�����Ľṹ
{
    int key;                       //��Ĺؼ���
    int start;                     //�����ʼֵ
    int end;                       //��Ľ���ֵ
} index_table[BLOCK_COUNT];        //����ṹ������
                                   //
int block_search(int key, int a[]) //�Զ���ʵ�ַֿ����
{
    int i, j;
    i = 1;

    while (i <= BLOCK_COUNT && key > index_table[i].key) //ȷ�����ĸ�����
    {
        i++;
    }

    if (i > BLOCK_COUNT) //���ڷֵõĿ������򷵻�0
    {
        return 0;
    }

    j = index_table[i].start; // j���ڿ鷶Χ����ʼֵ

    while (j <= index_table[i].end && a[j] != key) //��ȷ���Ŀ��ڽ���˳�����
    {
        j++;
    }

    if (j >
        index_table[i].end) //������ڿ鷶Χ�Ľ���ֵ����˵��û��Ҫ���ҵ�����j��0
    {
        j = 0;
    }

    return j;
}

int main() {
    int i, j = 0, k, key, a[16];
    printf("������15������\n");

    for (i = 1; i < 16; i++) {
        scanf("%d", &a[i]); //������С�����15����
    }

    for (i = 1; i <= BLOCK_COUNT; i++) {
        index_table[i].start = j + 1; //ȷ��ÿ���鷶Χ����ʼֵ
        j = j + 1;
        index_table[i].end = j + 4; //ȷ��ÿ���鷶Χ�Ľ���ֵ
        j = j + 1 + BLOCK_COUNT;
        index_table[i].key = a[j]; //ȷ��ÿ���鷶Χ��Ԫ�ص����ֵ
    }
    printf("������������ҵ�Ԫ�أ�\n");
    scanf("%d", &key);        //����Ҫ��ѯ����ֵ
    k = block_search(key, a); //���ú�����������

    if (k != 0) {
        printf("���ҳɹ�����λ���ǣ�%d\n", k); //����ҵ��������������λ��
    } else {
        printf("����ʧ��!"); //��δ�ҵ����������ʾ��Ϣ
    }

    return 0;
}

// ������15������
// 11 12 18 28 39 56 69 89 96 122 135 146 156 256 298
// ������������ҵ�Ԫ�أ�
// 96
// ���ҳɹ�����λ���ǣ�9