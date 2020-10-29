#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define height 20
#define width 40

char map[height][width], key;
int snake_len=0, block_list[height*width][2], x1=1, y1=0, alive=1;

void draw();
void move();
void spawnFood();
void controls();
void goToXY(int column, int line);
void change(int add_block);

int main() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);

    int x, y;
    for (y = 0; y < height; ++y) {
        for (x = 0; x < width; ++x) {
            if (y == 0 || y == height - 1 || x == 0 || x == width - 1) {
                map[y][x] = '#';
            } else {
                map[y][x] = ' ';
            }
        }
    }

    map[y][x] = 'O';
    block_list[0][0] = height/2;
    block_list[0][1] = width/2;
    
    spawnFood();
    while (alive) {
        Sleep(150);
        controls();
        move();
        draw();
    }
}


void controls() {
    if (_kbhit()) {
        key = _getch();
    }
    if (key == 72) {
        x1 = 0;
        y1 = -1;
    } else if (key == 80) {
        x1 = 0;
        y1 = 1;
    } else if (key == 75) {
        x1 = -1;
        y1 = 0;
    } else if (key == 77) {
        x1 = 1;
        y1 = 0;
    }
}

void spawnFood() {
    int x = rand() % (width - 3) + 1;
    int y = rand() % (height - 3) + 1;
    if (map[y][x] != 'O' && map[y][x] != 'o') {
        map[y][x] = '*';
        return;
    }
}

void draw() {
    int x, y;
    for (y = 0; y < height; y++) {
        goToXY(width/2, y);
        for (x = 0; x < width; x++) {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }
}

void change(int add_block) {
    if (add_block)
        snake_len++;
    else
        map[block_list[snake_len][0]][block_list[snake_len][1]] = ' ';

    for (int i = snake_len; i >= 1; --i) {
        block_list[i][0] = block_list[i-1][0];
        block_list[i][1] = block_list[i-1][1];
    }

    block_list[0][0] += y1;
    block_list[0][1] += x1;
    map[block_list[0][0]][block_list[0][1]] = 'O';
}

void move() {
    int y=block_list[0][0], x=block_list[0][1];
    if (map[y + y1][x + x1] == ' ') {
        change(0);
        return;
    } else if (map[y + y1][x + x1] == '*') {
        map[y + y1][x + x1] = ' ';
        change(0);
        change(1);
        spawnFood();
        return;
    } else if (map[y + y1][x + x1] == '#' || map[y + y1][x + x1] == 'O') {
        alive = 0;
    }
}

void goToXY(int column, int line) {
    COORD coord;
    coord.X = column;
    coord.Y = line;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, coord);
}