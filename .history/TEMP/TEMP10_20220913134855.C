#include <stdio.h>
#include <stdlib.h>

void Foo(int x) {
    printf("in foo before = 3\n");
    printf("%d\n", &x);
    x = 3;
}

int main() {
    int a = 5;
    printf("before foo\n");
    printf("%d\n", &a);
    Foo(a);
    printf("%d", a);

    getchar();
}