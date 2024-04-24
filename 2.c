/*
Seja PROGRAMADORES um arquivo direto, composto dos campos CPF, NOME, IDADE e
PROFISSÃO. Escreva um programa com uma rotina para recuperar os registros salvos no
disco, outra para inserir registros nesse arquivo e outra que exclua todas as informações
existentes sobre os programadores com idade entre 25 e 50 anos.
*/
#include <stdio.h>
#include<string.h>

struct Programador
{
  float cpf;
  char nome[50];
  int idade;
  char profissao;
};

void registros() {
  FILE *arq;
  struct Programador programador;

  arq = fopen("database.db","rb");

  if (arq == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }
  printf("Registros salvos no banco de dados.\n");
  while (fread(&programador, sizeof(struct Programador),1,arq)) {
    printf("CPF: %f\nNome: %s\nIdade: %d\nProfissao: %s\n\n", programador.cpf, programador.nome, programador.idade, programador.profissao);
  }
  fclose(arq);
}
void inserirRegistros() {
  FILE *arq;
  struct Programador programador;

  arq = fopen("database.db", "ab");
  if (arq == NULL) {

  }
  printf("Informe o CPF: ");
  scanf("%f", programador.cpf);
  fflush(stdin);
  printf("Informe o nome: ");
  scanf("%s", programador.nome);
  printf("Informe a idade: ");
  scanf("%d", programador.idade);
  printf("Informe a Profissao: ");
  scanf("%s", programador.profissao);

  fwrite(&programador, sizeof(struct Programador), 1, arq);
  fclose(arq);
  printf("Registro Inseridos!");
  }

  void excluirRegistro () {
    FILE *arqTemp, *arq;
    struct Programador programador;
    arq = fopen("database.db","wb");
    if (arq == NULL) {
      printf("Error ao abrir o banco de dados!.\n");
      return;
    }
    arqTemp = fopen("tempDB.db","wb");
    if (arqTemp == NULL) {
      printf("Error ao criar o banco de dados temporario!\n ");
      fclose(arq);
      return;
    }
    while (fread(&programador, sizeof(struct Programador), 1, arq)) {
      if(programador.idade < 25 || programador.idade > 50) {
        fwrite(&programador, sizeof(struct Programador),1,arqTemp);
      }
    }
    fclose(arq);
    fclose(arqTemp);
    remove("database.db");
    rename("tempDB.db","database.db");

    printf("Programadores com idade entre 25 a 50 excluidos!");
  }

  int main() {
    int op;

    do
    {
      printf("\nMenu:\n");
      printf("1. Recuperar registros\n");
      printf("2. Inserir registros\n");
      printf("3. Excluir programadores com idade entre 25 e 50\n");
      printf("4. Sair\n");
      scanf("%d",&op);

      switch (op)
      {
      case 1:
        registros();
        break;
      
      case 2:
        inserirRegistros();
        break;
      
      case 3:
        excluirRegistro();
      break;
      case 4:
        break;

      default:
        printf("Opcao invalida.\n");
        break;
      }
    } while (op !=4);
      return 0;
  }
