import java.util.*;

public class Main {
    public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int C = scan.nextInt();	// 사탕 가격
		int K = scan.nextInt();	// 0의 개수
		
		int num = (int) Math.pow(10, K);	// 10의 K제곱
		
    int ans = (C + num / 2) / num * num; // 반올림 처리
		System.out.println(ans);
		
		scan.close();
  }
}