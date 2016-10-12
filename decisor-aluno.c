#include <stdio.h>
#include <stdlib.h>
#include "decisor.h"

/*
typedef struct node {
	int categoria;
	int atributoOuDecisao;
	struct node *prox;
	struct node *lista;
} No;
*/




// DONE ################################################################################################
No *criaArvore(void){
	printf ("criaArvore\n");
	No *arvore = malloc(sizeof(No));
	arvore->categoria = -1;
	arvore->atributoOuDecisao = 0;
	arvore->prox = NULL;
	arvore->lista = NULL;
	return arvore;
	printf ("criaArvore\n");
}
// DONE ################################################################################################



// DONE ################################################################################################
No *criaFilho (No *pai, int atributoDoPai, int categoriaDoFilho, int atributoOuDecisao){
	printf ("criaFilho\n");
	/*
	// Prints para esclarecimento
	printf("%d", atributoDoPai);
	printf(", ");
	printf("%d", categoriaDoFilho);
	printf(", ");
	printf("%d", atributoOuDecisao);
	printf(")\n");
	*/
	No *filho = malloc(sizeof(No));
   
	// Esse filho é uma opção da relação "atributoDoPai"
	// Ex: aDP = 1 --> Esse filho é uma opção de "sexo", que sai de pai
	pai->atributoOuDecisao = atributoDoPai;
   
	// Esse filho é a X escolha
	filho->categoria = categoriaDoFilho;
   
	// Esse filho tem como atributoOuDecisao o valor X
	filho->atributoOuDecisao = atributoOuDecisao;
   
	// Se o pai tem uma lista, adicione o filho no final dela
	if(pai->lista){
		No *tmp;
		tmp = pai->lista;
		while(tmp->prox){
			tmp = tmp->prox;
		}
		tmp->prox = filho;
	}
	// Se o pai não tiver uma lista, então filho é o começo da nova lista de pai
	else{
		pai->lista = filho;
	}
   
   return filho;
}
// DONE ################################################################################################


// DONE ################################################################################################
void printNo(No *n){
	if(!n){
		printf("printNo() foi chamado para um valor NULL\n");
		return;
	}

	printf("Categoria: ");
	printf("%d\n", n->categoria);

	printf("atributoOuDecisao: ");
	printf("%d\n", n->atributoOuDecisao);

	if(n->prox){
		printf("Categoria do Prox: ");
		printf("%d\n", n->prox->categoria);
		
		printf("atributoOuDecisao do Prox: ");
		printf("%d\n", n->prox->atributoOuDecisao);
	}else{
		printf("Prox: NULL\n");
	}
	if(n->lista){
		printf("Categoria da Lista: ");
		printf("%d\n", n->lista->categoria);

		printf("atributoOuDecisao da Lista: ");
		printf("%d\n", n->lista->atributoOuDecisao);
	}else{
		printf("Lista: NULL\n");
	}
}
// DONE ################################################################################################



// DONE ################################################################################################
No *buscaFilho (No *n, int atributo, int categoria, No **antecessor){
	printf ("buscaFilho\n");
	No *atual;
	No *anterior;
	
	// "atual" é o primeiro elemento da lista no nó n
	atual = n->lista;
	
	// "anterior" é o próprio nó pai
	anterior = n;
	
	// Nota: esse loop checa do elemento (0) da lista ao elemento (tamanhoDaLista-1)
	// Enquanto houver outros elementos na lista do nó n
	while(atual->prox){
		// Se categoria e atributoOuDecisão corresponderem aos valores buscados
		if((atual->categoria == categoria)&&(atual->atributoOuDecisao == atributo)){
			printf("\nNó encontrado!!\n");
			
			// Se o nó for o primeiro da fila, avisar que o nó anterior é o nó pai
			if(anterior == n){
				printf("Nota: o nó encontrado era o primeiro da lista\n");
				printf("O nó pai foi considerado como o nó antecessor\n");
			}
			
			*antecessor = anterior;
			return atual;
		}
		// Se o elemento atual não for o desejado, então buscar no próximo elemento
		anterior = atual;
		atual = atual->prox;
	}
	
	// Realizar comparação para o último elemento
	if((atual->categoria == categoria)&&(atual->atributoOuDecisao == atributo)){
		printf("\nNó encontrado!!\n");
		*antecessor = anterior;
		return atual;
	}	
	
	// Se nem o último elemento for o desejado, então o elemento desejado não pertence a lista do nó n
	*antecessor = NULL;
	return NULL;
}
// DONE ################################################################################################








int decide (No *arvore, int *atributos){
	printf ("decide\n");
	
	//				ID		Sexo	Relacionamento	Renda	Região	Tipo	Transporte	Restaurante
	// atributos = [1234, 	0, 		1, 				2, 		2,		1,		1, 			2]
	//				[0]		[1]		[2]				[3]		[4]		[5]		[6]			[7]
	
	
	
	
	return NULL;
}

















// DONE ################################################################################################
int crawler(No *n, int quantidade){
	// Contar esse nó
	quantidade++;
	printf("\nNó número ");
	printf("%d\n", quantidade);
	printNo(n);
	
	// Checar se o nó é uma folha
	if((!n->prox)&&(!n->lista)){
		return quantidade;
	}
	
	// Checar se o nó tem próximo
	if(n->prox){
		quantidade = crawler(n->prox, quantidade);
	}
	
	// Checar se o nó tem uma lista
	if(n->lista){
		quantidade = crawler(n->lista, quantidade);
	}
	return quantidade;
}
// DONE ################################################################################################


// DONE ################################################################################################
void printFilhos(No *n){
	No *tmp;
	if(!n->lista){
		return;
	}
	tmp = n->lista;
	int i=0;
	
	while(tmp->prox){
		printf("Elemento: ");
		printf("%d\n", i);
		printNo(tmp);
		printf("\n");
		tmp = tmp->prox;
		i++;
	}
	printf("Elemento: ");
	printf("%d\n", i);
	printNo(tmp);
	printf("\n");	
}
// DONE ################################################################################################
