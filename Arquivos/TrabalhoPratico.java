package trabalhoPraticoI;

import java.util.Scanner;
import java.util.ArrayList;

public class TrabalhoPratico 
{
	static ArrayList<Conta> contasBancarias;
	static Scanner in = new Scanner (System.in);
	
	public static void novaConta()
    {
        System.out.printf("\n\tNome completo: ");
        String nome = in.next();

        System.out.printf("\tCPF: ");
        String cpf = in.next();

        Usuario usuario = new Usuario(cpf, nome);
        Conta conta = new Conta(usuario);
        
        contasBancarias.add(conta);
        System.out.printf("\tConta aberta com sucesso!\n");
        funcoesBancarias();
    }
    
    public static Conta encontrarConta(int idConta)
    {
        Conta conta = null;
        if(contasBancarias.size() > 0)
        {
            for(Conta c : contasBancarias)
            {
                if(c.getIdConta() == idConta) { conta = c; }
            }
        }
        return conta;
    }
    
    public static void deposito()
    {
    	Menus.menuDeposito();
        System.out.printf("\tNúmero da conta: ");
        int idConta = in.nextInt();

        Conta conta = encontrarConta(idConta);

        if(conta != null)
        {
            System.out.printf("\tValor para depósito: R$ ");
            float valorDeposito = in.nextFloat();
            conta.depositar(valorDeposito);
        }
        else
        {
            System.out.printf("\tErro, conta inválida.\n");
        }
        funcoesBancarias();
    }
    
    public static void saque()
    {
    	Menus.menuSaque();
        System.out.printf("\tNúmero da conta: ");
        int idConta = in.nextInt();
        Conta conta = encontrarConta(idConta);

        if(conta != null)
        {
            System.out.println("\tValor do saque: ");
            float valorSaque = in.nextFloat();
            conta.sacar(valorSaque);
        }
        else
        {
            System.out.printf("\tErro, conta inválida.\n");
        }
        funcoesBancarias();
    }

    public static void transferencia()
    {
    	Menus.menuTransferencia();
        System.out.printf("\tNúmero da conta remetente: ");

        int idContaRemetente = in.nextInt();
        Conta contaRemetente = encontrarConta(idContaRemetente);

        if(contaRemetente != null)
        {
            System.out.printf("\tNúmero da conta destinatária: ");
            int idContaDestinaria = in.nextInt();

            Conta contaDestinataria = encontrarConta(idContaDestinaria);

            if(contaDestinataria != null)
            {
                System.out.printf("\tValor da transferência: ");
                float valor = in.nextFloat();

                contaRemetente.transferir(contaDestinataria, valor);
            }
            else
            {
                System.out.printf("\nConta não encontrada!\n");
            }
        }
        funcoesBancarias();
    }
    
    public static void listarContas()
    {
        if(contasBancarias.size() > 0)
        {
            for(Conta c : contasBancarias)
            {
                System.out.println(c);
            }
        }
        else
        {
            System.out.printf("\tNenhuma conta cadastrada!\n");
        }
        funcoesBancarias();
    }
	
    public static void funcoesBancarias()
    {
    	Menus.menuInicial();
        byte opcao = in.nextByte();
		switch(opcao)
		{
			case 1:
			{
				novaConta();
				break;
			}
			case 2:
			{
				deposito();
				break;
			}
			case 3:
			{
				saque();
				break;
			}
			case 4:
			{
				transferencia();
				break;
			}
			case 5:
			{
				listarContas();
				break;
			}
			case 6:
			{
				System.out.printf("\n\tFim.\n");
				System.exit(0);
			}
			default:
			{
				System.out.printf("\n\tOpção inválida.\n");
				break;
			}
		}
    }
    
	public static void main (String [] args)
	{
		contasBancarias = new ArrayList<Conta>();
		funcoesBancarias();
	}
}
