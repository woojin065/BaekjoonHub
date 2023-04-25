import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
       Scanner s = new Scanner(System.in);
       int n = s.nextInt();
       for(int i=n-1;i>=0;i--){
           for(int j=0;j<2*n;j++){
               if(j>n+i-1) break;
               if(j<n-i-1) System.out.print(" ");
               else System.out.print("*");
           }
           System.out.println("");
       }
    }
}