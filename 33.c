#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
	int info;
	struct nodo *prox;
}Tfila;

typedef struct cabeca{
	struct nodo *inicio;
	struct nodo *fim;
}Tcabeca;


Tfila *obterend();
Tcabeca *initcabeca();
void incluir(Tcabeca*,Tcabeca*);
void mostrar(Tcabeca *, Tcabeca *);
void mostrarelatorio(Tcabeca* , Tcabeca*);

main(){

	int op;
	Tcabeca *igg = initcabeca();
	Tcabeca *igm = initcabeca();
	
    do {
        printf("1 - Entre com os dados para a Lista de IGM e IGG\n");
        printf("2 - Mostrar\n");
        printf("3 - Apresente um relatorio para cada paciente\n");
        printf("4 - Fim\n\n");
        scanf("%d",&op);
        
        switch(op){
        	case (1):
        		incluir(igm,igg);
        		break;
        	
        	case (2):
        		system("cls");
        		mostrar(igm,igg);
        		break;
        	
        	case(3):
        		system("cls");
        		mostrarelatorio(igm,igg);
        		break;
        	
		}
        
    printf("\n");
    }while (op!=4);
}

Tfila *obterend(){
	Tfila* novo = (Tfila*)malloc(sizeof(struct nodo));
	
	if(novo==NULL){
		printf("\nERRO FILA\n");
	}
	return (novo);
}

Tcabeca *initcabeca(){
	Tcabeca *cab = (Tcabeca*)malloc(sizeof(struct cabeca));
	
	if(cab==NULL){
		printf("\nERRO CABECA\n");	
	}
	cab->inicio=NULL;
	cab->fim=NULL;
	return (cab);
}

void incluir(Tcabeca *IGM, Tcabeca *IGG){

	Tfila *novoigm =obterend();
	Tfila *novoigg =obterend();

	printf("Entre com IGM do paciente :\n");
	scanf("%d",&novoigm->info);
	printf("Agora com IGG do paciente :\n");
	scanf("%d",&novoigg->info);
	
	if((IGM->inicio==NULL)&&(IGG->inicio==NULL)){
		
		IGM->inicio=novoigm;
		IGM->fim=novoigm;
		novoigm->prox=NULL;
		
		IGG->inicio=novoigg;
		IGG->fim=novoigg;
		novoigg->prox=NULL;
	}
	else{
		
		IGM->fim->prox=novoigm;
		IGM->fim=novoigm;
		novoigm->prox=NULL;
		
		IGG->fim->prox=novoigg;
		IGG->fim=novoigg;
		novoigg->prox=NULL;
	}
		
}

void mostrar(Tcabeca *IGM, Tcabeca *IGG){
	Tfila *auxigm = IGM->inicio;
	Tfila *auxigg = IGG->inicio;
	
	int paciente=0;
	while((auxigm!=NULL)&&(auxigg!=NULL)){
		
		printf("\nPaciente %d {",paciente++);
		printf("\nIGM :%d",auxigm->info);
		printf("\nIGG :%d\n}\n",auxigg->info);
		auxigm=auxigm->prox;
		auxigg=auxigg->prox;
	}
	printf("\n");
}

void mostrarelatorio(Tcabeca *IGM, Tcabeca *IGG){
	
	int paciente=0,sem=0,com=0,toxico=0;
	
	Tfila *auxigm = IGM->inicio;
	Tfila *auxigg = IGG->inicio;
	
	while((auxigm!=NULL)&&(auxigg!=NULL)){
		
		if((auxigg->info==0)&&(auxigm->info==0)){
			
			//printf("1\n");//nunca teve
			sem++;
		}
		else if( ((100> auxigm->info)&&(1< auxigm->info)) && (100< auxigg->info) ){//ja teve e esta ativa
			
			//printf("2\n");
			toxico++;
			com++;
			
		}else{
			
	//		if((100> auxigm->info)&&(auxigm->info > 1)){//ja teve
	//			printf("4\n");
	//			teve++;
	//		}
			
			if(100< auxigg->info){//ta ativa
				//printf("3\n");
				com++;
			}
		}
		auxigm=auxigm->prox;
		auxigg=auxigg->prox;
		paciente++;
		
		printf("\n");
	}
	printf("\n\nPacientes sem Toxoplasmose: %d\n ",sem);
	printf("Pacientes com Toxoplasmose: %d\n ",com);
	printf("Pacientes que tiveram a doença e estão com ela ativa: %d\n ",toxico);
}
