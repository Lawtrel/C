/*Escreva uma função que receba como parâmetro uma fila dinâmica e possa identificar quais números
contidos na fila satisfazem a propriedade descrita abaixo e possa colocar esses números em uma pilha
estática. No final mostre a pilha estática usando o critério de pilha.*/

 #include <stdio.h>
 #include <stdlib.h>
 typedef struct node {
    int num;
    struct node *prox;
 }T_node;
 
 typedef struct cab_fila {
    struct node *inicio;
    struct node *fim;
 }T_fila;

 typedef struct{
    int dados[100];
    int topo;
 }T_pilha;

T_fila *ini_fila();
T_node *obt_endereco();
void insere(int, T_fila *);
int retira(T_fila *);
void mostra(T_fila *);

//maldita pilha
void ini_pilha(T_pilha *pilha);
void empilhar(T_pilha *pilha, int valor);
void mostrar_pilha(T_pilha *pilha);
int verificar(int num);
void processa_fila(T_fila *fila, T_pilha *pilha);

main() {
    int op;
    int valor;
    T_fila *fila=ini_fila();
    T_pilha pilha;
    ini_pilha(&pilha);

    do {
        printf("\n 1 - Incluir");
        printf("\n 2 - Excluir");
        printf("\n 3 - Mostrar");
        printf("\n 0 - Sair \n");

        scanf("%d",&op);

        switch (op)
        {
        case(1):
            printf("\n Digite os Numeros: ");
            scanf("%d",&valor);
            insere(valor,fila);
            break;
        case(2):
            retira(fila);
            break;
        case(3):
            mostra(fila);
            break;
        case 4:
            processa_fila(fila,&pilha);
            printf("\n numeros que satisfazem a propriedade: \n");
            mostrar_pilha(&pilha);
            break;
        }

    }while(op!= 0);

}
    T_fila * ini_fila() {
        T_fila *fila = (T_fila *) malloc(sizeof(struct cab_fila));
        if (fila == NULL) {
            printf("Sem memoria!\n");
            exit(1);
        }else {
            fila->inicio = NULL;
            fila->fim=NULL;
            return fila;
        }
    }

T_node *obt_endereco() {
    T_node *novo;
    novo=(T_node *) malloc(sizeof(struct node));
    if (novo == NULL) {
        printf("Sem memoria");
        exit(1);
    }
    return(novo);
}

void insere(int valor, T_fila *fila) {
    T_node *novo=obt_endereco();
    novo->prox=NULL;
    novo->num=valor;
    if (fila->inicio == NULL) {
        fila->inicio = novo;
        fila->fim=novo;
    } else {
        fila->fim->prox=novo;
        fila->fim=novo;
    }

}

int retira(T_fila *fila) {
    T_node *aux;
    int valor = -1;
    if (fila->inicio == NULL) {
        printf("\n Fila vazia");
    } else {
        aux = fila->inicio;
        valor = aux->num;
        fila->inicio=aux->prox;
        free(aux);
    }
    return valor;
}

void mostra(T_fila *fila) {
    T_node *aux = fila->inicio;
    printf("Dados existente: ");
    while (aux != NULL) {
        printf("\n %d",aux->num);
        aux = aux->prox;
    }
}

void ini_pilha(T_pilha *pilha) {
    pilha->topo = -1;
}
void empilhar(T_pilha *pilha, int valor) {
    if (pilha->topo < 99) {
        pilha->dados[++pilha->topo] = valor;
    } else {
        printf("Pilha encheu menor! N da para empilhar mais");
    }
}

void mostrar_pilha(T_pilha *pilha) {
    for (int i= pilha->topo; i >= 0; i--) {
        printf("%d\n",pilha->dados[i]);
    }
}

int verificar(int num) {
    int n1 = num / 100;
    int n2 = num % 100;
    int som = n1 + n2;
    return (som * som == num);
}

void processa_fila(T_fila *fila, T_pilha *pilha) {
    while (fila->inicio != NULL) {
    int num = retira(fila);
    if (verificar(num)) {
        empilhar(pilha,num);
    }
}    
}

