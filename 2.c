/*Desenvolva uma rotina que receba duas listas circulares (listaA e listaB) como parâmetros. A seguir 
desenvolva a lógica para colocar os elementos da listaA e da listaB em ordem crescente em uma pilha 
criada localmente. Escreva no final os elementos da pilha. 
Obs: Considere que a listaA e a listaB já estão ordenadas e possuem o mesmo tamanho. Para trabalhar 
com a estrutura de pilha deve ser usado o critério. Podem ser usadas as funções descritas nos slides sem 
reescrevê-las.*/

 #include <stdio.h>
 #include <stdlib.h>
 typedef struct node {
    int num;
    struct node *prox;
 }T_node;
 
 typedef struct{
    T_node *topo;
 }T_pilha;

 typedef struct{
    T_node *inicio;
    T_node *fim;
 }T_lista;
 
T_node *obt_endereco();
void insere(int, T_lista *);


//maldita pilha
void ini_pilha(T_pilha *);
void empilhar(T_pilha *, int);
void mostrar_pilha(T_pilha *);
void ini_lista(T_lista *);
void mescla(T_lista *, T_lista *, T_pilha *);

main() {
    int op;
    int valor;
    T_lista listaA, listaB;
    T_pilha pilha;
    ini_pilha(&pilha);
    ini_lista(&listaA);
    ini_lista(&listaB);


    do {
        printf("\n 1 - Incluir");
        printf("\n 2 - Incluir 2");
        printf("\n 3 - Mostrar");
        printf("\n 4 - Mescla");
        printf("\n 0 - Sair \n");
        scanf("%d",&op);

        switch (op)
        {
        case 1:
            printf("\nDigite o Numeros: ");
            scanf("%d",&valor);
            insere(valor,&listaA);
            break;
        case 2:
            printf("\nDigite o Numero: ");
            scanf("%d",&valor);
            insere(valor,&listaB);
            break;
        case(3):
            mostrar_pilha(&pilha);
            break;
        case 4:
                mescla(&listaA, &listaB, &pilha);
                printf("\nElementos da Pilha em Ordem Crescente:\n");
                mostrar_pilha(&pilha);
            break;
        }
    }while(op!= 0);
    return 0;
}
void ini_lista(T_lista *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
}

T_node *obt_endereco() {
    T_node *novo = (T_node *) malloc(sizeof(T_node));
    if (novo == NULL) {
        printf("Sem memoria");
        exit(1);
    }
    return(novo);
}

void insere(int valor, T_lista *lista) {
    T_node *novo=obt_endereco();
    novo->num=valor;
    if (lista->inicio == NULL) {
        lista->inicio = novo;
        lista->fim = novo;
        novo->prox = lista->inicio; // circular ai mano
    } else {
        lista->fim->prox = novo;
        lista->fim = novo;
        novo->prox = lista->inicio; // vai circulando de novo ai
    }
}

void ini_pilha(T_pilha *pilha) {
    pilha->topo = NULL;
}
//empilha essa porra ai
void empilhar(T_pilha *pilha, int valor) {
    T_node *novo = obt_endereco();
    novo->num = valor;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

void mostrar_pilha(T_pilha *pilha) {
    T_node *temp = pilha->topo;
    if (temp == NULL) {
        printf("Vazio");
    } else {
        printf("Elementos da pilha: \n");
        while (temp != NULL){
            printf("%d\n", temp->num);
            temp = temp->prox;
        }
    }
}
void mescla(T_lista *listA, T_lista *listaB, T_pilha *pilha) {
    T_node *a = listA->inicio;
    T_node *b = listaB->inicio;
    if (a == NULL || b == NULL)
    {
        printf("Listas Vazias!");
        return;
    }
    
    do {
        if (a->num <= b->num) {
            empilhar(pilha, a->num);
            a = a->prox;
        } else {
            empilhar(pilha, b->num);
            b = b->prox;
        }
    } while (a != listA->inicio && b != listaB->inicio); // corre menor pela listas
    //insere qualquer merda na listas
    while (a != listA->inicio) {
        empilhar(pilha, a-> num);
        a = a->prox;
    }
    while (b != listaB->inicio)
    {
        empilhar(pilha, b->num);
        b = b->prox;
    }
}

