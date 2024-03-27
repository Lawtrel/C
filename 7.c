#include <stdio.h>
#include <string.h>

#define MAX_PESSOAS 10

struct Pessoa {
    char nome[50];
    char sexo;
    float altura;
    float peso;
};

void informacoes_pessoas(struct Pessoa pessoas[], int num_pessoas) {
    float soma_alturas_homens = 0, media_alturas_homens = 0;
    float soma_pesos_mulheres = 0, media_pesos_mulheres = 0;
    float altura_homem_mais_alto = 0, peso_mulher_mais_gorda = 0;
    char nome_homem_mais_alto[50] = "";
    char nome_mulher_mais_gorda[50] = "";
    int count_homens = 0, count_mulheres = 0;

    for (int i = 0; i < num_pessoas; i++) {
        if (pessoas[i].sexo == 'M' || pessoas[i].sexo == 'm') {
            soma_alturas_homens += pessoas[i].altura;
            count_homens++;
            if (pessoas[i].altura > altura_homem_mais_alto) {
                altura_homem_mais_alto = pessoas[i].altura;
                strcpy(nome_homem_mais_alto, pessoas[i].nome);
            }
        } else if (pessoas[i].sexo == 'F' || pessoas[i].sexo == 'f') {
            soma_pesos_mulheres += pessoas[i].peso;
            count_mulheres++;
            if (pessoas[i].peso > peso_mulher_mais_gorda) {
                peso_mulher_mais_gorda = pessoas[i].peso;
                strcpy(nome_mulher_mais_gorda, pessoas[i].nome);
            }
        }
    }

    if (count_homens > 0) {
        media_alturas_homens = soma_alturas_homens / count_homens;
    }

    if (count_mulheres > 0) {
        media_pesos_mulheres = soma_pesos_mulheres / count_mulheres;
    }

    printf("Média das alturas dos homens: %.2f\n", media_alturas_homens);
    printf("Média dos pesos das mulheres: %.2f\n", media_pesos_mulheres);
    printf("Homem mais alto: %s\n", nome_homem_mais_alto);
    printf("Mulher mais gorda: %s\n", nome_mulher_mais_gorda);
}

int main() {
    struct Pessoa pessoas[MAX_PESSOAS];

    printf("Digite os dados das pessoas:\n");

    for (int i = 0; i < MAX_PESSOAS; i++) {
        printf("Pessoa %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", pessoas[i].nome);
        printf("Sexo (M/F): ");
        scanf(" %c", &pessoas[i].sexo);
        printf("Altura (m): ");
        scanf("%f", &pessoas[i].altura);
        printf("Peso (kg): ");
        scanf("%f", &pessoas[i].peso);
    }

    informacoes_pessoas(pessoas, MAX_PESSOAS);

    return 0;
}
