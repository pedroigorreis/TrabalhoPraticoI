#ifndef BIBLIOTECAS_H
#define BIBLIOTECAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NEGRITO  "\033[1m"
#define CONVENCIONAL "\033[22m"

#define AZUL     "\033[0;34m"
#define ROSA     "\033[0;35m"
#define PRETO    "\033[0;30m"
#define VERDE    "\033[0;32m"
#define CIANO    "\033[0;36m"
#define BRANCO   "\033[0;37m"
#define AMARELO  "\033[0;33m"
#define VERMELHO "\033[0;31m"

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

#endif
