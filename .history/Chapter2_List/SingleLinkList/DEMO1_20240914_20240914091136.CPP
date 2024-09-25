#include <stdio.h>
#include <stdlib.h>

// using namespace std;

typedef struct {
    int data;
} Foo;

void fun1(Foo p) {
    p.data = 2;
}

int main() {
    Foo x;
    x.data = 1;

    printf("%d\n", x.data);
    fun1(x);
    printf("%d\n", x.data);


    int i;
    scanf("%d", &i);
}
