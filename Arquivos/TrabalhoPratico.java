package trabalhopraticoI;

import java.util.Scanner;
import java.util.ArrayList;

public class TrabalhoPratico 
{
	static ArrayList<Conta> contasBancarias;
	static Scanner in = new Scanner (System.in);
	
	public static void main (String [] args)
	{
		contasBancarias = new ArrayList<Conta>();
		
		Menus.menuInicial();
		byte opcao = in.nextByte();
		do
		{
			switch(opcao)
			{
				case 1:
				{
					FuncoesBancarias.novaConta();
					break;
				}
				case 2:
				{
					FuncoesBancarias.deposito();
					break;
				}
				case 3:
				{
					FuncoesBancarias.saque();
					break;
				}
				case 4:
				{
					FuncoesBancarias.transferencia();
					break;
				}
				case 5:
				{
					FuncoesBancarias.listarContas();
					break;
				}
				case 6:
				{
					System.out.println("Encerrando...");
					System.exit(0);
				}
				default:
				{
					System.out.println("Opção inválida.");
					break;
				}
			}
		}
		while(opcao != 6);
	}
}
