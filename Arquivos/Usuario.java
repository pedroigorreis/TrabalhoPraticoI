package trabalhoPraticoI;

public class Usuario 
{
    private String cpf;
    private String nome;
    private String cidade;
    public Usuario (String cpf, String nome, String cidade)
    {
        this.cpf = cpf;
        this.nome = nome;
        this.cidade = cidade;
    }

    public String getCpf() { return cpf; }
    public String getNome() { return nome; }
    public String getCidade() { return cidade; }

    public void setCpf(String cpf) { this.cpf = cpf; }
    public void setNome(String nome) { this.nome = nome; }
    public void setCidade( String cidade ) { this.cidade = cidade; }

    public String toString()
    {
        return "\nNome: " +  this.getNome() + "\nCPF: " + this.getCpf();
    }
}

