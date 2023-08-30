#include <stdio.h>

#define MAX_ALUNO 3
#define MAX_PROFESSOR 3
#define MAX_DISCIPLINA 3

typedef struct aluno{
  int matricula;
  char nome;
  char sexo;
  char nascimento;
  char CPF;
}Aluno;

int main(void){
  Aluno Aluno[MAX_ALUNO], Professor[MAX_PROFESSOR];
  int qtdAluno = 0;
  int opcao;
  int sair = 0;

  // Menu inicial
  while (!sair){
  printf("Projeto Escola\n");
  printf("0- Sair\n");
  printf("1- Aluno\n");
  printf("2- Professor\n");
  printf("3- Disciplina\n");
  
  scanf("%d", &opcao);

    // Switch do menu inicial
  switch(opcao){
    case 0:{
      printf("Saindo do sistema\n");
      sair = 1;
      break;}

    // MENU ALUNO
    case 1:{
      printf("Modulo - Aluno\n");
      int sairAluno = 0;
      int opcaoAluno;
      while(!sairAluno){
        printf("0 - Voltar\n");
        printf("1 - Cadastrar Aluno\n");
        printf("2 - Listar Aluno\n");
        printf("3 - Atualizar Aluno\n");
        printf("4 - Excluir Aluno\n");
        
        scanf("%d", &opcaoAluno);

        switch (opcaoAluno){
          case 0:{
            sairAluno = 1;
            printf("Retornando ao menu inicial\n");
            break;
          }

          case 1:{
            printf("Cadastrar Aluno\n");
            if (qtdAluno == MAX_ALUNO){
              printf("Lista de alunos cheia");}
            else{
              printf("Digite a matricula\n");
              int matricula;
              scanf("%d", &matricula);
              if (matricula < 0){
                printf("Matrícula Inválida");}
              else{
                Aluno[qtdAluno].matricula = matricula;
                qtdAluno++;
                printf("Matrícula realizada com sucesso");
              }
            }
          break;
          }

          case 2:{
            printf("Listar Aluno\n");
            if (qtdAluno == 0)
              printf("Lista vazia\n");
            else{
              for (int i = 0; i < qtdAluno; i++){
                printf("Matrícula: %d\n", Aluno[i].matricula);
              }}
            break;
          }

          case 3:{
            printf("Atualizar Aluno\n");
            break;
          }

          case 4:{
            printf("Excluir Aluno\n");
            break;
          }
          
        }
      }
      break;
      }
    
    case 2:{
      printf("Modulo - Professor\n");
      break;}
    
    case 3:{
      printf("Modulo - Disciplina\n");
      break;}
    
    default:{
      printf("Opcao invalida\n");}
    }
  }
}