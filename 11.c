#include <stdio.h>
void leia()
{
    int max = 5;
    int vet1[max];
    int vet2[max];
    int vet3[max];

    for (int i = 0; i < max; i++)
    {
        printf("Digite os valores do vetor 1 %d: ",i+1);
        scanf("%d",&vet1[i]);
    }

    for( int i = 0; i < max; i++)
    {
        printf("Digite os valores do vetor 2 %d: ",i+1);
        scanf("%d",&vet2[i]);
    }

    for (int i = 0; i < max; i++)
    {
        vet3[i*2] = vet1[i];
        vet3[i*2+1] = vet2[i];
    }

    printf("o vetor com elementos intercalados e: ");
    for ( int i = 0; i < max * 2; i++)
    {
        printf("%d ",vet3[i]);
    }

}


int main()
{
    leia();
    return 0;
}