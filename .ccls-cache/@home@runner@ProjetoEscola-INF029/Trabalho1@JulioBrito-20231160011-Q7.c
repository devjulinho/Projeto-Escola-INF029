//  ----- Dados do Aluno -----
//  Nome: Júlio Santos de Brito
//  email: julio01.brito@gmail.com
//  Matrícula: 20231160011
//  Semestre: 2024.1

#include <stdio.h>
#include <stdlib.h>

void imprimirJogo(char casas[]){
  printf("  %c  |  %c  |  %c  \n", casas[0], casas[1], casas[2]);
  printf("------------------\n");
  printf("  %c  |  %c  |  %c  \n", casas[3], casas[4], casas[5]);
  printf("------------------\n");
  printf("  %c  |  %c  |  %c  \n \n", casas[6], casas[7], casas[8]);
}

int fimJogo(char casas[]){
  //caso 1 - horizontal
  if ((casas[0] == 'X' && casas[1] == 'X' && casas[2] == 'X') || (casas[0] == 'O' && casas[1] == 'O' && casas[2] == 'O')){
    printf("Vitória do Jogador: --> %c <--\n", casas[0]);
    return 1;
  }

  //caso 2 - horizontal
  if ((casas[3] == 'X' && casas[4] == 'X' && casas[5] == 'X') || (casas[3] == 'O' && casas[4] == 'O' && casas[5] == 'O')){
    printf("Vitória do Jogador: --> %c <--\n", casas[3]);
    return 1;
  }

   //caso 3 - horizontal
  if ((casas[6] == 'X' && casas[7] == 'X' && casas[8] == 'X') || (casas[6] == 'O' && casas[7] == 'O' && casas[8] == 'O')){
    printf("Vitória do Jogador: --> %c <--\n", casas[6]);
    return 1;
  }

   //caso 4 - vertical
  if ((casas[0] == 'X' && casas[3] == 'X' && casas[6] == 'X') || (casas[0] == 'O' && casas[3] == 'O' && casas[6] == 'O')){
    printf("Vitória do Jogador: --> %c <--\n", casas[0]);
    return 1;
  }

   //caso 5 - vertical
  if ((casas[1] == 'X' && casas[4] == 'X' && casas[7] == 'X') || (casas[1] == 'O' && casas[4] == 'O' && casas[7] == 'O')){
    printf("Vitória do Jogador: --> %c <--\n", casas[1]);
    return 1;
  }

   //caso 6 - vertical
  if ((casas[2] == 'X' && casas[5] == 'X' && casas[8] == 'X') || (casas[2] == 'O' && casas[5] == 'O' && casas[8] == 'O')){
    printf("Vitória do Jogador: --> %c <--\n", casas[2]);
    return 1;
  }

   //caso 7 - diagonal
  if ((casas[0] == 'X' && casas[4] == 'X' && casas[8] == 'X') || (casas[0] == 'O' && casas[4] == 'O' && casas[8] == 'O')){
    printf("Vitória do Jogador: --> %c <--\n", casas[0]);
    return 1;
  }

   //caso 8 - diagonal
  if ((casas[2] == 'X' && casas[4] == 'X' && casas[6] == 'X') || (casas[2] == 'O' && casas[4] == 'O' && casas[6] == 'O')){
    printf("Vitória do Jogador: --> %c <--\n", casas[2]);
    return 1;
  }

  if (
    ((casas[0] == 'X') || (casas[0] == 'O')) &&
    ((casas[1] == 'X') || (casas[1] == 'O')) &&
    ((casas[2] == 'X') || (casas[2] == 'O')) && 
    ((casas[3] == 'X') || (casas[3] == 'O')) && 
    ((casas[4] == 'X') || (casas[4] == 'O')) && 
    ((casas[5] == 'X') || (casas[5] == 'O')) && 
    ((casas[6] == 'X') || (casas[6] == 'O')) && 
    ((casas[7] == 'X') || (casas[7] == 'O')) && 
    ((casas[8] == 'X') || (casas[8] == 'O'))){
    printf("------> EMPATE <------\n");
    printf("Vocês podem jogar novamente!!!\n");
    return 1;
  }

  return 0;
  
}

