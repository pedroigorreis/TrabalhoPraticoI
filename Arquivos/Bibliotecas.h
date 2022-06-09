//      ⏱ Data: 07/03/2022
//      ⚒ Autores: Pedro Igor Martins dos Reis & Hernane Veloso
//      ⛩ Curso: Engenharia de Computação / PUC Minas 2022
//      ⛺ Disciplina: Algoritmos e Estruturas de Dados III

#ifndef BIBLIOTECAS_H
#define BIBLIOTECAS_H

// Bibliotecas necessárias para o funcionamento do programa.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição de cores e estilo de escrita para impressão.
#define AZUL            "\033[0;34m"
#define ROSA            "\033[0;35m"
#define PRETO           "\033[0;30m"
#define VERDE           "\033[0;32m"
#define CIANO           "\033[0;36m"
#define BRANCO          "\033[0;37m"
#define AMARELO         "\033[0;33m"
#define VERMELHO        "\033[0;31m"
#define NEGRITO         "\033[1m"
#define CONVENCIONAL    "\033[22m"

#define BITS_DICIONARIO         12
#define CODIGO_FIM              0xffff
#define MAXIMO_BITS_DICIONARIO  (1 << BITS_DICIONARIO)

// Estrutura conta para gerenciamento.
typedef struct Conta
{
    int idConta;
    float saldo;
    char CPF[14];
    char cidade[40];
    char nomePessoa[40];
    unsigned int transferenciasRealizadas;
}
Conta;

typedef struct NoDicionario
{
    u_int16_t folha[256];
}
NoDicionario;

typedef struct EntradaDicionario
{
    int tamanho;
    u_int8_t *sequencia;
}
EntradaDicionario;

typedef struct AlocaInformacoes
{
    int comprimentoSequencia;
    u_int8_t *base;
    u_int8_t *proximaAlocacao;
}
AlocaInformacoes;

typedef struct EstadoDaLeitura
{
    FILE *arquivo;
    int bitsRemanecentes;
    int codigoRemanecente;
}
EstadoDaLeitura;

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
int  buscarContaTradicional(int id);

void removerIndice(int id);
int  buscaBinariaPorID(int ID);
void adicionarIndices(int id, long posicaoNoArquivo);

int  verificarListaInvertida(char *origemArquivo);
long buscarPosicaoListaInvertida(char *info,FILE *arquivo);
void removerDadosListaInvertida(int id,char *origemArquivo);
void buscarDadosListaInvertida(char *info,char *origemArquivo);
void adicionarDadosListaInvertida(int id,char *info,char *origemArquivo);
void atualizarDadosListaInvertida(int id,char *infoOriginal, char *infoNova,char *origemArquivo);

void criptografiaXOR(char *stringOriginal);

void compressaoLZW();
void descompressaoLZW();
int lerProximoCodigo(EstadoDaLeitura *EL);
u_int8_t *Alocar(AlocaInformacoes *AI, int comprimento);
void inicializarAlocacao(AlocaInformacoes *AI, int tamanho);


#endif
