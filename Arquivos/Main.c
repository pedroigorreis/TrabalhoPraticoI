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
            case 1:
            {
                system("clear");
                criarConta();
                break;
            }
            case 2:
            {
                system("clear");
                atualizarConta();
                break;
            }
            case 3:
            {
                system("clear");
                realizarTransferencia();
                break;
            }
            case 4:
            {
                system("clear");
                deletarConta();
                break;
            }
            case 5:
            {
                system("clear");
                imprimirContas();
                break;
            }
            case 6:
            {
                system("clear");
                int idTemp = 0;
                printf("\n\tDigite o ID da conta para buscar: ");
                scanf("%d", &idTemp);
                if(buscarConta(idTemp) != -1)
                {
                    printf("\n\t⨀ Conta encontrada com sucesso.\n");
                }
                else
                {
                    printf("\n\t⨂ Conta não encontrada no sistema.\n");
                }
                break;
            }
            case 7:
            {
                depositar();
                break;
            }
            case 8:
            {
                sacar();
                break;
            }
            case 9:
            {
                printf("\n\tFim\n");
                break;
            }
            default:
            {
                printf("\n\tOpção inválida.");
                break;
            }
        }
    }
    while(inst != 9);
    return 0;
}
