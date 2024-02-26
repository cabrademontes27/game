#include <stdio.h>
#include <windows.h>
#include <conio.h>

void gotoxy(int x, int y);
void ocultarCursor();



int main(){
    
    ocultarCursor();

    bool game_over = false;
    int x = 10;
    int y = 10; 
    int contador = 10;
    gotoxy(x,y);
    printf("*");

    while(!game_over){
        contador++;

          if(kbhit()){
            // se agrega esta parte para borrar la marca de los asteristcos
            char tecla = getch();
            gotoxy(x,y);
            printf(" ");
              switch(tecla){
                
            case 'a':
                x--;
                gotoxy(x,y);
                printf("*");
                break;

            case 'd':
                x++;
                gotoxy(x,y);
                printf("*");
                break;

            case 'w':
                y--;
                gotoxy(x,y);
                printf("*");
                break;

            case 's':
                y++;
                gotoxy(x,y);
                printf("*");
                break;

            case 'q':
            printf("game over"); game_over = true;
            // agregue esta parte para ver cuantas veces itera 
            printf("%d", contador);
            break;

            }
        }
        //esta func detiene el programa por 30 milisegundos lo que hace
        // que itere menos veces
        Sleep(30);
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

void ocultarCursor(){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO aparienciaCursor;
    aparienciaCursor.dwSize = 50;
    // ocultas el curso con esta struc
    aparienciaCursor.bVisible = FALSE; 
    // curioso, aqui nos pide que pasemos como referencia 
    // la func si no, no jala y por eso el &
    // lo pasa como referencia 
    SetConsoleCursorInfo(hCon,&aparienciaCursor);




}