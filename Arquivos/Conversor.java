package trabalhoPraticoI;

import java.text.NumberFormat;
import java.text.DecimalFormat;

public class Conversor 
{
	static NumberFormat formatavalores = new DecimalFormat("R$ #,##0.00");
	public static String floatParaString (float valor) { return formatavalores.format(valor); }
}
