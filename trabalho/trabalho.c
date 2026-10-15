// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: 
//  email: 
//  Matrícula:
//  Semestre:

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016 - 17/10/2025

// #################################################

#include <stdio.h>
#include "trabalho.h" 
#include <stdlib.h>

#define TAM_DATA 12
#define TAM_DIA 3
#define TAM_MES 3
#define TAM_ANO 5

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
  int datavalida = 1;

  //quebrar a string data em strings sDia, sMes, sAno
	char sDia[TAM_DIA];
	char sMes[TAM_MES];
	char sAno[TAM_ANO];
	
	int i = 0;
	int j = 0; 
	while (data[i] != '/' && data[i] != '\0'){
	sDia[j] = data[i];
		i++;
		j++;
	}
	sDia[j] = '\0';
	i = i + 1;
	
	int k = 0;
	while (data[i] != '/' && data[i] != '\0'){
	sMes[k] = data[i];
	i++;
	k++;
	}
	sMes[k] = '\0';
	i = i + 1;
	
	int l = 0;
	while (data[i] != '\0'){
	sAno[l] = data[i];
	i++;
	l++;
	}
	sAno[l] = '\0';
	
	int dia = atoi(sDia);
	int mes = atoi(sMes);
	int ano = atoi(sAno);
	
		if (mes >= 1 && mes <= 12) {
		
		if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
			if (dia >= 1 && dia <= 31){
				datavalida = 1;
			} else {
				datavalida = 0;
			}
		} else if (mes == 4 || mes == 6 || mes == 9 || mes == 11){
			if (dia >= 1 && dia <= 30){
				datavalida = 1;
			} else {
				datavalida = 0;
			}
		} else if (mes == 2) {
			// Verifica se o ano é bissexto
			if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
				if (dia >= 1 && dia <= 29) {
					datavalida = 1;
				} else {
					datavalida = 0;
				}
			} else { 
				// Ano NÃO bissexto
				if (dia >= 1 && dia <= 28) {
					datavalida = 1;
				} else {
					datavalida = 0;
				}
			}
		}

	} else {
		datavalida = 0; // Mês inválido
	}
	
	if (datavalida)
      return 1;
  else
      return 0;
	
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;

	 DiasMesesAnos dma;
    dma.qtdDias = 0;
    dma.qtdMeses = 0;
    dma.qtdAnos = 0;

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{
      //verifique se a data final não é menor que a data inicial
        
        int diaInicial = (datainicial[0] - '0') * 10 + (datainicial[1] - '0');
        int mesInicial = (datainicial[3] - '0') * 10 + (datainicial[4] - '0');
        int anoInicial = (datainicial[6] - '0') * 1000 + (datainicial[7] - '0') * 100 + (datainicial[8] - '0') * 10 + (datainicial[9] - '0');

        int diaFinal = (datafinal[0] - '0') * 10 + (datafinal[1] - '0');
        int mesFinal = (datafinal[3] - '0') * 10 + (datafinal[4] - '0');
        int anoFinal = (datafinal[6] - '0') * 1000 + (datafinal[7] - '0') * 100 + (datafinal[8] - '0') * 10 + (datafinal[9] - '0');

        //verifique se a data final não é menor que a data inicial
        if (anoInicial > anoFinal) {
            dma.retorno = 4;
            return dma;
        } 
        else if ((anoInicial == anoFinal) && (mesInicial > mesFinal)) {
            dma.retorno = 4;
            return dma;
        } 
        else if ((anoInicial == anoFinal) && (mesInicial == mesFinal)) {
            if (diaInicial > diaFinal) {
                dma.retorno = 4;
                return dma;
            }
        }
      //calcule a distancia entre as datas
		 if (diaFinal < diaInicial) {
            int mesAnterior = mesFinal - 1;
            int anoDoMesAnterior = anoFinal;
            
            
            if (mesAnterior == 0) {
                mesAnterior = 12;
                anoDoMesAnterior--;
            }

            
            int diasMesAnterior = 31;
            if (mesAnterior == 4 || mesAnterior == 6 || mesAnterior == 9 || mesAnterior == 11) {
                diasMesAnterior = 30;
            } else if (mesAnterior == 2) {
                // Verifica bissexto para fevereiro
                if ((anoDoMesAnterior % 4 == 0 && anoDoMesAnterior % 100 != 0) || (anoDoMesAnterior % 400 == 0)) {
                    diasMesAnterior = 29;
                } else {
                    diasMesAnterior = 28;
                }
            }

            diaFinal = diaFinal + diasMesAnterior;
            mesFinal--; 
        }
        dma.qtdDias = diaFinal - diaInicial;

   
        if (mesFinal < mesInicial) {
            mesFinal = mesFinal + 12;
            anoFinal--; 
        }
        dma.qtdMeses = mesFinal - mesInicial;

       
        dma.qtdAnos = anoFinal - anoInicial;


      //se tudo der certo
      dma.retorno = 1;
      return dma;
      
    }
    
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;
	char auxC = c;
	char letraAtual;
	
	
	if(isCaseSensitive != 1){
		if(auxC >= 'a' && auxC <= 'z'){
				auxC = auxC - 32;
		}
	}
	
	int i = 0;
	while(texto[i] != '\0'){
		
		if(isCaseSensitive == 1){
			if(texto[i] == auxC){
			qtdOcorrencias++;
		}
	} else {
		
		letraAtual = texto[i];
		
		if (letraAtual >= 'a' && letraAtual <= 'z') {	
		letraAtual = letraAtual - 32;
		}
		if(letraAtual == auxC){
			qtdOcorrencias++;
			}
		}

	i++;
}

	return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    char textoSem61[500];
	char buscaSem61[100];
	
	int k = 0;
	for(int i = 0; strTexto[i] != '\0'; i++){
		if(strTexto[i] != -61){
			textoSem61[k] = strTexto[i];
			k++;
		}
	}
	textoSem61[k] = '\0';
	
	k = 0;
	for(int i = 0; strBusca[i] != '\0'; i++){
		if(strBusca[i] != -61){
		buscaSem61[k] = strBusca[i];
		k++;
		}
	}
	buscaSem61[k] = '\0';
	
    int qtdOcorrencias = 0;
    int tamBusca = 0;
    int encontrou = 0;
    
    while (buscaSem61[tamBusca] != '\0') {
        tamBusca++;
    }
    if (tamBusca == 0) {
        return 0;
    }
    
    for(int i = 0; textoSem61[i] != '\0'; i++){
    	encontrou = 1;
    	for(int j = 0; j < tamBusca; j++){
    		if(textoSem61[i + j] == '\0' || textoSem61[i + j] != buscaSem61[j]){
    			 encontrou = 0;
    			 break;
			}	
		}
		if(encontrou == 1){
			posicoes[2 * qtdOcorrencias] = i + 1;
			posicoes[2 * qtdOcorrencias + 1] = i + tamBusca;
			qtdOcorrencias++;
			}
	}
    

    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
    int numInvertido = 0;
	int digito;
	
	while (num > 0){
		
	digito = num % 10;
	num = num / 10;
	numInvertido = (numInvertido * 10) + digito;
	}

	num = numInvertido;
    	
    return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias = 0;
    int tamBusca = 0;
    int auxBusca = numerobusca;

    //tamanho do numero de busca
    while(auxBusca != 0){
    	auxBusca = auxBusca / 10;
    	tamBusca++;
	}
    
	int divisor = 1;
	for(int i = 0; i < tamBusca; i++){
		divisor = divisor * 10;
		}
	 
	int digito;
	while(numerobase >= numerobusca){
	digito = numerobase % divisor;
	if(digito == numerobusca){
		qtdOcorrencias++;
	}
	numerobase = numerobase / 10;
	}
    return qtdOcorrencias;
}

/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 */

 int q7(char matriz[8][10], char palavra[5])
 {
     int achou;
     return achou;
 }



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}

