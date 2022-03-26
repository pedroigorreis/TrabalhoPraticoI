package trabalhoPraticoI;

import java.util.Scanner;
import java.io.EOFException;
import java.io.IOException;
import java.io.RandomAccessFile;

public class FuncoesBancarias 
{
	public void buscar(int id, RandomAccessFile RAF) throws IOException
	{
		byte lapide;
		byte byteArray[];
		int tamanhoRegistro;
		boolean confirma = false;
		Conta C = new Conta();
		
		RAF.seek(0);
		RAF.readInt();
		
		while(id != C.idConta)
		{
			try
			{
				lapide = RAF.readByte();
				tamanhoRegistro = RAF.readInt();
				
				byteArray = new byte[tamanhoRegistro];
				RAF.read(byteArray);
				C.fromByteArray(byteArray);
				
				if(lapide == 0 && C.idConta == id)
				{
					confirma = true;
					System.out.printf("\tConta encontrada.\n");
					break;
				}
			}
			catch (EOFException err) 
			{
				err.printStackTrace();
				break;
			}
		}
		if(confirma == false)
		{
			System.out.printf("\tConta não encontrada.\n");
		}
	}
	
	public static void cadastro(RandomAccessFile RAF) throws IOException
	{
		Scanner in = new Scanner(System.in);

		Menus.menuNovaConta();
		
		System.out.printf("\n\tCPF: ");
		String cpf = in.nextLine();
		System.out.printf("\tNome: ");
		String nome = in.nextLine();
		System.out.printf("\tCidade: ");
		String cidade = in.nextLine();
		System.out.printf("\tSaldo (utilize ','): ");
		Float saldo = in.nextFloat();
		
		Conta C = new Conta(cpf, cidade, saldo, nome);
				
		RAF.seek(0);
		int id = RAF.readInt();
		int idProximo = id + 1;
		
		RAF.seek(0);
		RAF.writeInt(idProximo);
		
		byte byteArray[] = C.toByteArray();
		RAF.seek(RAF.length());
		
		RAF.writeByte(0);
		RAF.writeInt(byteArray.length);
		RAF.write(byteArray);
		
		System.out.print(C.toString());
		System.out.printf("\tConta %d aberta com sucesso!\n",C.idConta);
		in.close();
		RAF.close();
	}
	
	public static void atualizar(RandomAccessFile RAF) throws IOException 
	{
		Menus.menuAtualizacao();
		
		byte lapide;
		long posicao;
		byte byteArray[];
		byte novoArray[];
		int tamanhoRegistro;
		Conta D = new Conta(); 
		Conta C = new Conta();
		boolean confirma = false;
		Scanner in = new Scanner(System.in);
		
		RAF.seek(0);
		RAF.readInt();
		
		while(true)
		{
			try
			{
				lapide = RAF.readByte();
				posicao = RAF.getFilePointer();
				tamanhoRegistro = RAF.readInt();
				
				byteArray = new byte[tamanhoRegistro];
				RAF.read(byteArray);
				
				if(lapide == 0 && D.idConta == C.idConta)
				{
					confirma = true;
					C.transferenciasRealizadas = D.transferenciasRealizadas;
					novoArray = C.toByteArray();
					
					if(novoArray.length <= tamanhoRegistro)
					{
						RAF.seek(posicao);
						RAF.readByte();
						RAF.readInt();
						RAF.write(byteArray);
					}
					else
					{
						RAF.seek(posicao);
						RAF.write(1);
						
						RAF.seek(RAF.length());
						RAF.writeByte(0);
						RAF.writeInt(novoArray.length);
						RAF.write(novoArray);
					}
					System.out.printf("\n\tDados atualizados.\n");
					D.toString();
					break;
				}
			}
			catch (EOFException err) 
			{
				err.printStackTrace();
				break;
			}
		}
		if(confirma == false) { System.out.printf("\n\tConta não encontrada.\n"); }
		in.close();
	}
	public static void deletar(RandomAccessFile RAF) throws IOException 
	{
		Menus.menuDeletarConta();
		Scanner in = new Scanner(System.in);
		
		System.out.printf("\n\tDigite o ID da conta desejada para remoção: ");
		int id = in.nextInt();
		
		byte lapide;
		long posicao;
		byte byteArray[];
		int tamanhoRegistro;
		Conta C = new Conta();
		boolean confirma = false;
		
		while(true)
		{
			try
			{
				lapide = RAF.readByte();
				posicao = RAF.getFilePointer();
				tamanhoRegistro = RAF.readInt();
				
				byteArray = new byte[tamanhoRegistro];
				RAF.read(byteArray);
				
				if(lapide == 0 && C.idConta == id)
				{
					confirma = true;
					RAF.seek(posicao);
					RAF.write(1);
					
					break;
				}
			}
			catch (Exception e) 
			{
				e.printStackTrace();
				break;
			}
		}
		if(confirma != true)
		{
			System.out.printf("\n\tConta não encontrada.\n");
		}
		in.close();
	}
	
	public static void transferencia(RandomAccessFile RAF) throws IOException
	{
		Menus.menuTransferencia();
		
		
		// Variáveis necessárias.
		byte lapide;
		int tamanhoRegistro;
		long posicaoRem = -1;
		long posicaoDes = -1;
		Conta C = new Conta(); // Leitura.
		Conta X = new Conta(); // Remetente.
		Conta Z = new Conta(); // Destinataria.
		boolean confirmaRem = false;
		boolean confirmaDes = false;
		Scanner in = new Scanner(System.in);
		
		System.out.printf("\n\tDigite o ID da conta Remetente: ");
		int idRemetente = in.nextInt();
		System.out.printf("\n\tDigite o ID da conta Destinatária: ");
		int idDestinatario = in.nextInt();
		System.out.printf("\n\tDigite o valor desejado para transferência: ");
		float valor = in.nextInt();
		
		while(true) // Loop de pesquisa/comparação.
		{
			try 
			{
				lapide = RAF.readByte();
				tamanhoRegistro = RAF.readInt();
				
				if(confirmaDes == false) { posicaoDes = RAF.getFilePointer(); }
				if(confirmaRem == false) { posicaoRem = RAF.getFilePointer(); }
				byte byteArray[] = new byte[tamanhoRegistro];
				
				RAF.read(byteArray);
				C.fromByteArray(byteArray);
				
				if(lapide == 0)
				{
					if(C.idConta == idRemetente)
					{
						confirmaRem = true;
						X.fromByteArray(byteArray);
					}
					else if(C.idConta == idDestinatario)
					{
						confirmaDes = true;
						Z.fromByteArray(byteArray);
					}
				}
				if(confirmaRem == true && confirmaDes == true) { break; }
				else
				{
					X.saldo = (X.saldo - valor);
					X.transferenciasRealizadas = (short) (X.transferenciasRealizadas + 1);
					Z.saldo = (Z.saldo - valor);
					Z.transferenciasRealizadas = (short) (Z.transferenciasRealizadas + 1);
					
					RAF.seek(posicaoRem);
					RAF.write(X.toByteArray());
					RAF.seek(posicaoDes);
					RAF.write(Z.toByteArray());
				}
			}
			catch (EOFException err) { break; }
		}
		in.close();
	}
}
