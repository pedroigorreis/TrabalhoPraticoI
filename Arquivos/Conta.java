package trabalhoPraticoI;

public class Conta 
{
    private int idConta;
    private Usuario usuario;
    private float saldo = 0;
    private static int contadorContas = 1;

    public Conta (Usuario usuario)
    {
        this.usuario = usuario;
        this.idConta = contadorContas;
        contadorContas += 1;
    }

    public float getSaldo() { return saldo; }
    public int getIdConta() { return idConta; }
    public Usuario getUsuario() { return usuario; }

    public void setSaldo( float saldo ) { this.saldo = saldo; }
    public void setIdConta( int idConta ) { this.idConta = idConta; }
    public void setUsuario( Usuario usuario ) { this.usuario = usuario; }

    public String toString()
    {
        return "\n\tNúmero da conta: " + this.getIdConta() 
        		+ "\n\tNome completo: " + this.usuario.getNome() 
        		+ "\n\tCPF: " + this.usuario.getCpf() 
        		+ "\n\tSaldo: " + ConversorReal.floatParaString(this.getSaldo()) + "\n";
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
}
