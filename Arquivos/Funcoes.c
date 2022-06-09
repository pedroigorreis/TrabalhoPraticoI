//      ⏱ Data: 07/03/2022
//      ⚒ Autores: Pedro Igor Martins dos Reis & Hernane Veloso
//      ⛩ Curso: Engenharia de Computação / PUC Minas 2022
//      ⛺ Disciplina: Algoritmos e Estruturas de Dados III

#include "Bibliotecas.h"

// Imprime de forma (mais) legível informações da conta. Não retorna nada.
void imprimirConta(Conta C)
{
    printf(NEGRITO);
    printf("\n\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    printf("\n\t┃                   Detalhes da conta                  ┃");
    printf("\n\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
    printf(CONVENCIONAL);
    printf("\n\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    printf("\n\t┃ ◌ ID: %-5d                                          ┃",    C.idConta);
    printf("\n\t┃ ◌ Nome: %-31s              ┃",                             C.nomePessoa);
    printf("\n\t┃ ◌ CPF: %-12s                                  ┃",          C.CPF);
    printf("\n\t┃ ◌ Cidade registrada: %-31s ┃",                             C.cidade);
    printf("\n\t┃ ◌ Saldo disponível: %-9.2f                        ┃",      C.saldo);
    printf("\n\t┃ ◌ Transferências: %-2u                                 ┃", C.transferenciasRealizadas);
    printf("\n\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
}

// Imprime todas funções disponíveis no programa. Não retorna nada.
void imprimirMenuPrincipal()
{
    printf(NEGRITO);
    printf("\n");
    printf("\t┏━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("\t┃    No bolso!    ┃ Modo Administrador  ┃\n");
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
    printf(CONVENCIONAL);
}

// Recolhe os dados necessários para criação da conta as escreve no arquivo "Contas.bin" de forma binária. Não retorna nada.
void criarConta()
{
    Conta C;
    FILE *Dados = fopen("Contas.bin", "ab");

    if(Dados != NULL)
    {
        printf("\n\t┏━━━━━━━━━━━━━━━━━━━┓");
        printf("\n\t┃    Criar conta    ┃");
        printf("\n\t┗━━━━━━━━━━━━━━━━━━━┛\n");

        printf("\n\tNome: ");   fgets(C.nomePessoa,sizeof(C.nomePessoa),stdin); C.nomePessoa[strcspn(C.nomePessoa, "\n")] = 0;
        printf("\n\tCPF: ");    fgets(C.CPF,sizeof(C.CPF),stdin);               C.CPF[strcspn(C.CPF, "\n")] = 0;
        printf("\n\tCidade: "); fgets(C.cidade,sizeof(C.cidade),stdin);         C.cidade[strcspn(C.cidade, "\n")] = 0;

        C.saldo = 0.0;
        C.idConta = (ftell(Dados) / 88) + 1;
        C.transferenciasRealizadas = 0;

        adicionarIndices(C.idConta,ftell(Dados));

        criptografiaXOR(C.nomePessoa);

        fwrite(&C.idConta, sizeof(int),1,Dados);
        fwrite(&C.nomePessoa,sizeof(char),33,Dados);
        fwrite(&C.CPF,sizeof(char),12,Dados);
        fwrite(&C.cidade,sizeof(char),31,Dados);
        fwrite(&C.saldo,sizeof(float),1,Dados);
        fwrite(&C.transferenciasRealizadas,sizeof(int),1,Dados);

        criptografiaXOR(C.nomePessoa);
        adicionarDadosListaInvertida(C.idConta,C.nomePessoa,"NomesLI.bin");
        fclose(Dados);
    }
    else { printf("Erro, arquivo inacessível para criação da conta.\n"); }
}

// Imprime em formato de lista todas as contas registradas no arquivo "Contas.bin". Não retorna nada.
void imprimirContas()
{
    FILE *Dados = fopen("Contas.bin", "rb");

    if(Dados != NULL)
    {
        Conta C;

        printf(NEGRITO);
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
            if(C.idConta >= 0)
            {
                criptografiaXOR(C.nomePessoa);
                printf("\n\t┃ %-5d ┃ %-31s ┃ %-12s ┃ %-31s ┃ %-12.2f ┃ %-7u ┃", C.idConta, C.nomePessoa, C.CPF,C.cidade, C.saldo,C.transferenciasRealizadas); }
        }
        printf("\n\t┗━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┻━━━━━━━━━┛\n\n");
        printf(CONVENCIONAL);
        fclose(Dados);
    }
    else{ printf("\n\t⨂ Arquivo não encontrada.\n"); }
}

// Busca no arquivo "Contas.bin" a conta diretamente pelo ID informado, porém não mais utilizado devido as demandas da segunda parte do projeto (Consultar: https://pucminas.instructure.com/courses/88639/files/5866512?module_item_id=2279453). Retorna a posição do registro no arquivo de contas.
int buscaContaTradicional(int id)
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
        { if(C.idConta == id && C.idConta >= 1) { posicaoCursor = ftell(Dados); } }
        fclose(Dados);
    }
    else { printf("\n\t⨂ Arquivo não encontrado.\n"); }
    return posicaoCursor;
}

// Função para adicionar novos fundos a conta registrada (caso a encontre) no arquivo, recolhe o valor a adicionar e soma ao valor atual registrado. Não retorna nada.
void depositar()
{
    printf(NEGRITO);
    printf("\n\t┏━━━━━━━━━━━━━┓");
    printf("\n\t┃  Depositar  ┃");
    printf("\n\t┗━━━━━━━━━━━━━┛\n");
    printf(CONVENCIONAL);

    printf("\n\tDigite o ID da conta desejada: "); int idTemporario = 0; scanf("%d", &idTemporario);
    int posicao = buscaBinariaPorID(idTemporario);

    if(posicao >= 0)
    {
        printf("\n\t⅏ Buscando contas...\n");
        printf("\n\t⨀ Conta encontrada com sucesso.\n");

        FILE *Dados = fopen("Contas.bin", "rb+");

        if(Dados != NULL)
        {
            Conta C;
            fseek(Dados,posicao + 80,SEEK_SET);
            fread(&C.saldo,sizeof(float),1,Dados);
            fseek(Dados,posicao + 80,SEEK_SET);
            printf("\n\tDigite o valor para depositar: ");
            float saldoTemporario = 0.0;
            scanf("%f", &saldoTemporario);
            C.saldo += saldoTemporario;
            fwrite(&C.saldo,sizeof(float),1,Dados);
            printf("\n\t⥣ Depósito realizado com sucesso.\n");

            fclose(Dados);
        }
        else { printf("\n\t⨂ Arquivo não encontrado.\n"); }
    }
    else { printf("\n\t⨂ Conta não encontrada no sistema.\n"); }
}

// Função para atualizar os dados a conta registrada (caso a encontre) no arquivo, recolhe novamente os dados necessários. Não retorna nada. Fora comentada a função que cria arquivo de 'CidadesLI' para facilitar no gerenciamento do projeto, no entanto, não apenas é possível adicionar outros campos, mas os métodos referentes as listas permitem que coloque qualquer caminho/arquivo de sua preferência.
void atualizarConta()
{
    printf(NEGRITO);
    printf("\n\t┏━━━━━━━━━━━━━━━━━━━━━┓");
    printf("\n\t┃  Atualizar Conta    ┃");
    printf("\n\t┗━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf(CONVENCIONAL);

    printf("\n\tDigite o ID da conta desejada: ");
    int idTemporario = 0;
    scanf("%d", &idTemporario);
    fgetc(stdin);
    int posicao = buscaBinariaPorID(idTemporario);

    if(posicao >= 0)
    {
        printf("\n\t⅏ Buscando conta...\n");
        printf("\n\t⨀ Conta encontrada com sucesso.\n");

        FILE *Dados = fopen("Contas.bin", "rb+");

        if(Dados != NULL)
        {
            char antigoNomePessoa[31];
            fseek(Dados,(posicao) + sizeof(int),SEEK_SET);
            fread(antigoNomePessoa,sizeof(char),31,Dados);
            fseek(Dados,(posicao) + sizeof(int),SEEK_SET);
            Conta C;

            printf("\n\tNome: ");   fgets(C.nomePessoa,sizeof(C.nomePessoa),stdin); C.nomePessoa[strcspn(C.nomePessoa, "\n")] = 0;
            printf("\n\tCPF: ");    fgets(C.CPF,sizeof(C.CPF),stdin);               C.CPF[strcspn(C.CPF, "\n")] = 0;
            printf("\n\tCidade: "); fgets(C.cidade,sizeof(C.cidade),stdin);         C.cidade[strcspn(C.cidade, "\n")] = 0;

            atualizarDadosListaInvertida(idTemporario,antigoNomePessoa,C.nomePessoa,"NomesLI.bin");
            criptografiaXOR(C.nomePessoa);

            fwrite(&C.nomePessoa,sizeof(char),33,Dados);
            fwrite(&C.CPF,sizeof(char),12,Dados);
            fwrite(&C.cidade,sizeof(char),31,Dados);

            fclose(Dados);
        }
        else { printf("\n\t⨂ Arquivo não encontrado.\n"); }
    }
    else { printf("\n\t⨂ Conta não encontrada no sistema.\n"); }
}

// Função para sacar valores da conta registrada (caso a encontre) no arquivo, possibilita a operação somente se o valor for inferior ou igual ao atual saldo. Não retorna nada.
void sacar()
{
    printf(NEGRITO);
    printf("\n\t┏━━━━━━━━━━━━━┓");
    printf("\n\t┃    Saque    ┃");
    printf("\n\t┗━━━━━━━━━━━━━┛\n");
    printf(CONVENCIONAL);

    printf("\n\tDigite o ID da conta desejada: ");
    int idTemporario = 0;
    scanf("%d", &idTemporario);
    int posicao = buscaBinariaPorID(idTemporario);

    if(posicao >= 0)
    {
        printf("\n\t⅏ Buscando conta...\n");
        printf("\n\t⨀ Conta encontrada com sucesso.\n");

        FILE *Dados = fopen("Contas.bin", "rb+");

        if(Dados != NULL)
        {
            Conta C;
            fseek(Dados,posicao + 80,SEEK_SET);
            fread(&C.saldo,sizeof(float),1,Dados);
            fseek(Dados,posicao + 80,SEEK_SET);
            printf("\n\tDigite o valor para sacar: ");
            float saldoTemporario = 0.0;
            scanf("%f", &saldoTemporario);
            C.saldo -= saldoTemporario;
            if(C.saldo < 0) { printf("\n\t🄏 Erro, saldo insuficiente.\n"); }
            else
            {
                fwrite(&C.saldo,sizeof(float),1,Dados);
                printf("\n\t⥥ Saque realizado com sucesso.\n");
            }
            fclose(Dados);
        }
        else { printf("\n\t⨂ Arquivo não encontrado.\n"); }
    }
    else { printf("\n\t⨂ Conta não encontrada no sistema.\n"); }
}

// Função para transferir valores de contas registradas (caso as encontre) no arquivo, possibilita a operação somente se o valor for inferior ou igual ao atual saldo da conta remetente, além disso há um incremento no atributo 'transferenciasRealizadas'. Não retorna nada.
void realizarTransferencia()
{
    printf(NEGRITO);
    printf("\n\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    printf("\n\t┃    Realizar transferências    ┃");
    printf("\n\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf(CONVENCIONAL);

    int idRem = -1;
    int idDes = -1;
    printf("\n\tDigite o ID da conta remetente: ");    scanf("%d", &idRem);
    printf("\n\tDigite o ID da conta destinatária: "); scanf("%d", &idDes);

    int posicaoR = buscaBinariaPorID(idRem);
    int posicaoD = buscaBinariaPorID(idDes);

    printf("\n\t⅏ Buscando contas...\n");

    if(posicaoD >= 0 && posicaoR >= 0)
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

            fseek(Dados,posicaoR + 80,SEEK_SET);
            fread(&remetente.saldo,sizeof(float),1,Dados);
            fread(&remetente.transferenciasRealizadas,sizeof(int),1,Dados);

            fseek(Dados,posicaoD + 80,SEEK_SET);
            fread(&destinataria.saldo,sizeof(float),1,Dados);
            fread(&destinataria.transferenciasRealizadas,sizeof(int),1,Dados);

            if(saldoTemporario > remetente.saldo) { printf("\n\t🄏 Erro, valor insuficiente para a operação.\n"); }
            else
            {
                remetente.saldo -= saldoTemporario;
                destinataria.saldo += saldoTemporario;
                remetente.transferenciasRealizadas++;
                destinataria.transferenciasRealizadas++;
                fseek(Dados,posicaoR + 80,SEEK_SET);
                fwrite(&remetente.saldo,sizeof(float),1,Dados);
                fwrite(&remetente.transferenciasRealizadas,sizeof(int),1,Dados);
                fseek(Dados,posicaoD + 80,SEEK_SET);
                fwrite(&destinataria.saldo,sizeof(float),1,Dados);
                fwrite(&destinataria.transferenciasRealizadas,sizeof(int),1,Dados);
                printf("\n\t⤮ Transferência realizada com sucesso.\n");
            }
            fclose(Dados);
        }
        else { printf("\n\t⨂ Arquivo não encontrado.\n"); }
    }
    else { printf("\n\t⨂ Uma ou ambas as contas não encontradas no sistema.\n"); }
}

// Função que remove uma conta desejada (caso a encontre) no arquivo, diferentemente que o nome sugere, o registro não é removido do arquivo, é sobrescrito, de forma que o ID é passado para negativo, os campos são modificados para 'Removida' e saldo e número de transferências realizadas é zerado, isso de forma que tenha auditoria de quais contas foram removidas do sistema, vale ressaltar que não é possível reutilizar ou atualizar contas removidas. Não retorna nada.
void deletarConta()
{
    printf(NEGRITO);
    printf("\n\t┏━━━━━━━━━━━━━━━━━━━━━┓");
    printf("\n\t┃    Deletar conta    ┃");
    printf("\n\t┗━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf(CONVENCIONAL);

    printf("\n\tDigite o ID da conta desejada: ");
    int idTemporario = 0;
    scanf("%d", &idTemporario);

    int posicao = buscaBinariaPorID(idTemporario);

    if(posicao >= 0)
    {
        printf("\n\t⅏ Buscando conta...\n");
        printf("\n\t⨀ Conta encontrada com sucesso.\n");

        FILE *Dados = fopen("Contas.bin", "rb+");
        if(Dados != NULL)
        {
            fseek(Dados,(posicao),SEEK_SET);

            Conta C;
            C.idConta = idTemporario*-1;
            strcpy(C.CPF, "Removida");
            strcpy(C.cidade, "Removida");
            strcpy(C.nomePessoa, "Removida");
            C.saldo = 0.0;
            C.transferenciasRealizadas = 0;

            fwrite(&C.idConta,sizeof(int),1,Dados);
            fwrite(&C.nomePessoa,sizeof(char),33,Dados);
            fwrite(&C.CPF,sizeof(char),12,Dados);
            fwrite(&C.cidade,sizeof(char),31,Dados);
            fwrite(&C.saldo,sizeof(float),1,Dados);
            fwrite(&C.transferenciasRealizadas,sizeof(int),1,Dados);

            removerIndice(idTemporario);
            removerDadosListaInvertida(idTemporario,"NomesLI.bin");
            printf("\n\t⊛ Conta removida com sucesso.\n");
            fclose(Dados);
        }
        else { printf("\n\t⨂ Arquivo não encontrado.\n"); }
    }
    else { printf("\n\t⨂ Conta não encontrada no sistema.\n"); }
}

// Função para adicionar os IDs e as respectivas posições dos registros no arquivo de contas original em um novo arquivo, denominado 'Indices.bin', para fins de estudo e melhor compreensão, operações realizadas no arquivo de índice imprimem o símbolo: 🄸. Não retorna nada.
void adicionarIndices(int id, long posicaoNoArquivo)
{
    FILE *Indices = fopen("Indices.bin","ab");

    if(Indices != NULL)
    {
        fwrite(&id,sizeof(int),1,Indices);
        fwrite(&posicaoNoArquivo,sizeof(long),1,Indices);
        fclose(Indices);
    }
    else { printf("\n\t🄸 Arquivo de índices não encontrado.\n"); }
}

// Da mesma maneira que a função deletarConta(), converte o respectivo ID para negativo no entanto a posição do registro no arquivo principal permanece o mesmo para auditoria. Não retorna nada.
void removerIndice(int ID)
{
    FILE *Indices = fopen("Indices.bin","rb+");

    int posicaoCursor = ID - 1;
    if(Indices != NULL)
    {
        int idAux = 0;
        long posicaoAux = 0;
        while(fread(&idAux, sizeof(int),1,Indices) != 0 && fread(&posicaoAux,sizeof(long),1,Indices) != 0)
        {
            if(idAux == ID)
            {
                fseek(Indices,posicaoCursor*(sizeof(int)+sizeof(long)),SEEK_SET);
                idAux = ID * -1;
                fwrite(&idAux,sizeof(int),1,Indices);
                printf("\n\t🄸 Remoção realizada com sucesso.\n");
            }
        }
        fclose(Indices);
    }
    else { printf("\n\t🄸 Arquivo de índices não encontrado.\n"); }
}

// Método de busca pelas contas no arquivo de Índices conforme exigências da segunda parte do projeto (Consultar: https://pucminas.instructure.com/courses/88639/files/5866512?module_item_id=2279453), há ganhos de performance em relação a primeira versão por dividir as operações. Retorna a posição do registro no arquivo principal e a partir desta e da função nativa de C 'fseek' posiciona o cursor no arquivo para a leitura.
int buscaBinariaPorID(int ID)
{
    int posicaoCursor = -1;
    if(ID >= 0)
    {
        FILE *Indices = fopen("Indices.bin","rb");

        if(Indices != NULL)
        {
            fseek(Indices,0,SEEK_END);
            int tamanhoVetor = ftell(Indices)/(sizeof(int)+sizeof(long));
            int finalVetor = tamanhoVetor;
            int idTemporario = 0;

            int *vetorIndices = (int*)malloc(tamanhoVetor*sizeof(int));

            if(vetorIndices == NULL) { printf("\n\tErro na alocação do vetor.\n"); }
            else
            {
                for(int i = 0; i < tamanhoVetor; i++)
                {
                    fseek(Indices,i*(sizeof(int)+sizeof(long)),SEEK_SET);
                    fread(&idTemporario,sizeof(int),1,Indices);
                    if(idTemporario > 0) { vetorIndices[i] = idTemporario; }
                }
                int inicioVetor = 0;
                while(inicioVetor <= finalVetor)
                {
                    int meioVetor = (inicioVetor + finalVetor)/2;
                    if(ID == vetorIndices[meioVetor])
                    {
                        fseek(Indices,(meioVetor*12)+4,SEEK_SET);
                        fread(&posicaoCursor,sizeof(long),1,Indices);
                        break;
                    }
                    else if(ID < vetorIndices[meioVetor]) { finalVetor = meioVetor - 1; continue;  }
                    else { inicioVetor = meioVetor + 1; continue; }
                }
            }
            free(vetorIndices);
            fclose(Indices);
        }
        else { printf("\n\t🄸 Arquivo não encontrado.\n"); }
    }
    else { printf("\n\t⊹ Conta removida ou desconhecida.\n"); }
    return posicaoCursor;
}

// Busca a conta por ID como demais funções porém imprime os dados da conta de forma mais detalhada ao usuário pelo método imprimirConta(Conta C). Não retorna nada.
void buscaAvulsa()
{
    printf(NEGRITO);
    printf("\n\t┏━━━━━━━━━━━━━━━━━━━━┓");
    printf("\n\t┃    Buscar conta    ┃");
    printf("\n\t┗━━━━━━━━━━━━━━━━━━━━┛\n");
    printf(CONVENCIONAL);

    printf("\n\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    printf("\n\t┃        Forma de busca        ┃");
    printf("\n\t┣━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━┫");
    printf("\n\t┃ 1 - ID ┃ 2 - Nome do usuário ┃");
    printf("\n\t┗━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━┛\n");
    int formaDeBusca = 0;
    scanf("%d",&formaDeBusca);
    fgetc(stdin);

    switch(formaDeBusca)
    {
        case 1:
        {
            printf("\n\tDigite o ID da conta: ");
            int idTemporario = 0;
            scanf("%d", &idTemporario);

            int posicao = buscaBinariaPorID(idTemporario);

            if(posicao >= 0)
            {
                FILE *Dados = fopen("Contas.bin","rb");
                if(Dados != NULL)
                {
                    fseek(Dados,posicao,SEEK_SET);
                    Conta C;
                    fread(&C.idConta, sizeof(int),1,Dados);
                    fread(&C.nomePessoa,sizeof(char),33,Dados);
                    fread(&C.CPF,sizeof(char),12,Dados);
                    fread(&C.cidade,sizeof(char),31,Dados);
                    fread(&C.saldo,sizeof(float),1,Dados);
                    fread(&C.transferenciasRealizadas,sizeof(int),1,Dados);
                    printf(AMARELO);

                    criptografiaXOR(C.nomePessoa);
                    imprimirConta(C);
                    fclose(Dados);
                }
                else { printf("\n\t⨂ Arquivo não encontrado.\n"); }
            }
            else { printf("\n\t⨂ Conta não encontrada no sistema.\n"); }
            break;
        }
        case 2:
        {
            printf("\n\tDigite o nome do usuário: ");

            char infoTemporaria[31] = " "; fgets(infoTemporaria,sizeof(infoTemporaria),stdin); infoTemporaria[strcspn(infoTemporaria, "\n")] = 0;

            buscarDadosListaInvertida(infoTemporaria,"NomesLI.bin");
            break;
        }
    }
}

// Verifica se o arquivo a ser lido está de fato vazio, a lógica é bastante simples, onde o documento é lido de modo 'ab', ou seja, o cursor se inicia no final, caso este seja 0, logo está vazio. Retorna a 1 se está vazio e 0 o contrário.
int verificarListaInvertida(char *origemArquivo)
{
    int arquivoEstaVazio = 1;
    FILE *ListaInvertida = fopen(origemArquivo,"ab");

    if(ListaInvertida != NULL) { if(ftell(ListaInvertida) != 0) { arquivoEstaVazio = 0; fclose(ListaInvertida); } }
    else { printf("\n\t₪ Erro, arquivo indisponível."); }

    return arquivoEstaVazio;
}

// Busca pelo arquivo desejado se a string informada já fora registrada anteriormente através da função 'strstr' do C, fora escolhida ela ao invés do 'strcmp' para aumentar as chances de encontrar a conta desejada. Retorna a posição do cursor no arquivo caso encontre o registro, -1 caso não seja encontrada.
long buscarPosicaoListaInvertida(char *info,FILE *arquivo)
{
    long posicao = -1;
    char infoTemporaria[31];
    int idsTemporarios[10] = {0,0,0,0,0,0,0,0,0,0};
    fseek(arquivo,0,SEEK_SET);

    while(fread(idsTemporarios,sizeof(int),10,arquivo) != 0 && fread(&infoTemporaria,sizeof(char),31,arquivo) != 0)
    {
        if(strstr(infoTemporaria,info) != NULL) { posicao = ftell(arquivo); }
    }

    return posicao;
}

// Adiciona os novos termos da Conta criada no arquivo de listas invertidas preferencial do usuário (seja nome ou cidade), onde o métedo "quebra" a string em partes delimitadas por um espaço em branco e verifica se essa substring já consta no documento, caso não é criado um vetor de 10 inteiros para cada nova string. Este vetor inclusive que sua última casa '9' direciona onde será escrito os novos IDs, no entanto se já consta, escreve na próxima casa utilizando o "apontador". Não retorna nada.
void adicionarDadosListaInvertida(int id,char *info,char *origemArquivo)
{
    if(verificarListaInvertida(origemArquivo) == 1)
    {
        FILE *ListaInvertida = fopen(origemArquivo,"ab");

        if(ListaInvertida != NULL)
        {
            char *novasStrings = strtok(info," ");

            while(novasStrings != NULL)
            {
                int idsTemporarios[10] = {id,0,0,0,0,0,0,0,0,1};
                fwrite(idsTemporarios,sizeof(int),10,ListaInvertida);
                fwrite(novasStrings,sizeof(char),31,ListaInvertida);
                novasStrings = strtok(NULL," ");
            }

            fclose(ListaInvertida);
        }
        else { printf("\n\t₪ Erro, arquivo indisponível."); }
    }
    else
    {
        FILE *ListaInvertida = fopen(origemArquivo,"rb+");

        if(ListaInvertida != NULL)
        {
            char *novasStrings = strtok(info," ");

            while(novasStrings != NULL)
            {
                int idsTemporarios[10] = {0,0,0,0,0,0,0,0,0,0};
                long posicao = buscarPosicaoListaInvertida(novasStrings,ListaInvertida);
                if(posicao != -1)
                {
                    fseek(ListaInvertida,posicao-71,SEEK_SET);
                    fread(idsTemporarios,sizeof(int),10,ListaInvertida);

                    if(idsTemporarios[9] > 9) { idsTemporarios[9] = 1; }

                    idsTemporarios[idsTemporarios[9]] = id;
                    idsTemporarios[9]++;
                    fseek(ListaInvertida,posicao-71,SEEK_SET);
                    fwrite(idsTemporarios,sizeof(int),10,ListaInvertida);
                }
                else
                {
                    idsTemporarios[9] = 1;
                    idsTemporarios[0] = id;
                    fwrite(idsTemporarios,sizeof(int),10,ListaInvertida);
                    fwrite(novasStrings,sizeof(char),31,ListaInvertida);
                }
                novasStrings = strtok(NULL," ");
            }
            fclose(ListaInvertida);
        }
        else { printf("\n\t₪ Erro, arquivo indisponível."); }
    }
}

// Informa ao usuário quais contas foram encontradas a partir do dado informado, seja pelo nome ou pela cidade. Não retorna nada.
void buscarDadosListaInvertida(char *info,char *origemArquivo)
{
    if(verificarListaInvertida(origemArquivo) == 0)
    {
        FILE *ListaInvertida = fopen(origemArquivo,"rb+");

        if(ListaInvertida != NULL)
        {
            long posicao = buscarPosicaoListaInvertida(info,ListaInvertida);
            if(posicao != -1)
            {
                fseek(ListaInvertida,posicao-71,SEEK_SET);
                int idsTemporarios[10] = {0,0,0,0,0,0,0,0,0,0};
                fread(idsTemporarios,sizeof(int),10,ListaInvertida);

                printf("\n\t┏━━━━━━━━━━━━━━━━━━━━━┓");
                printf("\n\t┃ IDs Correspondentes ┃");
                printf("\n\t┣━━━━━━━━━━━━━━━━━━━━━┫");
                for(int i = 0; i < 9; i++)
                {
                    if(idsTemporarios[i] > 0) { printf("\n\t┃ %-19d ┃",idsTemporarios[i]); }
                }
                printf("\n\t┗━━━━━━━━━━━━━━━━━━━━━┛\n");
            }
            else{ printf("\n\t₪ Nenhuma ID associada a esta informação.\n"); }
            fclose(ListaInvertida);
        }
        else { printf("\n\t₪ Erro, arquivo indisponível."); }
    }
    else { printf("\n\t₪ Não constam contas registradas no arquivo."); }
}

// Este método remove no arquivo o ID da conta excluída nas ocasiões onde foram registradas esta conta, de forma que zera a posição onde se encontrava e diminui por 1 nossa casa "apontadora", de forma que caso exita uma situação onde iria aparecer novamente a informação, possa ser escrita sem prejudicar a pesquisa.
void removerDadosListaInvertida(int id,char *origemArquivo)
{
    FILE *ListaInvertida = fopen("NomesLI.bin","rb+");

    if(ListaInvertida != NULL)
    {
        char infoTemporaria[31];
        int idsTemporarios[10] = {0,0,0,0,0,0,0,0,0,0};
        while(fread(idsTemporarios,sizeof(int),10,ListaInvertida) != 0 && fread(infoTemporaria,sizeof(char),31,ListaInvertida) != 0)
        {
            for(int i = 0; i < 9; i++)
            {
                if(idsTemporarios[i] == id)
                {
                    idsTemporarios[i] *= -1;
                    idsTemporarios[9]--;
                }
            }
            fseek(ListaInvertida,-71,SEEK_CUR);
            fwrite(idsTemporarios,sizeof(int),10,ListaInvertida);
            fseek(ListaInvertida,+31,SEEK_CUR);
        }
        fclose(ListaInvertida);
    }
    else { printf("\n\t₪ Erro, arquivo indisponível."); }
}

// Da mesma maneira que os métodos de remoção e adição, este remove resquícios das antigas informações no arquivo e escreve as novas, de maneira que não tenha conflitos de dados.
void atualizarDadosListaInvertida(int id,char *infoOriginal, char *infoNova,char *origemArquivo)
{
    if(verificarListaInvertida(origemArquivo) == 0)
    {
        FILE *ListaInvertida = fopen(origemArquivo,"rb+");

        if(ListaInvertida != NULL)
        {
            char *novasStrings = strtok(infoOriginal," ");

            while(novasStrings != NULL)
            {
                long posicao = buscarPosicaoListaInvertida(novasStrings,ListaInvertida);

                fseek(ListaInvertida,posicao-71,SEEK_SET);
                int idsTemporarios[10] = {0,0,0,0,0,0,0,0,0,0};
                fread(idsTemporarios,sizeof(int),10,ListaInvertida);
                for(int i = 0; i < 9; i++)
                {
                    if(idsTemporarios[i] == id)
                    {
                        idsTemporarios[i] = 0;
                        idsTemporarios[9]--;
                    }
                }
                fseek(ListaInvertida,-40,SEEK_CUR);
                fwrite(idsTemporarios,sizeof(int),10,ListaInvertida);
                novasStrings = strtok(NULL," ");
            }
            fclose(ListaInvertida);
            adicionarDadosListaInvertida(id,infoNova,origemArquivo);
        }
        else { printf("\n\t₪ Erro, arquivo indisponível."); }
    }
    else { printf("\n\t₪ Não constam contas registradas no arquivo."); }
}

// Função para criptografar e descriptografar os dados dos usuários no arquivo "Contas.bin", a criptografia criptografiaXOR é bastante simples de ser implementada e dificilmente é quebrada. Retorna a String com os caracteres modificados.
void criptografiaXOR(char *stringOriginal)
{
    char chave = 'X';
    int tamanhoString = strlen(stringOriginal);

    for(int i = 0; i < tamanhoString; i++) { stringOriginal[i] ^= chave; }
}

void inicializarAlocacao(AlocaInformacoes *AI, int tamanho)
{
    AI->base = malloc(tamanho);
    AI->comprimentoSequencia = tamanho;
    AI->proximaAlocacao = AI->base;
}

u_int8_t *Alocar(AlocaInformacoes *AI, int comprimento)
{
    u_int8_t *R = AI->proximaAlocacao;
    comprimento = (comprimento + 3) & ~3;
    AI->proximaAlocacao += comprimento;
    return R;
}

int lerProximoCodigo(EstadoDaLeitura *EL)
{
    int codigo = 0;
    int B0 = fgetc(EL->arquivo);

    if(B0 == EOF) { return CODIGO_FIM; }
    if(EL->bitsRemanecentes == 0)
    {
        int B1 = fgetc(EL->arquivo);
        if(B1 == EOF) { return CODIGO_FIM; }
        codigo = (B0 << 4) | (B1 >> 4);
        EL->bitsRemanecentes = 4;
        EL->codigoRemanecente = (B1 & 0xf) << 8;
    }
    else
    {
        codigo = EL->codigoRemanecente | B0;
        EL->bitsRemanecentes = 0;
    }
    return codigo;
}

void compressaoLZW()
{
    FILE *Dados = fopen("Contas.bin","rb");
    if(Dados != NULL)
    {
        FILE *DadosComprimidos = fopen("ContasX.bin","wb");
        if(DadosComprimidos != NULL)
        {
            fseek(Dados,0,SEEK_END);
            if(ftell(Dados) != 0)
            {
                fseek(Dados,0,SEEK_SET);
                int tamanhoDicionario = 256;
                NoDicionario *ND = calloc(MAXIMO_BITS_DICIONARIO,sizeof(NoDicionario));

                if(ND == NULL) { printf("\n\t◳ Erro ao alocar o dicionário na memória.\n"); }

                else
                {
                    int caractere      = 0;
                    int bitsRestantes  = 0;
                    int bytesRestantes = 0;
                    u_int16_t noAtual  = caractere;

                    do
                    {
                        int byteAtual = fgetc(Dados);
                        if(byteAtual == EOF)
                        {
                            if(bitsRestantes == 0)
                            {
                                fputc(noAtual >> 4, DadosComprimidos);
                                fputc(noAtual << 4, DadosComprimidos);
                            }
                            else
                            {
                                fputc(bytesRestantes | (noAtual >> 8), DadosComprimidos);
                                fputc(noAtual, DadosComprimidos);
                            }
                            break;
                        }

                        u_int16_t proximoNo = ND[noAtual].folha[byteAtual];

                        if(proximoNo != 0) { noAtual = proximoNo; continue; }

                        if (bitsRestantes == 0)
                        {
                            fputc(noAtual  >> 4, DadosComprimidos);
                            bitsRestantes  = 4;
                            bytesRestantes = (noAtual << 4);
                        }
                        else
                        {
                            fputc(byteAtual | (noAtual >> 8), DadosComprimidos);
                            fputc(noAtual, DadosComprimidos);
                            bitsRestantes = 0;
                        }

                        if(tamanhoDicionario < MAXIMO_BITS_DICIONARIO)
                        {
                            ND[noAtual].folha[byteAtual] = tamanhoDicionario++;
                        }
                        else
                        {
                            memset(ND,0,MAXIMO_BITS_DICIONARIO*sizeof(ND[0]));
                            tamanhoDicionario = 256;
                        }

                        noAtual = byteAtual;
                    }
                    while(1);
                }
                free(ND);

                printf("\n\t◮ Compressão realizada com sucesso.\n");
                printf("  \t------------------------------------\n");
                printf("\n\tTamanho original:   %ld\n",ftell(Dados));
                printf("\n\tTamanho modificado: %ld\n",ftell(DadosComprimidos));
            }
            else { printf("\n\t◮ Erro, arquivo vazio.\n"); }
            fclose(DadosComprimidos);
        }
        else { printf("\n\t◮ Erro, arquivo indisponível para escrita.\n"); }
        fclose(Dados);
    }
    else { printf("\n\t◮ Erro, arquivo indisponível para compressão.\n"); }
}

void descompressaoLZW()
{
    FILE *DadosComprimidos = fopen("ContasX.bin","rb");
    if(DadosComprimidos != NULL)
    {
        FILE *Dados = fopen("ContasAA.bin","wb");
        if(Dados != NULL)
        {
            fseek(DadosComprimidos,0,SEEK_END);
            if(ftell(DadosComprimidos) != 0)
            {
                fseek(DadosComprimidos,0,SEEK_SET);

                AlocaInformacoes AI;
                int tamanhoDicionario = 256;
                EstadoDaLeitura EL = { DadosComprimidos, 0, 0 };

                EntradaDicionario *ED = calloc(MAXIMO_BITS_DICIONARIO, sizeof(EntradaDicionario));
                inicializarAlocacao(&AI,MAXIMO_BITS_DICIONARIO*MAXIMO_BITS_DICIONARIO/2 + MAXIMO_BITS_DICIONARIO*2);

                for(int i = 0; i < tamanhoDicionario; i++)
                {
                    ED[i].sequencia = Alocar(&AI,1);
                    ED[i].sequencia[0] = i;
                    ED[i].tamanho = 1;
                }

                u_int8_t *marcador = AI.proximaAlocacao;
                u_int16_t codigoAnterior = lerProximoCodigo(&EL);

                fputc(codigoAnterior, Dados);

                do
                {
                    u_int16_t codigo = lerProximoCodigo(&EL);

                    if(codigo > tamanhoDicionario)
                    {
                        if(codigo == CODIGO_FIM) { break; }
                    }
                    if(tamanhoDicionario == MAXIMO_BITS_DICIONARIO)
                    {
                        tamanhoDicionario = 256;
                        AI.proximaAlocacao = marcador;
                    }
                    else
                    {
                        int comprimentoAnterior = ED[codigoAnterior].tamanho;
                        ED[tamanhoDicionario].tamanho = comprimentoAnterior + 1;
                        ED[tamanhoDicionario].sequencia = Alocar(&AI, comprimentoAnterior + 1);
                        memcpy(ED[tamanhoDicionario].sequencia,ED[codigoAnterior].sequencia,comprimentoAnterior);

                        if(codigo == tamanhoDicionario) { ED[tamanhoDicionario++].sequencia[comprimentoAnterior] = ED[codigoAnterior].sequencia[0]; }
                        else { ED[tamanhoDicionario++].sequencia[comprimentoAnterior] = ED[codigo].sequencia[0]; }
                    }
                    fwrite(ED[codigo].sequencia,1,ED[codigo].tamanho,Dados);
                    codigoAnterior = codigo;
                }
                while(1);

                free(ED);
                free(AI.base);

                printf("\n\t◭ Descompressão realizada com sucesso.\n");
                printf("  \t---------------------------------------\n");
            }
            else { printf("\n\t◭ Erro, arquivo vazio.\n"); }
            fclose(Dados);
        }
        else { printf("\n\t◭ Erro, arquivo indisponível para escrita.\n"); }
        fclose(DadosComprimidos);
    }
    else { printf("\n\t◭ Erro, arquivo indisponível para descompressão.\n"); }
}
