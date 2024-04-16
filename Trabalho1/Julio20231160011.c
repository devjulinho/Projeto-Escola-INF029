// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Júlio Santos de Brito
//  email: julio01.brito@gmail.com
//  Matrícula: 20231160011
//  Semestre: 2024.1

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "Julio20231160011.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>

// FUNCOES
int somar(int x, int y){
    int soma;
    soma = x + y;
    return soma;
}
int fatorial(int x){ //função utilizada para testes
  int i, fat = 1;

  for (i = x; i > 1; i--)
    fat = fat * i;

  return fat;
}
int teste(int a){
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
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
int anobissexto(int ano){
  if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 4 == 0 && ano % 400 == 0))
    return 1;
  else
    return 0;
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

int q1(char data[]){
  int datavalida = 1;
  int ano;
  int anobis;

  DataQuebrada dq = quebraData(data);

  if (dq.iMes == 1 || dq.iMes == 3 || dq.iMes == 5 || dq.iMes == 7 || dq.iMes == 8 || dq.iMes == 10 || dq.iMes == 12){
    if (dq.iDia > 31 || dq.iDia < 1)
      datavalida = 0;
  }

  if (dq.iMes == 4 || dq.iMes == 6 || dq.iMes == 9|| dq.iMes == 11){
    if (dq.iDia > 30 || dq.iDia < 1)
      datavalida = 0;
  }

  if (dq.iMes > 12 || dq.iMes < 1)
    datavalida = 0;

  ano = dq.iAno;
  
  //conferência de ano bissexto - como somar um inteiro na struct e um inteiro
  if (dq.iAno >= 0 && dq.iAno <= 40){
    ano = ano + 2000;
  } else if (dq.iAno >= 40 && dq.iAno <= 99){
    ano = ano + 1900;
  }
  
  anobis = anobissexto(ano);

  // CORRIGIR AQUI QUANDO O MÊS É IGUAL A 2 !!!!!
  if (dq.iMes == 2){
    if (anobis == 1 && (dq.iDia > 29 || dq.iDia < 1))
      datavalida = 0;
    else if (anobis == 0 && (dq.iDia > 28 || dq.iDia < 1))
      datavalida = 0;
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

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{
      //verifique se a data final não é menor que a data inicial

      //calcule a distancia entre as datas


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
int q3(char *texto, char c, int isCaseSensitive){
  int qtdOcorrencias = 0;

  if (isCaseSensitive == 1){
    for (int i = 0; texto[i] != '\0'; i++){
      if (texto[i] == c)
        qtdOcorrencias++;
    }
  }
    
  else{
    char aux = c;
    
    if (c >= 'A' && c <= 'Z'){
      aux += 32;
    }

    else if(c >= 'a' && c <= 'z'){
      aux -= 32;
    }
    
    for (int i = 0; texto[i] != '\0'; i++){
      if(texto[i] == c || texto[i] == aux)
        qtdOcorrencias++;
    }
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
int q4(char *strTexto, char *strBusca, int posicoes[30]){
  
  int qtdOcorrencias = 0;
  

  

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

int q5(int num){

  int quociente;
  int soma = 0;
  int divisor = 1;
  int divisor2;
  int lista[100];
  int cont = 0;

  while (quociente >= 0){
    quociente = num % divisor;
    divisor *= 10;
  }

  divisor /= 10;

  divisor2 = divisor;

  while (divisor != 1){
    lista[cont] = num % divisor;
    cont++;
    divisor /= 10;
  }

  cont--;
  
  while (cont <= 0){
    soma = soma + (lista[cont] * divisor2);
    divisor2 /= 10;
  }
  
  num = soma;

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
    int qtdOcorrencias;
    return qtdOcorrencias;
}