#include <stdio.h>

void novo_valor_produto(char nome[50], float preco) {
    float novo_preco = preco * 1.20;
    printf("O novo valor do produto %s é: R$%.2f\n", nome, novo_preco);
}

int main() {
    char nome_produto[50];
    float preco_produto;

    printf("Digite o nome do produto: ");
    scanf("%s", nome_produto);
    printf("Digite o preço antigo do produto: R$");
    scanf("%f", &preco_produto);

    novo_valor_produto(nome_produto, preco_produto);

    return 0;
}
