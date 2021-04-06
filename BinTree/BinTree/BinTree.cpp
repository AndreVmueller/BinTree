// PROBLEMA: Quero imprimir todos o números binários com N casas.
// Dificuldade do problema: Crescimento de tempo exponencial. Uma iteração com N=10 demoraria bastante tempo.
// Solução: Função recursiva para formar todas combinações possiveís. 
#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <string>
using namespace std;

// A função Bit é uma função recursiva que vai montar uma string com todas as combinações de número binário para N casas.
// Retorna uma string no formato => "DEC: DD  BIN: BBBB - DEC: DD  BIN: BBBB - ... "
// Bit = 0 ou 1. Chamada à esquerda concatena '0', chamada à direita concatena '1'.
// qtdBits = Número de casas binárias. É inicializado pelo valor de potência de 2 onde por exemplo, 2^4 = 2*2*2*2 = 16, logo na passagem de parâmetro o bit mais significante vai ser 16/2 = 8.
//			 Cada recursão o 'qtdBits' é dividido por 2 para representar o próximo valor menos significativo.			
// dec = É o somatório das operações de multiplicação por 0 e 1. Exemplo: Quatro chamadas recursivas quaisquer formando a sequência de bits 0101 => (1*1 + 0*2 + 1*4 + 0*8 = 5).
//		 O valor de 'dec' é formado recursivamente => dec + (bit * qtdBits)
// Retorno recursivo em cada chamada usa duas funções Bit (Bit - Bit). 
// Retorno de parada retorna a string.
string Bit(string  bit, int qtdBits, int dec)
{
	if (qtdBits == 0) //Ponto de parada de recursão
		return "DEC: " + std::to_string(dec) + " BIN: " +  bit ; 
	return  Bit( bit + "0" , qtdBits/2, dec + (0 * qtdBits) ) + " \n " +  Bit( bit + "1", qtdBits/2, dec + (1 * qtdBits) ) ; // chamada dupla da função para montar uma árvore
}

//Apenas para inicializar a função Bit e retorar uma string com todas as concatenações
//Função poderia ser modificada para retornar um xml, json, etc...
//Observe que a sequência montada também serve como indice para dizer como se chegar a folha. Exemplo: 1010 saimos da raiz "" depois vamos para Direita > Esquerda > Direita > Esquerda.
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
