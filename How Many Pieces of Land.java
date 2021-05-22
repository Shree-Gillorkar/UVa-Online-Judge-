import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        StringBuffer sb = new StringBuffer("");
        String m = "";
        int cases=Integer.parseInt(br.readLine());
       for(int i=0;i<cases;i++){
            int x=Integer.parseInt(br.readLine());
            sb.append(numOfLand(x)).append("\n");
        }
        System.out.print(sb);
    }
    static BigInteger numOfLand(int x){
        BigInteger temp=BigInteger.valueOf(x);
        temp=(temp.pow(4)).subtract((temp.pow(3)).multiply(BigInteger.valueOf(6)))
                .add((temp.pow(2)).multiply(BigInteger.valueOf(23)))
                .subtract(temp.multiply(BigInteger.valueOf(18))).add(BigInteger.valueOf(24));
        return temp.divide(BigInteger.valueOf(24));
    }
}