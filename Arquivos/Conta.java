package trabalhoPraticoI;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public class Conta // Definição do objeto 'Conta' e suas características.
{
	protected String cpf;
	protected int idConta;
	protected String cidade;
	protected float saldo = 0F;
	protected String nomePessoa;
	protected short transferenciasRealizadas = 0;
    
	public Conta() // Conta genérica para preenchimento.
	{
		this.cpf = "";
		this.saldo = 0F;
		this.cidade = "";
		this.idConta = -1;
		this.nomePessoa = "";
	}
	
	public Conta(String cpf, String cidade, float saldo, String nomePessoa) // Conta com os dados providos pelo usuário. 
	{
		this.cpf = cpf;
		this.saldo = saldo;
		this.cidade = cidade;
		this.idConta = (int)Math.floor(Math.random()*(9999-1000+1)+1000);
		this.nomePessoa = nomePessoa;
		this.transferenciasRealizadas = 0;
	}
	
    public String toString() // Formatação para impressão.
    {
        return "\n\t.-----------------------. "
        	 + "\n\t| Número da conta       | " + idConta
        	 + "\n\t| Nome completo         | " + nomePessoa
        	 + "\n\t| Cidade                | " + cidade
        	 + "\n\t| CPF                   | " + cpf 
        	 + "\n\t| Saldo                 | " + Conversor.floatParaString(saldo)
        	 + "\n\t| N° de transferências  | " + transferenciasRealizadas
        	 + "\n\t'-----------------------' "
        	 + "\n";
    }
    
    public byte[] toByteArray() throws IOException // Converter para vetor de Bytes.
    {
    	ByteArrayOutputStream gerador = new ByteArrayOutputStream();
    	DataOutputStream DOS = new DataOutputStream(gerador);

        DOS.writeInt(idConta);
        DOS.writeUTF(nomePessoa);
        DOS.writeUTF(cpf);
        DOS.writeUTF(cidade);
        DOS.writeShort(transferenciasRealizadas);
        DOS.writeFloat(saldo);
        
        return gerador.toByteArray();
    }
    
    public void fromByteArray(byte[] byteContas) throws IOException // Converter para informações legíveis.
    {
    	ByteArrayInputStream leitor = new ByteArrayInputStream(byteContas);
    	DataInputStream DIS = new DataInputStream(leitor);
    	
    	idConta = DIS.readInt();
    	nomePessoa = DIS.readUTF();
    	cpf = DIS.readUTF();
    	cidade = DIS.readUTF();
    	transferenciasRealizadas = DIS.readShort();
    	saldo = DIS.readFloat();
    }
}
