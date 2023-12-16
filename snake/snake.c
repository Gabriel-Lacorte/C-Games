#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

typedef struct Position {
    int x;
    int y;
    struct Position* next;
} Position;

void main(void) {
    srand(time(NULL));

    WINDOW *win = initscr();
    keypad(win, true);
    nodelay(win, true);

    int maxX = getmaxx(win);
    int maxY = getmaxy(win);

    Position* snake = malloc(sizeof(Position));
    snake->x = maxX / 2;
    snake->y = maxY / 2;
    snake->next = NULL;

    int foodX = rand() % maxX;
    int foodY = rand() % maxY;

    int dirX = 1;
    int dirY = 0;

    bool isDead = false;
    int score = 0;

    while(!isDead) {
        int pressed = wgetch(win);

        if (pressed == KEY_LEFT) {
            dirX = -1;
            dirY = 0;
        }

        if (pressed == KEY_RIGHT) {
            dirX = 1;
            dirY = 0;
        }
        if (pressed == KEY_UP) {
            dirX = 0;
            dirY = -1;
        }
        if (pressed == KEY_DOWN) {
            dirX = 0;
            dirY = 1;
        }

        erase();

        Position* newHead = malloc(sizeof(Position));
        newHead->x = snake->x + dirX;
        newHead->y = snake->y + dirY;
        newHead->next = snake;
        snake = newHead;

        if (snake->x == foodX && snake->y == foodY) {
            foodX = rand() % maxX;
            foodY = rand() % maxY;
            score++;
        } else {
            Position* temp = snake;
            while(temp->next->next != NULL) {
                temp = temp->next;
            }
            free(temp->next);
            temp->next = NULL;
        }

        if (snake->x < 0 || snake->y < 0 || snake->x >= maxX || snake->y >= maxY) {
            isDead = true;
            break;
        }

        Position* temp = snake;
        while(temp != NULL) {
            mvaddstr(temp->y, temp->x, "*");
            temp = temp->next;
        }

        mvaddstr(foodY, foodX, "@");

        mvprintw(0, 0, "Score: %d", score);

        usleep(100000);
    }

    endwin();

    printf("\nYou've died!\n\n");
}
