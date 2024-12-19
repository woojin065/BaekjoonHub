import java.util.*;

class Main {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        Stack<Integer> stack = new Stack<>();
        
        for (int i = 0; i < N; i++) {
            int a = sc.nextInt();
            if (a != 0){
                stack.push(a);
            } else if (!stack.isEmpty()) {
                stack.pop();
            }
        }
        int sum = 0; // 스택에 남아 있는 숫자의 합 계산
        for (int i = 0; i < stack.size(); i++) {
            sum += stack.get(i);
        }
        System.out.println(sum);
    }
}
