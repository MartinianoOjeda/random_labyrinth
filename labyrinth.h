#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

#define ESC 27
#define RANDOM_NUM_RANGE 11
#define X_SIZE 50
#define Y_SIZE 20

//PARTS
#define VERT_LINE_INTER_MID_LEFT 185
#define VERT_LINE_INTER_MID_RIGHT 204
#define VERT_LINE 186
#define HORI_LINE 205
#define RIGHT_UPPER_CORNER 187
#define RIGHT_LOWER_CORNER 188
#define LEFT_LOWER_CORNER 200
#define LEFT_UPPER_CORNER 201
#define HORI_LINE_INTER_MID_UP 202
#define HORI_LINE_INTER_MID_DOWN 203
#define CROSSING 206

#define EMPTY 32
#define COLOR 34

#define LEFT_UC_X 0 
#define LEFT_UC_Y 0
#define LEFT_LC_X 0
#define LEFT_LC_Y Y_SIZE - 1
#define RIGHT_UC_X X_SIZE - 1
#define RIGHT_UC_Y 0
#define RIGHT_LC_X X_SIZE - 1
#define RIGHT_LC_Y Y_SIZE - 1

typedef int labyrinth[X_SIZE][Y_SIZE];

typedef struct laby{
    labyrinth matix_lab;
}lab;

//PROTOTIPADO
void hideCursor();
void gotoxy(int, int);
void gotoXY(int, int);
void print(int, int, int, int, char);
lab createBorder(lab);    
    lab initializeArray(lab);
    lab edges(lab);
    lab corners(lab);
int selectPart();
lab creteLabyrinth(lab);
void printArray(int, int, lab);


void hideCursor() {
    HANDLE hc;
    CONSOLE_CURSOR_INFO cci;
    hc = GetStdHandle(STD_OUTPUT_HANDLE);
    cci.dwSize = 100;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hc, &cci); 
}

void gotoXY(int x, int y) {
    printf("%c[%d;%dH", ESC, y, x);
}

void printXY(int x, int y, int color, int tone, int c) {
    printf("%c[%d;%dm", ESC, tone, color); // color rojo (32) al caracter impreso
    gotoXY(x, y);
    printf("%c", c);
    printf("%c[0m", ESC); //reestablece el color por defecto de la consola
}

int randomNumber() {    
    int n = 0;
    srand(time(NULL));
    //srand((unsigned) time(&t));
    n =  rand() % RANDOM_NUM_RANGE;
    return n + 1;
}

lab initializeArray(lab l) {
    int i, j;
    for(i = 0; i < X_SIZE; i++) {
        for(j = 0; j < Y_SIZE; j++) {
            l.matix_lab[i][j] == EMPTY;
        }
    }

    return l;
}

lab edges(lab l) {
    int i, j;
    for(i = 0; i < X_SIZE; i++) {
        for(j = 0; j < Y_SIZE; j++) {
            if((j == 0 || j == Y_SIZE - 1) && (i > 0 && i < X_SIZE - 1)) {
                l.matix_lab[i][j] = HORI_LINE;
            }
            else {
                if ((i == 0 || i == X_SIZE - 1) && (j > 0 && j < Y_SIZE - 1)) {
                    l.matix_lab[i][j] = VERT_LINE;
                    if(j == (Y_SIZE/2)) {
                        l.matix_lab[i][j] = EMPTY;
                    }
                }
                else {
                    l.matix_lab[i][j] = EMPTY;
                }
            }
        }
    }

    return l;
}

lab corners(lab l) {
    l.matix_lab[LEFT_UC_X][LEFT_UC_Y] = LEFT_UPPER_CORNER;
    l.matix_lab[LEFT_LC_X][LEFT_LC_Y] = LEFT_LOWER_CORNER;
    l.matix_lab[RIGHT_UC_X][RIGHT_UC_Y] = RIGHT_UPPER_CORNER;
    l.matix_lab[RIGHT_LC_X][RIGHT_LC_Y] = RIGHT_LOWER_CORNER;
    return l;
}

lab createBorders(lab l) {
    l = initializeArray(l);
    l = edges(l);
    l = corners(l);
    return l;
}

int selectPart() {
    int n = 0;
    Sleep(1);
    n = randomNumber();
    switch(n) {
        case 1: n = VERT_LINE_INTER_MID_LEFT;
        break;
        case 2: n = VERT_LINE_INTER_MID_RIGHT;
        break;
        case 3: n = VERT_LINE;
        break;
        case 4: n = HORI_LINE;
        break;
        case 5: n = RIGHT_UPPER_CORNER;
        break;
        case 6: n = RIGHT_LOWER_CORNER;
        break;
        case 7: n = LEFT_LOWER_CORNER;
        break;
        case 8: n = LEFT_UPPER_CORNER;
        break;
        case 9: n = HORI_LINE_INTER_MID_UP;
        break;
        case 10: n = HORI_LINE_INTER_MID_DOWN;
        break;
        case 11: n = CROSSING;
        break;
    }

    return n;
}

lab creteLabyrinth(lab l) {
    int i, j;

    l = createBorders(l);
    
    for(i = 0; i < X_SIZE; i++) {
        for(j = 0; j < Y_SIZE; j++) {
            if(l.matix_lab[i][j] == EMPTY) {
                l.matix_lab[i][j] = selectPart();
            }
        }
    }

    return l;
}

void printArray(int x, int y, lab l) {
    int i, j;
    for(i = 0; i < X_SIZE; i++) {
        for(j = 0; j < Y_SIZE; j++) {
            if(l.matix_lab[i][j] != EMPTY) {
                printXY(x+i, y+j, COLOR, 1, l.matix_lab[i][j]);
            }
        }
    }
}

