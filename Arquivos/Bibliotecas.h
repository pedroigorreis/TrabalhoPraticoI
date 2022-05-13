#ifndef BIBLIOTECAS_H
#define BIBLIOTECAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void deletarConta();
void atualizarConta();
void realizarTransferencia();
int buscarContaTradicional(int id);

void removerIndice(int id);
int buscaBinariaPorID(int ID);
void adicionarIndices(int id, long posicaoNoArquivo);

#endif
