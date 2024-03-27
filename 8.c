#include <stdio.h>
#include <stdlib.h>

void leitura(int*);
void testa(int,int*,int);
void mostra(int);

int posicao=0;

main()
{
    int maior, numero, i=0;
    do {
        leitura(&numero);
        testa(numero, &maior,i);
        i++;
    } while (numero != 0);
    mostra(maior);
}

void leitura(int *n)
{
    printf("\n Entre com numeros: ");
    scanf("%d",n);
}

void testa(int n, int *m, int i)
{
    if (n > *m)
    {
        *m = n;
        posicao = i;
    }
}

void mostra(int m)
{
    printf("\n o maior valor %d esta na pos %d",m,posicao);
    getchar();
    getchar();
}