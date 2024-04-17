#include <stdio.h>
#include <string.h>

 typedef struct Notas
 {
     int matricula;
     char nome[30];
     float nota1;
     float nota2;
 } t_Notas;

 t_Notas var_arq;
 FILE *arq;
 int op;

 void Arq();
 void menu();
 void incluir();
 void ler();
 //void logs();

  void Arq() {
    arq = fopen("database.db","r+b");
    if (arq == NULL) {
        arq = fopen("database.db","w+b");
        if ( arq == NULL) {
            printf("\n Error 404");
            return;
        }
    }
 }

 void menu() {
    do
    {
        {
            printf("(1)Incluir dados,(2)Ler dados,(3)Logs,(0)Sair: ");
            scanf("%d",&op);
            switch(op) {
                case 1 : incluir();
                        break;
                case 2 : ler();
                        break;
                //case 3 : logs();
                //        break;
                //case 4 : sair();
                //        break;
            }
        }
    } while (op != 0);
    
 }

 int pesquisa(int c) {
    int achou = 0, contRegistros = -1;
    fseek(arq, 0, SEEK_SET);
    while ((feof(arq) == 0) && (achou ==0))
    { 
        fread(&var_arq,sizeof(var_arq), 1, arq);
        contRegistros++;
        if (c == var_arq.matricula) {
            achou = 1;
        }
    }
    if (achou == 1) {
        return contRegistros;
    }
    else {
        return -1;
    }
 }

 void incluir() {
    int matricula;
    char op;
    do
    {
        printf("\n Digite o codigo da matricula: ");
        scanf("%d",&matricula);

        if (pesquisa(matricula) == -1) {
            var_arq.matricula = matricula;
            printf("\n Entre com o nome: ");
            scanf("%s",& var_arq.nome);
            if (fwrite(&var_arq,sizeof(var_arq), 1, arq) != 1) {
                printf("\n Erro de gravacao");
            }
        }
        else {
            printf("\n Matricula ja cadastrada!");
        }
        printf("deseja Continuar?(s/n) : ");
        fflush(stdin);
        scanf("%c",&op);
    } while (op != 'n');
 }

 void ler() {
    fseek(arq, 0, SEEK_SET);
    fread(&var_arq,sizeof(var_arq), 1, arq);
    while (feof(arq)==0)
    {
        if (var_arq.matricula != 0) {
            printf("\n Codigo: %d Nome: %s \n",var_arq.matricula,var_arq.nome);
        }
        fread(&var_arq,sizeof(var_arq), 1, arq);
    }
    
 }

 main() {
    Arq();
    do {
        menu();
    } while (op!= 0);
 
 }