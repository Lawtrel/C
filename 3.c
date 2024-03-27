#include <stdio.h>

float operacoes(float a, float b, char operador) {
    switch (operador) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b != 0) {
                return a / b;
            } else {
                printf("Erro: divisão por zero!\n");
                return 0;
            }
        default:
            printf("Operador inválido!\n");
            return 0;
    }
}

int main() {
    float numero1, numero2, resultado;
    char operador;

    printf("Digite o primeiro número: ");
    scanf("%f", &numero1);
    printf("Digite o segundo número: ");
    scanf("%f", &numero2);
    printf("Digite a operação (+, -, *, /): ");
    scanf(" %c", &operador);

    resultado = operacoes(numero1, numero2, operador);

    printf("Resultado da operação: %.2f\n", resultado);

    return 0;
}
