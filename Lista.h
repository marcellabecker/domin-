# Ifndef _LIST_SE
# define  _LIST_SE

# include < stdio.h >
# include < stdlib.h >

typedef  int tp_item;

typedef  struct no {
	item tp_item;
	struct no * prox;
} tp_list_se;

tp_list_se * Init ();
int  CountList (tp_list_se * l);


tp_list_se * Init () {
	return  NULL ;
}

tp_list_se * Alloc () {
	tp_list_se * t = (tp_list_se *) malloc ( sizeof (tp_list_se));
	retornar t;
}

tp_list_se * Localizar (tp_list_se * l, tp_item e) {
	tp_list_se * atu = l;
	int i = 1 ;
	while (atu! = NULL && i = <e) {
		atu = atu-> prox ;
	}
	retorno atuado;
}

booleano  IsEmpty (tp_list_se * l) {
	se (l == NULL ) retornar  verdadeiro ;
	retornar  falso ;
}
 
bool  Add (tp_list_se ** l, tp_item e) {
	
	tp_list_se * atu;
	tp_list_se * novo_no = Alloc ();
	
	if (novo_no == NULL ) retorna  false ;
	
	novo_no-> item = e;
	novo_no-> prox = NULL ;
	
	if ( IsEmpty (* l)) {
		* l = novo_no;
	} mais {
		
		atu = * l;
		while (atu-> prox ! = NULL ) {
			atu = atu-> prox ;
		}
		atu-> prox = novo_no;
	}
	return  true ;
}
bool  AddIni (tp_list_se ** l, tp_item e) {
	
	tp_list_se * atu;
	tp_list_se * novo_no = Alloc ();
	
	if (novo_no == NULL ) retorna  false ;
	
	novo_no-> item = e;
	novo_no-> prox = NULL ;
	
	if ( IsEmpty (* l)) {
		* l = novo_no;
	} mais {
		
	atu = * l;
	novo_no-> prox = atu;
	* l = novo_no;
	}
	return  true ;
}
bool  OrderedAdd (tp_list_se ** l, tp_item e) {
	tp_list_se * novo_no, * atu, * ant;
	novo_no = Alloc ();
	
	if (novo_no == NULL ) retorna  0 ;
	novo_no-> item = e;
	atu = * l;
	ant = NULL ;	
	
	while ((atu! = NULL ) && atu-> item <e) {
	form = atu;
	atu = atu-> prox ;
	}
	if (ant == NULL ) {
	
		* l = novo_no;
	}
	mais {
		ant-> prox = novo_no;
	}
	novo_no-> prox = atu;
	return  true ;
}

void  Concat (lista tp_se * a, lista tp_se * b) {
	tp_list_se * atu;
	atu = a;
		while (atu-> prox ! = NULL ) {
			atu = atu-> prox ;
		}
		atu-> prox = b;
		atu = b;
		while (atu-> prox ! = NULL ) {
			atu = atu-> prox ;
		}
		atu-> prox = a;
		b = a;
}

tp_list_se * Dividir (lista tp_list_se, tp_item e) {
		tp_list_se * atu = & lista;
		tp_list_se * newList;
		while (atu-> prox ! = NULL && atu-> item ! = e) {
			atu = atu-> prox ;
		}
		if (atu == NULL ) retorna  NULL ;
		newList = atu-> prox ;
		atu-> prox = NULL ;
		return newList;
}

bool  Remover (tp_list_se ** l, tp_item e) {
	tp_list_se * ant;
	tp_list_se * atu;
	
	atu = * l;
	ant = NULL ;
	
	while ((atu! = NULL ) && (atu-> item ! = e)) {
		form = atu;
		atu = atu-> prox ;
	}
	
	if (ant == NULL ) {
		* l = atu-> prox ;
		livre (atu);
		return  true ;
	}
	if (atu == NULL ) {
		retornar  falso ;
	}
	ant-> prox = atu-> prox ;
	livre (atu);
	return  true ;
}

void  PrintList (tp_list_se * l, int Length) {
	tp_list_se * atu;
	atu = l;
	registre  int t = 0 ;
	para (; t <comprimento; t ++) {
	printf ( " % d  " , atu-> item );
		atu = atu-> prox ;	
	}
}

void  PrintFormatedToDomino (tp_list_se * l) {
	tp_list_se * atu;
	atu = l;
	int tamanho = CountList (l);
	registre  int t = 0 ;
	para (; t <tamanho; t ++) {
	printf ( " [ % d | % d ] " , atu-> item / 10 , atu-> item % 10 );
		atu = atu-> prox ;	
	}
}

 Limpar nulo (tp_list_se ** l) {
	tp_list_se * atu;
	atu = * l;
	
	while (atu! = NULL ) {
		* l = atu-> prox ;
		livre (atu);
		atu = * l;
	}
		
	* l = NULL ;
}

int  CountList (tp_list_se * l) {

	tp_list_se * atu = l; 
	registre  int i = 0 ;
	
	while (atu! = NULL ) {
		atu = atu-> prox ;
		i ++;
	}
	retornar i;
}

int  Get (tp_list_se * l, tp_item * e) {
	if ( IsEmpty (l)) retorna - 1 ;
	tp_list_se * atu = l;
	while (atu-> prox ! = NULL ) {
		atu = atu-> prox ;
	}
	* e = atu-> item ;
	return  true ;
}
int  GetIni (tp_list_se * l, tp_item * e) {
	if ( IsEmpty (l)) retorna - 1 ;
	* e = l-> item ;
	return  true ;
}
# endif
