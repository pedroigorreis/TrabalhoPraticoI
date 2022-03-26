package trabalhoPraticoI;

import java.io.RandomAccessFile;
import java.util.Scanner;

public class Main 
{
	public static void main(String[] args)
	// O 'main' apenas recebe qual opção o usuário
	// deseja (pelo byte "opcao") e o redireciona 
	// para o seriço desejadao, porém sua principal
	// funcionalidade é no controle do arquivo criado.
	{
		Scanner in = new Scanner(System.in);
		try
		{
			RandomAccessFile RAF = new RandomAccessFile("dados.dat", "rw");
			RAF.setLength(0);
			RAF.writeInt(0);
			
			byte opcao = 0;
			do
			{
				Menus.menuInicial();
				
				opcao = in.nextByte();
				in.nextLine();
				
				switch(opcao)
				{
					case 1:
					{
						FuncoesBancarias.cadastro(RAF);
						break;
					}
					case 2:
					{
						FuncoesBancarias.atualizar(RAF);
						break;
					}
					case 3:
					{
						FuncoesBancarias.transferencia(RAF);
						break;
					}
					case 4:
					{
						FuncoesBancarias.deletar(RAF);
						break;
					}
					case 5:
					{
						System.out.printf("\n\tPrgrama finalizado.\n");
						System.exit(0);
						break;
					}
					default:
					{
						System.out.printf("\n\tOpção inválida.\n");
						break;
					}
				}
			}
			while(opcao != 5);
			RAF.close();
		}
		catch (Exception e) 
		{
			e.printStackTrace();
		}
		in.close();
	}
}