# Ifndef MESA_H
# define  MESA_H
# include < stdio.h >
# include < stdlib.h >
# include " dom.h "

/ * 28 peças:
cod = 00> 0: 0
    = 01> 0: 1
    = 02> 0: 2
    = 03> 0: 3
    = 04> 0: 4
    = 05> 0: 5
    = 06> 0: 6
    = 11> 1: 1
    = 12> 1: 2
    = 13> 1: 3
    = 14> 1: 4
    = 15> 1: 5
    = 16> 1: 6
    = 22> 2: 2
    = 23> 2: 3
    = 24> 2: 4
    = 25> 2: 5
    = 26> 2: 6
    = 33> 3: 3
    = 34> 3: 4
    = 35> 3: 5
    = 36> 3: 6
    = 44> 4: 4
    = 45> 4: 5
    = 46> 4: 6
    = 55> 5: 5
    = 56> 5: 6
    = 66> 6: 6 * /

int  inserir_ini (lista * mesa ,eca e) // Inserir peça no início
{
	no_lista * newno = aloc_lista ();
	if (! newno)
		retornar  0 ;
	newno-> info = e;
	if ( lista_empty (mesa)) {
		newno-> prox = NULL ;
		newno-> ant = NULL ;
		mesa-> ini = mesa-> fim = newno;
	} mais {
		newno-> ant = NULL ;
		newno-> prox = mesa-> ini ;
		mesa-> ini -> ant = newno;
		mesa-> ini = newno;
	}
	mesa-> tamanho ++;
	retornar  1 ;
}

int  inserir_fim (lista * mesa ,eca e) // Inserir peça no fim
{
	no_lista * newno = aloc_lista ();
	if (! newno)
		retornar  0 ;
	newno-> info = e;
	if ( lista_empty (mesa)) {
		newno-> prox = NULL ;
		newno-> ant = NULL ;
		mesa-> ini = mesa-> fim = newno;
	} mais {
		newno-> prox = NULL ;
		newno-> ant = mesa-> fim ;
		mesa-> fim -> prox = newno;
		mesa-> fim = newno;
	}
	mesa-> tamanho ++;
	retornar  1 ;
}

void  print_mesa (lista * mesa) // sai da mesa
{
	no_lista * atu;
	int i = 0 ;
	atu = mesa-> ini ;
	while (atu! = NULL ) {
		if (i == 10 ) {
			i = 0 ;
			printf ( " \ n " );
		}
		i ++;
		printf ( " % d : % d   " , atu-> info . ladoE , atu-> info . ladoD );
		atu = atu-> prox ;
	}
}

// int quant_peca () // Verificar quantas peças tem na tabela
// {
//	
// }
//
// int iden_peca () // Verificar quais peças tem na tabela
// {
//	
// }
//
// int verifcar_jogo ()
// {
//
// }

# endif
