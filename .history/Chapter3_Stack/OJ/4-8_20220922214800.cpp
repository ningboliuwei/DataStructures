//
// Created by 慰 on 2018/10/7.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_COUNT   3
#define MAX_COLUMN_COUNT 20

typedef char DataType;

typedef struct StackNodeStruct {
  DataType data;
  struct StackNodeStruct* next;
} StackNode;

typedef struct {
  StackNode* top;
} LinkStack;

void InitStack(LinkStack* stack) {
  stack->top = NULL;
}

int ReadTop(LinkStack* stack, DataType& topElement) {
  if (stack->top == NULL) {
    return 0;
  }

  topElement = stack->top->data;

  return 1;
}

int Push(LinkStack* stack, DataType x) {
  StackNode* node = (StackNode*)malloc(sizeof(StackNode));
  node->data      = x;
  node->next      = stack->top;
  stack->top      = node;
}

int Pop(LinkStack* stack, DataType& x) {
  // 栈为空
  if (stack->top == NULL) {
    return 0;
  }

  StackNode* node = stack->top;
  x               = node->data;
  stack->top      = node->next;
  free(node);

  return 1;
}

int IsEmptyStack(LinkStack* stack) {
  if (stack->top == NULL) {
    return 1;
  }
  return 0;
}

int ClearStack(LinkStack* stack) {
  DataType topElement;

  while (!IsEmptyStack(stack)) {
    Pop(stack, topElement);
  }
}

int ShowLines(char lines[MAX_LINE_COUNT][MAX_COLUMN_COUNT]) {
  for (int i = 0; i < MAX_LINE_COUNT; i++) {
    for (int j = 0; j < MAX_COLUMN_COUNT; j++) {
      if (lines[i][j] == '$' || lines[i][j] == '\n') {
        for (int k = j - 1; k >= 0; k--) {
          char c = lines[i][k];
          printf("%c", c);
        }
        printf("\n");
      }

      if (lines[i][j] == '$') {
        return 1;
      }
    }
  }

  return 0;
}

void InputLines(char lines[MAX_LINE_COUNT][MAX_COLUMN_COUNT]) {
  int lineIndex = 0;

  DataType currentChar;
  DataType topElement;

  LinkStack* lineStack = (LinkStack*)malloc(sizeof(LinkStack));
  InitStack(lineStack);

  while (scanf("%c", &currentChar)) {
    if (currentChar == '\n' || currentChar == '$') {
      int columnIndex = 0;
      while (!IsEmptyStack(lineStack)) {
        Pop(lineStack, topElement);
        lines[lineIndex][columnIndex] = topElement;
        columnIndex++;
      }
      lines[lineIndex][columnIndex] = currentChar;
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

int main() {
  char lines[MAX_LINE_COUNT][MAX_COLUMN_COUNT];

  for (int i = 0; i < MAX_LINE_COUNT; i++) {
    for (int j = 0; j < MAX_COLUMN_COUNT; j++) {
      lines[i][j] = 'x';
    }
  }

  InputLines(lines);
  ShowLines(lines);
  getchar();
  getchar();
}