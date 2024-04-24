/*Escreva um programa que calcule os 20 primeiros números primos e armazene em um
arquivo direto. Números primos são aqueles divisíveis somente por um e por ele mesmo.
*/
#include <stdio.h>

int Primo(int num) {
  if (num <= 1) return 0;
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) return 0;
  }
  return 1;
}

int main() {
  FILE *arq;
  int cont = 0;
  int num = 2;

  arq = fopen("db.txt","w");
  if(arq == NULL) {
    printf("Erro ao abrir\n");
    return 1;
  }
  while (cont < 20) {
    if (Primo(num)) {
      fprintf(arq, "%d\n", num);
      cont++;
    }
    num++;
  }
  fclose(arq);
  printf("Os 20 primeiros numeros primos foram calculados e armazenados no arquivo db.txt \n");
  return 0;
}