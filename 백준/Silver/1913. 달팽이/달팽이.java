import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) throws IOException {
        StringBuilder sb = new StringBuilder();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());
        int resX = 0, resY = 0;
        int[][] isVisited = new int[N][N];
        int[] dx = {0, 1, 0, -1};
        int[] dy = {-1, 0, 1, 0};


        // sum 방문한 칸 수 / index 다음칸 인덱스
        int sum = 0, index = 0, nowX = 0, nowY = 0;
        isVisited[nowX][nowY] = N * N;
        sum++;

        while(sum < N * N){
            // 다음으로 이동할 칸 설정
            int newX = nowX + dx[index];
            int newY = nowY + dy[index];

            // 다음 위치가 배열 내부에서 이동가능한 위치인지 확인
            // 이미 방문한 위치인지 확인
            if (newX >= 0 && newY >= 0 &&
                    newX < N && newY < N &&
                    isVisited[newX][newY] == 0){
                // 방문 카운트를 올리고 isVisited에 현재 위치에 방문 체크
                isVisited[newX][newY] = N * N - sum;
                sum++;

                // TODO 아래부분 에서 같을 경우 resX resY 업데이트
                if (isVisited[newX][newY] == M){
                    resX = newX;
                    resY = newY;
                }
                nowX = newX;
                nowY = newY;
            }else{
                // 다음 위치가 배열 범위를 벗어나거나 이미 방문한 경우
                // 방향을 변경 (방향을 변경했으므로 count++)
                // 방향전환 배열을 벗어나지 않도록 % 4 로 내부 순환
                index = (index + 1) % 4;
            }
        }


        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                sb.append(isVisited[i][j]).append(" ");
            }
            sb.append("\n");
        }
        sb.append(resX + 1).append(" ").append(resY + 1);
        System.out.println(sb.toString());
    }
}