#include <stdio.h>
#include <windows.h>
#include <conio.h>

void gotoxy(int x, int y);
void ocultarCursor();

class NAVE{
    int x, y;

    public:
        NAVE(int _x, int _y);
        void marcar();
        void borrar();
        void mover();
};

NAVE::NAVE(int _x, int _y){

    x = _x;
    y = _y;
};

void NAVE::marcar(){
    // estamos llamando a la func gotoxy sobre la ubicacion 
    // y el print imprime a un caracter que tenga asignado el num 30 
    // segun la tabla ASCII
   gotoxy(x,y);    printf("  %c  ",30);
   gotoxy(x,y+1);  printf(" %c%c%c",30,30,30);
   gotoxy(x,y+2);  printf("  %c  ",30);
};

void NAVE::borrar(){

    gotoxy(x,y);  printf("      ");
    gotoxy(x,y+1);printf("      ");
    gotoxy(x,y+2);printf("      ");
};

void NAVE::mover(){

    if(kbhit()){
            // se agrega esta parte para borrar la marca de los asteristcos
            char tecla = getch();
            borrar();
              switch(tecla){
                
            case 'a':
                x--;
                break;

            case 'd':
                x++;
                break;

            case 'w':
                y--;
                break;

            case 's':
                y++;
                break;
            case 'q':
                // falta agregar la funcion para terminar, si no no puedes salir 
                // falta corregir el cursor ya que no desaparece 
                // falta mejorar el bucle y los metodos 
                break;

            };
            marcar();
        };
};




int main(){
    
    //ocultarCursor();

    NAVE N(7,7);
    N.marcar();
    

    bool game_over = false;
    while(!game_over){
        
        N.mover();
          
        //esta func detiene el programa por 30 milisegundos lo que hace que itere menos veces
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
    aparienciaCursor.dwSize = 0;
    // ocultas el curso con esta struc
    aparienciaCursor.bVisible = FALSE; 
    // curioso, aqui nos pide que pasemos como referencia 
    // la func si no, no jala y por eso el &
    // lo pasa como referencia 
    SetConsoleCursorInfo(hCon,&aparienciaCursor);




}