/*
Docente:		Fábio Nakano
Dicente:		Guilherme Bortoto de Moraes
Número USP:		9360760



*/
#include <stdio.h>
#include <stdlib.h>
#include "decisor.h"

// Ferramenta
// Mostra na tela o conteúdo de um nó
void printNo(No *n);

// Ferramenta
// Mostra na tela o conteúdo de todos os nós e retorna o número de nós no sistema
int crawler(No *n, int quantidade);

// Ferramenta
// Mostra na tela o conteúdo de todos os nós filhos de um nó pai
void printFilhos(No *n);


// Método 1 - criaArvore()
// Cria um nó raiz para uma árvore.
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

// Método 2 - criaFilho()
// Dado um nó pai, cria um nó filho
// Se já existir uma lista no nó pai, o nó filho é adicionado a essa lista.
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

// Método 3 - buscaSimples()
// Dado um nó pai, busca e retorna um nó filho com "categoria" igual ao valor desejado.
No *buscaSimples(No *n, int categoria){
	No *tmp;
	tmp = n->lista;
	do{
		if(tmp->categoria == categoria){
			return tmp;
		}
		tmp = tmp->prox;
	}while(tmp);
	return NULL;
}


// Método 4 - buscaFilho()
// Dado um nó pai, busca e retorna um filho com "categoria" e "atributo" iguais ao valor desejado
// Também aponta o ponteiro para ponteiro "antecessor" para o nó anterior ao retornado.
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

// Método 5 - decide
// Dado uma árvore de decisões e os atributos de uma pessoa, decide com base na arvore qual a situação
// apropriada e retorna a escolha feita.

int decide (No *arvore, int *atributos){
	printf ("decide\n");
	
	//				ID		Sexo	Relacionamento	Renda	Região	Tipo	Transporte	Restaurante
	// atributos = [1234, 	0, 		1, 				2, 		2,		1,		1, 			2]
	// posição   - [0]		[1]		[2]				[3]		[4]		[5]		[6]			[7]

	/*
	// Mostra uma tabela de atributos
	printf("\n\n\n*****\n");
	printf("ID:\t\t%d\n", atributos[0]);
	printf("Sexo\t\t%d\n", atributos[1]);
	printf("Relacionamento\t%d\n", atributos[2]);
	printf("Renda\t\t%d\n", atributos[3]);
	printf("Região\t\t%d\n", atributos[4]);
	printf("Tipo\t\t%d\n", atributos[5]);
	printf("Transporte\t%d\n", atributos[6]);
	printf("Restaurante\t%d\n", atributos[7]);
	printf("\n\n\n");
	*/
	
	No *tmp;
	// Enquanto o nó atual não for uma folha
	tmp = arvore;
	while(tmp){
		// Se tmp for uma folha
		if(!tmp->lista){
			// então retorne o atributoOuDecisão dessa folha
			return tmp->atributoOuDecisao;
		}else{
			// se o nó não for uma folha
			// procure na lista desse nó algum nó que possua a mesma característica (categoria) da
			// informação sobre a qual estamos buscando.
			tmp = buscaSimples(tmp, atributos[tmp->atributoOuDecisao]);
		}
	}
	// se não existir na lista, o valor é inválido
	printf("Valor inválido\n");
	return -1;
}


/*
			Métodos Auxiliares
	
		Afim de tornar as estruturas deste
		sistema mais visíveis durante e após
		seu desenvolvimento, foram criados
		métodos auxiliares que apresentam
		de forma visual (texto) as estruturas
		presentes nesse sistema (Nós, Arvores).
		
		O uso desses métodos é opcional e não
		afeta a lógica do sistema.
		
		São eles:
		- printNo(No *n);
		- crawler(No *n, int quantidade);
		- printFilhos(No *n);
*/

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
