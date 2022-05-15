#include "Bibliotecas.h"

int main(void)
{
    system("clear");
    int inst = -1;

    do
    {
        printf(CIANO);
        imprimirMenuPrincipal();
        printf(BRANCO);
        scanf("%d", &inst);
        fgetc(stdin);

        switch(inst)
        {
            case 1: { system("clear"); printf(AZUL);    criarConta();           break; }
            case 2: { system("clear"); printf(ROSA);    atualizarConta();       break; }
            case 3: { system("clear"); printf(VERDE);   realizarTransferencia();break; }
            case 4: { system("clear"); printf(VERMELHO);deletarConta();         break; }
            case 6: { system("clear"); printf(CIANO);   buscaAvulsa();          break; }
            case 5: { system("clear"); printf(AMARELO); imprimirContas();       break; }
            case 7: { system("clear"); printf(VERDE);   depositar();            break; }
            case 8: { system("clear"); printf(VERDE);   sacar();                break; }
            case 9: { break; }
            default:{ printf("\n\tOpção inválida."); break; }
        }
        printf(BRANCO);
    }
    while(inst != 9);
    return 0;
}
