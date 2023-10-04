class Solution {
    public int solution(int storey) {
        int answer = 0;
        
        while (storey != 0) {
            int r = storey % 10;
            storey /= 10;
            if (r > 5) {
                storey += 1;
                answer += 10 - r;
            }
            else if (r < 5) {
                answer += r;
            }
            else if (r == 5) {
                if (storey % 10 >= 5) {
                    storey += 1;
                }
                answer += 5;
            }  
        }
        return answer;
    }
}
