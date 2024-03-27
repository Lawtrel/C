#include <stdio.h>

float calcular_serie(int n) {
    float serie = 0.0;
    int numerador, denominador;
    for (int i = 1; i <= n; i++) {
        numerador = i;
        denominador = n - i + 1;
        if (i % 2 == 0) {
            serie -= (float) numerador / denominador;
        } else {
            serie += (float) numerador / denominador;
        }
    }
    return serie;
}

int main() {
    int n_termos;
    printf("Digite a quantidade de termos da série: ");
    scanf("%d", &n_termos);

    float resultado = calcular_serie(n_termos);
    printf("Resultado da série: %.2f\n", resultado);

    return 0;
}
