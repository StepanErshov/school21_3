#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define width 80   // ширина
#define height 25  // высота

void clear_field(int board[][width]);  //заполнение чистого поля
void print_field(int board[][width]);  // печать поля изначально
int count_neighbours(int board[][width], int x, int y);  // считаем количество живых соседей для клетки
void next_generation(int board[][width]);  // печать следующего поколения

int main(int argc, char *argv[]) {
    int time;
    (void)argc;
    int board[height][width];
    int speed = atoi(argv[1]);

    clear_field(board);
    switch (speed) {
        case 1:
            time = 500000;
            break;
        case 2:
            time = 1000000;
            break;
        case 3:
            time = 1500000;
            break;
        default:
            printf("Invalid speed selected. Exiting.\n");
            break;
    }
    print_field(board);
    usleep(time);

    while (1) {
        int count_LivingCells = 0;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (board[i][j] == 1) {
                    count_LivingCells++;
                }
            }
        }
        if (count_LivingCells == 0 || count_LivingCells == 1) {
            break;
        }
        printf("\033[26A");
        next_generation(board);
        putchar('\n');
        fflush(stdout);
        usleep(time);
    }
    return 0;
}

void clear_field(int board[][width]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            scanf("%d", &board[i][j]);
        }
    }
}

void print_field(int board[][width]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (board[i][j] == 1) {
                printf("■");
            } else if (board[i][j] == 0) {
                printf("░");
            }
        }
        printf("\n");
    }
}

int count_neighbours(int board[][width], int x, int y) {
    int count = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx != 0 || dy != 0) {
                int new_x = (x + dx + height) % height;
                int new_y = (y + dy + width) % width;
                if (board[new_x][new_y] == 1) {
                    count++;
                }
            }
        }
    }
    return count;
}

void next_generation(int board[][width]) {
    int new_board[height][width];
    for (int x = 0; x < height; x++) {
        for (int y = 0; y < width; y++) {
            int count_2 = count_neighbours(board, x, y);
            if (board[x][y] == 1) {
                new_board[x][y] = (count_2 == 2 || count_2 == 3) ? 1 : 0;
            } else {
                new_board[x][y] = (count_2 == 3) ? 1 : 0;
            }
        }
    }
    for (int x = 0; x < height; x++) {
        for (int y = 0; y < width; y++) {
            board[x][y] = new_board[x][y];
        }
    }
    print_field(board);
}
