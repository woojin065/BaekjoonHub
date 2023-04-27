import java.util.Scanner;

public class Main {
    public static int ans=0;
    public static int recursion(String s, int l, int r){
        ans+=1;
        if(l >= r) return 1;
        else if(s.charAt(l) != s.charAt(r)) return 0;
        else return recursion(s, l+1, r-1);
    }
    public static int isPalindrome(String s){
        return recursion(s, 0, s.length()-1);
    }
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        for(int i=0;i<n;i++){
            ans=0;
            String s1 = s.next();
            System.out.println(isPalindrome(s1)+" "+ans);
        }
    }
}