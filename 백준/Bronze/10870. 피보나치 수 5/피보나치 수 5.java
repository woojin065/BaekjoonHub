import java.util.Scanner;

public class Main {
    public static Long Fib(Long n){
        if(n==1||n==2)return 1L;
        else{
            return Fib(n-2)+Fib(n-1);
        }
    }
    public static void main(String[] args) {
       Scanner s = new Scanner(System.in);
       Long n = s.nextLong();
       if(n!=0)System.out.println(Fib(n));
       else System.out.println("0");
    }
}