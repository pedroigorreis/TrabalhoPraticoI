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
            case 1:  { criarConta(); break; }
            case 2:  { break; }
            case 3:  { break; }
            case 4:  { break; }
            case 5:  { imprimirContas(); break; }
            case 6:
            {
                int idTemp = 0;
                printf("\n\tDigite o ID da conta para buscar: ");
                scanf("%d", &idTemp);
                if(buscarConta(idTemp) != -1) { printf("\n\tConta encontrada com sucesso.\n"); }
                else { printf("\n\tConta não encontrada no sistema.\n"); }
                break;
            }
            case 7:  { depositar(); break; }
            case 8:  { break; }
            case 9:  { printf("\n\tFim\n"); break; }
            default: { printf("\n\tOpção inválida."); break; }
        }
    }
    while(inst != 9);
    return 0;
}
