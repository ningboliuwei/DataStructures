#include <stdio.h>
#include <stdlib.h>

void Foo(int x) {
    printf("in foo before x = 3, x value: %d\n", x);
    printf("address: %d\n", &x);
    x = 3;
    printf("in foo after x = 3, x value: %d\n", x);
    printf("address: %d\n", &x);
}

int main() {
    int a = 5;
    printf("before foo, a value:%d\n", a);
    printf("address: %d\n", &a);
    Foo(a);
    printf("after foo, a value:%d\n", a);
    printf("address: %d\n", &a);
    printf("%d", a);

    getchar();
}