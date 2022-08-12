#include "labyrinth.h"

int main() {
    int key;
    int game_over;

    system("cls");

    while(!game_over) {
        key = 0;

        if(kbhit()) {
            key = getch();
            game_over = (key == ESC);
        }
    }
    return 0;
}