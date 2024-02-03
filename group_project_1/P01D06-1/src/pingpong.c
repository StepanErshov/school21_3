#include <curses.h>
#include <unistd.h>

#define WIDTH 80
#define HEIGHT 24
#define BALL_SIZE 2
#define PADDLE_WIDTH 10
#define PADDLE_HEIGHT 3
#define BALL_SPEED 1

int main() {
    initscr();
    noecho();
    curs_set(FALSE);
    nodelay(stdscr, TRUE); // Make getch() non-blocking

    int ballX = WIDTH / 2;
    int ballY = HEIGHT / 2;
    int ballDX = BALL_SPEED;
    int ballDY = BALL_SPEED;

    int paddle1Y = HEIGHT / 2;
    int paddle2Y = HEIGHT / 2;

    while (1) {
        clear();

        // Draw ball
        mvaddch(ballY, ballX, 'O');

        // Draw paddles
        for (int i = 0; i < PADDLE_HEIGHT; ++i) {
            mvaddch(paddle1Y + i, 0, '#');
            mvaddch(paddle2Y + i, WIDTH - 1, '#');
        }

        // Move ball
        ballX += ballDX;
        ballY += ballDY;

        // Check collision with top/bottom edge
        if (ballY <= 0 || ballY + BALL_SIZE >= HEIGHT) {
            ballDY = -ballDY;
        }

        // Check collision with left paddle
        if (ballX <= PADDLE_WIDTH && ballY >= paddle1Y && ballY <= paddle1Y + PADDLE_HEIGHT) {
            ballDX = -ballDX;
        }

        // Check collision with right paddle
        if (ballX + BALL_SIZE >= WIDTH - PADDLE_WIDTH && ballY >= paddle2Y && ballY <= paddle2Y + PADDLE_HEIGHT) {
            ballDX = -ballDX;
        }

        // Handle user input
        int ch = getch();
        if (ch != ERR) {
            if (ch == 'w') paddle1Y--;
            else if (ch == 's') paddle1Y++;
            if (ch == 'i') paddle2Y--;
            else if (ch == 'k') paddle2Y++;
        }

        refresh();
        usleep(100000);
    }

    endwin();
    return 0;
}