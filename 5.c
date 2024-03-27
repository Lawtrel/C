#include <stdio.h>
#include <locale.h>

void fibonacci(int n) {
    int a = 0, b = 1, proximo;
    printf("Sequencia de Fibonacci ate o %d elemento:\n", n);

    for (int i = 1; i <= n; i++) {
        printf("%d, ", b);
        proximo = a + b;
        a = b;
        b = proximo;
    }
    printf("\n");
}

int main() {
    setlocale(LC_ALL,"");
    fibonacci(20);
    return 0;
}