#include <stdio.h>
#include <stdlib.h>

int calcular_serie() {
    int serie = 0, n=5;
    int num=1, deno=n;
    for (int i = 1; i <= n; i++) {
        serie= serie +(num/deno);  
        num++;
        deno--;
        serie= serie -(num/deno);
        num++;
        deno--;
    }
    return serie;
}

int main() {
    int n_termos, resultado;
    printf("Digite a quantidade de termos da serie: ");
    scanf("%d", &n_termos);

    resultado = calcular_serie();
    printf("Resultado da serie: %d\n", resultado);

    
}
