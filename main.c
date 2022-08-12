#include "labyrinth.h"

#define X_DIS 2
#define Y_DIS (X_DIS/2)


int main() {
    int x, y, key, game_over;
    lab l;
    game_over = 0;

    system("cls");

    hideCursor();

    l = creteLabyrinth(l);
    printArray(X_DIS, Y_DIS, l);

    while(!game_over) {
        key = 0;

        if(kbhit()) {
            key = getch();
            game_over = (key == ESC);
        }
    }
    return 0;
}