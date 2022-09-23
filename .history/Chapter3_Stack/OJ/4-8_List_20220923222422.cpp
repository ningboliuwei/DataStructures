//
// Created by 慰 on 2018/10/7.
// OJ PASSED

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_COUNT 3
#define MAX_COLUMN_COUNT 20

typedef char DataType;

typedef struct {
    DataType data[MAX_COLUMN_COUNT];
    int last;
} SeqList;

SeqList *CreatList() {
    SeqList *list = (SeqList *)malloc(sizeof(SeqList));
    list->last = -1;

    return list;
}

int InsertList(SeqList *list, int i, DataType x) {
    int index = 0;

    if (list->last == MAX_COLUMN_COUNT - 1) {
        return 0;
    }

    if (i < 0 || i > list->last + 1) {
        return 0;
    }

    for (index = list->last + 1; index >= i; index--) {
        list->data[index] = list->data[index - 1];
    }

    list->data[i] = x;
    list->last++;

    return 1;
    // @@!
}

typedef struct StackNodeStruct {
    DataType data;
    struct StackNodeStruct *next;
} StackNode;

typedef struct {
    StackNode *top;
} LinkStack;

void InitStack(LinkStack *stack) {
    stack->top = NULL;
}

int ReadTop(LinkStack *stack, DataType &topElement) {
    if (stack->top == NULL) {
        return 0;
    }

    topElement = stack->top->data;

    return 1;
}

int Push(LinkStack *stack, DataType x) {
    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    node->data = x;
    node->next = stack->top;
    stack->top = node;

    return 1;
}

int Pop(LinkStack *stack, DataType &x) {
    // 栈为空
    if (stack->top == NULL) {
        return 0;
    }

    StackNode *node = stack->top;
    x = node->data;
    stack->top = node->next;
    free(node);

    return 1;
}

int IsEmptyStack(LinkStack *stack) {
    if (stack->top == NULL) {
        return 1;
    }
    return 0;
}

int ClearStack(LinkStack *stack) {
    DataType topElement;

    while (!IsEmptyStack(stack)) {
        Pop(stack, topElement);
    }

    return 1;
}

int ShowLines(char lines[MAX_LINE_COUNT][MAX_COLUMN_COUNT]) {
    for (int i = 0; i < MAX_LINE_COUNT; i++) {
        for (int j = 0; j < MAX_COLUMN_COUNT; j++) {
            if (lines[i][j] == '\0') {
                for (int k = j - 1; k >= 0; k--) {
                    char c = lines[i][k];

                    if (c != '$') {
                        printf("%c", c);
                    }
                }

                if (lines[i][j] == '$') {
                    return 1;
                }

                break;
            }
        }
    }

    return 0;
}

void InputLines(char lines[MAX_LINE_COUNT][MAX_COLUMN_COUNT]) {
    int lineIndex = 0;

    DataType currentChar;
    DataType topElement;

    LinkStack *lineStack = (LinkStack *)malloc(sizeof(LinkStack));
    InitStack(lineStack);

    while (scanf("%c", &currentChar)) {
        if (currentChar == '\n' || currentChar == '$') {
            Push(lineStack, currentChar);
            int columnIndex = 0;
            while (!IsEmptyStack(lineStack)) {
                Pop(lineStack, topElement);
                lines[lineIndex][columnIndex] = topElement;
                columnIndex++;
            }
            lineIndex++;
        } else if (currentChar == '#') {
            Pop(lineStack, topElement);
        } else if (currentChar == '@') {
            ClearStack(lineStack);
        } else {
            Push(lineStack, currentChar);
        }

        if (currentChar == '$') {
            break;
        } else if (currentChar == '\n') {
            continue;
        }
    }
}

void InitializeLines(SeqList *lines[MAX_LINE_COUNT]) {
    for (int i = 0; i < MAX_LINE_COUNT; i++) {
        lines[i] = CreatList();
        for (int j = 0; j < MAX_COLUMN_COUNT; j++) {
            lines[i]->data[j] = '\0';
        }
    }
}

// 总体思路：
// 一个个字符读取，若不是 @, # 以及行结束符（\n 与 $），则放入栈。若
// #，弹出一个元素；若 @，清空栈。若是行结束符，则将栈中所有元素依次弹出并放入
// lines 二维数组的某行，然后处理下一行（lineIndex++）
// 所有字符读取完后，遍历二维数组中每一行，然后找到最后一个有意义的字符，并倒序输出

int main() {
    // 每个 line 是一个链表
    SeqList *lines[MAX_LINE_COUNT];

    InitializeLines(lines);
    InputLines(lines);
    ShowLines(lines);
    getchar();
    getchar();
}