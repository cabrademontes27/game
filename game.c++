#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

void gotoxy(int x, int y);
void ocultarCursor();
void pintar_limites();

using namespace std;

class NAVE{
    int x, y;
    int corazones;
    int vida;

    public:
        NAVE(int _x, int _y, int _corazones,int _vida);
        void marcar();
        void borrar();
        void mover();
        void barraDeSalud();
        void morir();
};

NAVE::NAVE(int _x, int _y, int _corazones,int _vida){
    vida = _vida;
    corazones = _corazones;
    x = _x;
    y = _y;
};

void NAVE::marcar(){
    // estamos llamando a la func gotoxy sobre la ubicacion 
    // y el print imprime a un caracter que tenga asignado el num 30 
    // segun la tabla ASCII
   gotoxy(x+1,y);    printf("%c",30);
   gotoxy(x,y+1);  printf("%c%c%c",30,30,30);
   gotoxy(x+1,y+2);  printf("%c",30);
};

void NAVE::borrar(){

    gotoxy(x,y);  printf("        ");
    gotoxy(x,y+1);printf("        ");
    gotoxy(x,y+2);printf("        ");
};

void NAVE::mover(){

    bool game_over = false;
    while(!game_over){
        
        morir();
        if(kbhit()){
                // se agrega esta parte para borrar la marca de los asteristcos
                char tecla = getch();
                borrar();
                // la conddicion de x>3 es para delimitar el limite 
                if(tecla == 'a' && (x > 3)){
                    x--;
                }
                if(tecla == 'd' && (x < 121)){
                    x++;
                }
                if(tecla == 'w' && (y > 3)){
                    y--;
                }
                if(tecla == 's' && (y < 34)){
                    y++;
                }
                if(tecla == 'q'){
                    game_over = true;
                }
                if(tecla == 'p'){
                    corazones--;
                    barraDeSalud();
                }
                

                marcar();
            };
        Sleep(30);
    }; 
};

// indicador de vidas 
void NAVE::barraDeSalud(){

    gotoxy(10,0); printf("VIDAS: %d", vida);
    gotoxy(100,0); printf("salud");
    gotoxy(110,0); printf("      ");
    for(int i = 1; i <= corazones; i++){ 
        gotoxy(110 + i,0);
        printf("%c",3);
    }
}

void NAVE::morir(){

    if(corazones == 0){
        borrar();
        gotoxy(x+1,y);   printf("**");
        gotoxy(x,y+1);   printf("****");
        gotoxy(x+1,y+2); printf("**");
        Sleep(300);

        borrar();
        gotoxy(x,y);   printf("* ** *");
        gotoxy(x,y+1); printf(" *  * ");
        gotoxy(x,y+2); printf("* ** *");
        Sleep(300);
        borrar();

        if(vida > 0){
            vida--;
        }
        corazones = 3;
        barraDeSalud();
        marcar();
        
        
    }


}



//nueva clase asteroide 
class ASTEROIDE{
private:
    int x,y;

public:
    ASTEROIDE(int _x, int _y);
    void pintar();
    void mover();




};

ASTEROIDE::ASTEROIDE(int _x, int _y){

    x = _x;
    y = _y;


}

void ASTEROIDE::pintar(){

    gotoxy(x,y); printf("%c",220);

}

void ASTEROIDE::mover(){


    bool apagador = false;
    while(!apagador){
        gotoxy(x,y); printf(" ");
        y++;

        gotoxy(x,y); printf(" ");
        if(y >= 37){
            y = 2;
            x = rand() % 126 + 2;
        }
        pintar();
        Sleep(200);

    }

}









int main(){
    
    ocultarCursor();
    pintar_limites();

    NAVE N(7,7,3,3);
    ASTEROIDE AST(10,2);
    N.marcar();
    N.barraDeSalud();


    AST.mover();
    N.mover();

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

// se agrego para pintar las paredes o limitantes 
void pintar_limites(){

    // pinta x o sea horizontal
    for(int i = 2; i < 127;i++){
        gotoxy(i,1);
        printf("%c",205);
        gotoxy(i,38);
        printf("%c",205);
        
        gotoxy(1,1);
        printf("%c",201);
        gotoxy(127,1);
        printf("%c",187);
    }
    // pinta la y o sea vertical
    for(int i = 2; i < 38; i++){
        gotoxy(1,i);
        printf("%c",186);
        gotoxy(127,i);
        printf("%c",186);

        gotoxy(1,38);
        printf("%c",200);
        gotoxy(127,38);
        printf("%c",188);
    }
}
