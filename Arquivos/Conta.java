package trabalhoPraticoI;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public class Conta
{
	private int idConta;
    private Usuario usuario;
    private float saldo = 0F;
    private static int contadorContas = 1;
    private short transferenciasRealizadas = 0;

    public Conta (Usuario usuario)
    {
        this.usuario = usuario;
        this.idConta = contadorContas;
        contadorContas += 1;
    }

    public float getSaldo() { return saldo; }
    public int getIdConta() { return idConta; } 
    public Usuario getUsuario() { return usuario; }
    public short getTransferenciasRealizadas() { return transferenciasRealizadas; }

    public void setSaldo( float saldo ) { this.saldo = saldo; }
    public void setIdConta( int idConta ) { this.idConta = idConta; }
    public void setUsuario( Usuario usuario ) { this.usuario = usuario; }
    public void setTR( short transferenciasRealizadas ) { this.transferenciasRealizadas = transferenciasRealizadas; }

    public String toString()
    {
        return "\n\tNúmero da conta: " + this.getIdConta() 
        		+ "\n\tNome completo: " + this.usuario.getNome()
        		+ "\n\tCidade: " + this.usuario.getCidade()
        		+ "\n\tCPF: " + this.usuario.getCpf() 
        		+ "\n\tSaldo: " + ConversorReal.floatParaString(this.getSaldo()) + "\n"
        		+ "\n\tN° de transferências: " + this.getTransferenciasRealizadas();
    }

    public void depositar(float valorSaldo)
    {
        if(valorSaldo > 0)
        {
            setSaldo(getSaldo() + valorSaldo);
            System.out.printf("\tDepósito realizado com sucesso.\n");
        }
        else
        {
            System.out.printf("\tSaldo insuficiente para esta operação.\n");
        }
    }

    public void sacar (float valorSaldo)
    {
        if(valorSaldo >= 0 && this.getSaldo() >= valorSaldo)
        {
            setSaldo(getSaldo() - valorSaldo);
            System.out.printf("\tSaque realizado com sucesso.\n");
        }
        else
        {
            System.out.printf("\tSaldo insuficiente para esta operação.\n");
        }
    }

    public void transferir (Conta contaDestinaria, float valorSaldo)
    {
        if(valorSaldo > 0 && this.getSaldo() >= valorSaldo)
        {
            setSaldo(getSaldo() - valorSaldo);
            contaDestinaria.saldo = contaDestinaria.getSaldo() + valorSaldo;
            System.out.printf("\tTransferência realizada com sucesso.\n");
        }
        else
        {
            System.out.printf("\tOps! Ocorreu um erro ao realizar a operação.\n");
        }
    }
    
    public void fromByteArray(byte[] dados) throws IOException
	{
		 ByteArrayInputStream leitor = new ByteArrayInputStream(dados);
		 DataInputStream DIS = new DataInputStream(leitor);
		 
		 idConta = DIS.readInt();
		 usuario.setNome(DIS.readUTF());
		 usuario.setCpf(DIS.readUTF());
		 usuario.setCidade(DIS.readUTF());
		 saldo = DIS.readFloat();
		 transferenciasRealizadas = DIS.readShort();
	}
    
	public byte[] toByteArray() throws IOException 
	{
		ByteArrayOutputStream gerador = new ByteArrayOutputStream();
		DataOutputStream DOS = new DataOutputStream(gerador);
		
		DOS.writeInt(getIdConta());
		DOS.writeUTF(getUsuario().getNome());
		DOS.writeUTF(getUsuario().getCidade());
		DOS.writeUTF(getUsuario().getCpf());
		DOS.writeFloat(getSaldo());
		DOS.writeShort(getTransferenciasRealizadas());
		
		return gerador.toByteArray();
	}
}
