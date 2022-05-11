#include "Bibliotecas.h"

// Símbolos ┗ ┃ ┓ ┏ ┛ ━ ┣ ┫ ┳ ┻

void imprimirConta(Conta C)
{
    printf("\n\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    printf("\n\t┃                    ⋑ Sua Conta ⋐                   ┃");
    printf("\n\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");
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
    printf("\t┏━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("\t┃    No bolso!    ┃ ⦛ Administrador ⦛   ┃\n");
    printf("\t┣━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━┫\n");
    printf("\t┃       » Escolha uma das opções «      ┃\n");
    printf("\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
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

    printf("\n\t┏━━━━━━━━━━━━━━━━━━━┓");
    printf("\n\t┃    Criar conta    ┃");
    printf("\n\t┗━━━━━━━━━━━━━━━━━━━┛\n");

    printf("\n\tNome: ");
    scanf("%[^\n]s", C.nomePessoa);
    fgetc(stdin);

    printf("\n\tCPF: ");
    scanf("%[^\n]s", C.CPF);
    fgetc(stdin);

    printf("\n\tCidade: ");
    scanf("%[^\n]s", C.cidade);
    fgetc(stdin);

    C.saldo = 0.0;
    C.idConta = (ftell(Dados) / 88) + 1;
    C.transferenciasRealizadas = 0;

    fwrite(&C.idConta, sizeof(int),1,Dados);
    fwrite(&C.nomePessoa,sizeof(char),33,Dados);
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

        printf("\n\t┏━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┳━━━━━━━━━┓");
        printf("\n\t┃  ID.  ┃          Nome Completo          ┃     CPF.     ┃             Cidade              ┃  Saldo (R$)  ┃ Transf. ┃");
        printf("\n\t┣━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━┫");
        while
        (
            fread(&C.idConta, sizeof(int),1,Dados) != 0 &&
            fread(&C.nomePessoa,sizeof(char),33,Dados) != 0 &&
            fread(&C.CPF,sizeof(char),12,Dados) != 0 &&
            fread(&C.cidade,sizeof(char),31,Dados) != 0 &&
            fread(&C.saldo,sizeof(float),1,Dados) != 0 &&
            fread(&C.transferenciasRealizadas,sizeof(int),1,Dados) != 0
        )
        {
            printf("\n\t┃ %-5d ┃ %-31s ┃ %-12s ┃ %-31s ┃ %-12.2f ┃ %-7d ┃", C.idConta, C.nomePessoa, C.CPF,C.cidade, C.saldo,C.transferenciasRealizadas);
        }
        printf("\n\t┗━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┻━━━━━━━━━┛\n\n");
        fclose(Dados);
    }
    else
    {
        printf("\n\t⨂ Arquivo não encontrada.\n");
    }
}

int buscarConta(int id)
{
    Conta C;
    int posicaoCursor = -1;

    FILE *Dados = fopen("Contas.bin", "rb");

    if(Dados != NULL)
    {
        while
        (
            fread(&C.idConta, sizeof(int),1,Dados) != 0 &&
            fread(&C.nomePessoa,sizeof(char),33,Dados) != 0 &&
            fread(&C.CPF,sizeof(char),12,Dados) != 0 &&
            fread(&C.cidade,sizeof(char),31,Dados) != 0 &&
            fread(&C.saldo,sizeof(float),1,Dados) != 0 &&
            fread(&C.transferenciasRealizadas,sizeof(int),1,Dados) != 0
        )
        {
            if(C.idConta == id)
            {
                posicaoCursor = ftell(Dados);
            }
        }
        fclose(Dados);
    }
    else
    {
        printf("\n\t⨂ Arquivo não encontrado.\n");
    }
    return posicaoCursor;
}

void depositar()
{
    printf("\n\t┏━━━━━━━━━━━━━━━━━┓");
    printf("\n\t┃    Depositar    ┃");
    printf("\n\t┗━━━━━━━━━━━━━━━━━┛\n");

    printf("\n\tDigite o ID da conta desejada: ");
    int idTemporario = 0;
    scanf("%d", &idTemporario);
    int posicao = buscarConta(idTemporario);

    if(posicao != -1)
    {
        printf("\n\t⅏ Buscando contas...\n");
        printf("\n\t⨀ Conta encontrada com sucesso.\n");

        FILE *Dados = fopen("Contas.bin", "rb+");

        if(Dados != NULL)
        {
            Conta C;
            fseek(Dados,(posicao - 8),SEEK_SET);
            fread(&C.saldo,sizeof(float),1,Dados);
            fseek(Dados,(posicao - 8),SEEK_SET);
            printf("\n\tDigite o valor para depositar: ");
            float saldoTemporario = 0.0;
            scanf("%f", &saldoTemporario);
            C.saldo += saldoTemporario;
            fwrite(&C.saldo,sizeof(float),1,Dados);
            printf("\n\t⥣ Depósito realizado com sucesso.\n");
        }
        else
        {
            printf("\n\t⨂ Arquivo não encontrado.\n");
        }
        fclose(Dados);
    }
    else
    {
        printf("\n\t⨂ Conta não encontrada no sistema.\n");
    }
}

void atualizarConta()
{
    printf("\n\t┏━━━━━━━━━━━━━━━━━━━━━━━┓");
    printf("\n\t┃    Atualizar Conta    ┃");
    printf("\n\t┗━━━━━━━━━━━━━━━━━━━━━━━┛\n");

    printf("\n\tDigite o ID da conta desejada: ");
    int idTemporario = 0;
    scanf("%d", &idTemporario); fgetc(stdin);
    int posicao = buscarConta(idTemporario);

    if(posicao != -1)
    {
        printf("\n\t⅏ Buscando conta...\n");
        printf("\n\t⨀ Conta encontrada com sucesso.\n");

        FILE *Dados = fopen("Contas.bin", "rb+");

        if(Dados != NULL)
        {
            fseek(Dados,(posicao - 88) + sizeof(int),SEEK_SET);
            Conta C;

            printf("\n\tNome: ");   scanf("%[^\n]s", C.nomePessoa); fgetc(stdin);
            printf("\n\tCPF: ");    scanf("%[^\n]s", C.CPF);        fgetc(stdin);
            printf("\n\tCidade: "); scanf("%[^\n]s", C.cidade);     fgetc(stdin);

            fwrite(&C.nomePessoa,sizeof(char),33,Dados);
            fwrite(&C.CPF,sizeof(char),12,Dados);
            fwrite(&C.cidade,sizeof(char),31,Dados);
        }
        else
        {
            printf("\n\t⨂ Arquivo não encontrado.\n");
        }
        fclose(Dados);
    }
    else
    {
        printf("\n\t⨂ Conta não encontrada no sistema.\n");
    }
}

void sacar()
{
    printf("\n\t┏━━━━━━━━━━━━━┓");
    printf("\n\t┃    Saque    ┃");
    printf("\n\t┗━━━━━━━━━━━━━┛\n");

    printf("\n\tDigite o ID da conta desejada: ");
    int idTemporario = 0;
    scanf("%d", &idTemporario);
    int posicao = buscarConta(idTemporario);

    if(posicao != -1)
    {
        printf("\n\t⅏ Buscando conta...\n");
        printf("\n\t⨀ Conta encontrada com sucesso.\n");

        FILE *Dados = fopen("Contas.bin", "rb+");

        if(Dados != NULL)
        {
            Conta C;
            fseek(Dados,(posicao - 8),SEEK_SET);
            fread(&C.saldo,sizeof(float),1,Dados);
            fseek(Dados,(posicao - 8),SEEK_SET);
            printf("\n\tDigite o valor para sacar: ");
            float saldoTemporario = 0.0;
            scanf("%f", &saldoTemporario);
            C.saldo -= saldoTemporario;
            if(C.saldo < 0)
            {
                printf("\n\tErro, saldo insuficiente.\n");
            }
            else
            {
                fwrite(&C.saldo,sizeof(float),1,Dados);
                printf("\n\t⥥ Saque realizado com sucesso.\n");
            }
        }
        else { printf("\n\t⨂ Arquivo não encontrado.\n"); }
        fclose(Dados);
    }
    else { printf("\n\t⨂ Conta não encontrada no sistema.\n"); }
}

void realizarTransferencia()
{
    printf("\n\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    printf("\n\t┃    Realizar transferências    ┃");
    printf("\n\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

    int idRem = -1;
    int idDes = -1;
    printf("\n\tDigite o ID da conta remetente: ");
    scanf("%d", &idRem);
    printf("\n\tDigite o ID da conta destinatária: ");
    scanf("%d", &idDes);

    int posicaoR = buscarConta(idRem);
    int posicaoD = buscarConta(idDes);

    printf("\n\t⅏ Buscando contas...\n");

    if(posicaoD != -1 && posicaoR != -1)
    {
        FILE *Dados = fopen("Contas.bin", "rb+");

        if(Dados != NULL)
        {
            printf("\n\t⨀ Contas encontradas com sucesso.\n");
            printf("\n\tDigite o valor a Transferir: ");
            float saldoTemporario = 0.0;
            scanf("%f", &saldoTemporario);

            Conta remetente;
            Conta destinataria;

            fseek(Dados,(posicaoR - 8),SEEK_SET);
            fread(&remetente.saldo,sizeof(float),1,Dados);
            fread(&remetente.transferenciasRealizadas,sizeof(int),1,Dados);

            fseek(Dados,(posicaoD - 8),SEEK_SET);
            fread(&destinataria.saldo,sizeof(float),1,Dados);
            fread(&destinataria.transferenciasRealizadas,sizeof(int),1,Dados);

            if(saldoTemporario > remetente.saldo)
            {
                printf("\n\tErro, valor insuficiente para a operação.\n");
            }
            else
            {
                remetente.saldo -= saldoTemporario;
                destinataria.saldo += saldoTemporario;
                remetente.transferenciasRealizadas++;
                destinataria.transferenciasRealizadas++;
                fseek(Dados,(posicaoR - 8),SEEK_SET);
                fwrite(&remetente.saldo,sizeof(float),1,Dados);
                fwrite(&remetente.transferenciasRealizadas,sizeof(int),1,Dados);
                fseek(Dados,(posicaoD - 8),SEEK_SET);
                fwrite(&destinataria.saldo,sizeof(float),1,Dados);
                fwrite(&destinataria.transferenciasRealizadas,sizeof(int),1,Dados);
                printf("\n\t⤮ Transferência realizada com sucesso.\n");
            }
        }
        else
        {
            printf("\n\t⨂ Arquivo não encontrado.\n");
        }
        fclose(Dados);
    }
    else
    {
        printf("\n\t⨂ Contas não encontradas no sistema.\n");
    }
}

void deletarConta()
{
    printf("\n\t┏━━━━━━━━━━━━━━━━━━━━━┓");
    printf("\n\t┃    Deletar conta    ┃");
    printf("\n\t┗━━━━━━━━━━━━━━━━━━━━━┛\n");

    printf("\n\tDigite o ID da conta desejada: ");
    int idTemporario = 0;
    scanf("%d", &idTemporario);

    int posicao = buscarConta(idTemporario);

    if(posicao != -1)
    {
        printf("\n\t⅏ Buscando conta...\n");
        printf("\n\t⨀ Conta encontrada com sucesso.\n");

        FILE *Dados = fopen("Contas.bin", "rb+");
        if(Dados != NULL)
        {
            fseek(Dados,(posicao - 88) + sizeof(int),SEEK_SET);

            Conta C;
            strcpy(C.CPF, "Removida");
            strcpy(C.cidade, "Removida");
            strcpy(C.nomePessoa, "Removida");
            C.saldo = 0.0;
            C.transferenciasRealizadas = 0;

            fwrite(&C.nomePessoa,sizeof(char),33,Dados);
            fwrite(&C.CPF,sizeof(char),12,Dados);
            fwrite(&C.cidade,sizeof(char),31,Dados);
            printf("%ld\n", ftell(Dados));
            fwrite(&C.saldo,sizeof(float),1,Dados);
            fwrite(&C.transferenciasRealizadas,sizeof(int),1,Dados);

            printf("\n\t⊛ Conta removida com sucesso.\n");
        }
        else
        {
            printf("\n\t⨂ Arquivo não encontrado.\n");
        }
        fclose(Dados);
    }
    else
    {
        printf("\n\t⨂ Conta não encontrada no sistema.\n");
    }
}
