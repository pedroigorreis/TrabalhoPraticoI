//    > Arquivo: 'TrabalhoPratico.java'
//    > Autores: Pedro Igor Martins dos Reis & Hermane Veloso
//    > Data: 27/02/2022
//    > Disciplina: AEDIII | Engenharia de Computação

import java.util.Scanner;

public class TrabalhoPratico
{
    private static void imprimirMenuInicial()
    {
        System.out.printf("\n");
        System.out.printf("\t.---------------------------------------.\n");
        System.out.printf("\t|               No bolso!               |\n");
        System.out.printf("\t|---------------------------------------|\n");
        System.out.printf("\t|       » Escolha uma das opções «      |\n");
        System.out.printf("\t|---------------------------------------|\n");
        System.out.printf("\t| 1 - Criar uma nova conta              |\n");
        System.out.printf("\t| 2 - Acessar sua conta                 |\n");
        System.out.printf("\t| 3 - Sair                              |\n");
        System.out.printf("\t'---------------------------------------'\n");
        System.out.printf("\n");
    }

    private static void imprimirMenuPrincipal()
    {
        System.out.printf("\n");
        System.out.printf("\n");
    }

    public static void main(String[] args) 
    {
        Scanner in = new Scanner(System.in);
        imprimirMenuInicial();
        byte opcaoMenu = in.nextByte();
        switch(opcaoMenu)
        {
            case 1:
            {
                break;
            }

            case 2:
            {
                System.out.printf("\n");
                System.out.printf("\t.------------------------.\n");
                System.out.printf("\t|     Acesso a conta     |\n");
                System.out.printf("\t'------------------------'\n");
                System.out.printf("\n");
                System.out.printf("Por gentileza, informe sua agência: ");
                byte auxAgencia = in.nextByte();
                System.out.printf("Agora, informe sua conta: ");
                byte auxConta = in.nextByte();
                System.out.printf("Por fim, informe sua senha: ");
                byte auxSenha = in.nextByte();
                break;
            }

            case 3:
            {
                break;
            }

            default:
            {
                System.out.printf("\n");
                System.out.printf("\t.-----------------------.\n");
                System.out.printf("\t| Erro, opção inválida. |\n");
                System.out.printf("\t'-----------------------'\n");
                System.out.printf("\n");
                break;
            }
        }
        in.close();
    }
}
