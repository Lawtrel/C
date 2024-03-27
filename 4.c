#include <stdio.h>

void numeros_pares_intervalo(int x, int y) {
    if (x > y) {
        int temp = x;
        x = y;
        y = temp;
    }

    printf("Números pares no intervalo [%d, %d]:\n", x, y);
    for (int i = x; i <= y; i++) {
        if (i % 2 == 0) {
            printf("%d\n", i);
        }
    }
}

int main() {
    int inicio, fim;

    printf("Digite o primeiro número do intervalo: ");
    scanf("%d", &inicio);
    printf("Digite o segundo número do intervalo: ");
    scanf("%d", &fim);

    numeros_pares_intervalo(inicio, fim);

    return 0;
}
