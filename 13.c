#include <stdio.h>
#define MAX 10;

int main()
{
    int matriz[MAX][MAX];
    int n,i,j,soma = 0;

    printf("Digite a ordem da matriz(%d)",MAX);
    scanf("%d",&n);

    printf("Digite os elementos da matriz %dx%d\n",n,n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Matriz[%d][%d]:",i,j);
            scanf("%d",&matriz[i][j]);
        }
    }


}