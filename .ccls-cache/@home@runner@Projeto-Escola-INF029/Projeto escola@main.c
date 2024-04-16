#include <stdio.h>

#define MAX_ALUNO 3
#define MAX_PROFESSOR 3
#define MAX_DISCIPLINA 3
#define TAM 100

typedef struct aluno{
  int matricula;
  char nome;
  char sexo;
  char nascimento;
  char CPF;
  int ativo;
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
  // PONTO PARA REVISAR: COMO BLOQUEAR O CADASTRO ANTES DA PESSOA PRECISAR PREENCHER TODAS AS PERGUNTAS

  // PONTO PARA REVISAR: COMO BLOQUEAR O CADASTRO CASO A MATRÍCULA JÁ EXISTA
            case 1:{
              printf("Cadastrar Aluno\n");
              if (qtdAluno == MAX_ALUNO){
                printf("Lista de alunos cheia\n");}
              else{
                int matricula;
                char nome;
                char sexo;
                char nascimento;
                char CPF;
                int ativo;
                printf("Digite a matricula\n");
                scanf("%d", &matricula);
                printf("Digite o nome completo\n");
                scanf("%TAM[^\n]", &nome);
                printf("Digite a data de nascimento\n");
                scanf("%s", &nascimento);
                printf("Digite o seu CPF (Cadastro de Pessoa Física)\n");
                scanf("%s", &CPF);
                printf("Matrícula está ativa? (0- Não / 1- Sim)\n");
                scanf("%d", &ativo);                
                if (matricula < 0){
                  printf("Matrícula Inválida\n");}
                else{
                  Aluno[qtdAluno].matricula = matricula;
                  Aluno[qtdAluno].nome = nome;
                  Aluno[qtdAluno].sexo = sexo;
                  Aluno[qtdAluno].nascimento = nascimento;
                  Aluno[qtdAluno].CPF = CPF;
                  Aluno[qtdAluno].ativo = ativo;
                  qtdAluno++;
                  printf("Matrícula realizada com sucesso\n");
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
                  printf("Nome: %s\n", Aluno[i].nome);
                  printf("Sexo: %s\n", Aluno[i].sexo);
                  printf("Data de nascimento: %s\n", Aluno[i].nascimento);
                  printf("CPF: %s\n", Aluno[i].CPF);
                  if (Aluno[i].ativo == 1)
                    printf("Matrícula ativa\n\n");
                  else
                    printf("Matrícula inativa\n\n");
                }
              }
              break;
            }

            /// PAREI AQUI
            
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
        break;
      }
      
      case 3:{
        printf("Modulo - Disciplina\n");
        break;
      }
      
      default:{
        printf("Opcao invalida\n");
      }
    }
  }
}