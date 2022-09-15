#include <stdio.h>
#include <stdlib.h>

int main() {
    int array[5] = {'a', 'b', 'c', 'd', 'e'};
    // 32位地址，占4个字节（1个字符型数据占1个字节）
    for (int i = 0; i < 5; i++) {
        printf("%x\n", &array[i]);
    }

    int x;
    scanf("%d", &x);
}