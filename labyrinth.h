#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

#define ESC 27
#define MAX_RANGE 10

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


//PROTOTIPADO
void hideCursor();
void gotoxy(int, int);
void gotoXY(int, int);
void print(int, int, int, int, char);


void hideCursor() {
    HANDLE hc;
    CONSOLE_CURSOR_INFO cci;
    hc = GetStdHandle(STD_OUTPUT_HANDLE);
    cci.dwSize = 100;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hc, &cci); 
}

void gotoxy(int x, int y) {
    HANDLE hc;
    COORD cordXY;
    cordXY.X = x;
    cordXY.Y = y;

    SetConsoleCursorPosition(hc, cordXY);
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
    n =  rand() % MAX_RANGE;
    
    return n + 1;
}