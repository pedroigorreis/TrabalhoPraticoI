package trabalhopraticoI;

public class Usuario 
{
    private String cpf;
    private String nome;
    private static int contador = 1;

    public Usuario (String cpf, String nome)
    {
        contador += 1;
        this.cpf = cpf;
        this.nome = nome;
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

