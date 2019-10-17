# ifndef _functions
# define  _functions

# Incluem  < iostream >
# include  " GameStructures.h "
# include  " Lista.h "
# include  " Pilha.h "
# include  < stdlib.h >
# include  < stdio.h >
# include  < time.h >
# include  < windows.h >
# include  < conio.h >

usando  espaço para nome  std ;

	 int screenx = 0 , screeny = 0 ;
	 int x_size = 128 , y_size = 16 ;
	 int x_start = 3 , y_start = 3 , dist = 4 ;
	 int pecaParaJogar = - 1 ;

int semente = 0 ;

void  AtualizaTela ();
int  Novo_Monte (pilha * s);
void  IniciarMesa (mesa * Mesa);
void  IniciaJogador (jogador * Jogador, mesa * Mesa, char * nome);
int  PorNaMesa ( int PecaCode, mesa * Mesa, jogador * Player, int dir);
int  JogadaValida ( int PecaCode, mesa * Mesa, int dir);
void  PegarDoMonte ();
void  IniciarJogo (mesa * Mesa, jogador * Jogador1, jogador * Jogador2);
void  gotoxy ( int x, int y);
void  PutCharOnPosition ( int x, int y, char c);

int  Jogador (jogador * Jogador, mesa * Mesa);

void  IniciarMesa (mesa * Mesa) {
	
	Mesa-> pecas = Init ();
	Criar (& Mesa-> monte );
	
	Novo_Monte (& Mesa-> monte );
	
	printf ( " Ordem do monte: " );
	PrintStack (& Mesa-> monte , '  ' );
	printf ( " \ n " );
}

void  IniciaJogador (jogador * Jogador, mesa * Mesa, char * nome) {
	registrar  int peca, i;
	
	Jogador-> mao = Init ();
	Jogador-> nome = nome;
	para (i = 0 ; i < 7 ; i ++) {
		Pop (& Mesa-> monte , & peca);
		Adicionar (& Player-> mao , peca);
	}
	
	PrintList (Player-> mao , CountList (Player-> mao ));
}

int  PorNaMesa ( int PecaCode, mesa * Mesa, jogador * Player, int dir) {

		if (dir == 2 ) {
		if ( JogadaValida (PecaCode, Mesa, dir)! = - 1 ) {
				Adicionar (& Mesa-> pecas , PecaCode);	
		    Remover (& Player-> mao , PecaCode);
		    retornar  1 ;
			}
		    
		}
		outro
		{
		if ( JogadaValida (PecaCode, Mesa, dir)! = - 1 ) {
			AddIni (& Mesa-> pecas , PecaCode);
			Remover (& Player-> mao , PecaCode);
			retornar  1 ;
		}
		}
	
	
retorno - 1 ;
}

int  JogadaValida ( int PecaCode, mesa * Mesa, int dir) {
	
// -1 jogada invalida
// -2 tabela vazia, jogada sempre válida
// caso contrário retornará uma peça

	
	int peca;
	int pecaR;
	if (dir == 2 ) {
	    if ( Get (Mesa-> pecas , & peca) == - 1 ) return - 2 ;
	
	} mais {
	    if ( GetIni (Mesa-> pecas , & peca) == - 1 ) return - 2 ;
	}
	
	pecaR = peca;
		
	if (peca% 10 == PecaCode% 10 || peca% 10 == PecaCode / 10 || peca / 10 == PecaCode% 10 || peca / 10 == PecaCode / 10 ) {
		
		
		
		if (dir == 2 && (peca% 10 ! = PecaCode / 10 )) {
			
	        pecaR = ((peca% 10 ) * 10 ) + PecaCode / 10 ;
	    } senão  se (PecaCode% 10 ! = peca / 10 ) {
	    	pecaR = ((PecaCode% 10 ) * 10 ) + peca / 10 ;
		}
			retorno pecaR;
	}
		
		retorno - 1 ;
}

void  PegarDoMonte () {
	
}

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

