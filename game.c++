#include <stdio.h>
#include <windows.h>
#include <conio.h>

void gotoxy(int x, int y);

int main(){
    
    gotoxy(4,6); 
    printf("*");
    
    bool game_over = false;
    int x = 10;
    int y = 10; 

    while(!game_over){
        gotoxy(x,y);
        printf("*");

        switch (kbhit()){
            char teclas = getch();
        case teclas == 'A': x--;


         for(){};
        break;
        
        
        default:
            break;
        }


    }

    return 0;
}

void gotoxy(int x, int y){

    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    
    SetConsoleCursorPosition(hCon,dwPos );


}