int main(){
  char casas[10];
  int i = 0;
  int iniciar = 1;
  char jogadores[3];
  int fimJogoInt = 0;
  char escolha[2];

  // iniciando casas
  while(i < 9){
    casas[i] = 'a' + i;
    i++;
  }
  casas[9] = '\0';

  //iniciando jogadores
  i = 0;
  while(i < 2){
    jogadores[i] = 'A';
    i++;
  }
  jogadores[2] = '\0';
  
  printf("----> INF029: JOGO DA VELHA - v0.2 <----\n");
  printf("--------> Júlio Brito <--------\n \n");
  
  while(iniciar == 1){
    printf("Digite 1 para iniciar o jogo:\n");
    scanf("%d", &iniciar);
    getchar();
    printf("\n");

    if (iniciar != 1)
      break;
    
    printf("Jogador 1, escolha X ou O:\n");
    scanf("%c", &jogadores[0]);
    getchar();
    while (jogadores[0] != 'X' && jogadores[0] != 'x' && jogadores[0] != 'O' && jogadores[0] != 'o'){
      printf("Opa, essa opção não está dentro das alternativas. Você escolhe X ou O?\n");
      scanf("%c", &jogadores[1]);
      getchar();
    }
    
    if (jogadores [0] == 'X' || jogadores [0] == 'x'){
      if (jogadores [0] == 'x')
        jogadores [0] = 'X';
      jogadores[1] = 'O';
    }

    if (jogadores [0] == 'O' || jogadores [0] == 'o'){
      if (jogadores [0] == 'o')
        jogadores [0] = 'O';
      jogadores[1] = 'X';
    }

    while(!fimJogoInt){
      printf("Vez do Jogador 1 (%c)\n \n", jogadores[0]);
      imprimirJogo(casas);
      scanf("%c", &escolha[0]);
      getchar();

      if(escolha[0] == 'a')
        casas[0] = jogadores[0];
      if(escolha[0] == 'b')
        casas[1] = jogadores[0];
      if(escolha[0] == 'c')
        casas[2] = jogadores[0];
      if(escolha[0] == 'd')
        casas[3] = jogadores[0];
      if(escolha[0] == 'e')
        casas[4] = jogadores[0];
      if(escolha[0] == 'f')
        casas[5] = jogadores[0];
      if(escolha[0] == 'g')
        casas[6] = jogadores[0];
      if(escolha[0] == 'h')
        casas[7] = jogadores[0];
      if(escolha[0] == 'i')
        casas[8] = jogadores[0];

      fimJogoInt = fimJogo(casas);
      if (fimJogoInt == 1)
        break;
      
      printf("Vez do Jogador 2 (%c)\n \n", jogadores[1]);
      imprimirJogo(casas);
      scanf("%c", &escolha[0]);
      getchar();

      if(escolha[0] == 'a')
        casas[0] = jogadores[1];
      if(escolha[0] == 'b')
        casas[1] = jogadores[1];
      if(escolha[0] == 'c')
        casas[2] = jogadores[1];
      if(escolha[0] == 'd')
        casas[3] = jogadores[1];
      if(escolha[0] == 'e')
        casas[4] = jogadores[1];
      if(escolha[0] == 'f')
        casas[5] = jogadores[1];
      if(escolha[0] == 'g')
        casas[6] = jogadores[1];
      if(escolha[0] == 'h')
        casas[7] = jogadores[1];
      if(escolha[0] == 'i')
        casas[8] = jogadores[1];

      fimJogoInt = fimJogo(casas);
      if (fimJogoInt == 1)
        break;
      
    }
    

  }

  if (iniciar != 1)
    printf("Encerrando o jogo!\n");
  
}