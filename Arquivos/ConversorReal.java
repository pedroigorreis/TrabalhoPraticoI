//    > Data: 27/02/2022
//    > Arquivo: 'ConversorReal.java'
//    > Disciplina: AEDIII | Engenharia de Computação
//    > Autores: Pedro Igor Martins dos Reis & Hermane Veloso

package trabalhoPraticoI;

import java.text.NumberFormat;
import java.text.DecimalFormat;

public class ConversorReal // Utilitário para formatação em R$ para valores movimentados.
{
    static NumberFormat formatavalores = new DecimalFormat("R$ #,##0.00");
    public static String floatParaString (float valor)
    {
        return formatavalores.format(valor);
    }
}
