#include <stdio.h>
#include <stdlib.h>

// 定义多项式项的结构体
struct PolyTerm {
    int coefficient;       // 系数
    int exponent;          // 指数
    struct PolyTerm *next; // 指向下一个多项式项的指针
};

// 创建多项式链表
// 用户输入一系列的系数和指数，以0 0结束
// 返回一个链表，代表用户输入的多项式
struct PolyTerm *CreatePolynomial() {
    int coefficient, exponent;
    struct PolyTerm *currentTerm, *newTerm, *head = NULL;
    while (1) {
        scanf("%d %d", &coefficient, &exponent); // 读取用户输入
        if (coefficient == 0 && exponent == 0)
            break; // 结束输入的标志
        // 创建新的多项式项
        newTerm = (struct PolyTerm *)malloc(sizeof(struct PolyTerm));
        newTerm->coefficient = coefficient;
        newTerm->exponent = exponent;
        newTerm->next = NULL;
        // 如果这是第一个项，则将其设为头部
        // 否则，将其添加到链表的末尾
        if (head == NULL) {
            head = newTerm;
            currentTerm = newTerm;
        } else {
            currentTerm->next = newTerm;
            currentTerm = newTerm;
        }
    }
    return head;
}

// 将两个多项式相加
// 两个输入的多项式由链接表表示，其中每个节点表示一个项
// 返回一个新的链表，代表相加后的多项式
struct PolyTerm *AddPolynomials(struct PolyTerm *poly1, struct PolyTerm *poly2) {
    struct PolyTerm *resultHead = NULL, *term1 = poly1, *term2 = poly2, *newTerm, *lastTerm;
    // lastTerm 保留了对结果链表的最后一个节点的引用。这对我们在循环中动态地向结果链表添加新节点非常有用。
    // newTerm是通过动态内存分配创建的一个新的结构体变量（表示一个多项式中的一项）的指针。它用于创建一个新的多项式项，并将其添加到结果的多项式链表中。
    // 遍历两个输入的链表，根据指数合并项
    // 这个while循环在term1或term2任何一个到达它们所在链表的末尾时会终止。也就是说，这个循环会遍历poly1和poly2这两个链表，直到任何一个链表遍历完为止。 while (
        term1 != NULL && term2 != NULL) {
        newTerm = (struct PolyTerm *)malloc(sizeof(struct PolyTerm));
        if (resultHead == NULL) {
            resultHead = newTerm;
            lastTerm = newTerm;
        } else {
            lastTerm->next = newTerm;
            lastTerm = newTerm;
        }
        // 如果指数相等，合并这两个项的系数
        // 如果不等，将指数较大的项添加到结果中，并且将其在原链表中向后移动
        if (term1->exponent > term2->exponent) {
            newTerm->coefficient = term1->coefficient;
            newTerm->exponent = term1->exponent;
            term1 = term1->next;
        }

        else if (term1->exponent == term2->exponent) {
            newTerm->coefficient = term1->coefficient + term2->coefficient; // 将两个项的系数相加
            newTerm->exponent = term1->exponent;                            // 保留相同的指数
            term1 = term1->next;
            term2 = term2->next;
        } else { // term1的指数 < term2的指数
            newTerm->coefficient = term2->coefficient;
            newTerm->exponent = term2->exponent;
            term2 = term2->next;
        }
        newTerm->next = NULL;
    }
    // 如果 term1 或 term2 还有剩余的项，将其添加到结果中
    while (term1 != NULL) {
        newTerm = (struct PolyTerm *)malloc(sizeof(struct PolyTerm));
        lastTerm->next = newTerm;
        lastTerm = newTerm;
        newTerm->coefficient = term1->coefficient;
        newTerm->exponent = term1->exponent;
        newTerm->next = NULL;
        term1 = term1->next;
    }

    while (term2 != NULL) {
        newTerm = (struct PolyTerm *)malloc(sizeof(struct PolyTerm));
        lastTerm->next = newTerm;
        lastTerm = newTerm;
        newTerm->coefficient = term2->coefficient;
        newTerm->exponent = term2->exponent;
        newTerm->next = NULL;
        term2 = term2->next;
    }

    return resultHead;
}

// 显示多项式
// 遍历链表并打印出非零系数的项
void DisplayPolynomial(struct PolyTerm *head) {
    struct PolyTerm *term = head;
    while (term != NULL) {
        if (term->coefficient != 0)
            printf("%d %d\n", term->coefficient, term->exponent);
        term = term->next;
    }
}

// 删除多项式，释放内存
// 遍历链表并释放每个节点
void DeletePolynomial(struct PolyTerm *head) {
    struct PolyTerm *term;
    while (head != NULL) {
        term = head;
        head = head->next;
        free(term);
    }
}

// 实现main函数，实现 x^2 + 2x + 1 和 2x^3 + 3x^2 + 4x + 5 的相加 → x^3 + 4x^2 + 6x + 6
int main() {
    struct PolyTerm *poly1, *poly2, *sumPoly;
    printf("Enter terms for the first polynomial (coefficient exponent) and end with 0 0:\n");
    poly1 = CreatePolynomial();
    printf("Enter terms for the second polynomial (coefficient exponent) and end with 0 0:\n");
    poly2 = CreatePolynomial();

    // 两个多项式相加
    sumPoly = AddPolynomials(poly1, poly2);

    // 打印结果多项式
    printf("The resulting polynomial is:\n");
    DisplayPolynomial(sumPoly);

    // 删除多项式，释放内存
    DeletePolynomial(sumPoly);

    // 按任意键退出程序
    printf("Press any key to exit...\n");
    getchar();
    getchar();
    getchar();
    return 0;
}