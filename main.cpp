#include <stdlib.h>
#include <ctime>
#include <iostream>
using std::cout;
using std::cin;
using namespace std;
#include <vector>
using std::vector;
#include <math.h>

struct Score
{
  int vitorias;
};


struct Jogador
{
  char nome[50];
  Score numVitorias;
};

void exibeTabuleiroInicial(int [], int & );
int verificaRegras( int [], int & );
int jogarDados( );
void exibeJogador( Jogador * );
void exibeTabuleiro( int &, Jogador *, int &, int * );
bool verificaVencedor ( int & );
int numVitoriasJog1( Jogador *, int & );
int numVitoriasJog2( Jogador *, int & );
void verificaPerc( int & );
const int SIZE = 30;

int main( )
{
  const int NUMJOGADAS = 5;
	int i = 0;
  while( i < NUMJOGADAS )
  {
	  int size = 0;
	  int jog1 = 1;
	  int lastPosJog1 = 0;
	  int jog2 = 2;
	  int lastPosJog2 = 0;
	  int myArray[ SIZE ];
	  size = SIZE;
	  struct Jogador jog[ 2 ];
	  int *tabuleiro1Ptr = 0;
	  int *tabuleiro2Ptr = 0;
  	//vector< Jogador * > *rankingPtr[ NUMJOGADAS ];
	
    exibeJogador( jog );
    exibeTabuleiroInicial( myArray, size );
  
    cout << '\n';
    //rankingPtr[ i ] = new Jogador [ 1 ];
	  do
	  {
	    tabuleiro1Ptr = new int [ size ];
		  lastPosJog1 += jogarDados( );
		  lastPosJog1 = verificaRegras( myArray, lastPosJog1 );	
		  exibeTabuleiro( lastPosJog1, jog, jog1, tabuleiro1Ptr );
		  verificaPerc( lastPosJog1 );
		  if( verificaVencedor( lastPosJog1 ) )
		  {
			  cout << "\n\n" << jog[ jog1 ].nome << " venceu! Parabens!" << '\n';
			  int vit1 = numVitoriasJog1( jog, jog1 );
			  cout << "Numero de vitorias: " << vit1  << '\n';
			  //rankingPtr[ i ] = jog[ jog1 ];
	      break;
		  }
		  delete [] tabuleiro1Ptr;
		  tabuleiro1Ptr = 0;
					
	    tabuleiro2Ptr = new int [ size ];
		  lastPosJog2 += jogarDados( );
		  lastPosJog2 = verificaRegras( myArray, lastPosJog2 );
		  exibeTabuleiro( lastPosJog2, jog, jog2, tabuleiro2Ptr );
		  verificaPerc( lastPosJog2 );
		  if( verificaVencedor( lastPosJog2 ) )
		  {
			  cout << "\n\n" << jog[ jog2 ].nome << " venceu! Parabens!" << '\n';
			  int vit2 = numVitoriasJog2( jog, jog2 );
			  cout << "Numero de vitorias: " << vit2  << '\n';
			  //rankingPtr[ i ] = jog[ jog2 ];
			  break;
		  }
		  delete [] tabuleiro2Ptr;
		  tabuleiro2Ptr = 0;
	  } while ( lastPosJog1 < SIZE || lastPosJog2 < SIZE );
	  i++;
	}
	
	 //for ( int j = 0; j < rankingPtr; j++ )
    //cout << "Ranking: " << '\n' << rankingPtr[ j ] << '\n';
	  
	 //delete [] rankingPtr;
	  
  system ("pause"); 
  return 0;

}

void exibeTabuleiro( int & lastPos, Jogador *jog, int & indicaJog, int * tabuleiro )
{
	for(int i = 0; i < SIZE; i++)
  {
    if( lastPos < SIZE )
    {
    	if( i == lastPos )
   			tabuleiro[ i ] = 1;
   		else
   			tabuleiro[ i ] = 0;
   	}
   	else
   	{
    	if( i == SIZE - 1 )
   			tabuleiro[ i ] = 1;
   		else
   			tabuleiro[ i ] = 0;
   	}  		
  }       
  cout << "Tabuleiro do Jogador: " << jog[ indicaJog ].nome << '\n';
  cout << "Jogador: " << indicaJog << '\n';
  for (int i = 0; i < SIZE; i++)
    cout << tabuleiro[ i ] << '\t';
}

void exibeJogador( Jogador *dadosJog )
{
	// Estrutura de dados para mostrar o nome dos jogadores
  for( int i = 1; i < 3; i++ )
  {
    cout <<"\nNome do Jogador " << i << ": " << '\n';
    cin >> dadosJog[i].nome;
  }

  for( int i = 1; i < 3; i++ )
  {
    cout << "-----------------------------------\n";
    cout << "Nome do Jogador " << i << ": " << dadosJog[ i ].nome << '\n';
    cout << "-----------------------------------\n";
    cout << "\n";
  }
}

int jogarDados( )
{
	int dado1, dado2, dadoSoma;
	srand ( time( NULL) );
	char pergunta;
	
	cout << "\n-----------------------------------\n";
	cout << "\nPara jogar o dado, digite 'S'. " << '\n';
  cin >> pergunta;
  if( pergunta == 'S' )
  {
    dado1 = 1 + rand( ) % 6;
		dado2 = 1 + rand( ) % 6;	
		dadoSoma = dado1 + dado2;
		cout << "Ande " << dadoSoma << " casas!" << '\n';
	}
	return dadoSoma;		
}

void exibeTabuleiroInicial( int array[ ], int & size )
{
  for(int i = 0; i < size; i++)
  {
    if( i % 3 == 0 && i != 0 )
    	array[ i ] = -1;
		else
			array[ i ] = 0;		
	}
        
  cout << "Tabuleiro inicial: " << '\n';
  for (int i = 0; i < size; i++)
      cout << array[ i ] << '\t';
}

int verificaRegras( int array[ ], int & lastPosition )
{
  if( array[ lastPosition ] == -1 ) //Regra: volte 2 casas.
  {
   	lastPosition = lastPosition - 2;
   	cout << "Volte duas casas!" << '\n';
  }		
	return lastPosition;
}

bool verificaVencedor ( int & lastPosition )
{
  if( lastPosition >= SIZE - 1 )
    return true;
  else 
    return false;
}

int numVitoriasJog1( Jogador *jog, int & indicaJog )
{
  static int estatica1 = 0;
  return estatica1 += 1;
  //jog[ indicaJog ].numVitorias.vitorias = estatica1 + 1;
  //cout << "Numero de vitorias: " << jog[ indicaJog ].numVitorias.vitorias << '\n';
}

int numVitoriasJog2( Jogador *jog, int & indicaJog )
{
  static int estatica2 = 0;
  return estatica2 += 1;
  //jog[ indicaJog ].numVitorias.vitorias = estatica2++;
  //cout << "Numero de vitorias: " << jog[ indicaJog ].numVitorias.vitorias << '\n';
}

void verificaPerc( int & lastPosition )
{
  double perc = lastPosition * 100.0 / (double)(SIZE - 1);
  std::cout.precision(2);
  std::cout << "\n\n" << "Voce percorreu " << std::fixed << perc << "%" << endl;
}