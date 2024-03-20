#include <stdio.h>
#include <stdlib.h>

// 定义多项式项的结构体
struct PolyTerm {
    int coefficient;       // 系数
    int exponent;          // 指数
    struct PolyTerm *next; // 指向下一个多项式项的指针
};

// 创建多项式链表
struct PolyTerm *CreatePolynomial() {
    int coefficient, exponent;
    struct PolyTerm *currentTerm, *newTerm, *head = NULL;
    while (1) {
        scanf("%d %d", &coefficient, &exponent);
        if (coefficient == 0 && exponent == 0)
            break; // 结束输入的标志
        newTerm = (struct PolyTerm *)malloc(sizeof(struct PolyTerm));
        newTerm->coefficient = coefficient;
        newTerm->exponent = exponent;
        newTerm->next = NULL;
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
struct PolyTerm *AddPolynomials(struct PolyTerm *poly1, struct PolyTerm *poly2) {
    struct PolyTerm *resultHead = NULL, *term1 = poly1, *term2 = poly2, *newTerm, *lastTerm;
    while (term1 != NULL && term2 != NULL) {
        newTerm = (struct PolyTerm *)malloc(sizeof(struct PolyTerm));
        if (resultHead == NULL) {
            resultHead = newTerm;
            lastTerm = newTerm;
        } else {
            lastTerm->next = newTerm;
            lastTerm = newTerm;
        }
        if (term1->exponent > term2->exponent) {
            newTerm->coefficient = term1->coefficient;
            newTerm->exponent = term1->exponent;
            term1 = term1->next;
        } else if (term1->exponent == term2->exponent) {
            newTerm->coefficient = term1->coefficient + term2->coefficient;
            newTerm->exponent = term1->exponent;
            term1 = term1->next;
            term2 = term2->next;
        } else { // term1->exponent < term2->exponent
            newTerm->coefficient = term2->coefficient;
            newTerm->exponent = term2->exponent;
            term2 = term2->next;
        }
        newTerm->next = NULL;
    }
    // 如果一个多项式已经完全添加到结果中，直接连接另一个多项式的剩余部分
    lastTerm->next = (term1 == NULL) ? term2 : term1;

    return resultHead;
}

// 显示多项式
void DisplayPolynomial(struct PolyTerm *head) {
    struct PolyTerm *term = head;
    while (term != NULL) {
        if (term->coefficient != 0)
            printf("%d %d\n", term->coefficient, term->exponent);
        term = term->next;
    }
}

// 删除多项式，释放内存
void DeletePolynomial(struct PolyTerm *head) {
    struct PolyTerm *term;
    while (head != NULL) {
        term = head;
        head = head->next;
        free(term);
    }
}

// 实现main函数，实现 x^2 + 2x + 1 和 2x^3 + 3x^2 + 4x + 5 的相加
int main() {
    struct PolyTerm *poly1, *poly2, *sumPoly;
    printf("Enter terms for the first polynomial (coefficient exponent) and end with 0 0:\n");
    poly1 = CreatePolynomial();
    printf("Enter terms for the second polynomial (coefficient exponent) and end with 0 0:\n");
    poly2 = CreatePolynomial();
    sumPoly = AddPolynomials(poly1, poly2);
    printf("The resulting polynomial is:\n");
    DisplayPolynomial(sumPoly);
    DeletePolynomial(sumPoly);

    getchar();
    getchar();
    getchar();
    getchar();
    return 0;
}