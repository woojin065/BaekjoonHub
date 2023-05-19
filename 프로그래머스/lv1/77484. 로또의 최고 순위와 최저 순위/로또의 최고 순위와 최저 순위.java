class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        int[] answer = {0, 0};
        int cor = 0;
        int zero = 0;
        for(int i=0;i<lottos.length;i++){
            if(lottos[i]!=0){
                for(int j=0;j<lottos.length;j++){
                    if(lottos[i]==win_nums[j]){
                        cor++;
                        break;
                    }
                }
            }
            else
                zero++;
        }
        System.out.print(cor);
        answer[1]=7-cor>6?6:7-cor;
        answer[0]=answer[1]-zero==0?1:answer[1]-zero;
        
        
        return answer;
    }
}