# Ifndef _pilha
# define  _pilha

# include < stdio.h >

# define  _SIZE_PILHA  28

typedef  int elemento;

typedef  struct {
	elementos do elemento [_SIZE_PILHA];
	int top;
}pilha;

bool  Creat (pilha * s) {
	s-> top = -1 ;
	return  true ;
}

bool  IsEmpty (pilha * s) {
	retornar s-> top == - 1 ;
}

bool  IsFull (pilha * s) {
	retornar s-> top == _ SIZE_PILHA- 1 ;
}

bool  Push (pilha * s, elemento e) {
	if ( IsFull (s)) retorna  false ;
		s-> elementos [++ s-> top ] = e;
	return  true ;
}

bool  Pop (pilha * s, elemento * e) {
	if ( IsEmpty (s)) retorna  false ;
	if (e! = NULL ) * e = s-> elementos [s-> top -];
	else s-> top -;
	return  true ;
}

bool  Top (pilha * s, elemento * e) {
	if ( IsEmpty (s)) retorna  false ;
		* e = s-> elementos [s-> top ];
	return  true ;
}

int  CountPilha (pilha * s) {
	retornar s-> top + 1 ;
}

booleano  PrintStack (pilha * s, caractere entre) {
	if ( IsEmpty (s)) retorna  false ;
	registre  int t = s-> top ;
	while (t! = - 1 ) {
		printf ( " % d " , s-> elementos [t]);
		printf ( " % c " , entre);
		t--;
	}
	return  true ;
}
bool  ExistElement (pilha * s, elemento e) {
	if ( IsEmpty (s)) retorna  false ;

	registre  int t = s-> top ;
	
	para (; t! = - 1 ; t--) {
		if (s-> elementos [t] == ​​e) {
			return  true ;
		}
	}
	retornar  falso ;
}



# endif
