#include <stdio.h>

void fibonacci(int n) {
    int a = 0, b = 1, proximo;
    printf("Sequência de Fibonacci até o %dº elemento:\n", n);

    for (int i = 1; i <= n; i++) {
        printf("%d, ", a);
        proximo = a + b;
        a = b;
        b = proximo;
    }
    printf("\n");
}

int main() {
    fibonacci(20);
    return 0;
}