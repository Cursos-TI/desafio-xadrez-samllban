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
                letra = (r == 1 ) ? peca : letra;
                if ((lin + col) % 2 == 0)
                {
                    printf("\xB2\xB2%c\xB2\xB2", letra);
                }
                else
                {
                    printf("  %c    ", letra);
                }
            }
            printf("\n");
        }
    }
}

int main()
{
    printarTelaTexto();
    return 0;
}
