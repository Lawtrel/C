/*Escreva um programa que calcule os 7 primeiros números perfeitos e armazene em um
arquivo direto. Considere números perfeitos, os números que a soma de seus divisores de
o próprio número.
Exemplo: 6 é perfeito porque 1 + 2 + 3 = 6.
*/
#include <stdio.h>

int nPerfeito(int num) {
  int soma = 0;
  for (int i = 1; i < num; i++) {
    if (num % i == 0) {
      soma += i;
    }
  }
  return soma == num;
}
int main() {
  FILE *arq;
  int cont = 0;
  int num = 2;

  arq = fopen("numeros.txt","w");
  if (arq == NULL) {
    printf("Error ao Abrir!\n");
    return 1;
  }
  while (cont < 7) {
    if (nPerfeito(num)) {
      fprintf(arq, "%d\n", num);
      cont++;
    }
    num++;
  }
  fclose(arq);
  printf("Os 7 primeiros numeros perfeitos foram armazenados!");
  return 0;

}