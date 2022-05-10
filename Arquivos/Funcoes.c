#include "Bibliotecas.h"

// Símbolos ┗ ┃ ┓ ┏ ┛ ━

void imprimirConta(Conta C)
{
    printf("\n\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    printf("\n\t┃                    » Sua Conta «                   ┃");
    printf("\n\t┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃");
    printf("\n\t┃ ID: %-5d                                          ┃", C.idConta);
    printf("\n\t┃ Nome: %-31s              ┃", C.nomePessoa);
    printf("\n\t┃ CPF: %-12s                                  ┃", C.CPF);
    printf("\n\t┃ Cidade registrada: %-31s ┃", C.cidade);
    printf("\n\t┃ Saldo disponível: %-9.2f                        ┃", C.saldo);
    printf("\n\t┃ Tranferências: %-2d                                  ┃", C.transferenciasRealizadas);
    printf("\n\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
}

void imprimirMenuPrincipal()
{
    printf("\n");
    printf("\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("\t┃            No bolso! ┃ ADM            ┃\n");
    printf("\t┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n");
    printf("\t┃       » Escolha uma das opções «      ┃\n");
    printf("\t┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n");
    printf("\t┃ 1 • Criar uma nova conta              ┃\n");
    printf("\t┃ 2 • Atualizar conta                   ┃\n");
    printf("\t┃ 3 • Transferir                        ┃\n");
    printf("\t┃ 4 • Deletar conta                     ┃\n");
    printf("\t┃ 5 • Listar contas                     ┃\n");
    printf("\t┃ 6 • Buscar conta                      ┃\n");
    printf("\t┃ 7 • Depositar                         ┃\n");
    printf("\t┃ 8 • Sacar                             ┃\n");
    printf("\t┃ 9 • Sair                              ┃\n");
    printf("\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf("\n");
}

void criarConta()
{
    Conta C;
    FILE *Dados = fopen("Contas.bin", "ab");

    printf("\n\t\tCriar conta\n");

    printf("\n\tNome: ");   scanf("%[^\n]s", C.nomePessoa); fgetc(stdin);
    printf("\n\tCPF: ");    scanf("%[^\n]s", C.CPF);        fgetc(stdin);
    printf("\n\tCidade: "); scanf("%[^\n]s", C.cidade);     fgetc(stdin);

    C.saldo = 0.0;
    C.idConta = (ftell(Dados) / 86) + 1;
    C.transferenciasRealizadas = 0;

    fwrite(&C.idConta, sizeof(int),1,Dados);
    fwrite(&C.nomePessoa,sizeof(char),31,Dados);
    fwrite(&C.CPF,sizeof(char),12,Dados);
    fwrite(&C.cidade,sizeof(char),31,Dados);
    fwrite(&C.saldo,sizeof(float),1,Dados);
    fwrite(&C.transferenciasRealizadas,sizeof(int),1,Dados);

    imprimirConta(C);
    fclose(Dados);
}

void imprimirContas()
{
    FILE *Dados = fopen("Contas.bin", "rb");

    if(Dados != NULL)
    {
        Conta C;

        printf("\n\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
        printf("\n\t┃   ID  ┃            Nome Completo        ┃      CPF     ┃             Cidade              ┃  Saldo (R$)  ┃ Transf. ┃");
        printf("\n\t┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃");
        while
        (
            fread(&C.idConta, sizeof(int),1,Dados) != 0 &&
            fread(&C.nomePessoa,sizeof(char),31,Dados) != 0 &&
            fread(&C.CPF,sizeof(char),12,Dados) != 0 &&
            fread(&C.cidade,sizeof(char),31,Dados) != 0 &&
            fread(&C.saldo,sizeof(float),1,Dados) != 0 &&
            fread(&C.transferenciasRealizadas,sizeof(int),1,Dados) != 0
        )
        {
            printf("\n\t┃ %-5d ┃ %-31s ┃ %-12s ┃ %-31s ┃ %-12.2f ┃ %-7d ┃", C.idConta, C.nomePessoa, C.CPF,C.cidade, C.saldo,C.transferenciasRealizadas);
        }
        printf("\n\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
    }
    else { printf("\n\tArquivo vazio.\n"); }

    fclose(Dados);
}

int buscarConta(int id)
{
    Conta C;
    int posicaoCursor = -1;

    FILE *Dados = fopen("Contas.bin", "rb");

    if(Dados != NULL)
    {
        rewind(Dados);
        while
        (
            fread(&C.idConta, sizeof(int),1,Dados) != 0 &&
            fread(&C.nomePessoa,sizeof(char),31,Dados) != 0 &&
            fread(&C.CPF,sizeof(char),12,Dados) != 0 &&
            fread(&C.cidade,sizeof(char),31,Dados) != 0 &&
            fread(&C.saldo,sizeof(float),1,Dados) != 0 &&
            fread(&C.transferenciasRealizadas,sizeof(int),1,Dados) != 0
        )
        { if(C.idConta == id) { posicaoCursor = ftell(Dados) / 86; } }
    }
    else { printf("\n\tArquivo vazio.\n"); }
    return posicaoCursor;
    fclose(Dados);
}

void depositar()
{
    printf("\n\tDigite o ID da conta desejada: ");
    int idTemporario = 0;
    scanf("%d", &idTemporario);
    int posicao = buscarConta(idTemporario);

    if(posicao != -1)
    {
        printf("\n\tConta encontrada com sucesso.\n");

        FILE *Dados = fopen("Contas.bin", "rb+");

        if(Dados != NULL)
        {
            Conta C;
            fseek(Dados,posicao*75,SEEK_SET);
            printf("\n\tDigite o valor para depositar: ");
            scanf("%f", &C.saldo);
            fwrite(&C.saldo,sizeof(float),1,Dados);
            printf("\n\tDepósito realizado com sucesso.\n");
        }
        else
        {
            printf("\n\tArquivo não encontrado.\n");
        }
        fclose(Dados);
    }
    else { printf("\n\tConta não encontrada no sistema.\n"); }
}
