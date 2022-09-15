#include <stdio.h>
#include <stdlib.h>

void Foo(int x) { x = 3; }

int main() {
    int a = 5;
    Foo(a);
    printf("%d", a);

    getchar();
}