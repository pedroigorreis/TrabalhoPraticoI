//      ⏱ Data: 07/03/2022
//      ⚒ Autores: Pedro Igor Martins dos Reis & Hernane Veloso
//      ⛩ Curso: Engenharia de Computação / PUC Minas 2022
//      ⛺ Disciplina: Algoritmos e Estruturas de Dados III

#ifndef BIBLIOTECAS_H
#define BIBLIOTECAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Bibliotecas necessárias para o funcionamento do programa.

#define AZUL     "\033[0;34m"
#define ROSA     "\033[0;35m"
#define PRETO    "\033[0;30m"
#define VERDE    "\033[0;32m"
#define CIANO    "\033[0;36m"
#define BRANCO   "\033[0;37m"
#define AMARELO  "\033[0;33m"
#define VERMELHO "\033[0;31m"
#define NEGRITO  "\033[1m"
#define CONVENCIONAL "\033[22m"
// Definição de cores e estilo de escrita para impresssão.

typedef struct Conta
{
    int idConta;
    float saldo;
    char CPF[12];
    char cidade[31];
    char nomePessoa[31];
    unsigned int transferenciasRealizadas;
}
Conta;
// Estrutura conta para gerenciamento.

void imprimirContas();
void imprimirConta(Conta C);
void imprimirMenuPrincipal();

void sacar();
void depositar();
void criarConta();
void buscaAvulsa();
void deletarConta();
void atualizarConta();
void realizarTransferencia();
int buscarContaTradicional(int id);

void removerIndice(int id);
int buscaBinariaPorID(int ID);
void adicionarIndices(int id, long posicaoNoArquivo);

int verificarListaInvertida(char *origemArquivo);
long buscarPosicaoListaInvertida(char *info,FILE *arquivo);
void removerDadosListaInvertida(int id,char *origemArquivo);
void buscarDadosListaInvertida(char *info,char *origemArquivo);
void adicionarDadosListaInvertida(int id,char *info,char *origemArquivo);
void atualizarDadosListaInvertida(int id,char *infoOriginal, char *infoNova,char *origemArquivo);

#endif
