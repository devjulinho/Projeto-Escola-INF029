#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

typedef struct estrutura{
    int * ptr_vetor[TAM];
    int totalCasas[TAM];
    int cont[TAM];
}posicoesGestao;

struct estrutura vetor;

int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 
*/

void inicializar(){
    for(int i = 0; i < TAM; i++){
        vetor.ptr_vetor[i] = NULL;
        vetor.totalCasas[i] = -1;
        vetor.cont[i] = -1;
    }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar(){
    for(int i = 0; i < TAM; i++){
        free(vetor.ptr_vetor[i]);
    }
}

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Retorno (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/

int criarEstruturaAuxiliar(int posicao, int tamanho){
    int retorno = 0;
    
    if(posicao < 1 || posicao > TAM)
    {
        // se posição é um valor válido {entre 1 e 10}
        retorno = POSICAO_INVALIDA;
    }
    
    else if(vetor.totalCasas[posicao - 1] != -1)
    {
    // a posicao pode já existir estrutura auxiliar
        retorno = JA_TEM_ESTRUTURA_AUXILIAR;
    }

    else if(tamanho < 1)
    {
        // o tamanho nao pode ser menor que 1
        retorno = TAMANHO_INVALIDO;
    }

    else{
        vetor.ptr_vetor[posicao - 1] = malloc(tamanho * sizeof(int));
        
        if(vetor.ptr_vetor[posicao - 1] == NULL)
        {
            // o tamanho ser muito grande
            retorno = SEM_ESPACO_DE_MEMORIA;
        }
    
        else
        {
            // deu tudo certo, crie
            vetor.totalCasas[posicao - 1] = tamanho;
            vetor.cont[posicao - 1] = 0;
            retorno = SUCESSO;
        }
    }

    return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Retorno (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor){
    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;

    if (posicao < 1 || posicao > 10)
        posicao_invalida = 1;

    if (posicao_invalida)
        retorno = POSICAO_INVALIDA;
        
    else{
        if(vetor.cont[posicao -1] != -1)
            existeEstruturaAuxiliar = 1;
        
        // testar se existe a estrutura auxiliar
        if (existeEstruturaAuxiliar){
            if(vetor.totalCasas[posicao - 1] > vetor.cont[posicao - 1])
                temEspaco = 1;
            
            if (temEspaco)
            {
                vetor.ptr_vetor[posicao - 1][vetor.cont[posicao - 1]] = valor;
                vetor.cont[posicao - 1]++;
                //insere
                retorno = SUCESSO;
            }
            else
            {
                retorno = SEM_ESPACO;
            }
        }
            
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Retorno (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    int retorno = 0;
    
    if (posicao < 1 || posicao > 10)
        retorno = POSICAO_INVALIDA;

    else if(vetor.cont[posicao - 1] == -1)
        retorno = SEM_ESTRUTURA_AUXILIAR;

    else if(vetor.cont[posicao - 1] == 0)
        retorno = ESTRUTURA_AUXILIAR_VAZIA;

    else{
        vetor.cont[posicao - 1]--;
        retorno = SUCESSO;
    }
        
    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    {
        int retorno = 0;

        if (posicao < 1 || posicao > 10)
            retorno = POSICAO_INVALIDA;

        else if(vetor.cont[posicao - 1] == -1)
            retorno = SEM_ESTRUTURA_AUXILIAR;

        else if(vetor.cont[posicao - 1] == 0)
            retorno = ESTRUTURA_AUXILIAR_VAZIA;

        else{
            int flag = -1;
            
            for (int i = 0; i < vetor.cont[posicao - 1]; i++){
                if (vetor.ptr_vetor[posicao - 1][i] == valor)
                    flag = i;
            }
            
            if (flag == -1)
                retorno = NUMERO_INEXISTENTE;

            else{
                for (int i = flag; i < vetor.cont[posicao - 1]; i++)
                    vetor.ptr_vetor[posicao - 1][i] = vetor.ptr_vetor[posicao - 1][i + 1];
                    
                vetor.cont[posicao - 1]--;
                retorno = SUCESSO;
            }
        }

        return retorno;
    }
}

// // se posição é um valor válido {entre 1 e 10}
// int ehPosicaoValida(int posicao)
// {
//     int retorno = 0;
//     if (posicao < 1 || posicao > 10)
//     {
//         retorno = POSICAO_INVALIDA;
//     }
//     else
//         retorno = SUCESSO;

//     return retorno;
// }
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int retorno = 0;

    if (posicao < 1 || posicao > 10)
        retorno = POSICAO_INVALIDA;

    else if(vetor.cont[posicao - 1] == -1)
        retorno = SEM_ESTRUTURA_AUXILIAR;

    else if(vetor.cont[posicao - 1] == 0)
        retorno = ESTRUTURA_AUXILIAR_VAZIA;

    else{
        for (int i = 0; i < vetor.cont[posicao - 1]; i++)
            vetorAux[i] = vetor.ptr_vetor[posicao - 1][i];
        
        retorno = SUCESSO;
    }
    
    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int retorno = 0;
    int auxiliar;
    int trocou = 0;
    int contador = 0;
    
    if (posicao < 1 || posicao > 10)
        retorno = POSICAO_INVALIDA;

    else if(vetor.cont[posicao - 1] == -1)
        retorno = SEM_ESTRUTURA_AUXILIAR;

    else if(vetor.cont[posicao - 1] == 0)
        retorno = ESTRUTURA_AUXILIAR_VAZIA;

    else{
        trocou = 1;
        for (int i = 0; i < vetor.cont[posicao - 1]; i++){
            vetorAux[i] = vetor.ptr_vetor[posicao - 1][i];
            contador++;
        }
    }
        
        if (trocou == 1){
            for (int k = 0; k < contador; k++)
                for(int j = k; j < contador; j++){
                    if(vetorAux[k] > vetorAux[j]){
                        auxiliar = vetorAux[k];
                        vetorAux[k] = vetorAux[j];
                        vetorAux[j] = auxiliar;
                    }
                }
            retorno = SUCESSO;
        }

    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{   
    int retorno = 0;
    int contador = 0;

    for (int i = 0; i < TAM; i++){
        for(int j = 0; j < vetor.cont[i]; j++){
            vetorAux[contador] = vetor.ptr_vetor[i][j];
            contador++;
        }
    }

    if (contador == 0)
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    else
        retorno = SUCESSO;
                
    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int retorno = 0;

    int contador = 0;

    for (int i = 0; i < TAM; i++){
        for(int j = 0; j < vetor.cont[i]; j++){
            vetorAux[contador] = vetor.ptr_vetor[i][j];
            contador++;
        }
    }

    if (contador == 0)
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    else
        retorno = SUCESSO;

    if (retorno == SUCESSO){
        int auxiliar;
        for (int k = 0; k < contador; k++){
            for(int j = k; j < contador; j++){
                if(vetorAux[k] > vetorAux[j]){
                    auxiliar = vetorAux[k];
                    vetorAux[k] = vetorAux[j];
                    vetorAux[j] = auxiliar;
                }
            }
        }
    }
    
    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    xSEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    xPOSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    xNOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{

    int retorno = 0;
    
    if (posicao < 1 || posicao > 10){
        retorno = POSICAO_INVALIDA;
    }

    else if((vetor.totalCasas[posicao - 1] + novoTamanho) < 1){
        retorno = NOVO_TAMANHO_INVALIDO;
    }

    else if(vetor.totalCasas[posicao-1] == -1){
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }

    else{

        vetor.ptr_vetor[posicao - 1] = realloc(vetor.ptr_vetor[posicao - 1], (vetor.totalCasas[posicao - 1] + novoTamanho) * sizeof(int));

        if (vetor.ptr_vetor[posicao - 1] == NULL)
            retorno = SEM_ESPACO_DE_MEMORIA;
        else{
            vetor.totalCasas[posicao - 1] += novoTamanho;

            if (vetor.totalCasas[posicao - 1] < vetor.cont[posicao - 1])
                vetor.cont[posicao - 1] = vetor.totalCasas[posicao - 1];
            
            retorno = SUCESSO;
        }    
    }
    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    
    int retorno = 0;

    if(posicao < 1 || posicao > 10)
        retorno = POSICAO_INVALIDA;

    else if (vetor.totalCasas[posicao - 1] == -1)
        retorno = SEM_ESTRUTURA_AUXILIAR;

    else if (vetor.cont[posicao - 1] == 0)
        retorno = ESTRUTURA_AUXILIAR_VAZIA;

    else
        retorno = vetor.cont[posicao - 1];

    return retorno;
}

void inserirElementoNaEstrutura(No * inicio, int valor){
    No * novo = (No *) malloc(sizeof(No));
    novo -> conteudo = valor;
    novo -> prox = NULL;

    No * atual = inicio;
    
    while(atual -> prox != NULL){
        atual = atual -> prox;
    }

    atual -> prox = novo;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{
    No *inicio = (No*) malloc(sizeof(No));
    inicio->prox = NULL;

    for (int i = 0; i < TAM; i++){
        for(int j = 0; j < vetor.cont[i]; j++){
            inserirElementoNaEstrutura(inicio, vetor.ptr_vetor[i][j]);
        }
    }

    if (inicio->prox == NULL)
        return NULL;
    else
        return inicio;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
    No *atual = inicio->prox;
    int i = 0;
    
    while(atual != NULL){
        vetorAux[i] = atual -> conteudo;
        i++;
        atual = atual -> prox;
    }

    free(atual);
    
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
    No * atual;
    No * proximo;

    atual = *inicio;
    
    while(atual != NULL){
        proximo = atual -> prox;
        free(atual);
        atual = proximo;
    }

    *inicio = NULL;
    
}