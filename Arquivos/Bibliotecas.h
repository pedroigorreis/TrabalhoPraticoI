#ifndef BIBLIOTECAS_H
#define BIBLIOTECAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Conta
{
    float saldo;
    char CPF[12];
    char cidade[31];
    char nomePessoa[31];
    unsigned int idConta;
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
int buscarConta(int id);
void realizarTransferencia();

#endif
