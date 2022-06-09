//      ⏱ Data: 07/03/2022
//      ⚒ Autores: Pedro Igor Martins dos Reis & Hernane Veloso
//      ⛩ Curso: Engenharia de Computação / PUC Minas 2022
//      ⛺ Disciplina: Algoritmos e Estruturas de Dados III

#include "Bibliotecas.h"

// Apenas imprime o menu principal e redireciona o usuário para a função requisitada, retorna 0.
int main(void)
{
    unsigned int inst = 0;
    system("clear");

    do
    {
        printf(BRANCO);
        imprimirMenuPrincipal();
        scanf("%u",&inst);
        fgetc(stdin);

        switch(inst)
        {
            case 1: { system("clear"); printf(AZUL);     criarConta();            break; }
            case 2: { system("clear"); printf(ROSA);     atualizarConta();        break; }
            case 3: { system("clear"); printf(VERDE);    realizarTransferencia(); break; }
            case 4: { system("clear"); printf(VERMELHO); deletarConta();          break; }
            case 6: { system("clear"); printf(CIANO);    buscaAvulsa();           break; }
            case 5: { system("clear"); printf(AMARELO);  imprimirContas();        break; }
            case 7: { system("clear"); printf(VERDE);    depositar();             break; }
            case 8: { system("clear"); printf(VERDE);    sacar();                 break; }
            case 9: {                                                             break; }
            default:{ system("clear"); printf("\n\t Erro, opção inválida.\n");    break; }

            // Protótipos
            case 10:{ system("clear"); printf(CIANO);    compressaoLZW();         break; }
            case 11:{ system("clear"); printf(CIANO);    descompressaoLZW();      break; }
        }
        printf(BRANCO);
    }
    while(inst != 9);
    return 0;
}
