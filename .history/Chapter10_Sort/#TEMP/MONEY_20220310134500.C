#include <stdio.h>

int main() {
    int moneyAmount = 0;

    scanf("%d", &moneyAmount);

    int bookPrices[4] = {6, 13, 15, 20};
    int bookQuantities[4] = {0, 0, 0, 0};
    int leftAmount = moneyAmount;

    for (int i = 0; i < 1000; i++) {
    }

    for (int i = 0; i < 4; i++) {
        printf("гд%d * %d\n", bookPrices[i], bookQuantities[i]);
    }

    int x = 0;
    scanf("%d", &x);
}