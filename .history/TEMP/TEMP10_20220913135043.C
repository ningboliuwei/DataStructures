#include <stdio.h>
#include <stdlib.h>

void Foo(int x) {
    printf("in foo before x = 3, x\n");
    printf("%d\n", &x);
    x = 3;
    printf("in foo after x = 3, x\n");
    printf("%d\n", &x);
}

int main() {
    int a = 5;
    printf("before foo, a\n");
    printf("%d\n", &a);
    Foo(a);
    printf("after foo, a\n");
    printf("%d\n", &a);
    printf("%d", a);

    getchar();
}