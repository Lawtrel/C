#include <stdio.h>

float multiplicacao_numeros(float a, float b) {
    return a * b;
}

int main() {
    float num1, num2, resultado;
    char resposta;

    printf("Digite o primeiro número: ");
    scanf("%f", &num1);
    printf("Digite o segundo número: ");
    scanf("%f", &num2);

    resultado = multiplicacao_numeros(num1, num2);

    printf("Deseja saber o resultado da multiplicação (s/n)? ");
    scanf(" %c", &resposta);

    if (resposta == 's' || resposta == 'S') {
        printf("O resultado da multiplicação é: %.2f\n", resultado);
    }

    return 0;
}