void  AtualizaTela (mesa * Mesa) {
	sistema ( " cls " );

      screenx = 0 ;
	  screeny = 0 ;
	  x_size = 128 ;
	  y_size = 16 ;
	  x_start = 3 ;
	  y_start = 3 ;
	  dist = 4 ;
	
	para (screenx = 0 ; screenx <x_size; screenx ++) {
		para (screeny = 0 ; screeny <tamanho_da; screeny ++) {
			
			if (screenx == 0 && screeny == 0 ) PutCharOnPosition (screenx + x_start, screeny + y_start, 201 );
			 caso contrário, if (screenx == 0 && screeny == y_size- 1 ) PutCharOnPosition (screenx + x_start, screeny + y_start, 200 );
			 caso contrário, if (screenx == x_size- 1 && screeny == y_size- 1 ) PutCharOnPosition (screenx + x_start, screeny + y_start, 188 );
			 caso contrário, if (screenx == x_size- 1 && screeny == 0 ) PutCharOnPosition (screenx + x_start, screeny + y_start, 187 );
			 caso contrário, if (screenx == 0 && screeny! = 0 ) PutCharOnPosition (screenx + x_start, screeny + y_start, 186 );
			 caso contrário, if (screenx! = 0 && screeny == 0 ) PutCharOnPosition (screenx + x_start, screeny + y_start, 205 );
			 caso contrário, if (screenx == x_size- 1 && screeny! = 0 ) PutCharOnPosition (screenx + x_start, screeny + y_start, 186 );
			 caso contrário, if (screenx! = 0 && screeny == y_size- 1 ) PutCharOnPosition (screenx + x_start, screeny + y_start, 205 );
		}	
	}
	
	para (screenx = 0 ; screenx <x_size; screenx ++) {
		for (screeny = 0 ; screeny <tamanho_da_y / 2 ; screeny ++) {
			
			if (screenx == 0 && screeny == 0 ) PutCharOnPosition (screenx + x_start, screeny + dist + y_size, 201 );
			 caso contrário, if (screenx == 0 && screeny == y_size / 2 - 1 ) PutCharOnPosition (screenx + x_start, screeny + dist + y_size, 200 );
			 caso contrário, if (screenx == x_size- 1 && screeny == y_size / 2 - 1 ) PutCharOnPosition (screenx + x_start, screeny + dist + y_size, 188 );
			 caso contrário, if (screenx == x_size- 1 && screeny == 0 ) PutCharOnPosition (screenx + x_start, screeny + dist + y_size, 187 );
			 caso contrário, if (screenx == 0 && screeny! = 0 ) PutCharOnPosition (screenx + x_start, screeny + dist + y_size, 186 );
			 caso contrário, if (screenx! = 0 && screeny == 0 ) PutCharOnPosition (screenx + x_start, screeny + dist + y_size, 205 );
			 caso contrário, if (screenx == x_size- 1 && screeny! = 0 ) PutCharOnPosition (screenx + x_start, screeny + dist + y_size, 186 );
			 caso contrário, if (screenx! = 0 && screeny == y_size / 2 - 1 ) PutCharOnPosition (screenx + x_start, screeny + dist + y_size, 205 );
		}	
	}
	
	gotoxy (x_start + 2 , (y_size / 2 ) + y_size / 4 );
	PrintFormatedToDomino (Mesa-> peças );
	
}

void  gotoxy ( int x, int y) {
     SetConsoleCursorPosition ( GetStdHandle (STD_OUTPUT_HANDLE), (Coord) {x- 1 , y- 1 });
}

void  PutCharOnPosition ( int x, int y, char c) {
gotoxi (x, y);
printf ( " % c " , c);	
}

void  IniciarJogo (mesa * Mesa, jogador * Jogador1, jogador * Jogador2) {
	cout << " Comecando partida \ n \ n " ;
		char n [ 15 ];
		char n2 [ 15 ];
		
		fflush (stdin);
		printf ( " % s " , " Nome do jogador 1: " );
		gets (n);
		fflush (stdin);
		printf ( " % s " , " Nome do Player 2: " );
		recebe (n2);
		fflush (stdin);
		
	cout << " Gerando monte ... \ n " ;
	IniciarMesa (Mesa);
	cout << " Monte criado! \ n \ n " ;
	
	cout << " Dando pecas aos jogadores ... \ n " ;
	cout << " Mao do jogador1: " ;

	IniciaJogador (Jogador1, Mesa, n);
	cout << " Mao do jogador2: " ;

	IniciaJogador (Player2, Mesa, n2);
	
	cout << " Jogadores prontos! \ n \ n " ;
}

int  Jogador (jogador * Jogador, mesa * Mesa) {
	int dir = 0 ;
	
	gotoxy (x_start + 2 , screeny + dist + 2 + y_size / 2 );
	
	cout << " Sua mao: " ;
 	PrintFormatedToDomino (Player-> mao );
 
 	gotoxy (x_start + 2 , screeny + dist + 3 + y_size / 2 );
 	
	 if (pecaParaJogar == - 1 ) {
 		cout << " Digite qual peca deseja jogar: " ;
 		cin >> pecaParaJogar;
 		
		 if ( Find (Player-> mao , pecaParaJogar) == NULL ) {
 			pecaParaJogar = - 1 ;
 			retorno - 1 ;
		 }
		 
 		gotoxy (x_start + 2 , screeny + dist + 4 + y_size / 2 );
 	}
 	
	 
 	  cout << " Digite em qual lado deseja jogar (1 = Esquerdo, 2 = Direito): " ;
 	  cin >> dir;	
	 if (dir! = 1 && dir! = 2 ) return - 1 ;
	
	if ( PorNaMesa (pecaParaJogar, Mesa, Player, dir) == - 1 ) return - 1 ;
	
 	pecaParaJogar = - 1 ;
 	retornar  1 ;
}

	
int  PodeJogar (jogador * Jogador, mesa * Mesa) {
	int i, j, tamanho;
	tamanho = CountList (Player-> mao );

	para (i = 0 ; i <tamanho; i ++) {
		
	}
}

# endif
