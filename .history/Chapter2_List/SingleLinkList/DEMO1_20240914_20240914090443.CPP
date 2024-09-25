#include <stdio.h>
#include <stdlib.h>

// using namespace std;

typedef struct {
    int data;
} Foo;


int main() {
    Foo x;
    x.data = 1;

    printf("%d\n", x.data);

    int i;
    scanf("%d", &i);
}
