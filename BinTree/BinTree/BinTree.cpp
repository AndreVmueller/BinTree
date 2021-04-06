// PROBLEMA: Quero imprimir todos o n�meros bin�rios com N casas.
// Dificuldade do problema: Crescimento de tempo exponencial. Uma itera��o com N=10 demoraria bastante tempo.
// Solu��o: Fun��o recursiva para formar todas combina��es possive�s. 
#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <string>
using namespace std;

// A fun��o Bit � uma fun��o recursiva que vai montar uma string com todas as combina��es de n�mero bin�rio para N casas.
// Retorna uma string no formato => "DEC: DD  BIN: BBBB - DEC: DD  BIN: BBBB - ... "
// Bit = 0 ou 1. Chamada � esquerda concatena '0', chamada � direita concatena '1'.
// qtdBits = N�mero de casas bin�rias. � inicializado pelo valor de pot�ncia de 2 onde por exemplo, 2^4 = 2*2*2*2 = 16, logo na passagem de par�metro o bit mais significante vai ser 16/2 = 8.
//			 Cada recurs�o o 'qtdBits' � dividido por 2 para representar o pr�ximo valor menos significativo.			
// dec = � o somat�rio das opera��es de multiplica��o por 0 e 1. Exemplo: Quatro chamadas recursivas quaisquer formando a sequ�ncia de bits 0101 => (1*1 + 0*2 + 1*4 + 0*8 = 5).
//		 O valor de 'dec' � formado recursivamente => dec + (bit * qtdBits)
// Retorno recursivo em cada chamada usa duas fun��es Bit (Bit - Bit). 
// Retorno de parada retorna a string.
string Bit(string  bit, int qtdBits, int dec)
{
	if (qtdBits == 0) //Ponto de parada de recurs�o
		return "DEC: " + std::to_string(dec) + " BIN: " +  bit ; 
	return  Bit( bit + "0" , qtdBits/2, dec + (0 * qtdBits) ) + " \n " +  Bit( bit + "1", qtdBits/2, dec + (1 * qtdBits) ) ; // chamada dupla da fun��o para montar uma �rvore
}

//Apenas para inicializar a fun��o Bit e retorar uma string com todas as concatena��es
//Fun��o poderia ser modificada para retornar um xml, json, etc...
//Observe que a sequ�ncia montada tamb�m serve como indice para dizer como se chegar a folha. Exemplo: 1010 saimos da raiz "" depois vamos para Direita > Esquerda > Direita > Esquerda.
string  ImprimirDecBin (int qtdBits)
{
	return  Bit("", _Pow_int(2,qtdBits)/2, 0);
}

//Imprimir os dados
//Como ImprimirDecBin retonar uma String. 
int main()
{
	cout << ImprimirDecBin(10) << endl;
	return 0;
}
