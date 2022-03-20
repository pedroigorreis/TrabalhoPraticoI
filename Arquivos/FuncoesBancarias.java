package trabalhoPraticoI;

import java.util.Scanner;

public class FuncoesBancarias 
{
	static Scanner in = new Scanner (System.in);
	
    public static void novaConta()
    {
        System.out.printf("\tNome completo: ");
        String nome = in.next();

        System.out.printf("\tCPF: ");
        String cpf = in.next();

        Usuario usuario = new Usuario(nome, cpf);

        Conta conta = new Conta(usuario);
        TrabalhoPratico.contasBancarias.add(conta);

        System.out.printf("\tConta aberta com sucesso!\n");
        TrabalhoPratico.main(null);
    }
    
    public static Conta encontrarConta(int idConta)
    {
        Conta conta = null;
        if(TrabalhoPratico.contasBancarias.size() > 0)
        {
            for(Conta c : TrabalhoPratico.contasBancarias)
            {
                if(c.getIdConta() == idConta)
                {
                    conta = c;
                }
            }
        }
        return conta;
    }
    
    public static void deposito()
    {
        System.out.printf("\tNúmero da conta: ");
        int idConta = in.nextInt();

        Conta conta = encontrarConta(idConta);

        if(conta != null)
        {
            System.out.printf("\tValor para depósito: ");
            float valorDeposito = in.nextFloat();
            conta.depositar(valorDeposito);
            System.out.printf("\tValor depositado com sucesso.\n");
        }
        else
        {
            System.out.printf("\tErro, conta inválida.\n");
        }
        TrabalhoPratico.main(null);
    }
    public static void saque()
    {
        System.out.printf("\tNúmero da conta: ");
        int idConta = in.nextInt();
        Conta conta = encontrarConta(idConta);

        if(conta != null)
        {
            System.out.println("Valor do saque: ");
            float valorSaque = in.nextFloat();
            conta.sacar(valorSaque);
        }
        else
        {
            System.out.printf("\tErro, conta inválida.\n");
        }
        TrabalhoPratico.main(null);
    }

    public static void transferencia()
    {
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
        TrabalhoPratico.main(null);
    }
    public static void listarContas()
    {
        if(TrabalhoPratico.contasBancarias.size() > 0)
        {
            for(Conta conta : TrabalhoPratico.contasBancarias)
            {
                System.out.println(conta);
            }
        }
        else
        {
            System.out.printf("\tNenhuma conta cadastrada!\n");
        }
        TrabalhoPratico.main(null);
    }
}
