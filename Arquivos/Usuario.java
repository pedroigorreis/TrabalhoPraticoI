package trabalhoPraticoI;

public class Usuario 
{
    private String cpf;
    private String nome;
    private static int contador = 1;
    public Usuario (String cpf, String nome)
    {
        this.cpf = cpf;
        this.nome = nome;
        contador += 1;
    }

    public String getCpf() { return cpf; }
    public String getNome() { return nome; }

    public void setCpf(String cpf) { this.cpf = cpf; }
    public void setNome(String nome) { this.nome = nome; }

    public String toString()
    {
        return "\nNome: " +  this.getNome() + "\nCPF: " + this.getCpf();
    }
}

