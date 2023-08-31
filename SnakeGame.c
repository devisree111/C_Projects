#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
int i, j, srow, scolumn, frow, fcolumn,r,score=0;
char choice,a[15][15];
void srandomnumber() {
    srand(time(NULL));
    srow = rand() % 13 + 1;
    scolumn = rand() % 13 + 1;
}
void frandomnumber() {
    srand(time(NULL));
    frow = rand() % 12 + 1 ;
    fcolumn = rand() % 12 + 1;
}
void drawboard() {
    for (i = 0; i < 15; i++) {
        for (j = 0; j < 15; j++) {
            if (i == 14 || i == 0 || j == 0 || j == 14)
                a[i][j] = '#';
            else
                a[i][j] = ' ';
        }
    }
}
void snake() {
    for (i = 0; i < 15; i++) {
        for (j = 0; j < 15; j++) {
            if (i == srow && j == scolumn)
                a[i][j] = '0';
        }
    }
}
void food() {
    for (i = 0; i < 15; i++) {
        for (j = 0; j < 15; j++) {
            if (i == frow && j == fcolumn)
                a[i][j] = '*';
        }
    }
}
void display() {
    for (i = 0; i < 15; i++) {
        for (j = 0; j < 15; j++)
            printf("%c", a[i][j]);
        printf("\n");
    }
}
void check(int srow, int scolumn) {
    if (a[srow][scolumn] == a[frow][fcolumn]) {
        score+=1;
        frandomnumber();
        food();
        clrscr();
        display();
        printf("your score is %d\n",score);
    }
}
void movement(int srow, int scolumn) {
    choice = getch();
    switch (choice) {
    case 'u':
            a[srow - 1][scolumn] = '0';
            a[srow][scolumn] = ' ';
            clrscr();
            display();
        if (a[srow-2][scolumn] == '#')
            printf("GAME OVER");
        else {
            check(srow-1,scolumn);
            movement(srow-1,scolumn);
        }
        break;
    case 'd':
            a[srow + 1][scolumn] = '0';
            a[srow][scolumn] = ' ';
            clrscr();
            display();
        if (a[srow+2][scolumn] == '#')
            printf("GAME OVER");
        else {
            check(srow+1,scolumn);
            movement(srow+1,scolumn);
        }
        break;
    case 'r':
            a[srow][scolumn + 1] = '0';
            a[srow][scolumn] = ' ';
            clrscr();
            display();
        if (a[srow][scolumn+2] == '#')
            printf("GAME OVER");
        else {
            check(srow,scolumn+1);
            movement(srow,scolumn+1);
        }
        break ;
    case 'l':
            a[srow][scolumn - 1] = '0';
            a[srow][scolumn] = ' ';
            clrscr();
            display();
        if (a[srow][scolumn-2] == '#')
            printf("GAME OVER");
        else {
            check(srow,scolumn-1);
            movement(srow,scolumn-1);
        }
        break;
    case 'e':
        exit(0);
    default :
        printf("ENTER VALID CHOICE\n");
        movement (srow,scolumn);
    }
}
int main() {
 printf("Enter your choice\n1.u for up\n2.d for down\n3.r for right\n4.l for left\n");
    srandomnumber();
    frandomnumber();
    drawboard();
    snake();
    food();
    display();
    movement(srow, scolumn);
    return 0;
}
