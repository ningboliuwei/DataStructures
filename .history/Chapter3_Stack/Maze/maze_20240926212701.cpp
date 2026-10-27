#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STACK_SIZE 1000
#define MAX_ROWS 20
#define MAX_COLS 20

// 结构体表示迷宫中的一个位置
typedef struct {
    int row;
    int col;
} Position;

// 栈结构
typedef struct {
    Position data[MAX_STACK_SIZE];
    int top;
} Stack;

// 初始化栈
void InitStack(Stack *s) {
    s->top = -1;
}

// 判断栈是否为空
int IsEmpty(Stack *s) {
    return s->top == -1;
}

// 判断栈是否已满
int IsFull(Stack *s) {
    return s->top >= MAX_STACK_SIZE - 1;
}

// 压栈操作
int Push(Stack *s, Position pos) {
    if (IsFull(s)) {
        printf("Stack is full, cannot push position (%d, %d).\n", pos.row, pos.col);
        return 0; // 压栈失败
    }
    s->data[++(s->top)] = pos;
    return 1; // 压栈成功
}

// 弹栈操作
int Pop(Stack *s, Position *pos) {
    if (IsEmpty(s)) {
        return 0; // 弹栈失败，栈为空
    }
    *pos = s->data[(s->top)--];
    return 1; // 弹栈成功
}

// 读取栈顶元素但不弹出
int ReadTop(Stack *s, Position *pos) {
    if (IsEmpty(s)) {
        return 0; // 读取失败，栈为空
    }
    *pos = s->data[s->top];
    return 1; // 读取成功
}

// 打印迷宫
void PrintMaze(int maze[][MAX_COLS], int rows, int cols, Position start, Position end) {
    printf("Maze:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == start.row && j == start.col) {
                printf("S "); // 起点
            } else if (i == end.row && j == end.col) {
                printf("E "); // 终点
            } else if (maze[i][j] == 1) {
                printf("1 "); // 墙壁
            } else if (maze[i][j] == 2) {
                printf("0 "); // 路径
            } else {
                printf(". "); // 可通行路径
            }
        }
        printf("\n");
    }
    printf("\n");
}

// 打印路径
void PrintPath(int maze[][MAX_COLS], Stack *path, int rows, int cols, Position start, Position end) {
    // 标记路径
    for (int i = 0; i <= path->top; i++) {
        Position pos = path->data[i];
        // 不覆盖起点和终点的标记
        if (!(pos.row == start.row && pos.col == start.col) && !(pos.row == end.row && pos.col == end.col)) {
            maze[pos.row][pos.col] = 2; // 使用2表示路径
        }
    }

    printf("Maze with path:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == start.row && j == start.col) {
                printf("S "); // 起点
            } else if (i == end.row && j == end.col) {
                printf("E "); // 终点
            } else if (maze[i][j] == 1) {
                printf("1 "); // 墙壁
            } else if (maze[i][j] == 2) {
                printf("* "); // 路径
            } else {
                printf(". "); // 可通行路径
            }
        }
        printf("\n");
    }
    printf("\n");
}

// 检查位置是否合法且可通行
int isValid(int maze[][MAX_COLS], int row, int col, int rows, int cols, int visited[][MAX_COLS]) {
    return (row >= 0) && (row < rows) && (col >= 0) && (col < cols) && (maze[row][col] == 0) && (!visited[row][col]);
}

// 深度优先搜索迷宫
int solveMaze(int maze[][MAX_COLS], int rows, int cols, Position start, Position end, Stack *path) {
    // 定义移动方向（上、右、下、左）
    int rowDir[] = {-1, 0, 1, 0};
    int colDir[] = {0, 1, 0, -1};

    // 标记已访问的位置
    int visited[MAX_ROWS][MAX_COLS];
    memset(visited, 0, sizeof(visited));

    // 初始化栈并压入起点
    InitStack(path);
    Push(path, start);
    visited[start.row][start.col] = 1;

    while (!IsEmpty(path)) {
        Position current;
        ReadTop(path, &current);

        // 如果到达终点，返回成功
        if (current.row == end.row && current.col == end.col) {
            return 1;
        }

        // 尝试所有方向
        int found = 0;
        for (int i = 0; i < 4; i++) {
            int newRow = current.row + rowDir[i];
            int newCol = current.col + colDir[i];

            if (isValid(maze, newRow, newCol, rows, cols, visited)) {
                Position next = {newRow, newCol};
                Push(path, next);
                visited[newRow][newCol] = 1;
                found = 1;
                break; // 继续向下探索
            }
        }

        // 如果没有找到新的位置，弹出当前位置
        if (!found) {
            Pop(path, &current);
        }
    }

    // 如果栈为空且未找到终点，返回失败
    return 0;
}

