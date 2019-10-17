# Ifndef MAO_H
# define  MAO_H
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

void  print_mao (lista * mao) // Exibe uma mão do jogador
{
	no_lista * atu;
	int i = 0 ;
	atu = mao-> ini ;
	while (atu! = NULL ) {
		i ++;
		printf ( " % d > % d : % d \ n " , i, atu-> info . ladoE , atu-> info . ladoD );
		atu = atu-> prox ;
	}
}

int  remove_peca_mao (lista * mao, int local, int * cod) // Retira da mão uma peça do local requerido e manda de volta seu código
{
	no_lista * atu;
	atu = mao-> ini ;
	int i = 1 ;
	while ((atu! = NULL ) && (i <local)) { // Procura de uma peça do pedido local
		atu = atu-> prox ;
		i ++;
	}
	if (atu == NULL )
		retornar  0 ;
	* cod = atu-> info . bacalhau ;
	if (mao-> ini == mao-> fim ) // Veja o único elemento da lista
		mao-> ini = mao-> fim = NULL ;
	mais {
		if (mao-> ini == atu) { // Veja o primeiro elemento da lista
			mao-> ini = atu-> prox ;
			atu-> prox -> ant = NULL ;
		} mais {
			if (mao-> fim == atu) { // Consulte o último item da lista
				mao-> fim = atu-> formiga ;
				atu-> ant -> prox = NULL ;
			} else { // Nenhum intermediário
				atu-> prox -> ant = atu-> ant ;
				atu-> ant -> prox = atu-> prox ;
			}
		}
	}
	mao-> tamanho -;
	livre (atu);
	retornar  1 ;
}

int  inserir_ordenado (lista * mao, peca e) // Inserir um item oredenadamente (mão do jogador)
{
	no_lista * newno;
	newno = aloc_lista ();
	if (! newno)
		retornar  0 ;
	newno-> info = e;
	e soma = e. ladoD + e. ladoE ;
	if ( lista_empty (mao)) { // Veja uma lista disponível
		newno-> prox = NULL ;
		newno-> ant = NULL ;
		mao-> ini = mao-> fim = newno;
		retornar  1 ;
	} mais {
		no_lista * atu = mao-> ini ;
		while ((atu! = NULL ) && (atu-> info . sum <e. sum )) // Procura uma peça anterior da nova peça que será inserida
 			atu = atu-> prox ;
		if (atu == mao-> ini ) { // Início
			newno-> ant = NULL ;
			newno-> prox = mao-> ini ;
			mao-> ini -> ant = newno;
			mao-> ini = newno;
		} mais {
			if (atu! = NULL ) { // Meio
				newno-> prox = atu;
				atu-> ant -> prox = newno;
				newno-> ant = atu-> ant -> prox ;
				atu-> ant = newno;
			} else { // Final
				newno-> ant = mao-> fim ;
				newno-> prox = NULL ;
				mao-> fim = newno;
			}
		}
	}
	retornar  1 ;
}

# endif
