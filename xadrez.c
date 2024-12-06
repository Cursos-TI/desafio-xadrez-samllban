#include <stdio.h>
#include <stdlib.h>

char xadrez[8][8] = {
    {'T', 'C', 'B', 'Q', 'K', 'B', 'C', 'T'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'t', 'c', 'b', 'q', 'k', 'b', 'c', 't'}};

int printarTelaTexto()
{
    system("CLS");
    int lin, col, r;

    for (lin = 0; lin < 8; lin++)
    {
        for (r = 0; r < 3; r++)
        {
            for (col = 0; col < 8; col++)
            {
                char peca = xadrez[lin][col];
                char letra = ((lin + col) % 2 == 0) ? '\xB2' : ' ';
                letra = (r == 1 && peca != ' ') ? peca : letra;
                if ((lin + col) % 2 == 0)
                {
                    printf("\xB2\xB2%c\xB2\xB2", letra);
                }
                else
                {
                    printf("  %c  ", letra);
                }
            }
            printf("\n");
        }
    }
}

int moverPeca(int linOri, int colOri, int linDes, int colDes){
        int mover = 0;
        char peca;
        int dV = abs(linDes - linOri);
        int dH = abs(colDes - colOri);

        if((linOri >= 0 && linOri < 8 && colOri >= 0 && colOri < 8) && (linDes >= 0 && linDes < 8 && colDes >= 0 && colDes < 8)) {
            peca = xadrez[linOri][colOri];
            if((peca == 'T' || peca == 't') && (dV == 0 || dH == 0)) {
                mover = 1;
            }
            if((peca == 'B' || peca == 'b') && (dV = dH)) {
                mover = 1;
            }
            if((peca == 'C' || peca == 'c') && ((dV == 1 || dH == 2) || (dV == 2 || dH == 1))) {
                mover = 1;
            }
            if((peca =='Q' || peca =='q') && ((dV == dH) || (dV == 0) || (dH == 0)) ) {
                mover = 1;
            }
            if((peca =='K' || peca =='k') && ((dV >= 0 && dV <= 1) && (dH >= 0 && dH <= 1))) {
                mover = 1;
            }
            if((peca == 'p') && ((linDes - linOri) == 1) && (dH == 0)) {
                mover = 1;
            }
            if((peca == 'p') && ((linDes - linOri) == -1) && (dH == 0)) {
                mover = 1;
            }
            if (mover) {
                xadrez[linDes][linDes] = xadrez[linOri][colOri];
                xadrez[linOri][colOri] = " ";
                return 1;
            } else {
                return 8;
            }
        }else {
            return 0;
        }
    }

int main(){

    int linOri, colOri, linDes, colDes;
    
    while (1){
        printarTelaTexto();
        printf("Informe a lina e coluna de origem : ");
        scanf(" %d %d ", &linOri, &linDes);
        printf("informe a linha e a coluna de destino : ");
        scanf(" %d %d ", &linDes, &colDes );
        int resultado = moverPeca(linOri, colOri, linDes, colDes);

        if ((resultado)!= 1) {
            switch (resultado)
            {
            case 8:
                printf("Movimento invalido!!!");
                break;
            case 0:
                printf("Coordenadas inválidas!!!");
                break;
            case 1: 
                break;
            default:
                break;
            }
            printf("Movimento invalido\n");
        }
    }
    return 0;
}
