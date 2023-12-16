#include <curses.h>
#include <stdlib.h>
#include <unistd.h>

void main(void) {
    WINDOW *win = initscr();

    keypad(win, true);
    nodelay(win, true);

    int maxY = getmaxy(win);
    int maxX = getmaxx(win);

    int p1PosX = 1;
    int p1PosY = maxY / 2;

    int p2PosX = maxX -2;
    int p2PosY = maxY / 2;

    int p1DirY = 0;
    int p2DirY = 0;

    int ballPosX = maxX / 2;
    int ballPosY = maxY / 2;
    int ballDirX = 1;
    int ballDirY = 1;

    int p1Score = 0;
    int p2Score = 0;

    while(true) {
        int pressed = wgetch(win);

        if (pressed == 's') {
            p1DirY = 1;
        }
        if (pressed == 'w') {
            p1DirY = -1;
        }

        if (pressed == KEY_DOWN) {
            p2DirY = 1;
        }

        if (pressed == KEY_UP) {
            p2DirY = -1;
        }

        erase();

        p1PosY += p1DirY;
        p2PosY += p2DirY;

        ballPosX += ballDirX;
        ballPosY += ballDirY;

        if (ballPosX <= 0) {
            ballDirX *= -1;
            p2Score++;
        }
        if (ballPosX >= maxX - 1) {
            ballDirX *= -1;
            p1Score++;
        }
        if (ballPosY <= 0 || ballPosY >= maxY - 1) {
            ballDirY *= -1;
        }

        for (int i = 0; i < 4; i++) {
            if ((ballPosX == p1PosX && ballPosY == p1PosY + i) || (ballPosX == p2PosX && ballPosY == p2PosY + i)) {
                ballDirX *= -1;
                break;
            }
        }

        if (p1PosY < 0) p1PosY = 0;
        if (p1PosY > maxY - 4) p1PosY = maxY - 4;
        if (p2PosY < 0) p2PosY = 0;
        if (p2PosY > maxY - 4) p2PosY = maxY - 4;

        for (int i = 0; i < 4; i++) {
            mvaddstr(p1PosY + i, p1PosX, "#");
            mvaddstr(p2PosY + i, p2PosX, "#");
        }

        mvaddstr(ballPosY, ballPosX, "*");

        mvprintw(1, 2, "P1 Score: %d", p1Score);
        mvprintw(1, maxX - 13, "P2 Score: %d", p2Score);

        usleep(100000);
    }

    endwin();
}
