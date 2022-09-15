#include <stdio.h>
#include <stdlib.h>

void Foo(int x) {
    printf("in foo before = 3");
    printf("%d", &x);
    x = 3;
}

int main() {
    int a = 5;
    printf("before foo");
    printf("%d", &a);
    Foo(a);
    printf("%d", a);

    getchar();
}