// 迷宫生成：递归回溯算法
void generateMaze(int maze[][MAX_COLS], int rows, int cols, int r, int c, int visited[][MAX_COLS]) {
    // 定义移动方向（上、右、下、左）的顺序随机化
    int directions[4] = {0, 1, 2, 3};
    // 打乱方向数组
    for (int i = 3; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = directions[i];
        directions[i] = directions[j];
        directions[j] = temp;
    }

    // 标记当前单元格为路径
    maze[r][c] = 0;
    visited[r][c] = 1;

    // 遍历所有方向
    for (int i = 0; i < 4; i++) {
        // dr 表示当前单元格向 上 或 下 移动时，行数（Row）的变化量。
        // dc 表示当前单元格向 左 或 右 移动时，列数（Column）的变化量。
        int dr = 0, dc = 0;

        switch (directions[i]) {
            case 0:
                dr = -2;
                dc = 0;
                break; // 上
            case 1:
                dr = 0;
                dc = 2;
                break; // 右
            case 2:
                dr = 2;
                dc = 0;
                break; // 下
            case 3:
                dr = 0;
                dc = -2;
                break; // 左
        }

        int nr = r + dr;
        int nc = c + dc;

        // 检查相邻单元格是否在迷宫范围内且未被访问
        if (nr > 0 && nr < rows - 1 && nc > 0 && nc < cols - 1 && !visited[nr][nc]) {
            // 连接当前单元格和相邻单元格
            maze[r + dr / 2][c + dc / 2] = 0;
            generateMaze(maze, rows, cols, nr, nc, visited);
        }
    }
}

int main() {
    int maze[MAX_ROWS][MAX_COLS];
    int rows, cols;

    // 设置随机种子
    srand(time(NULL));

    // 用户输入迷宫的行数和列数
    printf("Enter number of rows and columns (max %d x %d, must be odd numbers): ", MAX_ROWS, MAX_COLS);
    scanf("%d %d", &rows, &cols);

    // 清除输入缓冲区
    while (getchar() != '\n')
        ;

    // 检查行数和列数是否为奇数且不超过最大值
    if (rows > MAX_ROWS || cols > MAX_COLS || rows <= 0 || cols <= 0 || rows % 2 == 0 || cols % 2 == 0) {
        printf("Invalid maze size. Rows and columns must be odd numbers and within the maximum limit.\n");
        return 1;
    }

    // 初始化迷宫：全部设置为墙壁
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            maze[i][j] = 1;
        }
    }

    // 初始化访问数组
    int visited[MAX_ROWS][MAX_COLS];
    memset(visited, 0, sizeof(visited));

    // 生成迷宫
    // 起点设置为 (1,1) 以确保路径开始
    Position startGen = {1, 1};
    generateMaze(maze, rows, cols, startGen.row, startGen.col, visited);

    // 设置起点和终点
    Position start = {1, 1};
    Position end = {rows - 2, cols - 2};
    maze[start.row][start.col] = 0; // 确保起点为路径
    maze[end.row][end.col] = 0;     // 确保终点为路径

    // 打印生成的迷宫
    PrintMaze(maze, rows, cols, start, end);

    // 求解迷宫
    Stack path;
    int result = solveMaze(maze, rows, cols, start, end, &path);

    if (result) {
        PrintPath(maze, &path, rows, cols, start, end);
    } else {
        printf("No path found from (%d, %d) to (%d, %d).\n", start.row, start.col, end.row, end.col);
    }

    getchar();
    getchar();
    getchar();
    return 0;
}
