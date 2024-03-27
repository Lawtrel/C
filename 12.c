#include <stdio.h>

void Simu(int[],int[]);
int main()
{
    int LT1[] = {5, 7, 9, 2, 8};
    int Calculo1[] = {3, 2, 6, 4, 5};
    Simu(LT1, Calculo1);
}

void Simu(int LT1[],int Calculo1[]) {
    int i,j;
    printf("Alunos que estao cursando LT1 e Calculo 1 simultaneamente: \n");
    for (i = 0; i < 5 ;i++) {
        for (j = 0; j < 5; j++)
        if (LT1[i] == Calculo1[j]) {
            printf("Matricula: %d\n", LT1[i]);
        }
    }

}