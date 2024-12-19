import java.util.*;

class Main{
      public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        Queue<Integer> q = new LinkedList<>();
          for (int i = 1; i <= n; i++) { 
            q.add(i);
        }

        while (q.size() > 1) { // 큐에 한 요소만 남을 때까지 반복
            q.poll(); // 첫 번째 요소 제거
            q.add(q.poll()); // 두 번째 요소를 맨 뒤로 이동
        }

        System.out.println(q.peek());
    }
}