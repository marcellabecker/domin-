# include  < stdio.h >
# include  " Pilha.h "
# include  < stdlib.h >
# include  < time.h >

int semente = 0 ;

int  Novo_Monte (pilha * s) {
	registre  int v = -1 ;
	srand ( tempo ( NULL ) + semente);
	semente + = 10 ;
	while ( IsFull (s) == 0 )
	{
		v = rand ()% 67 ;

		if (((v> = 0 && v <= 6 ) || (v> = 11 && v <= 16 ) || (v> = 22 && v <= 26 ) || (v> = 33 && v < = 36 ) || (v> = 44 && v <= 46 ) || v == 55 || v == 56 || v == 66 )) {

			if (! ExistElement (s, v)) {
				Push (s, v);
			}
		}
	}


	retornar v;
}
