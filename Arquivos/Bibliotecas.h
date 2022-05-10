#ifndef BIBLIOTECAS_H
#define BIBLIOTECAS_H

#include <stdio.h>
#include <stdlib.h>
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

void criarConta();
void depositar();
int buscarConta(int id);
void atualizarConta(Conta C);
void realizarTransferencia(Conta A, Conta B, float valor);

#endif
