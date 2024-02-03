#include <fcntl.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
//Заполнение шапки
/*if ((y == 27) && (i == 1))
    printf("For exit press:  ");
if ((y == 27) && (i == 27))
    printf("Player_1: %d", sc1);
if ((y == 27) && (i == 36))
  printf("Player_2: %d", sc2);*/

int movePadle(char temp, int y);
void DrawCongrats(char win);
void drawer(int RL, int RR, int BX, int BY, int ScoreR, int ScoreL);

int main() {
    char win = 'n', command;
    int time = 0, BX = 40, BY = 12, BVX = 1, BVY = 1, Score1 = 0, Score2 = 0, PadleLeft = 12, PadleRight = 12;
    drawer(PadleLeft, PadleRight, BX, BY, Score2, Score1);
    fcntl(0, F_GETFL);
    struct termios raw;
    tcgetattr(0, &raw);
    raw.c_lflag &= ~(ICANON);
    tcsetattr(0, TCSAFLUSH, &raw);
    while (win == 'n') {
        usleep(5000);
        fcntl(0, F_SETFL, O_NONBLOCK);
        command = getchar();
        fcntl(0, F_SETFL, O_APPEND);
        time += 1;
        if ((command == 'a') || (command == 'z')) {
            PadleLeft += movePadle(command, PadleLeft);
        }
        if ((command == 'k') || (command == 'm')) {
            PadleRight += movePadle(command, PadleRight);
        }
        command = ' ';
        if (time == 16) {
            BX += BVX;
            BY += BVY;
            if ((BY == 1) && (BVY == -1)) {
                BVY += 2;
            }
            if ((BY == 25) && (BVY == 1)) {
                BVY -= 2;
            }
            if ((BX == 2) && (BVX == -1) && (PadleLeft - 1 <= BY) && (PadleLeft + 1 >= BY)) {
                BVX += 2;
            }
            if ((BX == 79) && (BVX == 1) && (PadleRight - 1 <= BY) && (PadleRight + 1 >= BY)) {
                BVX -= 2;
            }
            if (BX == 1) {
                BX = 40;
                BY = 12;
                Score2 += 1;
            }
            if (BX == 80) {
                BX = 40;
                BY = 12;
                Score1 += 1;
            }
            drawer(PadleLeft, PadleRight, BX, BY, Score2, Score1);
            if (Score1 == 21) {
                win = '1';
            }
            if (Score2 == 21) {
                win = '2';
            }
            time = 0;
        }
    }
    DrawCongrats(win);
    return 0;
}

int movePadle(char temp, int y) {
    int speed = 0;

    if (((temp == 'a') || (temp == 'k')) && (y > 2)) {
        speed = -1;
    }
    if (((temp == 'z') || (temp == 'm')) && (y < 24)) {
        speed = 1;
    };
    return speed;
}

void DrawCongrats(char win) {
    printf("********************************************************************************\n\n");
    printf("                            Congratulations, Player %c!                         \n\n", win);
    printf("********************************************************************************\n");
}

void drawer(int RL, int RR, int BX, int BY, int ScoreR, int ScoreL) {
    char run = 'y';
    printf("                           Press CTRL+C to exit                                 \n");
    if (ScoreL > 9) {
        printf("                      Player1 %d           Player2 %d                           \n", ScoreL,
               ScoreR);
    } else {
        printf("                      Player1 %d           Player2 %d                           \n", ScoreL,
               ScoreR);
    }
    printf("********************************************************************************\n");
    for (int y = 1; y <= 25; ++y) {
        for (int x = 1; x <= 80; ++x) {
            if ((x == 1) && ((y >= RL - 1) && (y <= RL + 1))) {
                printf("|");
                run = 'n';
            }
            if (((x == 80) && ((y >= RR - 1) && (y <= RR + 1))) && run == 'y') {
                printf("|");
                run = 'n';
            }
            if (((x == BX) && (y == BY)) && run == 'y') {
                printf("o");
                run = 'n';
            }
            if (run == 'y') {
                printf(" ");
            }
            run = 'y';
        }
        printf("\n");
    }
    printf("********************************************************************************\n");
}
