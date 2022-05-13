#include "Bibliotecas.h"

int main(void)
{
    system("clear");
    int inst = -1;

    do
    {
        imprimirMenuPrincipal();
        scanf("%d", &inst);
        fgetc(stdin);

        switch(inst)
        {
            case 1: { system("clear"); criarConta(); break; }
            case 2: { system("clear"); atualizarConta(); break; }
            case 3: { system("clear"); realizarTransferencia(); break; }
            case 4: { system("clear"); deletarConta(); break; }
            case 5: { system("clear"); imprimirContas(); break; }
            case 7: { system("clear"); depositar(); break; }
            case 8: { system("clear"); sacar(); break; }
            case 9: { break; }
            default:{ printf("\n\tOpção inválida."); break; }
        }
    }
    while(inst != 9);
    return 0;
}
