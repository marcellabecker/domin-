# Ifndef DOM_H
# define  DOM_H
# include < stdlib.h >

vazio  titulo ()
{
	printf ( "                                                 __ \ n " );
	printf ( "                                                / _ / \ n " );
	printf ( "        _____ _____ __ __ _ _ _ _____ \ n " );
	printf ( "   o O | _   \\ | _ | |   \\ / | | _ | | \\ | | _ | O o \ n " );
	printf ( " o O o | | | | | | | V | | |   \\ | | | | | o O o \ n " );
	printf ( "   o O | | _ | | | _ | | | \\ _ / | | | | | | \\   | | _ | | O o \ n " );
	printf ( "     o | _____ / | _____ | | _ | | _ | | _ | | | | \\ _ | | _____ | o \ n - - - = - = - = - = - = - = - = - = - = - = - = - = - = - = - = - = - = - = - = - = - = - = - = - = - - - \ n " );
}

int  sair ()
{
	int r;
	sistema ( " cls " );
	printf ( " Tem certeza? \ n 1> Sim \ n 2> Nao \ n 	:: " );
	scanf ( " % d " , & r);
	se (r == 1 )
		retornar  0 ;
	retornar  1 ;
}

/ * ###### LISTA ###### * /

typedef  struct {
	int ladoE, ladoD, bacalhau, soma;
} peca;

typedef  struct noaux_lista {
	peca info;
	struct noaux_lista * ant;
	struct noaux_lista * prox;
} no_lista;

typedef  struct {
	no_lista * ini;
	no_lista * fim;
	int tamanho;
} lista;

no_lista * aloc_lista () // Aloca um espaço de memória para um novo nó da lista
{
	no_lista * pt;
	pt = (no_lista *) malloc ( sizeof (no_lista));
	return pt;
}

peca gera_peca ( int cod) // Retorna uma peça especificada pelo seu código
{
	peca e;
	int num1 = cod / 10 , num2 = cod% 10 ;
	if (num1 <= num2) {
		e ladoE = num1;
		e ladoD = num2;
		e bacalhau = bacalhau;
	} mais {
		e ladoE = num2;
		e ladoD = num1;
		e cod = num1 * 10 + num2;
	}
	e soma = num1 + num2;
	retornar e;
}

lista * ini_lista () // Inicialização da mão do jogador
{
	lista * lst = (lista *) malloc ( sizeof (lista));
	lst-> ini = NULL ;
	lst-> fim = NULL ;
	lst-> tamanho = 0 ;
	return lst;
}

int  lista_empty (lista * lst ) // Verifica se a mão está vazia
{
	if (! lst-> size )
		retornar  1 ;
	retornar  0 ;
}

/ * ###### PILHA ###### * /



# endif
